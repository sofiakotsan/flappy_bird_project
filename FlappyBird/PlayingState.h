#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Obstacle.h>
#include <State.h>
#include <vector>
#include <string>


class PlayingState: public State
{
	Bird* bird;
	std::vector<Obstacle> obstacles;

public: 
	

	PlayingState(sf::RenderWindow& window);
	~PlayingState();

	void ProcessInput(sf::Event& inputEvent, float deltaTime) override;
	void Update(float deltaTime) override;
	void Draw() override;
};

