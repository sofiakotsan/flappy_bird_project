#include "Game.h"

Game::Game(int width, int height, std::string title)
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

	currentState = new PlayingState;
	//currentState = std::make_shared(new PlayingState);

	this->Run();
}

Game::~Game() {
	if (currentState != nullptr)
		delete currentState;
}

void Game::Run()
{

	//currentState->ProcessInput();



	while (this->window.isOpen())
	{
		sf::Event inputEvent;
		while (window.pollEvent(inputEvent))
		{
			if (inputEvent.type == sf::Event::Closed)
				window.close();
		}

		currentState->ProcessInput(inputEvent);
		currentState->Draw(this->window);
	}
}