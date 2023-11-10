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

	float sizeX = radius;
	float sizeY = radius;
	
	hitBox = new sf::RectangleShape(sf::Vector2f(radius * 2, radius * 2));
	hitBox->setPosition(x, y);
	hitBox->setFillColor(sf::Color::Green);
	hitBox->setOrigin(radius, radius);
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

void GameObject::setDirection(float directionX, float directionY) {

	float norme = sqrt((directionX * directionX) + (directionY * directionY));
	this->directionX = directionX / norme;
	this->directionY = directionY / norme;

}

void GameObject::move(float fDeltaTime) {

	speed = 500.f;

	float ballX = pShape->getPosition().x;
	float ballY = pShape->getPosition().y;

	ballX = ballX + directionX * speed * fDeltaTime;
	ballY = ballY + directionY * speed * fDeltaTime;

	pShape->setPosition(ballX, ballY); 
	hitBox->setPosition(ballX, ballY); 

}

void GameObject::getX() {

	sf::Vector2f vect;
	vect.x = pShape->getPosition().x - sizeX / 2;
	vect.y = pShape->getPosition().x + sizeX / 2;
	return vect;

}

void GameObject::getY() {


}

bool GameObject::isInside(float v, float vMin, float vMax) {

	v > vMin;
	v < vMax;

}

void GameObject::collision() {



}

void GameObject::bounce() {



}