#include <SFML/Graphics.hpp>

int main()
{
    //Define some constanst
    const int screenWidth = 800;
    const int screenHeight = 500;
    const sf::Vector2f paddleSize(35, 100);
    const float ballRadius = 12.f;

    //Create the window of application
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Pong!", sf::Style::Titlebar | sf::Style::Close);
    
    //Create the left paddle
    sf::RectangleShape leftPaddle;
    leftPaddle.setSize(paddleSize);
    leftPaddle.setFillColor(sf::Color::Green);
    leftPaddle.setOutlineThickness(3);
    leftPaddle.setOutlineColor(sf::Color(0,0,0));
    leftPaddle.setPosition(0, screenHeight / 2);
    leftPaddle.setOrigin(paddleSize / 2.f);

    //Create the right paddle
    sf::RectangleShape rightPaddle;
    rightPaddle.setSize(paddleSize);
    rightPaddle.setFillColor(sf::Color::Red);
    rightPaddle.setOutlineThickness(3);
    rightPaddle.setOutlineColor(sf::Color(0,0,0));
    rightPaddle.setPosition(screenWidth, screenHeight / 2);
    rightPaddle.setOrigin(paddleSize / 2.f);

    //Create the ball
    sf::CircleShape ball;
    ball.setRadius(ballRadius);
    ball.setFillColor(sf::Color::Yellow);
    ball.setOutlineThickness(3);
    ball.setOutlineColor(sf::Color(0,0,0));
    ball.setPosition(screenWidth / 2, screenHeight / 2);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.display();
    }
    return 0;
}