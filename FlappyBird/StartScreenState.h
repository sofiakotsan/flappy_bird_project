#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Obstacle.h>
#include <State.h>
#include <vector>
#include <string>


class StartScreenState : public State
{
public:
	void ProcessInput(sf::Event& inputEvent, float deltaTime) override;
};

