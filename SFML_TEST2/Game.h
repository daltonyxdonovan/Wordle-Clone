#pragma once



class Game
{
private:
	sf::RenderWindow* window;



	void initVariables();
	{

	}
	void initWindow();
	{

	}





public:
	//constructors and destructors
	Game();
	virtual ~Game();


	//functions
	void update();
	void render();

};

