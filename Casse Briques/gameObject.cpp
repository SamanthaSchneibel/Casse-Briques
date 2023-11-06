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
}

GameObject::~GameObject()
{
}

void GameObject::move() {



}

void GameObject::rotation() {



}

void GameObject::collision() {



}