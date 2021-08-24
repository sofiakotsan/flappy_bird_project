#include "GameOverState.h"

GameOverState::GameOverState(sf::RenderWindow& _window) :
	State{ _window } 
{
	gameOverLabelTexture.loadFromFile(GAME_OVER_LABEL);
	scoreBoardTexture.loadFromFile(SCORE_BOARD);
	playButtonTexture.loadFromFile(PLAY_BUTTON);

	gameOverLabel.setTexture(gameOverLabelTexture);
	scoreBoard.setTexture(scoreBoardTexture);
	playButton.setTexture(playButtonTexture);

	/*gameOverLabel.setPosition(0, 0);
	scoreBoard.setPosition(0, 0);
	playButton.setPosition(0, 0);*/

	gameOverLabel.setOrigin(gameOverLabel.getGlobalBounds().width / 2, 0);
	scoreBoard.setOrigin(scoreBoard.getGlobalBounds().width / 2, 0);
	playButton.setOrigin(playButton.getGlobalBounds().width / 2, 0);

	gameOverLabel.setPosition(window->getSize().x / 2, 100);
	scoreBoard.setPosition(window->getSize().x / 2, 250);
	playButton.setPosition(window->getSize().x / 2, 600);
}

void GameOverState::Update()
{
	/*gameOverLabel.setPosition(window->getSize().y / 10, window->getSize().x / 2);
	scoreBoard.setPosition(window->getSize().y / 10, window->getSize().x / 2);
	playButton.setPosition(window->getSize().y / 10, window->getSize().x / 2);*/

	//gameOverLabel.setPosition(0, 0);
	//scoreBoard.setPosition(0, 0);
	//playButton.setPosition(0, 0);

}

void GameOverState::ProcessInput(sf::Event& inputEvent)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//if (inputEvent.type == sf::Event::MouseButtonPressed)
	{
		printf("%d, %d\n", sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		//sf::Mouse::getPosition().x;
		//inputEvent.MouseButtonPressed

		int mouseX = sf::Mouse::getPosition().x - window->getPosition().x;
		int mouseY = sf::Mouse::getPosition().y - window->getPosition().y;
		printf("%d, %d\n", mouseX, mouseY);


		if (playButton.getGlobalBounds().contains(mouseX, mouseY))
		{
			printf("contains\n");
		}

		//playButton.getTextureRect().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)
	}

}

void GameOverState::Draw()
{
	if (clock.getElapsedTime().asSeconds() >= 1.0)
	{
		State::Draw();

		//window->clear();

		window->draw(gameOverLabel);
		window->draw(scoreBoard);
		window->draw(playButton);

			//printf("3\n");

		window->display();
	}
}