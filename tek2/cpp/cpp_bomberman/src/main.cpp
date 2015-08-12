//
// main.cpp for  in /home/zwertv_e/rendu/cpp_bomberman/src
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Wed May 20 02:54:44 2015 zwertv_e
// Last update Wed May 27 15:25:43 2015 zwertv_e
//

#include	"GameEngine.hh"
#include	"Display.hh"

int main(void) {
    try {
        GameEngine ge;

        ge.initialize();
        while (ge.update()) {
            ge.draw();
        }
    } catch (const Exception &exception) {
        std::cerr << exception.where() << ": " << exception.what() << std::endl;
    }

    return 0;
}
