#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int x, int y, int h, int w, sf::Color oColor);
	GameObject(int x, int y, int radius, sf::Color oColor);
	~GameObject();

	void rotation(float mouseX, float mouseY);

	void setDirection(float fDirectionX, float fDirectionY);

	void move(float fDeltaTime);

	void collision();

	sf::Shape* pShape;

private:

	float directionX;
	float directionY;
	float speed;

};