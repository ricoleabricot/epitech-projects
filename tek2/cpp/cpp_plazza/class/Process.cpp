/* 
* @Author: gicque_p
* @Date:   2015-04-20 16:17:03
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-20 16:17:20
*/

#include "Process.hpp"

Process::Process(void) {}
Process::~Process(void) {}

int		Process::createProcess(void)
{
  return (fork());
}
