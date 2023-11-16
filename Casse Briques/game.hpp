#include "gameObject.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "canon.hpp"

class Game
{
public:
	Game();
	~Game();

	void event();
	void update();
	void draw();

	bool isRunning() { return running; };

private:

	sf::RenderWindow* oWindow;

	std::vector<Ball*> listBall;
	Canon oCanon;
	std::vector<Brick*> listBrick;

	sf::Clock oClock;
	float fDeltaTime = 0;

	bool running = true;

};