#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Pipe.h>
#include <State.h>
#include <vector>
#include <string>


class PlayingState: public State
{
	Bird* bird;
	std::vector<Pipe> pipes;
	Pipe pipe;
public: 
	

	PlayingState(sf::RenderWindow& window);
	~PlayingState();

	void ProcessInput(sf::Event& inputEvent) override;
	void Update(float deltaTime) override;
	void Draw() override;
};

