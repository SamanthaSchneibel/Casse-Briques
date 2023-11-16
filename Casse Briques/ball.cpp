#include "ball.hpp"

Ball::Ball(float mouseX, float mouseY) : GameObject(320, 480, 10, sf::Color::White)
{
    float ballX = hitBox->getPosition().x;
    float ballY = hitBox->getPosition().y;

    setDirection(mouseX - ballX, mouseY - ballY);
}

Ball::~Ball()
{
}

bool Ball::eraseBall() {

	float positionX = pShape->getPosition().x;
	float positionY = pShape->getPosition().y;

	if (positionY > 480)
	{
		std::cout << "erased ball" << std::endl;
		return true;
	}
	return false;

}

bool Ball::onCollision(GameObject* object) {

	GameObject* minWidth;
	GameObject* maxWidth;
	if (width > object->width)
	{
		minWidth = object;
		maxWidth = this;
	}
	else
	{
		minWidth = this;
		maxWidth = object;
	}

	GameObject* minHeight;
	GameObject* maxHeight;
	if (height > object->height)
	{
		minHeight = object;
		maxHeight = this;
	}
	else
	{
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
	{
		return true;
	}
	else
	{
		return false;
	}

}