#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int x, int y, int h, int w, sf::Color oColor);
	GameObject(int x, int y, int radius, sf::Color oColor);
	~GameObject();

	void move();
	void rotation();
	void collision();

	sf::Shape* pShape;

private:



};