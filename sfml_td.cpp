#include <SFML/Graphics.hpp>
#include "Application.h"

#include <iostream>

int main()
{
    try {
        Application app;
        app.run();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
	return 0;
}