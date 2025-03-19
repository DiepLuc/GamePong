#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    srand(time(NULL));

    //Define some constanst
    const int screenWidth = 800;
    const int screenHeight = 500;
    const sf::Vector2f paddleSize(35, 100);
    const float ballRadius = 12.f;
    const float pi = 3.14;

    //Create the window of application
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Pong!", sf::Style::Titlebar | sf::Style::Close);
    
    //Create the leftPaddle
    sf::RectangleShape leftPaddle;
    leftPaddle.setSize(paddleSize);
    leftPaddle.setFillColor(sf::Color::Green);
    leftPaddle.setOutlineThickness(3);
    leftPaddle.setOutlineColor(sf::Color(0,0,0));
    leftPaddle.setPosition(0, screenHeight / 2);
    leftPaddle.setOrigin(paddleSize / 2.f);

    //Create the rightPaddle
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

    //Difine paddle properties
    float paddleSpeed = 200.f;

    //Difine ball propertis
    const float ballSpeed = 240.f;
    float angleBall = -90.f;

    sf::Clock clock;
    float deltaTime = 0.f;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //The leftPaddle moving
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::Vector2f pos = leftPaddle.getPosition();
            if (pos.y + paddleSize.y / 2 + paddleSpeed * deltaTime > screenHeight) leftPaddle.setPosition(pos.x, screenHeight - paddleSize.y / 2);
            else leftPaddle.move(0, paddleSpeed * deltaTime); // di xuong
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {       
            sf::Vector2f pos = leftPaddle.getPosition();
            if (pos.y - paddleSize.y / 2 - paddleSpeed * deltaTime < 0)  leftPaddle.setPosition(pos.x, 0 + paddleSize.y / 2);
            else leftPaddle.move(0, -paddleSpeed * deltaTime); //di len
        }           
        
        //The rightPaddle moving
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sf::Vector2f pos = rightPaddle.getPosition();
            if (pos.y + paddleSize.y / 2 + paddleSpeed * deltaTime > screenHeight) rightPaddle.setPosition(pos.x, screenHeight - paddleSize.y / 2);
            else rightPaddle.move(0, paddleSpeed * deltaTime); // di xuong
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sf::Vector2f pos = rightPaddle.getPosition();
            if (pos.y - paddleSize.y / 2 - paddleSpeed * deltaTime < 0) rightPaddle.setPosition(pos.x,0 + paddleSize.y / 2);
            else rightPaddle.move(0, -paddleSpeed * deltaTime); //di len
        }

        //The ball moving
        float factor = ballSpeed * deltaTime;
        ball.move(sin(angleBall * pi / 180) * factor, -cos(angleBall * pi / 180) * factor);

        //Check Collison with Top_Down Wall
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= screenHeight) angleBall = 180.f - angleBall;

        //Check Collison with the paddle
        //LeftPaddle
        if (ball.getPosition().x - ballRadius <= leftPaddle.getPosition().x + paddleSize.x / 2
            && ball.getPosition().y >= leftPaddle.getPosition().y - paddleSize.y / 2
            && ball.getPosition().y <= leftPaddle.getPosition().y + paddleSize.y / 2
            && ball.getPosition().x >= leftPaddle.getPosition().x)
        {
            angleBall = 360.f - angleBall + rand() % 10;
        }
        //RightPaddle
        if (ball.getPosition().x + ballRadius >= rightPaddle.getPosition().x - paddleSize.x / 2
            && ball.getPosition().y >= rightPaddle.getPosition().y - paddleSize.y / 2
            && ball.getPosition().y <= rightPaddle.getPosition().y + paddleSize.y / 2)
        {
            angleBall = 360.f - angleBall + rand() % 10;
        }

        window.clear(sf::Color::White);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);
        window.display();
    }
    return 0;
}