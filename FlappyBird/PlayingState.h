#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Ground.h>
#include <Pipe.h>
#include <State.h>
#include <vector>
#include <string>
#include <memory>
#include <time.h>


class PlayingState: public State
{
	std::unique_ptr<Bird> bird;
	std::unique_ptr<Ground> ground;
	//Ground* bird;
	std::vector<std::unique_ptr<Pipe>> pipes;
	//Pipe pipe;
	//sf::View gameView;
	sf::Clock clock;
	std::shared_ptr<bool> gameOver;
public: 
	
	//sf::View()
	PlayingState(sf::RenderWindow& window, std::shared_ptr<bool>& _gameOver);
	~PlayingState();

	void ProcessInput(sf::Event& inputEvent) override;
	void Update() override;
	void Draw() override;
};

