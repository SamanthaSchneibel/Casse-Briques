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
	pShape->setOrigin(radius, radius);
}

GameObject::~GameObject()
{
}

void GameObject::rotation(float mouseX, float mouseY) {

	pShape->setOrigin(10, 40);
	float canonX = pShape->getPosition().x;
	float canonY = pShape->getPosition().y;
	float opp = mouseX - canonX;
	float adj = mouseY - canonY;

	float angle = -atan(opp / adj) * 180 / 3.14;
	pShape->setRotation(angle);

}

void GameObject::move(float fDeltaTime, float directionX, float directionY) {

	float norme = sqrt((directionX * directionX) + (directionY * directionY));
	float nDirectionX = directionX / norme;
	float nDirectionY = directionY / norme;

	float ballX = pShape->getPosition().x;
	float ballY = pShape->getPosition().y;

	float speed = 500.f;

	ballX += nDirectionX * speed * fDeltaTime;
	ballY += nDirectionY * speed * fDeltaTime;

	pShape->setPosition(ballX, ballY);
}

void GameObject::collision() {



}