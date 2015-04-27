## 
## @Author: gicque_p
## @Date:   2015-02-07 00:21:10
## @Last Modified by:   gicque_p
## @Last Modified time: 2015-02-07 00:43:30
##

CURS_SRC	+=		class/Ncurses.cpp
CURS_SRC	+=		class/Coord.cpp
CURS_SRC	+=		class/Error.cpp

SFML_SRC	+=		class/Sfml.cpp
SFML_SRC	+=		class/Coord.cpp
SFML_SRC	+=		class/Error.cpp

OGL_SRC		+=		class/OpenGL.cpp
OGL_SRC		+=		class/Coord.cpp
OGL_SRC		+=		class/Error.cpp

CLASS_SRC	+=		class/Core.cpp
CLASS_SRC	+=		class/Coord.cpp
CLASS_SRC	+=		class/EarthWorm.cpp
CLASS_SRC	+=		class/Misc.cpp
CLASS_SRC	+=		class/Error.cpp

TEST_SRC	+=		source/unit.cpp
TEST_SRC	+=		test/Core.test.cpp
TEST_SRC	+=		test/Plugin.test.cpp
TEST_SRC	+=		test/EarthWorm.test.cpp
TEST_SRC	+=		test/Misc.test.cpp
TEST_SRC	+=		$(CLASS_SRC)

SRC			+=		source/main.cpp
SRC			+=		$(CLASS_SRC)
