#ifndef OPENGL_HPP_
# define OPENGL_HPP_

# include <map>

# include "SDL/SDL.h"
# include "GL/gl.h"
# include "GL/glut.h"

# include "IDisplay.hpp"
# include "Error.hpp"

class OpenGL : public IDisplay {
	int _width;
	int _height;

	Uint32 _startTime;
	std::map<t_color, int> _checkColor;

 public:
	OpenGL() {};
	~OpenGL() {};

	int getWidth() const;
	void setWidth(int);
	int getHeight() const;
	void setHeight(int);
	void init();
	void end_init();
	void printSquare(int, int, t_color);
	void clearWin();
	void refreshWin();
	bool wait();
	t_direct getNextDirect();
};

#endif /* !OPENGL_HPP_ */