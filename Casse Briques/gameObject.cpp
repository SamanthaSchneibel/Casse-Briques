#include "gameObject.hpp"

GameObject::GameObject(int x, int y, int w, int h, sf::Color oColor)
{
	pShape = new sf::RectangleShape(sf::Vector2f(w, h));
	pShape->setPosition(x, y);
	pShape->setFillColor(oColor);

	width = w;
	height = h;

	hitBox = new sf::RectangleShape(sf::Vector2f(w, h));
	hitBox->setPosition(x, y);
}

GameObject::GameObject(int x, int y, int radius, sf::Color oColor)
{
	pShape = new sf::CircleShape(radius);
	pShape->setPosition(x, y);
	pShape->setFillColor(oColor);

	width = radius * 2;
	height = radius * 2;
	
	hitBox = new sf::RectangleShape(sf::Vector2f(radius * 2, radius * 2));
	hitBox->setPosition(x, y);
	hitBox->setFillColor(sf::Color::Green);
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

void GameObject::setPosition(float x, float y) {

	pShape->setPosition(x, y);
	hitBox->setPosition(x, y);

}

void GameObject::move(float fDeltaTime) {

	speed = 50.f;

	float ballX = pShape->getPosition().x;
	float ballY = pShape->getPosition().y;

	ballX = ballX + directionX * speed * fDeltaTime;
	ballY = ballY + directionY * speed * fDeltaTime;

	pShape->setPosition(ballX, ballY); 
	hitBox->setPosition(ballX, ballY); 

}

sf::Vector2f GameObject::getXMinMax() {

	sf::Vector2f vect;
	vect.x = pShape->getPosition().x;
	vect.y = pShape->getPosition().x + width;
	return vect;

}

sf::Vector2f GameObject::getYMinMax() {

	sf::Vector2f vect;
	vect.x = pShape->getPosition().y;
	vect.y = pShape->getPosition().y + height;
	return vect;

}

bool GameObject::isInside(float v, float vMin, float vMax) {

	if (v >= vMin && v <= vMax){
		return true;
	}
	return false;

}

void GameObject::checkCollision(GameObject* object) {

	GameObject* minWidth;
	GameObject* maxWidth;
	if (width > object->width) {
		minWidth = object;
		maxWidth = this;
	}
	else {
		minWidth = this;
		maxWidth = object;
	}

	GameObject* minHeight;
	GameObject* maxHeight;
	if (height > object->height) {
		minHeight = object;
		maxHeight = this;
	}
	else {
		minHeight = this;
		maxHeight = object;
	}

	sf::Vector2f xMinMax = minWidth->getXMinMax();
	sf::Vector2f yMinMax = minHeight->getYMinMax();
	sf::Vector2f xMinMaxObj = maxWidth->getXMinMax();
	sf::Vector2f yMinMaxObj = maxHeight->getYMinMax();
	bool xMinInside = isInside(xMinMax.x, xMinMaxObj.x, xMinMaxObj.y);
	bool xMaxInside = isInside(xMinMax.y, xMinMaxObj.x, xMinMaxObj.y);
	bool yMinInside = isInside(yMinMax.x, yMinMaxObj.x, yMinMaxObj.y);
	bool yMaxInside = isInside(yMinMax.y, yMinMaxObj.x, yMinMaxObj.y);
	
	if ((xMinInside or xMaxInside) and (yMinInside or yMaxInside))
		std::cout << "collision" << std::endl;
	else
		std::cout << "-------" << std::endl;

}

void GameObject::collision() {



}

void GameObject::bounce() {



}