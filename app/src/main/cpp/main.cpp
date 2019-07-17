/************************************************/
/* main.cpp, (c) Rene Puchinger                 */
/************************************************/

#include "PPM.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	PPM *ppm = new PPM();
	std::string in = argv[2];
	std::string s = ppm->run(argv[1], in);
	std::cout << s;
	delete ppm;
	return 0;
}
