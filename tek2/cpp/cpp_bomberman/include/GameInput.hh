#ifndef GAMEINPUT_HH_
# define GAMEINPUT_HH_

# include <SdlContext.hh>
# include <Input.hh>
# include <Clock.hh>

# include "Display.hh"
# include "Map.hh"

class GameInput {
 private:
    gdl::Input _input;

 public:
    GameInput();
    ~GameInput();

    void move(Display *, APlayer *, Map &map, const gdl::Clock &);

    bool quitGame(void);
    bool itemAction(void);
    bool turnLeft(void);
    bool turnRight(void);
    bool turnUp(void);
    bool turnDown(void);

    gdl::Input &getInput(void);
};

#endif /* GAMEINPUT_HH_ */
