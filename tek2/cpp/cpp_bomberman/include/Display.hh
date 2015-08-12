//
// Display.hh for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Tue May 26 16:34:18 2015 zwertv_e
// Last update Thu Jun 11 17:18:44 2015 zwertv_e
//

#ifndef     DISPLAY_HH__
# define    DISPLAY_HH__

# include <list>
# include <sys/types.h>
# include <string>

# include <Geometry.hh>
# include <Texture.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>

# include "ADrawableObject.hh"
# include "BasicShader.hh"
# include "SdlContext.hh"
# include "Exception.hh"
# include "AItem.hh"
# include "APlayer.hh"

enum screenmode
  {
    NORMAL = 0,
    SPLIT2H,
    SPLIT2V,
    SPLIT4
  };

class Display
{
private:
  size_t width;
  size_t height;
  gdl::SdlContext context;
  gdl::BasicShader shader;
  screenmode smode;

  glm::vec3 _translation;
  glm::vec3 _rotation;
  glm::vec3 _scale;

public:
  Display(size_t _width, size_t _height, const std::string & _title, screenmode _smode = NORMAL);
  ~Display(void);
  void clear(void);
  void flush(void) const;
  void updateContext(gdl::Clock & _clock, gdl::Input & _input);
  void draw(std::list<AItem *> const & _items, std::list<APlayer *> const &_players);
  void draw(std::list<ADrawableObject *> const & _items);
  bool setScreenMode(screenmode mode);

  glm::vec3 &getTranslation(void);
  glm::vec3 getPosition(void);
  void setTranslation(const glm::vec3 &);
};

#endif
