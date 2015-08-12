//
// ADrawableObject.hh for  in /home/zwertv_e/rendu/cpp_bomberman
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Jun 11 16:03:25 2015 zwertv_e
// Last update Thu Jun 11 18:42:14 2015 zwertv_e
//

#ifndef		ADRAWABLEOBJECT_HH__
# define	ADRAWABLEOBJECT_HH__

# include <list>
# include <map>

# include <Clock.hh>
# include <Texture.hh>
# include <Geometry.hh>

# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>

class ADrawableObject
{
public:
  ADrawableObject(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &);
  ADrawableObject(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &);
  virtual ~ADrawableObject();

  virtual bool initialize(void) = 0;

  glm::vec3 getPosition(void) const;

  void translate(glm::vec3 const &);
  void rotate(glm::vec3 const &, float);
  void scale(glm::vec3 const &);

  glm::mat4 transformation(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &) const;
  void draw(gdl::AShader &shader, glm::vec3 const &, glm::vec3 const &, glm::vec3 const &);

protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;

  gdl::Texture _texture;
  gdl::Geometry _geometry;
};

#endif		/* ADRAWABLEOBJECT_HH__ */
