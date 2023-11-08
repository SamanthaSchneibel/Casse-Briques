#include "gameObject.hpp"
#include "canon.hpp"

int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Casse Briques");

    GameObject oCanon(320, 480, 20, 40, sf::Color::Red);
    GameObject oBall(320, 480, 10, sf::Color::White);


    //GameLoop
    sf::Clock oClock;
    float fDeltaTime = 0;
    bool move = false;
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        if (oEvent.mouseButton.button == sf::Mouse::Left)
        {
            move = true;
        }
        
        //UPDATE
        fDeltaTime = oClock.restart().asSeconds();
        oCanon.rotation(sf::Mouse::getPosition(oWindow).x, sf::Mouse::getPosition(oWindow).y);
        

        float ballX = oBall.pShape->getPosition().x;
        float ballY = oBall.pShape->getPosition().y;
        float mouseX = sf::Mouse::getPosition(oWindow).x;
        float mouseY = sf::Mouse::getPosition(oWindow).y;

        float directionX = mouseX - ballX;
        float directionY = mouseY - ballY;
        
        if (move == true)
        {
            oBall.move(fDeltaTime, directionX, directionY);
            move = false;
        }

        //DRAW
        oWindow.clear();

        oWindow.draw(*oBall.pShape);
        oWindow.draw(*oCanon.pShape);
       
        oWindow.display();

    }

    return 0;
}