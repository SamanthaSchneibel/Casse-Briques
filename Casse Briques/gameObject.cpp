#include "gameObject.hpp"

GameObject::GameObject(int x, int y, int h, int w)
{
	pShape = new sf::RectangleShape(sf::Vector2f(h, w));
	pShape->setPosition(x, y);
	pShape->setFillColor(sf::Color::Blue);
}

GameObject::GameObject(int x, int y, int radius)
{
	pShape = new sf::CircleShape(radius);
	pShape->setPosition(x, y);
	pShape->setFillColor(sf::Color::White);
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