#include "Game.h"

Game::Game(int width, int height, std::string title)
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

	currentState = new PlayingState{window};
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
	
	//float currentTime = clock.getElapsedTime().asMicroseconds();
	//float frameTime = 1000;


	while (this->window.isOpen())
	{
		sf::Event inputEvent;
		//float currentTime = clock.getElapsedTime().asMicroseconds();
		//float frameTime = 0.5;
		//float currentTime = clock.getElapsedTime().asSeconds();
		float deltaTime = clock.getElapsedTime().asSeconds();
		
		currentState->Update(deltaTime);

		while (window.pollEvent(inputEvent))
		{
			if (inputEvent.type == sf::Event::Closed)
				window.close();

			

			currentState->ProcessInput(inputEvent, deltaTime);

			/*if (clock.getElapsedTime().asMicroseconds() >= frameTime)
			{
				printf("1\n");
				clock.restart();
			}*/

		}

		currentState->Draw();

	}
}