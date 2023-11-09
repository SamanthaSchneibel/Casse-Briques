#include "gameObject.hpp"
#include "canon.hpp"
#include <vector>

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Casse Briques");

    GameObject oCanon(320, 480, 20, 40, sf::Color::Red);
    GameObject oBall(320, 480, 10, sf::Color::White);
    GameObject oBrick(50, 50, 100, 50, sf::Color::Blue);

    //GameLoop
    sf::Clock oClock;
    bool click = false;
    float fDeltaTime = 0;
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();

     
            if (oEvent.type == sf::Event::EventType::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                if (click == false)
                {
                    float mouseX = sf::Mouse::getPosition(oWindow).x;
                    float mouseY = sf::Mouse::getPosition(oWindow).y;
                    float ballX = oBall.pShape->getPosition().x;
                    float ballY = oBall.pShape->getPosition().y;

                    oBall.setDirection(mouseX - ballX, mouseY - ballY);
                }
                click = true;
            }
        }
        
        //UPDATE
        fDeltaTime = oClock.restart().asSeconds();
        oCanon.rotation(sf::Mouse::getPosition(oWindow).x, sf::Mouse::getPosition(oWindow).y);
        
        oBall.move(fDeltaTime);

        //DRAW
        oWindow.clear();

        oWindow.draw(*oBall.pShape);
        oWindow.draw(*oCanon.pShape);
        oWindow.draw(*oBrick.pShape);
       
        oWindow.display();

    }

    return 0;
}