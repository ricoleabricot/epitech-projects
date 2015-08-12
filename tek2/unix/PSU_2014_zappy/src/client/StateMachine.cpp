//
// StateMachine.cpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun 22 17:18:07 2015 rousse_3
// Last update Mon Jun 22 19:39:48 2015 rousse_3
//

# include	<algorithm>
# include	"client/StateMachine.hpp"

StateMachine::StateMachine(void) : _nodeList(), _currentNode() {}

StateMachine::~StateMachine(void) throw()
{
  std::vector<Node*>::iterator	it = _nodeList.begin();
  std::vector<Node*>::iterator	end = _nodeList.end();

  while (it != end)
    {
      delete *end;
      ++it;
    }
}

bool		StateMachine::addNode(const std::string &nameNode, bool isStart)
{
  std::vector<Node*>::iterator	it = _nodeList.begin();
  std::vector<Node*>::iterator	end = _nodeList.end();
  std::string			buffer;
  
  if (isStart && _currentNode != NULL)
    return (false);
  while (it != end)
    {
      (*it)->getName(buffer);
      if (buffer == nameNode)
	return (false);
      ++it;
    }

  Node		*newNode = new Node(nameNode);

  _nodeList.push_back(newNode);
  if (isStart)
    _currentNode = newNode;
  return (true);
}

bool		StateMachine::addLink(const std::string &nameNodeA, const std::string &nameNodeB, const std::string &trigger)
{
  std::vector<Node*>::iterator	it = _nodeList.begin();
  std::vector<Node*>::iterator	end = _nodeList.end();
  Node				*nodeA = NULL;
  Node				*nodeB = NULL;
  std::string			buffer;
  
  while (it != end)
    {
      (*it)->getName(buffer);
      if (buffer == nameNodeA)
	nodeA = *it;
      if (buffer == nameNodeB)
	nodeB = *it;
      ++it;
    }
  if (nodeA == NULL || nodeB == NULL)
    return (false);
  nodeA->addLink(trigger, nodeB);
  nodeB->addLink(trigger, nodeA);
  return (true);
}

bool		StateMachine::getNodeName(std::string &nodeName) const
{
  if (_currentNode == NULL)
    return (false);
  _currentNode->getName(nodeName);
  return (true);
}

bool		StateMachine::trigger(const std::string &trigger)
{
  if (_currentNode == NULL)
    return (false);
  _currentNode = _currentNode->trigger(trigger);
  return (true);
}

StateMachine::Node::Node(const std::string &name) : _name(name), _neighbourg(), _triggers() {}

StateMachine::Node::~Node(void) throw()
{
  std::vector<Node*>::iterator	it = _neighbourg.begin();
  std::vector<Node*>::iterator	end = _neighbourg.end();

  while (it != end)
    {
      delete *end;
      ++it;
    }
}

void		StateMachine::Node::getName(std::string &NodeName) const
{
  NodeName = _name;
}

/*
** TODO gerer les triggers deja existant
*/
bool		StateMachine::Node::addLink(const std::string &trigger, Node *node)
{
  _triggers.push_back(trigger);
  _neighbourg.push_back(node);
  return (true);
}

StateMachine::Node		*StateMachine::Node::trigger(const std::string &trigger)
{
  std::vector<std::string>::iterator	it = std::find(_triggers.begin(), _triggers.end(), trigger);

  if (it != _triggers.end())
    return (_neighbourg[_triggers.begin() - it]);
  return (this);
}
