/* 
* @Author: gicque_p
* @Date:   2015-03-10 12:16:45
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 23:24:22
*/

#include <unistd.h>

#include "Ncurses.hpp"
#include "Error.hpp"

int Ncurses::getWidth() const {
	return (this->_width);
}

void Ncurses::setWidth(int width) {
	this->_width = width;
}

int Ncurses::getHeight() const {
	return (this->_height);
}

void Ncurses::setHeight(int height) {
	this->_height = height;
}

void Ncurses::init() {
	if (initscr() == NULL) {
		throw DisplayError("Syscall initscr returns a NULL pointer", "Ncurses");
	}

	if (keypad(stdscr, TRUE) == ERR) {
		throw DisplayError("Sycall keypad returns an error", "Ncurses");
	}

	if (nodelay(stdscr, TRUE) == ERR) {
		throw DisplayError("Syscall nodelay returns an error", "Ncurses");
	}

	if (start_color() == ERR) {
		throw DisplayError("Syscall start_color returns an error", "Ncurses");		
	}

	if (curs_set(0) == ERR) {
		throw DisplayError("Syscall curs_set returns an error", "Ncurses");		
	}

	if (init_pair(BLACK, COLOR_BLACK, COLOR_BLACK) == ERR) {
		throw DisplayError("Syscall init_pair Black returns an error", "Ncurses");
	}

	if (init_pair(RED, COLOR_RED, COLOR_RED) == ERR) {
		throw DisplayError("Syscall init_pair Red returns an error", "Ncurses");
	}

	if (init_pair(GREEN, COLOR_GREEN, COLOR_GREEN) == ERR) {
		throw DisplayError("Syscall init_pair Green returns an error", "Ncurses");
	}

	if (init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW) == ERR) {
		throw DisplayError("Syscall init_pair Yellow returns an error", "Ncurses");
	}

	if (init_pair(BLUE, COLOR_BLUE, COLOR_BLUE) == ERR) {
		throw DisplayError("Syscall init_pair Blue returns an error", "Ncurses");
	}

	if (init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA) == ERR) {
		throw DisplayError("Syscall init_pair Magenta returns an error", "Ncurses");
	}

	if (init_pair(CYAN, COLOR_CYAN, COLOR_CYAN) == ERR) {
		throw DisplayError("Syscall init_pair Cyan returns an error", "Ncurses");
	}

	if (init_pair(WHITE, COLOR_WHITE, COLOR_WHITE) == ERR) {
		throw DisplayError("Syscall init_pair White returns an error", "Ncurses");
	}
}

void Ncurses::end_init() {
	if (endwin() == ERR) {
		throw DisplayError("Sycall endwin return an error", "Ncurses");
	}
}

void Ncurses::printSquare(int x, int y, t_color color) {

	if (move(y, x * 2) == ERR) {
		throw DisplayError("Sycall move return an error", "Ncurses");
	}

	if (attron(COLOR_PAIR(color)) == ERR) {
		throw DisplayError("Syscall attron return an error", "Ncurses");
	}

	if (printw("XX") == ERR) {
		throw DisplayError("Syscall printw return an error", "Ncurses");
	}

	if (attroff(COLOR_PAIR(color)) == ERR) {
		throw DisplayError("Syscall attron return an error", "Ncurses");
	}
}

void Ncurses::clearWin()
{
	if (erase() == ERR) {
		throw DisplayError("Syscall attron return an error", "Ncurses");
	}
}

void Ncurses::refreshWin()
{
	if (refresh() == ERR) {
		throw DisplayError("Syscall attron return an error", "Ncurses");
	}
}

bool Ncurses::wait()
{
	static int i = 0;

	i++;
	if (i == 300000)
	{
		i = 0;
		return (true);
	}
	else
		return (false);
}

t_direct Ncurses::getNextDirect()
{
	int c;

	c = getch();

	if (c == KEY_LEFT)
		return (LEFT);
	else if (c == KEY_RIGHT)
		return (RIGHT);
	else if (c == 27)
		return (EXIT);
	return (NONE);
}

extern "C" {
	IDisplay *createModule(void) {
		return new Ncurses;
	}
}
