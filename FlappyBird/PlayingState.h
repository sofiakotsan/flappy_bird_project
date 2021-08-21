#pragma once
#include <SFML/Graphics.hpp>
#include <Bird.h>
#include <Pipe.h>
#include <State.h>
#include <vector>
#include <string>
#include <memory>
#include <time.h>


class PlayingState: public State
{
	Bird* bird;
	std::vector<std::unique_ptr<Pipe>> pipes;
	//Pipe pipe;
	//sf::View gameView;
	sf::Clock clock;
public: 
	
	//sf::View()
	PlayingState(sf::RenderWindow& window);
	~PlayingState();

	void ProcessInput(sf::Event& inputEvent) override;
	void Update(float deltaTime) override;
	void Draw() override;
};

