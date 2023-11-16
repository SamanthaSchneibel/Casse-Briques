#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

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

	virtual bool onCollision(GameObject* object) { return false; };
	virtual bool inCollision() { return false; };

	void checkBounce(GameObject* object);
	void bounceWindow();
	void bounce(GameObject* object);

	sf::Shape* pShape;
	sf::RectangleShape* hitBox;

	std::vector<GameObject*> colliding;


	
	float width;
	float height;

private:

	float directionX;
	float directionY;
	float speed;

};