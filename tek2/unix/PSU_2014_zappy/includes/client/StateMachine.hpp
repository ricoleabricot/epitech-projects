//
// StateMachine.hpp for Zappy in /home/rousse_3/rendu/PSU_2014_zappy
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun 22 16:47:45 2015 rousse_3
// Last update Mon Jun 22 19:39:20 2015 rousse_3
//

#ifndef		STATEMACHINE_HPP_
# define	STATEMACHINE_HPP_

#include	<string>
#include	<vector>

class		StateMachine
{
public:
  StateMachine(void);
  ~StateMachine(void) throw();

  bool		addNode(const std::string &nodeName, bool isStart);
  bool		addLink(const std::string &nodeNameA, const std::string &nodeNameB, const std::string &trigger);

  bool		getNodeName(std::string &nodeName) const;
  bool		trigger(const std::string &trigger);
private:
  
  class				Node
  {
  public:
    Node(const std::string &name);
    Node(const Node &copy);
    ~Node(void) throw();

    void			getName(std::string &nodeName) const;

    bool			addLink(const std::string &trigger, Node *node);

    Node			*trigger(const std::string &trigger);
  private:
    std::string			_name;
    std::vector<Node*>		_neighbourg;
    std::vector<std::string>	_triggers;
  };
  
  std::vector<Node*>	_nodeList;
  Node			*_currentNode;
};

#endif		/* !STATE_MACHINE */
