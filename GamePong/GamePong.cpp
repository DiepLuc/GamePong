#include <SFML/Graphics.hpp>

int main()
{
    //Define some constanst
    const int screenWidth = 800;
    const int screenHeight = 500;
    
    //Create the window of application
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Pong!", sf::Style::Titlebar | sf::Style::Close);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
    return 0;
}