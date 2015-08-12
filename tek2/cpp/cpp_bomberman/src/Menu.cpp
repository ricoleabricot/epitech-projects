

#include "Menu.hh"

Menu::Menu() :
  _items()
{
}

Menu::~Menu() 
{
    for (std::list<ADrawableObject *>::iterator it = _items.begin(); it != _items.end(); it++) 
    {
        delete *it;
    }
}

void Menu::addItem(ADrawableObject *item) 
{
    if (item->initialize()) 
    {
        _items.push_back(item);
    }
    else 
    {
        //throw MenuException("Cannot initialize item");
    }
}

void Menu::deleteItem(ADrawableObject *item) {
    for (std::list<ADrawableObject *>::iterator it = _items.begin(); it != _items.end(); it++) {
        if (*it == item) {
            _items.erase(it);
            break;
        }
    }
}

void Menu::update(const gdl::Clock &clock, gdl::Input &input) 
{
  (void)input;
  (void) clock;
  //glm::vec3 test = glm::vec3(1, 0, 0);
/*
    for (std::list<ADrawableObject *>::iterator it = _items.begin(); it != _items.end(); it++) 
    {
      
      if ((*it)->getType() == AItem::Bomb)
        (*it)->translate(test);
        
      else if ((*it)->getType() == AItem::Bomb)
        (*it)->translate(glm::vec3(-1, 0, 0));
      (*it)->play(clock);

    }*/
}

std::list<ADrawableObject *> const &Menu::getItems(void) const 
{
    return _items;
}

void Menu::createMenu()
{
  ADrawableObject *temp;
/*
  temp = new Bomb(glm::vec3(0, 0, 0), glm::vec3(100, 0, 0), glm::vec3(1, 1, 1));
  addItem(temp);
  //temp->initialize();
  //exception a jeter si il y a un probleme
  //_background = temp;
  //idem
  //_cursor = temp;
  
  temp = new Bomb(glm::vec3(1, 0, 0), glm::vec3(90, 0, 0), glm::vec3(1, 1, 1));
  addItem(temp);
  temp = new Bomb(glm::vec3(0, 2, 0), glm::vec3(90, 0, 0), glm::vec3(1, 1, 1));
  addItem(temp);
  temp = new Bomb(glm::vec3(0, 0, 3), glm::vec3(90, 0, 0), glm::vec3(1, 1, 1));
  addItem(temp);
*/
  //temp = new MenuItem(glm::vec3(0, -3, 0), glm::vec3(90, 0, 0), glm::vec3(1, 1, 1));
  //addItem(temp);
  temp = new Cursor(glm::vec3(0, 5, 0), glm::vec3(90, 0, 0), glm::vec3(1, 1, 1));
  addItem(temp);
  std::cout << "taille de la liste" << _items.size() << std::endl;
}
