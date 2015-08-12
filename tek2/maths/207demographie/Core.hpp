#ifndef CORE_HPP_
# define CORE_HPP_

# include <iostream>
# include <iomanip>
# include <algorithm>

# include <cmath>
# include <cstdlib>

# include <list>
# include <vector>

#include "Exception.hpp"
using namespace std;

class Core {
    fstream _file;
    char **_env;
    ostringstream _stream;

    list<string> _args;
    list<string> _names;

    vector<int> _years;
    vector<double> _values;

    double _a1;
    double _b1;

    double _a2;
    double _b2;

    double _e1;
    double _e2;

    double _c;

 public:
    Core() {};
    ~Core() {};

    void init(int argc, char **argv, char **envp) {
        this->_env = envp;
        this->_stream << "./display.py ";

        this->_years.resize(51);
        this->_years.assign(51, 0);

        this->_values.resize(51);
        this->_values.assign(51, 0);

        for (int i = 1; i < argc; i++) {
            string toArg(argv[i]);
            std::transform(toArg.begin(), toArg.end(), toArg.begin(), ::toupper);

            if (std::find(this->_args.begin(), this->_args.end(), toArg) != this->_args.end()) {
                throw Exception("Same code written twice");
            } else {
                this->_args.push_back(toArg);
            }
        }
    }

    void run(void) {
        this->fill();

        cout << setprecision(2) << fixed;
        cout << "\033[1;4mPays:\033[0m" << endl;
        for (list<string>::iterator it = this->_names.begin(); it != this->_names.end(); it++) {
            cout << "\t" << *it << endl;
        }
        cout << endl;

        this->ajust(this->_years, this->_values, &this->_a1, &this->_b1);
        this->firstCovariance();
        cout << "\033[1;4mAjustement de Y en X:\033[0m" << endl;
        cout << "\ty = " << (this->_a1 / 1000000) << "x";
        cout << ((this->_b1 > 0) ? " + " : " - ");
        cout << (abs(this->_b1) / 1000000) << endl;
        cout << "\tEcart-Type:\t\t\t\t" << (this->_e1 / 1000000) << endl;
        cout << "\tEstimation de la population en 2050:\t" << ((this->_a1 / 1000000) * 2050 + (this->_b1 / 1000000)) << endl;
        cout << endl;

        this->_stream << (this->_a1 / 1000000) << " " << (this->_b1 / 1000000);

        this->ajust(this->_values, this->_years, &this->_a2, &this->_b2);
        this->secondCovariance();
        if (this->_a2 < 0) {
            throw Exception("Division by zero");
        } else {
            cout << "\033[1;4mAjustement de X en Y:\033[0m" << endl;
            cout << "\tx = " << (this->_a2 * 1000000) << "y";
            cout << ((this->_b2 > 0) ? " + " : " - ");
            cout << abs(this->_b2) << endl;
            cout << "\tEcart-Type:\t\t\t\t" << (this->_e2 / 1000000) << endl;
            cout << "\tEstimation de la population en 2050:\t" << (((-(this->_b2) + 2050) / this->_a2) / 1000000) << endl;
            cout << endl;

            this->_stream << " " << (this->_a2 * 1000000) << " " << this->_b2;

            this->correlation();
            cout << setprecision(4) << fixed;
            cout << "\033[1;4mCoéfficient de corrélation:\033[0m\t\t\t" << this->_c << endl;

            for (vector<double>::iterator it = this->_values.begin(); it != this->_values.end(); it++) {
                this->_stream << " " << (*it / 1000000);
            }

            system(this->_stream.str().c_str());
        }
    }

    void end(void) {
        this->_file.close();

        this->_args.clear();
        this->_names.clear();

        this->_values.clear();
        this->_years.clear();
    }
    
    void fill(void) {
        for (int i = 0; i <= 50; i++) {
            this->_years[i] = 1961 + i;
        }

        for (list<string>::iterator it = this->_args.begin(); it != this->_args.end(); it++) {
            string line;
            char name[512];
            char code[512];
            char token[512];
            bool exist(false);

            this->open();
            while (getline(this->_file, line)) {
                istringstream cell(line);

                cell.getline(name, 512, ';');
                cell.getline(code, 512, ';');

                if (*it == code) {
                    this->_names.push_back(name);
                    exist = true;

                    int i(0);
                    while (cell.getline(token, 512, ';') and i < 51) {
                        this->_values[i] += stringToNumber(token);
                        i++;
                    }

                    break;
                }
            }

            if (exist == false) {
                ostringstream stream;

                stream << *it;
                stream << " code is not in .csv file";
                throw Exception(stream.str());
            }


            this->close();
        }
    }

    template <typename T, typename U>
    void ajust(T x, U y, double *a, double *b) {
        double xsomme(0);
        double ysomme(0);
        double xysomme(0);
        double xxsomme(0);
        int n(51);

        for (int i = 0; i < n; i++) {
            xsomme += x[i];
            ysomme += y[i];
            xxsomme += pow(x[i], 2);
            xysomme += x[i] * y[i];
        }

        if ((n * xxsomme - xsomme * xsomme) < 0) {
            throw Exception("Division by zero");
        } else if ((n * xxsomme - xsomme * xsomme) < 0) {
            throw Exception("Division by zero");
        } else {
            *a = (n * xysomme - xsomme * ysomme) / (n * xxsomme - pow(xsomme, 2));
            *b = (ysomme * xxsomme - xsomme * xysomme) / (n * xxsomme - pow(xsomme, 2));
        }
    }

    void firstCovariance(void) {
        double ecart(0);
        int n(51);

        for (int i = 0; i < n; i++) {
            ecart += pow(this->_values[i] - (this->_a1 * this->_years[i] + this->_b1), 2);
        }

        this->_e1 = sqrt(ecart / n);
    }

    void secondCovariance(void) {
        double ecart(0);
        int n(51);

        for (int i = 0; i < n; i++) {
            ecart += pow(this->_values[i] - ((-(this->_b2) + this->_years[i]) / this->_a2), 2);
        }

        this->_e2 = sqrt(ecart / n);
    }

    void correlation(void) {
        double ecart(0);
        int n(51);

        for (int i = 0; i < n; i++) {
            ecart += (this->_values[i] - (this->_a1 * this->_years[i] + this->_b1)) * (this->_values[i] - ((-(this->_b2) + this->_years[i]) / this->_a2));
        }
        ecart /= n;

        this->_c = ecart / (this->_e1 * this->_e2);
    }

    double stringToNumber(const std::string &value) {
        stringstream stream(value);
        double number(0);

        stream >> number;
        return number;
    }

    string numberToString(double value) {
        stringstream stream;
        string str;

        stream << value;
        stream >> str;
        return str;
    }

    void open(void) {
        this->_file.open("data.csv");
        if (!this->_file) {
            throw Exception("File data.csv missing");
        }
    }

    void close(void) {
        this->_file.close();
    }

};

#endif /* CORE_HPP_ */
