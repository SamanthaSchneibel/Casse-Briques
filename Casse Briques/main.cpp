#include "gameObject.hpp"
#include "canon.hpp"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Casse Briques");

    GameObject oRectangle(0, 0, 70, 30, sf::Color::Blue);
    GameObject oRectangle2(72, 0, 70, 30, sf::Color::Green);
    GameObject oRectangle3(144, 0, 70, 30, sf::Color::Red);
    GameObject oRectangle4(216, 0, 70, 30, sf::Color::Yellow);
    GameObject oCircle(355, 350, 10, sf::Color::White);

    GameObject oCanon(320, 480, 20, 40, sf::Color::Red);


    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE
        oCanon.rotation(sf::Mouse::getPosition(oWindow).x, sf::Mouse::getPosition(oWindow).y);

        //DRAW
        oWindow.clear();

        oWindow.draw(*oRectangle.pShape);
        oWindow.draw(*oRectangle2.pShape);
        oWindow.draw(*oRectangle3.pShape);
        oWindow.draw(*oRectangle4.pShape);
        oWindow.draw(*oCircle.pShape);

        oWindow.draw(*oCanon.pShape);
       
        oWindow.display();
    }

    return 0;
}