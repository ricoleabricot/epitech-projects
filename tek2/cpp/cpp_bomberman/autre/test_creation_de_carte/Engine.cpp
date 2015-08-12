//
// Engine.cpp for  in /home/bbr2394/rendu2015/cpp_bomberman/test_creation_de_carte
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed May  6 01:23:10 2015 Bertrand-Rapello Baptiste
// Last update Wed May  6 01:37:07 2015 Bertrand-Rapello Baptiste
//

#include "Engine.hh"

Engine::Engine()
{
  _x = 10;
  _y = 10;
}

Engine::~Engine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}

void Engine::createMap()
{
  AObject *tmp;
  int c = -4, d = -4;

  tmp = new Cube(glm::vec3(-5, -5, 3), glm::vec3(0, 0, 0), "./player.tga");
  if(tmp->initialize() == false)
  {
    std::cout << "probleme !!" << std::endl ;

  }
  _objects.push_back(tmp);
  tmp = new Cube(glm::vec3(5, -5, 3), glm::vec3(0, 0, 0), "./player.tga");
  tmp->initialize();
  _objects.push_back(tmp);
  tmp = new Cube(glm::vec3(-5, 5, 3), glm::vec3(0, 0, 0), "./player.tga");
  tmp->initialize();
  _objects.push_back(tmp);
  tmp = new Cube(glm::vec3(5, 5, 3), glm::vec3(0, 0, 0), "./player.tga");
  tmp->initialize();
  _objects.push_back(tmp);

  
}

bool Engine::initialize()
{
  if (!_context.start(800, 600, "My bomberman!"))
    {
      std::cout << "error on start context" << std::endl;
      return false;
    }
  glEnable(GL_DEPTH_TEST);

  // On cree un shader, petit programme permettant de dessiner nos objets a l'ecran
  if (!_shader.load("../LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER) || !\
      _shader.load("../LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER) || !_shader.build())
    {
      std::cout << "shader failed" << std::endl;
      return (false);
    }

  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 0, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  this->createMap();
  
  AObject *cube = new Cube;

  if (cube->initialize() == false)
    return (false);

  _objects.push_back(cube);
  return true;
  
}

bool Engine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return true;
}

void Engine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}
