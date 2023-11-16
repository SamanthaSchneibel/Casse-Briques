#include "gameObject.hpp"

class Ball : public GameObject
{
public:
	Ball(float mouseX, float mouseY);
	~Ball();

	bool eraseBall();

	bool onCollision(GameObject* object) override;

	std::vector<GameObject*> colliding;

private:

	float width;
	float height;

};