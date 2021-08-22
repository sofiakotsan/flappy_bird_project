#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Pipe.h>
#include <State.h>
#include <vector>
#include <string>


class StartScreenState : public State
{
public:
	void ProcessInput(sf::Event& inputEvent) override;
};

