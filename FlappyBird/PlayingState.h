#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Pipe.h>
#include <State.h>
#include <vector>
#include <string>
#include <time.h>


class PlayingState: public State
{
	Bird* bird;
	std::vector<Pipe> pipes;
	//Pipe pipe;
	sf::Clock clock;
public: 
	

	PlayingState(sf::RenderWindow& window);
	~PlayingState();

	void ProcessInput(sf::Event& inputEvent) override;
	void Update(float deltaTime) override;
	void Draw() override;
};

