#ifndef APLAYER_HH_
# define APLAYER_HH_

# include <list>

# include "ADrawableObject.hh"
# include "AItem.hh"

class APlayer : public ADrawableObject {
 protected:
    int _id;
    int _hp;
    int _itemsPlanted;
    int _maxPlantableItems;

 public:
    APlayer(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &, gdl::Texture const &, int, int);
    virtual ~APlayer();

    virtual bool initialize(void);

    void update(const std::list<AItem *> &);

    void plantItem(void);
    void deplantItem(void);
    void damage(int hp = 1);

    void translate(const glm::vec3 &);

    int getHp(void) const;
    int getId(void) const;
    int getItemsPlanted(void) const;
    int getMaxPlantableItems(void) const;
};

#endif /* APLAYER_HH_ */
