/* 
* @Author: gicque_p
* @Date:   2015-02-11 19:17:13
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-11 22:00:26
*/

void testsCore(void);
void testsPlugin(void);
void testsEarthWorm(void);
void testsNcurses(void);
void testsMisc(void);

int main() {
	testsCore();	
	testsPlugin();
	testsEarthWorm();
	testsMisc();

	return 0;
}