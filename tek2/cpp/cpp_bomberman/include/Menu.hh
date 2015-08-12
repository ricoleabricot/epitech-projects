#ifndef MENU_HH_
# define MENU_HH_

# include <iostream>
# include <list>

# include <Clock.hh>
# include <Input.hh>

# include "AItem.hh"
# include "MenuItem.hh"
# include "Bomb.hh"
# include "Cursor.hh"

class Menu 
{
 private:
    std::list<ADrawableObject *> _items;

 public:
    Menu();
    ~Menu();

    void addItem(ADrawableObject *);
    void deleteItem(ADrawableObject *);

    void update(const gdl::Clock &,  gdl::Input &);
    //void draw(const gdl::Clock &, const gdl::Input &);
    void createMenu();
    std::list<ADrawableObject *> const &getItems(void) const;
};

#endif /* MENU_HH_ */
