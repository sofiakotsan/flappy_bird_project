#include "Game.h"

Game::Game(int width, int height, std::string title) : birdIntersected{ new bool {false} }
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	currentState = new PlayingState{window, birdIntersected };

	//birdIntersected = std::make_shared<bool>(false);

	//*birdIntersected = false;

	//birdIntersected = std::make_shared(false);

	this->Run();
}

Game::~Game() {
	if (currentState != nullptr)
		delete currentState;
}

void Game::Run()
{

	while (this->window.isOpen())
	{
		sf::Event inputEvent;

		float deltaTime = clock.getElapsedTime().asSeconds();
		
		currentState->Update(deltaTime);

		while (window.pollEvent(inputEvent))
		{
			if (inputEvent.type == sf::Event::Closed)
				window.close();

			currentState->ProcessInput(inputEvent);
		}

		currentState->Draw();

		if (*birdIntersected)
		{
			printf("intr\n");
		}

	}
}