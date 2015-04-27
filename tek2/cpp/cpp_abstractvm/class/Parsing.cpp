/*
** Parser.cpp for Parser in /home/mathon_j/rendu/cpp_abstractvm/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Feb 17 22:44:53 2015 Jérémy MATHON
** Last update Fri Feb 20 23:18:17 2015 Pierrick Gicquelais
*/

#include	"Parsing.hpp"

Parsing::Parsing() {
	this->_instructions.push_back(std::make_pair("push", true));
	this->_instructions.push_back(std::make_pair("pop", false));
	this->_instructions.push_back(std::make_pair("dump", false));
	this->_instructions.push_back(std::make_pair("assert", true));
	this->_instructions.push_back(std::make_pair("add", false));
	this->_instructions.push_back(std::make_pair("sub", false));
	this->_instructions.push_back(std::make_pair("mul", false));
	this->_instructions.push_back(std::make_pair("div", false));
	this->_instructions.push_back(std::make_pair("mod", false));
	this->_instructions.push_back(std::make_pair("print", false));
	this->_instructions.push_back(std::make_pair("exit", false));

	this->_values["int8"] = Int8;
	this->_values["int16"] = Int16;
	this->_values["int32"] = Int32;
	this->_values["float"] = Float;
	this->_values["double"] = Double;

	this->_map["push"] = &Core::push;
	this->_map["pop"] = &Core::pop;
	this->_map["dump"] = &Core::dump;
	this->_map["assert"] = &Core::assert;
	this->_map["add"] = &Core::add;
	this->_map["sub"] = &Core::sub;
	this->_map["mul"] = &Core::mul;
	this->_map["div"] = &Core::div;
	this->_map["mod"] = &Core::mod;
	this->_map["print"] = &Core::print;
	this->_map["exit"] = &Core::exit;

	this->_line = 1;	
	this->_elements = 0;
	this->_exit = false;
}

void Parsing::getCommands(std::istream &in, Core *core) {
	std::string line;

	if (in) {
		while (getline(in, line)) {
			if (in == std::cin and line.find(";;") != line.npos) {
				break;
			}

			if (line.size() != 0 and line.at(0) != ';') {
				if (line.find_first_of(';') != line.npos) {
					line.erase(line.find_first_of(';'), line.npos);
				}

				if (line == "exit") {
					this->_exit = true;
				}

				try {
					this->commandLine(line, core);
				} catch (const ParsingError &error) {
					throw ParsingError(this->getErrorLine(error.what()));
				}
			}
			this->_line++;
		}

		if (this->_exit == false) {
			throw ParsingError("You must finish your commands file with exit instruction");
		}
	} else {
		throw ParsingError("Commands file does not exists");
	}
}

void Parsing::commandLine(const std::string &line, Core *core) {
	std::istringstream word(line);
	std::string instruction;
	std::string type;
	std::string value;
	bool status = false;

	word >> instruction;
	word >> type;

	if (!type.empty()) {
		if (type.find('(') != type.npos and type.find(')') != type.npos) {
			value = type.substr(type.find_first_of('(') + 1);
			value = value.substr(0, value.find_last_of(')'));
			type.erase(type.find_first_of('('), type.npos);
			status = true;
		} else {
			throw ParsingError("A value between () was expected");
		}
	}

	if (std::find(this->_instructions.begin(), this->_instructions.end(), std::make_pair(instruction, status)) == this->_instructions.end()) {
		throw ParsingError("Undefined instruction");
	} else {
		if (!type.empty() and this->_values.find(type) == this->_values.end()) {
			throw ParsingError("Undefined type");
		} else {
			try {
				this->checkElements(instruction);
			} catch (const ParsingError &error) {
				throw ParsingError(error.what());
			}

			try {
				this->isNumber(value);
			} catch (const ParsingError &error) {
				throw ParsingError(error.what());
			}

			this->createInstruction(instruction, type, value, core);
		}
	}
}

void Parsing::checkElements(const std::string &instr) {
	if (instr == "pop" and this->_elements == 0) {
		throw ParsingError("Pop instruction on an empty list");
	} else if ((instr == "add" or instr == "sub" or instr == "mul" or instr == "div" or instr == "mod") and this->_elements < 2) {
		throw ParsingError("Calculate instruction on a list without more 2 elements");
	} else if ((instr == "add" or instr == "sub" or instr == "mul" or instr == "div" or instr == "mod" or instr == "pop")) {
		this->_elements--;
	} else if (instr == "push") {
		this->_elements++;
	}
}

void Parsing::isNumber(const std::string &value) {
	std::string::const_iterator it = value.begin();
	while (it != value.end()) {
		if (!std::isdigit(*it) and *it != '.' and *it != '-') {
			throw ParsingError("Value is not a number");
		} else {
			*it++;
		}
	}
}

void Parsing::createInstruction(const std::string &instr, const std::string &type, const std::string &value, Core *core) {
	Hatchery hatchery;

	if (this->_map.find(instr) != this->_map.end()) {		
		try {
			IOperand *operand = hatchery.createOperand(this->_values[type], value);
			core->pushMemoryInstruction(this->_map[instr], operand);
		} catch (const std::exception &error) {
			throw ParsingError(error.what());
		}
	}

}

std::string Parsing::getErrorLine(const char *specification) const {
	std::stringstream stream;
	stream << "Line ";
	stream << this->_line;
	stream << ": ";
	stream << specification;

	return stream.str();
}
