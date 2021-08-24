#include "Game.h"

Game::Game(int width, int height, std::string title) : isGameOver{ new bool {false} }, isStartScreen{ new bool {false} }
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	currentState = std::make_unique<PlayingState>(window, isGameOver);//new PlayingState{window, isGameOver };

	//isGameOver = std::make_shared<bool>(false);

	//*isGameOver = false;

	//isGameOver = std::make_shared(false);

	this->Run();
}

Game::~Game() {
	/*if (currentState != nullptr)
		delete currentState;*/
}

void Game::Run()
{

	while (this->window.isOpen())
	{
		sf::Event inputEvent;

		//float deltaTime = clock.getElapsedTime().asSeconds();
		
		/*else 
		{
			currentState = std::make_unique<GameOverState>(window);
		}*/

		currentState->Update();



		while (window.pollEvent(inputEvent))
		{
			if (inputEvent.type == sf::Event::Closed)
				window.close();

			//if (*isGameOver)
			//{
				currentState->ProcessInput(inputEvent);

			//}
		}

		currentState->Draw();

		if (*isGameOver)
		{
			//printf("1\n");
			//printf("%d\n", *isGameOver);

			currentState.release();

			currentState = std::make_unique<GameOverState>(window);
			*isGameOver = false;
			//printf("2\n");

		}

	}
}