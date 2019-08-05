#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "../include/Application.h"

int main()
{
    ///Code
    ///std::cout << "Hello Window\n";

    Application app;
    app.RunLoop();

	system("pause");

    return 0;
}
