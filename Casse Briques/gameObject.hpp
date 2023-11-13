#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int x, int y, int w, int h, sf::Color oColor);
	GameObject(int x, int y, int radius, sf::Color oColor);
	~GameObject();

	void rotation(float mouseX, float mouseY);

	void setDirection(float fDirectionX, float fDirectionY);
	void setPosition(float x, float y);
	void move(float fDeltaTime);

	sf::Vector2f getXMinMax();
	sf::Vector2f getYMinMax();
	bool isInside(float v, float vMin, float vMax);
	void checkCollision(GameObject* object);
	void collision();

	void bounce();

	sf::Shape* pShape;
	sf::RectangleShape* hitBox;

private:

	float directionX;
	float directionY;
	float speed;
	float width;
	float height;

};