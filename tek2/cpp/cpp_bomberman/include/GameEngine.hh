#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

# include <iostream>
# include <vector>
# include <Game.hh>
# include <SdlContext.hh>
# include <Clock.hh>

# include "Bomb.hh"
# include "Floor.hh"
# include "Box.hh"
# include "Map.hh"
# include "Wall.hh"
# include "Exception.hh"
# include "Display.hh"
# include "Menu.hh"
# include "TextureLoader.hh"
# include "GameInput.hh"
# include "Player.hh"

class GameEngine : public gdl::Game {
 private:
    gdl::Clock _clock;
    Display *_display;
    Map _map;
    Menu _menu;
    TextureLoader _textureloader;
    GameInput _input;

 public:
    GameEngine();
    ~GameEngine();

    bool initialize(void);
    bool update(void);
    void action(APlayer *);
    void draw(void);
};

#endif /* GAMEENGINE_HH_ */
