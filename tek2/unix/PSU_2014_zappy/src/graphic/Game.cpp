//
// Game.cpp for zappy in /home/ribeir_b/rendu/PSU_2014_zappy/graphique
// 
// Made by Nicolas Ribeiro Teixeira
// Login   <ribeir_b@epitech.net>
// 
// Started on  Wed Jun 24 16:17:30 2015 Nicolas Ribeiro Teixeira
// Last update Sun Jul  5 23:23:27 2015 Nayden Makusa
//

#include		<sstream>
#include		<iostream>
#include		<SFML/Window.hpp>
#include		<SFML/Graphics.hpp>
#include		<SFML/Audio.hpp>
#include		"graphic/Game.hh"

Game::Game(std::string const &addr, int port) : m_sock(addr, port), m_x(0), m_y(0), m_window(sf::VideoMode(800, 800, 32), "OMG, IT'S A LEGEND OF ZAPPY !!!")
{
  if (m_sock.getOkay())
    {
      int		i;
      int		j;
      int		k;

      m_tab[0].first = "msz";
      m_tab[1].first = "bct";
      m_tab[2].first = "pnw";
      m_tab[3].first = "ppo";
      m_tab[4].first = "plv";
      m_tab[5].first = "pex";
      m_tab[6].first = "pbc";
      m_tab[7].first = "pic";
      m_tab[8].first = "enw";
      m_tab[9].first = "pdi";
      m_tab[10].first = "ebo";
      m_tab[11].first = "edi";
      m_tab[12].first = "pfk";
      m_tab[13].first = "seg";
      m_tab[14].first = "sgt";

      m_tab[0].second = &Game::myMsz;
      m_tab[1].second = &Game::myBct;
      m_tab[2].second = &Game::myPnw;
      m_tab[3].second = &Game::myPpo;
      m_tab[4].second = &Game::myPlv;
      m_tab[5].second = &Game::myPex;
      m_tab[6].second = &Game::myPbc;
      m_tab[7].second = &Game::myPic;
      m_tab[8].second = &Game::myEnw;
      m_tab[9].second = &Game::myPdi;
      m_tab[10].second = &Game::myEbo;
      m_tab[11].second = &Game::myEbo;
      m_tab[12].second = &Game::myPfk;
      m_tab[13].second = &Game::mySeg;
      m_tab[14].second = &Game::mySgt;

      m_pos[DERAUMERE][0] = 60;
      m_pos[DERAUMERE][1] = 20;
      m_pos[LINEMATE][0] = 60;
      m_pos[LINEMATE][1] = 40;
      m_pos[MENDIANE][0] = 60;
      m_pos[MENDIANE][1] = 60;
      m_pos[PHIRAS][0] = 0;
      m_pos[PHIRAS][1] = 20;
      m_pos[SIBUR][0] = 0;
      m_pos[SIBUR][1] = 40;
      m_pos[THYSTAME][0] = 0;
      m_pos[THYSTAME][1] = 60;
      m_pos[EGG][0] = 60;
      m_pos[EGG][1] = 0;
      m_pos[FOOD][0] = 0;
      m_pos[FOOD][1] = 0;
      m_pos[GRASS][0] = 0;
      m_pos[GRASS][1] = 0;
      m_pos[TREE][0] = 0;
      m_pos[TREE][1] = 0;

      m_pos[DEAD1][0] = 20;
      m_pos[DEAD1][1] = 0;
      m_pos[INVOKE1][0] = 20;
      m_pos[INVOKE1][1] = 0;
      m_pos[PONDING1][0] = 20;
      m_pos[PONDING1][1] = 0;
      m_pos[PUSHING1][0] = 0;
      m_pos[PUSHING1][1] = 0;
      m_pos[PUSHING_NORTH1][0] = 0;
      m_pos[PUSHING_NORTH1][1] = 0;
      m_pos[PUSHING_EAST1][0] = 0;
      m_pos[PUSHING_EAST1][1] = 0;
      m_pos[PUSHING_SOUTH1][0] = 0;
      m_pos[PUSHING_SOUTH1][1] = 0;
      m_pos[PUSHING_WEST1][0] = 0;
      m_pos[PUSHING_WEST1][1] = 0;
      m_pos[PUTTING1][0] = 20;
      m_pos[PUTTING1][1] = 0;
      m_pos[SPEAKING1][0] = 20;
      m_pos[SPEAKING1][1] = 0;
      m_pos[SPEAKING_NORTH1][0] = 20;
      m_pos[SPEAKING_NORTH1][1] = 0;
      m_pos[SPEAKING_EAST1][0] = 20;
      m_pos[SPEAKING_EAST1][1] = 0;
      m_pos[SPEAKING_SOUTH1][0] = 20;
      m_pos[SPEAKING_SOUTH1][1] = 0;
      m_pos[SPEAKING_WEST1][0] = 20;
      m_pos[SPEAKING_WEST1][1] = 0;
      m_pos[STANDING1][0] = 20;
      m_pos[STANDING1][1] = 0;
      m_pos[STANDING_NORTH1][0] = 20;
      m_pos[STANDING_NORTH1][1] = 0;
      m_pos[STANDING_EAST1][0] = 20;
      m_pos[STANDING_EAST1][1] = 0;
      m_pos[STANDING_SOUTH1][0] = 20;
      m_pos[STANDING_SOUTH1][1] = 0;
      m_pos[STANDING_WEST1][0] = 20;
      m_pos[STANDING_WEST1][1] = 0;
      m_pos[TAKING1][0] = 20;
      m_pos[TAKING1][1] = 0;

      m_pos[DEAD2][0] = 20;
      m_pos[DEAD2][1] = 0;
      m_pos[INVOKE2][0] = 20;
      m_pos[INVOKE2][1] = 0;
      m_pos[PONDING2][0] = 20;
      m_pos[PONDING2][1] = 0;
      m_pos[PUSHING2][0] = 0;
      m_pos[PUSHING2][1] = 0;
      m_pos[PUSHING_NORTH2][0] = 0;
      m_pos[PUSHING_NORTH2][1] = 0;
      m_pos[PUSHING_EAST2][0] = 0;
      m_pos[PUSHING_EAST2][1] = 0;
      m_pos[PUSHING_SOUTH2][0] = 0;
      m_pos[PUSHING_SOUTH2][1] = 0;
      m_pos[PUSHING_WEST2][0] = 0;
      m_pos[PUSHING_WEST2][1] = 0;
      m_pos[PUTTING2][0] = 20;
      m_pos[PUTTING2][1] = 0;
      m_pos[SPEAKING2][0] = 20;
      m_pos[SPEAKING2][1] = 0;
      m_pos[SPEAKING_NORTH2][0] = 20;
      m_pos[SPEAKING_NORTH2][1] = 0;
      m_pos[SPEAKING_EAST2][0] = 20;
      m_pos[SPEAKING_EAST2][1] = 0;
      m_pos[SPEAKING_SOUTH2][0] = 20;
      m_pos[SPEAKING_SOUTH2][1] = 0;
      m_pos[SPEAKING_WEST2][0] = 20;
      m_pos[SPEAKING_WEST2][1] = 0;
      m_pos[STANDING2][0] = 20;
      m_pos[STANDING2][1] = 0;
      m_pos[STANDING_NORTH2][0] = 20;
      m_pos[STANDING_NORTH2][1] = 0;
      m_pos[STANDING_EAST2][0] = 20;
      m_pos[STANDING_EAST2][1] = 0;
      m_pos[STANDING_SOUTH2][0] = 20;
      m_pos[STANDING_SOUTH2][1] = 0;
      m_pos[STANDING_WEST2][0] = 20;
      m_pos[STANDING_WEST2][1] = 0;
      m_pos[TAKING2][0] = 20;
      m_pos[TAKING2][1] = 0;

      m_pos[DEAD3][0] = 20;
      m_pos[DEAD3][1] = 0;
      m_pos[INVOKE3][0] = 20;
      m_pos[INVOKE3][1] = 0;
      m_pos[PONDING3][0] = 20;
      m_pos[PONDING3][1] = 0;
      m_pos[PUSHING3][0] = 0;
      m_pos[PUSHING3][1] = 0;
      m_pos[PUSHING_NORTH3][0] = 0;
      m_pos[PUSHING_NORTH3][1] = 0;
      m_pos[PUSHING_EAST3][0] = 0;
      m_pos[PUSHING_EAST3][1] = 0;
      m_pos[PUSHING_SOUTH3][0] = 0;
      m_pos[PUSHING_SOUTH3][1] = 0;
      m_pos[PUSHING_WEST3][0] = 0;
      m_pos[PUSHING_WEST3][1] = 0;
      m_pos[PUTTING3][0] = 20;
      m_pos[PUTTING3][1] = 0;
      m_pos[SPEAKING3][0] = 20;
      m_pos[SPEAKING3][1] = 0;
      m_pos[SPEAKING_NORTH3][0] = 20;
      m_pos[SPEAKING_NORTH3][1] = 0;
      m_pos[SPEAKING_EAST3][0] = 20;
      m_pos[SPEAKING_EAST3][1] = 0;
      m_pos[SPEAKING_SOUTH3][0] = 20;
      m_pos[SPEAKING_SOUTH3][1] = 0;
      m_pos[SPEAKING_WEST3][0] = 20;
      m_pos[SPEAKING_WEST3][1] = 0;
      m_pos[STANDING3][0] = 20;
      m_pos[STANDING3][1] = 0;
      m_pos[STANDING_NORTH3][0] = 20;
      m_pos[STANDING_NORTH3][1] = 0;
      m_pos[STANDING_EAST3][0] = 20;
      m_pos[STANDING_EAST3][1] = 0;
      m_pos[STANDING_SOUTH3][0] = 20;
      m_pos[STANDING_SOUTH3][1] = 0;
      m_pos[STANDING_WEST3][0] = 20;
      m_pos[STANDING_WEST3][1] = 0;
      m_pos[TAKING3][0] = 20;
      m_pos[TAKING3][1] = 0;

      m_pos[DEAD4][0] = 20;
      m_pos[DEAD4][1] = 0;
      m_pos[INVOKE4][0] = 20;
      m_pos[INVOKE4][1] = 0;
      m_pos[PONDING4][0] = 20;
      m_pos[PONDING4][1] = 0;
      m_pos[PUSHING4][0] = 0;
      m_pos[PUSHING4][1] = 0;
      m_pos[PUSHING_NORTH4][0] = 0;
      m_pos[PUSHING_NORTH4][1] = 0;
      m_pos[PUSHING_EAST4][0] = 0;
      m_pos[PUSHING_EAST4][1] = 0;
      m_pos[PUSHING_SOUTH4][0] = 0;
      m_pos[PUSHING_SOUTH4][1] = 0;
      m_pos[PUSHING_WEST4][0] = 0;
      m_pos[PUSHING_WEST4][1] = 0;
      m_pos[PUTTING4][0] = 20;
      m_pos[PUTTING4][1] = 0;
      m_pos[SPEAKING4][0] = 20;
      m_pos[SPEAKING4][1] = 0;
      m_pos[SPEAKING_NORTH4][0] = 20;
      m_pos[SPEAKING_NORTH4][1] = 0;
      m_pos[SPEAKING_EAST4][0] = 20;
      m_pos[SPEAKING_EAST4][1] = 0;
      m_pos[SPEAKING_SOUTH4][0] = 20;
      m_pos[SPEAKING_SOUTH4][1] = 0;
      m_pos[SPEAKING_WEST4][0] = 20;
      m_pos[SPEAKING_WEST4][1] = 0;
      m_pos[STANDING4][0] = 20;
      m_pos[STANDING4][1] = 0;
      m_pos[STANDING_NORTH4][0] = 20;
      m_pos[STANDING_NORTH4][1] = 0;
      m_pos[STANDING_EAST4][0] = 20;
      m_pos[STANDING_EAST4][1] = 0;
      m_pos[STANDING_SOUTH4][0] = 20;
      m_pos[STANDING_SOUTH4][1] = 0;
      m_pos[STANDING_WEST4][0] = 20;
      m_pos[STANDING_WEST4][1] = 0;
      m_pos[TAKING4][0] = 20;
      m_pos[TAKING4][1] = 0;

      m_pos[DEAD5][0] = 20;
      m_pos[DEAD5][1] = 0;
      m_pos[INVOKE5][0] = 20;
      m_pos[INVOKE5][1] = 0;
      m_pos[PONDING5][0] = 20;
      m_pos[PONDING5][1] = 0;
      m_pos[PUSHING5][0] = 0;
      m_pos[PUSHING5][1] = 0;
      m_pos[PUSHING_NORTH5][0] = 0;
      m_pos[PUSHING_NORTH5][1] = 0;
      m_pos[PUSHING_EAST5][0] = 0;
      m_pos[PUSHING_EAST5][1] = 0;
      m_pos[PUSHING_SOUTH5][0] = 0;
      m_pos[PUSHING_SOUTH5][1] = 0;
      m_pos[PUSHING_WEST5][0] = 0;
      m_pos[PUSHING_WEST5][1] = 0;
      m_pos[PUTTING5][0] = 20;
      m_pos[PUTTING5][1] = 0;
      m_pos[SPEAKING5][0] = 20;
      m_pos[SPEAKING5][1] = 0;
      m_pos[SPEAKING_NORTH5][0] = 20;
      m_pos[SPEAKING_NORTH5][1] = 0;
      m_pos[SPEAKING_EAST5][0] = 20;
      m_pos[SPEAKING_EAST5][1] = 0;
      m_pos[SPEAKING_SOUTH5][0] = 20;
      m_pos[SPEAKING_SOUTH5][1] = 0;
      m_pos[SPEAKING_WEST5][0] = 20;
      m_pos[SPEAKING_WEST5][1] = 0;
      m_pos[STANDING5][0] = 20;
      m_pos[STANDING5][1] = 0;
      m_pos[STANDING_NORTH5][0] = 20;
      m_pos[STANDING_NORTH5][1] = 0;
      m_pos[STANDING_EAST5][0] = 20;
      m_pos[STANDING_EAST5][1] = 0;
      m_pos[STANDING_SOUTH5][0] = 20;
      m_pos[STANDING_SOUTH5][1] = 0;
      m_pos[STANDING_WEST5][0] = 20;
      m_pos[STANDING_WEST5][1] = 0;
      m_pos[TAKING5][0] = 20;
      m_pos[TAKING5][1] = 0;

      m_pos[DEAD6][0] = 20;
      m_pos[DEAD6][1] = 0;
      m_pos[INVOKE6][0] = 20;
      m_pos[INVOKE6][1] = 0;
      m_pos[PONDING6][0] = 20;
      m_pos[PONDING6][1] = 0;
      m_pos[PUSHING6][0] = 0;
      m_pos[PUSHING6][1] = 0;
      m_pos[PUSHING_NORTH6][0] = 0;
      m_pos[PUSHING_NORTH6][1] = 0;
      m_pos[PUSHING_EAST6][0] = 0;
      m_pos[PUSHING_EAST6][1] = 0;
      m_pos[PUSHING_SOUTH6][0] = 0;
      m_pos[PUSHING_SOUTH6][1] = 0;
      m_pos[PUSHING_WEST6][0] = 0;
      m_pos[PUSHING_WEST6][1] = 0;
      m_pos[PUTTING6][0] = 20;
      m_pos[PUTTING6][1] = 0;
      m_pos[SPEAKING6][0] = 20;
      m_pos[SPEAKING6][1] = 0;
      m_pos[SPEAKING_NORTH6][0] = 20;
      m_pos[SPEAKING_NORTH6][1] = 0;
      m_pos[SPEAKING_EAST6][0] = 20;
      m_pos[SPEAKING_EAST6][1] = 0;
      m_pos[SPEAKING_SOUTH6][0] = 20;
      m_pos[SPEAKING_SOUTH6][1] = 0;
      m_pos[SPEAKING_WEST6][0] = 20;
      m_pos[SPEAKING_WEST6][1] = 0;
      m_pos[STANDING6][0] = 20;
      m_pos[STANDING6][1] = 0;
      m_pos[STANDING_NORTH6][0] = 20;
      m_pos[STANDING_NORTH6][1] = 0;
      m_pos[STANDING_EAST6][0] = 20;
      m_pos[STANDING_EAST6][1] = 0;
      m_pos[STANDING_SOUTH6][0] = 20;
      m_pos[STANDING_SOUTH6][1] = 0;
      m_pos[STANDING_WEST6][0] = 20;
      m_pos[STANDING_WEST6][1] = 0;
      m_pos[TAKING6][0] = 20;
      m_pos[TAKING6][1] = 0;

      m_pos[DEAD7][0] = 20;
      m_pos[DEAD7][1] = 0;
      m_pos[INVOKE7][0] = 20;
      m_pos[INVOKE7][1] = 0;
      m_pos[PONDING7][0] = 20;
      m_pos[PONDING7][1] = 0;
      m_pos[PUSHING7][0] = 0;
      m_pos[PUSHING7][1] = 0;
      m_pos[PUSHING_NORTH7][0] = 0;
      m_pos[PUSHING_NORTH7][1] = 0;
      m_pos[PUSHING_EAST7][0] = 0;
      m_pos[PUSHING_EAST7][1] = 0;
      m_pos[PUSHING_SOUTH7][0] = 0;
      m_pos[PUSHING_SOUTH7][1] = 0;
      m_pos[PUSHING_WEST7][0] = 0;
      m_pos[PUSHING_WEST7][1] = 0;
      m_pos[PUTTING7][0] = 20;
      m_pos[PUTTING7][1] = 0;
      m_pos[SPEAKING7][0] = 20;
      m_pos[SPEAKING7][1] = 0;
      m_pos[SPEAKING_NORTH7][0] = 20;
      m_pos[SPEAKING_NORTH7][1] = 0;
      m_pos[SPEAKING_EAST7][0] = 20;
      m_pos[SPEAKING_EAST7][1] = 0;
      m_pos[SPEAKING_SOUTH7][0] = 20;
      m_pos[SPEAKING_SOUTH7][1] = 0;
      m_pos[SPEAKING_WEST7][0] = 20;
      m_pos[SPEAKING_WEST7][1] = 0;
      m_pos[STANDING7][0] = 20;
      m_pos[STANDING7][1] = 0;
      m_pos[STANDING_NORTH7][0] = 20;
      m_pos[STANDING_NORTH7][1] = 0;
      m_pos[STANDING_EAST7][0] = 20;
      m_pos[STANDING_EAST7][1] = 0;
      m_pos[STANDING_SOUTH7][0] = 20;
      m_pos[STANDING_SOUTH7][1] = 0;
      m_pos[STANDING_WEST7][0] = 20;
      m_pos[STANDING_WEST7][1] = 0;
      m_pos[TAKING7][0] = 20;
      m_pos[TAKING7][1] = 0;

      setSprite(DERAUMERE, "sprites/gems/Deraumère.png");
      setSprite(LINEMATE, "sprites/gems/Linemate.png");
      setSprite(MENDIANE, "sprites/gems/Mendiane.png");
      setSprite(PHIRAS, "sprites/gems/Phiras.png");
      setSprite(SIBUR, "sprites/gems/Sibur.png");
      setSprite(THYSTAME, "sprites/gems/Thystame.png");

      setSprite(EGG, "sprites/objects/egg.png");
      setSprite(FOOD, "sprites/objects/food.png");
      setSprite(GRASS, "sprites/objects/grass.png");
      setSprite(TREE, "sprites/objects/tree.png");

      setSprite(DEAD1, "sprites/player/level_1/player_dead.png");
      setSprite(INVOKE1, "sprites/player/level_1/player_invocating.png");
      setSprite(PONDING1, "sprites/player/level_1/player_ponding.png");
      setSprite(PUSHING1, "sprites/player/level_1/player_pushing_n.png");
      setSprite(PUSHING_NORTH1, "sprites/player/level_1/player_pushing_n.png");
      setSprite(PUSHING_EAST1, "sprites/player/level_1/player_pushing_e.png");
      setSprite(PUSHING_SOUTH1, "sprites/player/level_1/player_pushing_s.png");
      setSprite(PUSHING_WEST1, "sprites/player/level_1/player_pushing_w.png");
      setSprite(PUTTING1, "sprites/player/level_1/player_putting.png");
      setSprite(SPEAKING1, "sprites/player/level_1/player_speaking_n.png");
      setSprite(SPEAKING_NORTH1, "sprites/player/level_1/player_speaking_n.png");
      setSprite(SPEAKING_EAST1, "sprites/player/level_1/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH1, "sprites/player/level_1/player_speaking_s.png");
      setSprite(SPEAKING_WEST1, "sprites/player/level_1/player_speaking_w.png");
      setSprite(STANDING1, "sprites/player/level_1/player_standing_n.png");
      setSprite(STANDING_NORTH1, "sprites/player/level_1/player_standing_n.png");
      setSprite(STANDING_EAST1, "sprites/player/level_1/player_standing_e.png");
      setSprite(STANDING_SOUTH1, "sprites/player/level_1/player_standing_s.png");
      setSprite(STANDING_WEST1, "sprites/player/level_1/player_standing_w.png");
      setSprite(TAKING1, "sprites/player/level_1/player_taking.png");

      setSprite(DEAD2, "sprites/player/level_2/player_dead.png");
      setSprite(INVOKE2, "sprites/player/level_2/player_invocating.png");
      setSprite(PONDING2, "sprites/player/level_2/player_ponding.png");
      setSprite(PUSHING2, "sprites/player/level_2/player_pushing_n.png");
      setSprite(PUSHING_NORTH2, "sprites/player/level_2/player_pushing_n.png");
      setSprite(PUSHING_EAST2, "sprites/player/level_2/player_pushing_e.png");
      setSprite(PUSHING_SOUTH2, "sprites/player/level_2/player_pushing_s.png");
      setSprite(PUSHING_WEST2, "sprites/player/level_2/player_pushing_w.png");
      setSprite(PUTTING2, "sprites/player/level_2/player_putting.png");
      setSprite(SPEAKING2, "sprites/player/level_2/player_speaking_n.png");
      setSprite(SPEAKING_NORTH2, "sprites/player/level_2/player_speaking_n.png");
      setSprite(SPEAKING_EAST2, "sprites/player/level_2/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH2, "sprites/player/level_2/player_speaking_s.png");
      setSprite(SPEAKING_WEST2, "sprites/player/level_2/player_speaking_w.png");
      setSprite(STANDING2, "sprites/player/level_2/player_standing_n.png");
      setSprite(STANDING_NORTH2, "sprites/player/level_2/player_standing_n.png");
      setSprite(STANDING_EAST2, "sprites/player/level_2/player_standing_e.png");
      setSprite(STANDING_SOUTH2, "sprites/player/level_2/player_standing_s.png");
      setSprite(STANDING_WEST2, "sprites/player/level_2/player_standing_w.png");
      setSprite(TAKING2, "sprites/player/level_2/player_taking.png");

      setSprite(DEAD3, "sprites/player/level_3/player_dead.png");
      setSprite(INVOKE3, "sprites/player/level_3/player_invocating.png");
      setSprite(PONDING3, "sprites/player/level_3/player_ponding.png");
      setSprite(PUSHING3, "sprites/player/level_3/player_pushing_n.png");
      setSprite(PUSHING_NORTH3, "sprites/player/level_3/player_pushing_n.png");
      setSprite(PUSHING_EAST3, "sprites/player/level_3/player_pushing_e.png");
      setSprite(PUSHING_SOUTH3, "sprites/player/level_3/player_pushing_s.png");
      setSprite(PUSHING_WEST3, "sprites/player/level_3/player_pushing_w.png");
      setSprite(PUTTING3, "sprites/player/level_3/player_putting.png");
      setSprite(SPEAKING3, "sprites/player/level_3/player_speaking_n.png");
      setSprite(SPEAKING_NORTH3, "sprites/player/level_3/player_speaking_n.png");
      setSprite(SPEAKING_EAST3, "sprites/player/level_3/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH3, "sprites/player/level_3/player_speaking_s.png");
      setSprite(SPEAKING_WEST3, "sprites/player/level_3/player_speaking_w.png");
      setSprite(STANDING3, "sprites/player/level_3/player_standing_n.png");
      setSprite(STANDING_NORTH3, "sprites/player/level_3/player_standing_n.png");
      setSprite(STANDING_EAST3, "sprites/player/level_3/player_standing_e.png");
      setSprite(STANDING_SOUTH3, "sprites/player/level_3/player_standing_s.png");
      setSprite(STANDING_WEST3, "sprites/player/level_3/player_standing_w.png");
      setSprite(TAKING3, "sprites/player/level_3/player_taking.png");

      setSprite(DEAD4, "sprites/player/level_4/player_dead.png");
      setSprite(INVOKE4, "sprites/player/level_4/player_invocating.png");
      setSprite(PONDING4, "sprites/player/level_4/player_ponding.png");
      setSprite(PUSHING4, "sprites/player/level_4/player_pushing_n.png");
      setSprite(PUSHING_NORTH4, "sprites/player/level_4/player_pushing_n.png");
      setSprite(PUSHING_EAST4, "sprites/player/level_4/player_pushing_e.png");
      setSprite(PUSHING_SOUTH4, "sprites/player/level_4/player_pushing_s.png");
      setSprite(PUSHING_WEST4, "sprites/player/level_4/player_pushing_w.png");
      setSprite(PUTTING4, "sprites/player/level_4/player_putting.png");
      setSprite(SPEAKING4, "sprites/player/level_4/player_speaking_n.png");
      setSprite(SPEAKING_NORTH4, "sprites/player/level_4/player_speaking_n.png");
      setSprite(SPEAKING_EAST4, "sprites/player/level_4/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH4, "sprites/player/level_4/player_speaking_s.png");
      setSprite(SPEAKING_WEST4, "sprites/player/level_4/player_speaking_w.png");
      setSprite(STANDING4, "sprites/player/level_4/player_standing_n.png");
      setSprite(STANDING_NORTH4, "sprites/player/level_4/player_standing_n.png");
      setSprite(STANDING_EAST4, "sprites/player/level_4/player_standing_e.png");
      setSprite(STANDING_SOUTH4, "sprites/player/level_4/player_standing_s.png");
      setSprite(STANDING_WEST4, "sprites/player/level_4/player_standing_w.png");
      setSprite(TAKING4, "sprites/player/level_4/player_taking.png");

      setSprite(DEAD5, "sprites/player/level_5/player_dead.png");
      setSprite(INVOKE5, "sprites/player/level_5/player_invocating.png");
      setSprite(PONDING5, "sprites/player/level_5/player_ponding.png");
      setSprite(PUSHING5, "sprites/player/level_5/player_pushing_n.png");
      setSprite(PUSHING_NORTH5, "sprites/player/level_5/player_pushing_n.png");
      setSprite(PUSHING_EAST5, "sprites/player/level_5/player_pushing_e.png");
      setSprite(PUSHING_SOUTH5, "sprites/player/level_5/player_pushing_s.png");
      setSprite(PUSHING_WEST5, "sprites/player/level_5/player_pushing_w.png");
      setSprite(PUTTING5, "sprites/player/level_5/player_putting.png");
      setSprite(SPEAKING5, "sprites/player/level_5/player_speaking_n.png");
      setSprite(SPEAKING_NORTH5, "sprites/player/level_5/player_speaking_n.png");
      setSprite(SPEAKING_EAST5, "sprites/player/level_5/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH5, "sprites/player/level_5/player_speaking_s.png");
      setSprite(SPEAKING_WEST5, "sprites/player/level_5/player_speaking_w.png");
      setSprite(STANDING5, "sprites/player/level_5/player_standing_n.png");
      setSprite(STANDING_NORTH5, "sprites/player/level_5/player_standing_n.png");
      setSprite(STANDING_EAST5, "sprites/player/level_5/player_standing_e.png");
      setSprite(STANDING_SOUTH5, "sprites/player/level_5/player_standing_s.png");
      setSprite(STANDING_WEST5, "sprites/player/level_5/player_standing_w.png");
      setSprite(TAKING5, "sprites/player/level_5/player_taking.png");

      setSprite(DEAD6, "sprites/player/level_6/player_dead.png");
      setSprite(INVOKE6, "sprites/player/level_6/player_invocating.png");
      setSprite(PONDING6, "sprites/player/level_6/player_ponding.png");
      setSprite(PUSHING6, "sprites/player/level_6/player_pushing_n.png");
      setSprite(PUSHING_NORTH6, "sprites/player/level_6/player_pushing_n.png");
      setSprite(PUSHING_EAST6, "sprites/player/level_6/player_pushing_e.png");
      setSprite(PUSHING_SOUTH6, "sprites/player/level_6/player_pushing_s.png");
      setSprite(PUSHING_WEST6, "sprites/player/level_6/player_pushing_w.png");
      setSprite(PUTTING6, "sprites/player/level_6/player_putting.png");
      setSprite(SPEAKING6, "sprites/player/level_6/player_speaking_n.png");
      setSprite(SPEAKING_NORTH6, "sprites/player/level_6/player_speaking_n.png");
      setSprite(SPEAKING_EAST6, "sprites/player/level_6/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH6, "sprites/player/level_6/player_speaking_s.png");
      setSprite(SPEAKING_WEST6, "sprites/player/level_6/player_speaking_w.png");
      setSprite(STANDING6, "sprites/player/level_6/player_standing_n.png");
      setSprite(STANDING_NORTH6, "sprites/player/level_6/player_standing_n.png");
      setSprite(STANDING_EAST6, "sprites/player/level_6/player_standing_e.png");
      setSprite(STANDING_SOUTH6, "sprites/player/level_6/player_standing_s.png");
      setSprite(STANDING_WEST6, "sprites/player/level_6/player_standing_w.png");
      setSprite(TAKING6, "sprites/player/level_6/player_taking.png");

      setSprite(DEAD7, "sprites/player/level_7/player_dead.png");
      setSprite(INVOKE7, "sprites/player/level_7/player_invocating.png");
      setSprite(PONDING7, "sprites/player/level_7/player_ponding.png");
      setSprite(PUSHING7, "sprites/player/level_7/player_pushing_n.png");
      setSprite(PUSHING_NORTH7, "sprites/player/level_7/player_pushing_n.png");
      setSprite(PUSHING_EAST7, "sprites/player/level_7/player_pushing_e.png");
      setSprite(PUSHING_SOUTH7, "sprites/player/level_7/player_pushing_s.png");
      setSprite(PUSHING_WEST7, "sprites/player/level_7/player_pushing_w.png");
      setSprite(PUTTING7, "sprites/player/level_7/player_putting.png");
      setSprite(SPEAKING7, "sprites/player/level_7/player_speaking_n.png");
      setSprite(SPEAKING_NORTH7, "sprites/player/level_7/player_speaking_n.png");
      setSprite(SPEAKING_EAST7, "sprites/player/level_7/player_speaking_e.png");
      setSprite(SPEAKING_SOUTH7, "sprites/player/level_7/player_speaking_s.png");
      setSprite(SPEAKING_WEST7, "sprites/player/level_7/player_speaking_w.png");
      setSprite(STANDING7, "sprites/player/level_7/player_standing_n.png");
      setSprite(STANDING_NORTH7, "sprites/player/level_7/player_standing_n.png");
      setSprite(STANDING_EAST7, "sprites/player/level_7/player_standing_e.png");
      setSprite(STANDING_SOUTH7, "sprites/player/level_7/player_standing_s.png");
      setSprite(STANDING_WEST7, "sprites/player/level_7/player_standing_w.png");
      setSprite(TAKING7, "sprites/player/level_7/player_taking.png");

      m_xcam = 0;
      m_ycam = 0;
      i = 0;
      while (i < 10)
	{
	  j = 0;
	  while (j < 10)
	    {
	      k = 0;
	      while (k < 7)
		{
		  m_map[i][j][k] = 0;
		  ++k;
		}
	      ++j;
	    }
	  ++i;
	}
    }
  else
    m_xcam = -2;
}

Game::~Game()
{
}

bool			Game::initWorked(void)
{
  if (m_xcam != -2)
    return (true);
  return (false);
}

void			Game::setSprite(eTexType nb, std::string const &name)
{
  if (!(m_tex[nb].loadFromFile(name)))
    {
      std::cerr << "Erreur durant le chargement de l'image" << std::endl;
      exit(-1);
    }
  m_sprite[nb].setTexture(m_tex[nb]);
}

sf::Sprite const	&Game::getSprite(eTexType nb) const
{
  return (m_sprite[nb]);
}

void			Game::run()
{
  struct timeval	new_time;
  struct timeval	old_time;
  int			elapsed_time;
  sf::Music		gameMusic;

  if (!gameMusic.openFromFile("musics/game.ogg"))
    {
      std::cerr << "Problem with the importation of a music (gameMusic)" << std::endl;
      exit(1);
    }
  gameMusic.play();
  gameMusic.setLoop(true);
  gettimeofday(&new_time, NULL);
  while (m_window.isOpen())
    {
      sf::Event		event;

      if (m_window.pollEvent(event))
	{
	  if (event.type == sf::Event::KeyPressed)
	    {
	      switch (event.key.code)
		{
		case sf::Keyboard::Left:
		  if ((m_xcam - 1) >= -1)
		    --m_xcam;
		  break;
		case sf::Keyboard::Right:
		  if ((m_xcam + 1) <= m_x - 9)
		    ++m_xcam;
		  break;
		case sf::Keyboard::Up:
		  if ((m_ycam - 1) >= -1)
		    --m_ycam;
		  break;
		case sf::Keyboard::Down:
		  if ((m_ycam + 1) <= m_y - 9)
		    ++m_ycam;
		  break;
		case sf::Keyboard::Escape:
		  m_window.close();
		  gameMusic.stop();
		  break;
		default:
		  break;
		}
	    }
	  else if (event.type == sf::Event::Closed)
	    {
	      m_window.close();
	      gameMusic.stop();
	    }
	}
      old_time = new_time;
      gettimeofday(&new_time, NULL);
      elapsed_time = (new_time.tv_sec * 1000000ull + new_time.tv_usec) - (old_time.tv_sec * 1000000ull + old_time.tv_usec);
      updateGame();
      m_window.clear();
      fillBackground();
      fillObjects();
      fillPlayer(elapsed_time);
      m_window.display();
    }
}

void			Game::myMsz(std::istringstream &linestream)
{
  int			parsed;

  linestream >> parsed;
  m_x = parsed;
  linestream >> parsed;
  m_y = parsed;
}

void			Game::myBct(std::istringstream &linestream)
{
  int			x;
  int			y;
  int			i;
  int			val;

  linestream >> x;
  linestream >> y;
  if (x >= m_xcam && x < (m_xcam + 10))
    if (y >= m_ycam && y < (m_ycam + 10))
      {
	i = 0;
	while (i < 7)
	  {
	    linestream >> val;
	    m_map[x - m_xcam][y - m_ycam][i] = val;
	    ++i;
	  }
      }
}

void			Game::myPnw(std::istringstream &linestream)
{
  int					id;
  std::string				teamname;
  Player				*new_player;
  int					x;
  int					y;
  int					orientation;
  int					level;

  linestream >> id;
  linestream >> x;
  linestream >> y;
  linestream >> orientation;
  linestream >> level;
  linestream >> teamname;
  new_player = new Player(id, x, y, level, orientation, teamname, static_cast<int>(STANDING1));
  m_player.push_back(new_player);
}

void			Game::myPpo(std::istringstream &linestream)
{
  std::list<Player *>::iterator					Iplayer;
  int								id;
  int								x;
  int								y;
  int								o;
  bool								done;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  linestream >> x;
	  linestream >> y;
	  linestream >> o;
	  (*Iplayer)->setX(x);
	  (*Iplayer)->setY(y);
	  (*Iplayer)->setOrientation(o);
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myPlv(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  int								level;
  bool								done;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  linestream >> level;
	  (*Iplayer)->setLvl(level);
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myPex(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  bool								done;
  struct timeval						start;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  gettimeofday(&start, NULL);
	  (*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(PUSHING1) + (((*Iplayer)->getLvl() - 1) * 20)));
	  (*Iplayer)->setTimer((7.0f / m_sgt) * 100000);
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myPbc(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  bool								done;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  (*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(SPEAKING1) + (((*Iplayer)->getLvl() - 1) * 20)));
	  (*Iplayer)->setTimer((7.0f / m_sgt) * 100000);
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myPic(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  bool								done;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  (*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(INVOKE1) + (((*Iplayer)->getLvl() - 1) * 20)));
	  (*Iplayer)->setTimer((300.0f / m_sgt) * 100000);
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myEnw(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  int								id_egg;
  bool								done;

  done = false;
  linestream >> id_egg;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  std::pair<int [2], int>				Egg;

	  (Egg.first)[0] = (*Iplayer)->getX();
	  (Egg.first)[1] = (*Iplayer)->getY();
	  (Egg.second) = id_egg;
	  m_egg.push_back(Egg);
	  (*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(STANDING1) + (((*Iplayer)->getLvl() - 1) * 20)));
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myPdi(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  bool								done;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  (*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(DEAD1) + (((*Iplayer)->getLvl() - 1) * 20)));
	  (*Iplayer)->resetId();
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::myEbo(std::istringstream &linestream)
{
  std::list<std::pair<int [2], int> >::iterator			Iegg;
  int								id;
  bool								done;

  done = false;
  linestream >> id;
  Iegg = m_egg.begin();
  while (Iegg != m_egg.end() && !done)
    {
      if ((*Iegg).second == id)
	{
	  m_egg.remove((*Iegg));
	  done = true;
	}
      ++Iegg;
    }
}

void			Game::myPfk(std::istringstream &linestream)
{
  std::list<Player *>::iterator		Iplayer;
  int								id;
  bool								done;

  done = false;
  linestream >> id;
  Iplayer = m_player.begin();
  while (Iplayer != m_player.end() && !done)
    {
      if ((*Iplayer)->getId() == id)
	{
	  (*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(PONDING1) + (((*Iplayer)->getLvl() - 1) * 20)));
	  done = true;
	}
      ++Iplayer;
    }
}

void			Game::mySeg(std::istringstream &linestream)
{
  std::string		team;

  linestream >> team;
  std::cout << "Team :'" << team << "' has won the game" << std::endl;
  m_window.close();
  exit(0);
}

void			Game::mySgt(std::istringstream &linestream)
{
  double		time;

  linestream >> time;
  m_sgt = time;
}

void			Game::checkCommand(std::string const &str, std::istringstream &linestream)
{
  int			i;
  bool			done;

  i = 0;
  done = false;
  while (i < 15 && !done)
    {
      if (str == m_tab[i].first)
	{
	  (this->*(m_tab[i].second))(linestream);
	  done = true;
	}
      ++i;
    }
}

void			Game::updateGame()
{
  std::string			line;
  std::string			parsed;
  std::string			square("");
  std::ostringstream		oss;
  int				i;
  int				j;
  int				x;
  int				y;
  size_t			remove;

  while (m_sock.toRead() == true)
    {
      line = m_sock.receiveMessage();
      while ((remove = line.find_first_of('#')) != std::string::npos)
	line.erase(remove, 1);
      std::istringstream	linestream(line);
      std::getline(linestream, parsed, ' ');
      checkCommand(parsed, linestream);
    }
  i = 0;
  while (i != 10)
    {
      j = 0;
      while (j != 10)
	{
	  x = i + m_xcam;
	  y = j + m_ycam;
	  if (x >= 0 && x < m_x && y >= 0 && y < m_y)
	    {
	      square += "bct ";
	      oss << x;
	      square += oss.str();
	      oss.str("");
	      square += " ";
	      oss << y;
	      square += oss.str();
	      oss.str("");
	      m_sock.sendMessage(square);
	      while (!(m_sock.toRead()));
	      line = m_sock.receiveMessage();
	      while ((remove = line.find_first_of('#')) != std::string::npos)
		line.erase(remove, 1);
	      std::istringstream	linestream(line);
	      std::getline(linestream, parsed, ' ');
	      checkCommand(parsed, linestream);
	      square.clear();
	    }
	  ++j;
	}
      ++i;
    }
}

void			Game::fillEgg()
{
  int								x;
  int								y;
  std::list<std::pair<int [2], int> >::iterator			Iegg;

  Iegg = m_egg.begin();
  while (Iegg != m_egg.end())
    {
      x = ((*Iegg).first)[0];
      y = ((*Iegg).first)[1];
      if (((x >= m_xcam) && (x < (m_xcam + 10))) && ((y >= m_ycam) && (y < (m_ycam + 10))))
	drawSprite(x - m_xcam, y - m_ycam, EGG);
      ++Iegg;
    }
}

void			Game::fillPlayer(int elapsed_time)
{
  int								x;
  int								y;
  std::list<Player *>::iterator					Iplayer;
  int								state;
  eTexType							e_state;

  Iplayer = m_player.begin();
  while (Iplayer != m_player.end())
    {
      x = (*Iplayer)->getX();
      y = (*Iplayer)->getY();
      (*Iplayer)->decrementTimer(elapsed_time);
      if ((*Iplayer)->getTimer() <= 0 && (*Iplayer)->getId() != -1)
	(*Iplayer)->setState(static_cast<eTexType>(static_cast<int>(STANDING1) + (((*Iplayer)->getLvl() - 1) * 20)));
      if (((x >= m_xcam) && (x < (m_xcam + 10))) && ((y >= m_ycam) && (y < (m_ycam + 10))))
	{
	  state = ((*Iplayer)->getState());
	  state -= ((((*Iplayer)->getLvl()) - 1) * 20);
	  e_state = static_cast<eTexType>(state);
	  if (e_state == STANDING1 || e_state == PUSHING1 || e_state == SPEAKING1)
	    state += (*Iplayer)->getOrientation();
	  state += ((((*Iplayer)->getLvl()) - 1) * 20);
	  e_state = static_cast<eTexType>(state);
	  if ((x - m_xcam) > -1 && (y - m_ycam) > -1)
	    drawSprite(x - m_xcam, y - m_ycam, e_state);
	}
      ++Iplayer;
    }
}

void			Game::fillObjects()
{
  int								i;
  int								j;
  int								k;

  i = 0;
  while (i < 10)
    {
      j = 0;
      while (j < 10)
	{
	  k = 0;
	  while (k < 7)
	    {
	      if (m_xcam + i <= m_x - 1 && m_xcam + i >= 0)
		if (m_ycam + j <= m_y - 1 && m_ycam + j >= 0)
		  if (m_map[i][j][k] > 0)
		    drawSprite(i, j, static_cast<eTexType>(k));
	      ++k;
	    }
	  ++j;
	}
      ++i;
    }
}

void			Game::putTree(int i_start, int j_start, bool inverted)
{
  int			i;
  int			j;

  i = i_start;
  j = j_start;
  while (j != 10)
    {
      if (!inverted)
	drawSprite(i, j, TREE);
      else
	drawSprite(j, i, TREE);
      ++j;
    }
}

void			Game::fillBackground()
{
  int			i = 0;
  int			j;
  sf::RectangleShape	RectX(sf::Vector2f(2, 800));
  sf::RectangleShape	RectY(sf::Vector2f(800, 2));

  RectX.setFillColor(sf::Color(0, 0, 0));
  RectY.setFillColor(sf::Color(0, 0, 0));
  while (i != 10)
    {
      j = 0;
      while (j != 10)
	{
	  m_window.draw(m_sprite[GRASS]);
	  m_sprite[GRASS].setPosition(80 * i, 80 * j);
	  ++j;
	}
      ++i;
    }
  m_window.draw(m_sprite[GRASS]);
  m_sprite[GRASS].setPosition(80 * i, 80 * j);
  i = 0;
  while (i != 10)
    {
      j = 0;
      while (j != 10)
	{
	  RectX.setPosition(i * 80 - 2, j * 80 - 2);
	  RectY.setPosition(i * 80 - 2, j * 80 - 2);
	  m_window.draw(RectX);
	  m_window.draw(RectY);
	  ++j;
	}
      ++i;
    }
  if (m_xcam == -1)
    putTree(0, 0, false);
  else if (m_xcam == m_x - 9)
    putTree(9, 0, false);
  if (m_ycam == -1)
    putTree(0, 0, true);
  else if (m_ycam == m_y - 9)
    putTree(9, 0, true);
}

void			Game::drawSprite(int x, int y, eTexType type)
{
  if (type == TREE)
    m_sprite[type].setPosition(m_pos[type][0] + (x * 80), ((m_pos[type][1] + (y * 80)) - 40));
  else
    m_sprite[type].setPosition(m_pos[type][0] + (x * 80), m_pos[type][1] + (y * 80));
  m_window.draw(m_sprite[type]);
}
