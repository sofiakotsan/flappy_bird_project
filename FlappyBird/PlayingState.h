#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Obstacle.h>
#include <State.h>
#include <vector>
#include <string>


class PlayingState: public State
{
public: 
	Bird* bird;
	std::vector<Obstacle> obstacles;

	void ProcessInput(sf::Event& inputEvent) override;
	void Update() override;
	void Draw(sf::RenderWindow& window) override;
};

