//
// Game.hh for Game in /home/ribeir_b/rendu/PSU_2014_zappy/graphique
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Wed Jun 24 16:17:36 2015 Nicolas Ribeiro Teixeira
// Last update Sun Jul  5 21:52:31 2015 Pierrick Gicquelais
//

#ifndef					GAME_HH_
# define				GAME_HH_

# include				<SFML/Graphics.hpp>
# include				<sstream>
# include				<list>
# include				"Socket.hh"
# include				"Player.hh"

# define				NB_TEX		150

enum					eTexType
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    DEAD1,
    STANDING1,
    STANDING_NORTH1,
    STANDING_EAST1,
    STANDING_SOUTH1,
    STANDING_WEST1,
    INVOKE1,
    PONDING1,
    PUSHING1,
    PUSHING_NORTH1,
    PUSHING_EAST1,
    PUSHING_SOUTH1,
    PUSHING_WEST1,
    PUTTING1,
    SPEAKING1,
    SPEAKING_NORTH1,
    SPEAKING_EAST1,
    SPEAKING_SOUTH1,
    SPEAKING_WEST1,
    TAKING1,
    DEAD2,
    STANDING2,
    STANDING_NORTH2,
    STANDING_EAST2,
    STANDING_SOUTH2,
    STANDING_WEST2,
    INVOKE2,
    PONDING2,
    PUSHING2,
    PUSHING_NORTH2,
    PUSHING_EAST2,
    PUSHING_SOUTH2,
    PUSHING_WEST2,
    PUTTING2,
    SPEAKING2,
    SPEAKING_NORTH2,
    SPEAKING_EAST2,
    SPEAKING_SOUTH2,
    SPEAKING_WEST2,
    TAKING2,
    DEAD3,
    STANDING3,
    STANDING_NORTH3,
    STANDING_EAST3,
    STANDING_SOUTH3,
    STANDING_WEST3,
    INVOKE3,
    PONDING3,
    PUSHING3,
    PUSHING_NORTH3,
    PUSHING_EAST3,
    PUSHING_SOUTH3,
    PUSHING_WEST3,
    PUTTING3,
    SPEAKING3,
    SPEAKING_NORTH3,
    SPEAKING_EAST3,
    SPEAKING_SOUTH3,
    SPEAKING_WEST3,
    TAKING3,
    DEAD4,
    STANDING4,
    STANDING_NORTH4,
    STANDING_EAST4,
    STANDING_SOUTH4,
    STANDING_WEST4,
    INVOKE4,
    PONDING4,
    PUSHING4,
    PUSHING_NORTH4,
    PUSHING_EAST4,
    PUSHING_SOUTH4,
    PUSHING_WEST4,
    PUTTING4,
    SPEAKING4,
    SPEAKING_NORTH4,
    SPEAKING_EAST4,
    SPEAKING_SOUTH4,
    SPEAKING_WEST4,
    TAKING4,
    DEAD5,
    STANDING5,
    STANDING_NORTH5,
    STANDING_EAST5,
    STANDING_SOUTH5,
    STANDING_WEST5,
    INVOKE5,
    PONDING5,
    PUSHING5,
    PUSHING_NORTH5,
    PUSHING_EAST5,
    PUSHING_SOUTH5,
    PUSHING_WEST5,
    PUTTING5,
    SPEAKING5,
    SPEAKING_NORTH5,
    SPEAKING_EAST5,
    SPEAKING_SOUTH5,
    SPEAKING_WEST5,
    TAKING5,
    DEAD6,
    STANDING6,
    STANDING_NORTH6,
    STANDING_EAST6,
    STANDING_SOUTH6,
    STANDING_WEST6,
    INVOKE6,
    PONDING6,
    PUSHING6,
    PUSHING_NORTH6,
    PUSHING_EAST6,
    PUSHING_SOUTH6,
    PUSHING_WEST6,
    PUTTING6,
    SPEAKING6,
    SPEAKING_NORTH6,
    SPEAKING_EAST6,
    SPEAKING_SOUTH6,
    SPEAKING_WEST6,
    TAKING6,
    DEAD7,
    STANDING7,
    STANDING_NORTH7,
    STANDING_EAST7,
    STANDING_SOUTH7,
    STANDING_WEST7,
    INVOKE7,
    PONDING7,
    PUSHING7,
    PUSHING_NORTH7,
    PUSHING_EAST7,
    PUSHING_SOUTH7,
    PUSHING_WEST7,
    PUTTING7,
    SPEAKING7,
    SPEAKING_NORTH7,
    SPEAKING_EAST7,
    SPEAKING_SOUTH7,
    SPEAKING_WEST7,
    TAKING7,
    GRASS,
    TREE,
    EGG,
  };

class Game
{
private:
  Socket								m_sock;
  int									m_x;
  int									m_y;
  int									m_xcam;
  int									m_ycam;
  double								m_sgt;
  int									m_pos[NB_TEX][2];
  sf::Texture								m_tex[NB_TEX];
  sf::Sprite								m_sprite[NB_TEX];
  sf::RenderWindow							m_window;
  std::pair<std::string, void (Game::*)(std::istringstream &linestream)>	m_tab[15];
  int									m_map[10][10][7];
  std::list<std::pair<int [2], int> >					m_egg;
  std::list<Player *>							m_player;
public:
  Game(std::string const &addr, int port);
  ~Game();
  bool									initWorked(void);
  void									setSprite(eTexType nb, std::string const &name);
  sf::Sprite const							&getSprite(eTexType nb) const;
  void									run();
  void									myMsz(std::istringstream &linestream);
  void									myBct(std::istringstream &linestream);
  void									myPnw(std::istringstream &linestream);
  void									myPpo(std::istringstream &linestream);
  void									myPlv(std::istringstream &linestream);
  void									myPex(std::istringstream &linestream);
  void									myPbc(std::istringstream &linestream);
  void									myPic(std::istringstream &linestream);
  void									myEnw(std::istringstream &linestream);
  void									myPdi(std::istringstream &linestream);
  void									myEbo(std::istringstream &linestream);
  void									myPfk(std::istringstream &linestream);
  void									mySeg(std::istringstream &linestream);
  void									mySgt(std::istringstream &linestream);
  void									checkCommand(std::string const &str, std::istringstream &linestream);
  void									updateGame();
  void									fillEgg();
  void									fillPlayer(int elapsed_time);
  void									fillObjects();
  void									putTree(int i_start, int j_start, bool inverted);
  void									fillBackground();
  void									drawSprite(int x, int y, eTexType type);
};

#endif			/* !GAME_HH_ */
