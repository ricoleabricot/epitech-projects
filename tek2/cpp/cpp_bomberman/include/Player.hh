#ifndef PLAYER_HH_
# define PLAYER_HH_

# include "APlayer.hh"

class Player : public APlayer {
 public:
    Player(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int, int);
    ~Player();
};

#endif /* PLAYER_HH_ */
