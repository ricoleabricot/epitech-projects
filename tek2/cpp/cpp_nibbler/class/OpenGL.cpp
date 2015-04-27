/* 
* @Author: gicque_p
* @Date:   2015-03-10 12:17:00
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-05 12:39:41
*/

#include "OpenGL.hpp"

int OpenGL::getWidth() const {
	return this->_width;
}

void OpenGL::setWidth(int width) {
	this->_width = width;
}

int OpenGL::getHeight() const {
	return this->_height;
}

void OpenGL::setHeight(int height) {
	this->_height = height;
}

void OpenGL::init() {
	double newWidth(500 + (500 / this->_width) * 2);
	double newHeight(500 + (500 / this->_height) * 2);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw DisplayError("SDL Init failed", "OpenGL");
	}

	SDL_WM_SetCaption("Nibbler OpenGL", NULL);

	if (!SDL_SetVideoMode(newWidth, newHeight, 32, SDL_OPENGL)) {
		throw DisplayError("Impossible to set Video Mode", "OpenGL");
	}

	if (SDL_EnableKeyRepeat(10, 10) == -1) {
		throw DisplayError("Impossible to set Enable KeyRepeat", "OpenGL");
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)newWidth / newHeight, 1, 1000);

	glEnable(GL_DEPTH_TEST);
	glClearDepth(1);
	gluLookAt(this->_width / 2, -this->_height / 2, (this->_height / 2) + 10, this->_width / 2, this->_height / 2, 0, 0, 0, 1);

	this->_startTime = 0;
	this->_checkColor[BLACK] = 0x000000;
	this->_checkColor[RED] = 0xFF0000;
	this->_checkColor[GREEN] = 0x00FF00;
	this->_checkColor[YELLOW] = 0xFFFF00;
	this->_checkColor[BLUE] = 0x0000FF;
	this->_checkColor[MAGENTA] = 0xFF00FF;
	this->_checkColor[CYAN] = 0x00FFFF;
	this->_checkColor[WHITE] = 0xFFFFFF;
}

void OpenGL::end_init() {
	SDL_Quit();
}

t_direct OpenGL::getNextDirect() {
	SDL_Event event;

	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			return EXIT;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					return RIGHT;
				case SDLK_RIGHT:
					return LEFT;
				case SDLK_ESCAPE:
					return EXIT;
				default:
					return NONE;
			}
		default:
			return NONE;
	}
}

void OpenGL::printSquare(int x, int y, t_color color) {
	int newColor;

	this->_startTime = SDL_GetTicks();
	if (this->_checkColor[color]) {
		newColor = this->_checkColor[color];
	} else {
		newColor = this->_checkColor[WHITE];
	}

	glColor3ub((newColor >> 16) & 0xFF, (newColor >> 8) & 0xFF, newColor & 0xFF);
	if (color != 3) {
		glBegin(GL_QUADS);
			glVertex3d(x + 1, y + 1, 1);
			glVertex3d(x + 1, y, 1);
			glVertex3d(x, y, 1);
			glVertex3d(x, y + 1, 1);

			glVertex3d(x + 1, y + 1, 0);
			glVertex3d(x + 1, y, 0);
			glVertex3d(x + 1, y, 1);
			glVertex3d(x + 1, y + 1, 1);

			glVertex3d(x, y + 1, 1);
			glVertex3d(x, y, 1);
			glVertex3d(x, y, 0);
			glVertex3d(x, y + 1, 0);

			glVertex3d(x + 1, y, 1);
			glVertex3d(x + 1, y, 0);
			glVertex3d(x, y, 0);
			glVertex3d(x, y, 1);
		glEnd();
	} else {
		glBegin(GL_QUADS);
			// glColor3ub(100,40,40);
			glVertex3d(x, y+1, 0);
			glVertex3d(x, y, 0);
			glVertex3d(x+1, y, 0);
			glVertex3d(x+1, y+1, 0);
		glEnd();
	}
}

void OpenGL::clearWin() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL::refreshWin() {
	glFlush();
	SDL_GL_SwapBuffers();
}

bool OpenGL::wait() {
	Uint32 ellapsedTime = SDL_GetTicks() - this->_startTime;

	if (ellapsedTime < 10) {
		SDL_Delay(45 - ellapsedTime);
		return false;
	}

	return true;
}

extern "C" {
	IDisplay *createModule(void) {
		return new OpenGL;
	}
} 
