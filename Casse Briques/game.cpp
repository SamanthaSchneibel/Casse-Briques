#include "game.hpp"

Game::Game()
{    
    //Création d'une fenêtre
    oWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "Casse Briques");

    listBrick.push_back(new Brick(50, 50));
    listBrick.push_back(new Brick(152, 50));
    listBrick.push_back(new Brick(254, 50));
    listBrick.push_back(new Brick(356, 50));
    listBrick.push_back(new Brick(458, 50));
    listBrick.push_back(new Brick(50, 102));
    listBrick.push_back(new Brick(152, 102));
    listBrick.push_back(new Brick(254, 102));
    listBrick.push_back(new Brick(356, 102));
    listBrick.push_back(new Brick(458, 102));

}

Game::~Game()
{
}

void Game::event() {

    sf::Event oEvent;
    while (oWindow->pollEvent(oEvent))
    {
        if (oEvent.type == sf::Event::Closed)
            oWindow->close();

        if (oEvent.type == sf::Event::EventType::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
        {
            listBall.push_back(new Ball(sf::Mouse::getPosition(*oWindow).x, sf::Mouse::getPosition(*oWindow).y));
        }
    }

}

void Game::update() {

    fDeltaTime = oClock.restart().asSeconds();

    oCanon.rotation(sf::Mouse::getPosition(*oWindow).x, sf::Mouse::getPosition(*oWindow).y);

    for (auto ball = listBall.begin(); ball != listBall.end();)
    {
        (*ball)->move(fDeltaTime);
        //oBall.setPosition(sf::Mouse::getPosition(oWindow).x, sf::Mouse::getPosition(oWindow).y);
        for (auto brick = listBrick.begin(); brick != listBrick.end();)
        {
            if ((*ball)->onCollision(*brick))
            {
                (*ball)->checkBounce(*brick);
                (*ball)->bounce(*brick);
                if ((*brick)->inCollision() == true)
                {
                    delete* brick;
                    brick = listBrick.erase(brick);
                    std::cout << "erased brick" << std::endl;
                }
                else
                {
                    brick++;
                }
            }
            else
            {
                brick++;
            }
        }
        (*ball)->bounceWindow();
        if ((*ball)->eraseBall())
        {
            delete* ball;
            ball = listBall.erase(ball);
        }
        else
        {
            ball++;
        }
    }

}

void Game::draw() {

    //DRAW
    oWindow->clear();

    for (auto ball = listBall.begin(); ball != listBall.end(); ball++)
    {
        oWindow->draw(*(*ball)->pShape);
    }

    for (auto brick = listBrick.begin(); brick != listBrick.end(); brick++)
    {
        oWindow->draw(*(*brick)->pShape);
    }

    oWindow->draw(*oCanon.pShape);

    oWindow->display();

}