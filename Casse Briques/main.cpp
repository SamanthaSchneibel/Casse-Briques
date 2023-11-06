#include <SFML/Graphics.hpp>
#include "gameObject.hpp"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "Casse Briques");

    GameObject oRectangle(0, 0, 100, 300);
    GameObject oCircle(350, 350, 50);

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

        //DRAW
        oWindow.clear();

        oWindow.draw(*oRectangle.pShape);
        oWindow.draw(*oCircle.pShape);
       
        oWindow.display();
    }

    return 0;
}