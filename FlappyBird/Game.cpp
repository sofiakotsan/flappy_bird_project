#include "Game.h"

Game::Game(int width, int height, std::string title) : gameOver{ new bool {false} }, gameStateEnum{ GameState::StartScreen }
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	currentState = std::make_unique<PlayingState>(window, gameOver);//new PlayingState{window, gameOver };

	//gameOver = std::make_shared<bool>(false);

	//*gameOver = false;

	//gameOver = std::make_shared(false);

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

			//if (*gameOver)
			//{
				currentState->ProcessInput(inputEvent);

			//}
		}

		currentState->Draw();

		if (*gameOver)
		{
			//printf("1\n");
			//printf("%d\n", *gameOver);

			currentState.release();

			currentState = std::make_unique<GameOverState>(window);
			*gameOver = false;
			//printf("2\n");

		}

	}
}