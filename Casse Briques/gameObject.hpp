#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int x, int y, int h, int w);
	GameObject(int x, int y, int radius);
	~GameObject();

	void move();
	void rotation();
	void collision();

	sf::Shape* pShape;

private:



};