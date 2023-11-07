#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int x, int y, int h, int w, sf::Color oColor);
	GameObject(int x, int y, int radius, sf::Color oColor);
	~GameObject();

	void rotation(float x, float y);
	void move();
	void collision();

	sf::Shape* pShape;

private:



};