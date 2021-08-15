#pragma once
#include <SFML/Graphics.hpp>
//#include <Bird.h>
//#include <Obstacle.h>
#include <State.h>
#include <PlayingState.h>
#include <StartScreenState.h>
#include <vector>
#include <string>
//#include <shared_ptr>

class Game
{
public:
	/*enum class GameState {
		StartScreen,
		InProgress,
		GameOver
	} currentStateId;*/

	sf::RenderWindow window;

	State* currentState;
	//std::shared_ptr<State> currentState;

	sf::Clock clock;

	Game(int width, int height, std::string title);
	~Game();
	void Run();

};

