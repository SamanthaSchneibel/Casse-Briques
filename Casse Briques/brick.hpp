#include "gameObject.hpp"

class Brick : public GameObject
{
public:
	Brick(int x, int y);
	~Brick();

	bool inCollision() override;

private:

	int life;
	int width;
	int height;

};