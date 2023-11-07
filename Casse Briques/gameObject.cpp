#include "gameObject.hpp"

GameObject::GameObject(int x, int y, int h, int w, sf::Color oColor)
{
	pShape = new sf::RectangleShape(sf::Vector2f(h, w));
	pShape->setPosition(x, y);
	pShape->setFillColor(oColor);
}

GameObject::GameObject(int x, int y, int radius, sf::Color oColor)
{
	pShape = new sf::CircleShape(radius);
	pShape->setPosition(x, y);
	pShape->setFillColor(oColor); 
}

GameObject::~GameObject()
{
}

void GameObject::rotation(float x1, float y1) {

	pShape->setOrigin(10, 40);
	float x2 = pShape->getPosition().x;
	float y2 = pShape->getPosition().y;
	float opp = abs(y2 - y1);
	float adj = abs(x2 - x1);

	float fAddedAngle = 0.f;
	if (x1 < x2)
		fAddedAngle = -90.f;

	float angle = atan2(opp, adj) * 180 / 3.14;
	pShape->setRotation(90-angle + fAddedAngle);
	std::cout << angle << std::endl;

}

void GameObject::move() {



}

void GameObject::collision() {



}