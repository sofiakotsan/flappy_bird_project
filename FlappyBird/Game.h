#pragma once
#include <SFML/Graphics.hpp>
//#include <Bird.h>
//#include <Obstacle.h>
#include <State.h>
#include <PlayingState.h>
#include <GameOverState.h>
#include <StartScreenState.h>
#include <vector>
#include <string>
//#include <shared_ptr>

class Game
{
	std::shared_ptr<bool> gameOver;
	sf::RenderWindow window;
	std::unique_ptr<State> currentState;
	sf::Clock clock;


public:
	/*enum class GameState {
		StartScreen,
		InProgress,
		GameOver
	} currentStateId;*/


	//std::shared_ptr<State> currentState;


	Game(int width, int height, std::string title);
	~Game();
	void Run();

};

