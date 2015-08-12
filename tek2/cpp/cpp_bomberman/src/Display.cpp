//
// Display.cpp for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Tue May 26 16:36:42 2015 zwertv_e
// Last update Sun Jun 14 16:18:38 2015 zwertv_e
//

#include	"Display.hh"

Display::Display(size_t _width, size_t _height, const std::string & _title, screenmode _smode) : width(_width), height(_height), smode(_smode)
{
  glm::mat4	projection;
  glm::mat4	transformation;

  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(-5, 8, 0), glm::vec3(5, -5, 0), glm::vec3(0, 1, 0));
  if (!this->context.start(_width, _height, _title))
    throw DisplayException("Can't start context");
  glEnable(GL_DEPTH_TEST);
  if (!this->shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER))
    throw DisplayException("Can't load fragment shader");
  if (!this->shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER))
    throw DisplayException("Can't load vertex shader");
  this->shader.build();
  this->shader.bind();
  this->shader.setUniform("view", transformation);
  this->shader.setUniform("projection", projection);
  this->context.flush();

  _translation = glm::vec3(0, 0, 0);
  _rotation = glm::vec3(0, 0, 0);
  _scale = glm::vec3(1, 1, 1);
}

bool	Display::setScreenMode(screenmode mode)
{
  switch (mode)
    {
    case NORMAL:
      this->smode = NORMAL;
      break;
    case SPLIT2H:
      this->smode = SPLIT2H;
      break;
    case SPLIT2V:
      this->smode = SPLIT2V;
      break;
    case SPLIT4:
      this->smode = SPLIT4;
      break;
    }
  return (false);
}

Display::~Display(void) {}

void	Display::updateContext(gdl::Clock & _clock, gdl::Input & _input)
{
  this->context.updateClock(_clock);
  this->context.updateInputs(_input);
}

void	Display::clear(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->shader.bind();
}

void	Display::flush(void) const
{
  this->context.flush();
}

void	Display::draw(std::list<AItem *> const & _items, std::list<APlayer *> const &players)
{
  std::list<AItem *>::const_iterator    it;
  std::list<APlayer *>::const_iterator    it2;

  glEnable(GL_SCISSOR_TEST);
  glScissor(0, 0, width, height);

  for (it = _items.begin(); it != _items.end(); ++it)
    (*it)->draw(this->shader, _translation, _rotation, _scale);

  for (it2 = players.begin(); it2 != players.end(); it2++)
    (*it2)->draw(this->shader, -_translation, -_rotation, -_scale);

  glDisable(GL_SCISSOR_TEST);
}

void	Display::draw(std::list<ADrawableObject *> const & _items)
{
  std::list<ADrawableObject *>::const_iterator	it;

  for (it = _items.begin(); it != _items.end(); ++it)
    (*it)->draw(this->shader, _translation, _rotation, _scale);
}

glm::vec3 &Display::getTranslation(void) {
    return _translation;
}

glm::vec3 Display::getPosition(void) {
    return glm::vec3(-_translation.x, 0.6, -_translation.z);
}

void Display::setTranslation(const glm::vec3 &translation) {
    _translation += translation;
}
