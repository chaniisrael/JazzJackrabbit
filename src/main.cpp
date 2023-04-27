#include <SFML/Graphics.hpp>
#include <iostream>
#include"Controller.h"
#include <exception>

int main()
{
	try {
		srand(time(0));
		Controller c;
		c.run();

	}
	catch (const std::exception & e) {
		std::cerr << "Exception: " << e.what() << '\n'; return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << "Unknown exception\n"; return EXIT_FAILURE;
	}
	return 0;
}


