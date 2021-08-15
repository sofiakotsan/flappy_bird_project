#include "PlayingState.h"

PlayingState::PlayingState() : bird{ new Bird }
{
	
}

PlayingState::~PlayingState()
{
	if (bird != nullptr)
		delete bird;
}

void PlayingState::ProcessInput(sf::Event& inputEvent)
{
	if (inputEvent.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			bird->birdSprite.move(sf::Vector2f(10, 10));
		}
	}


}

void PlayingState::Update()
{
	
}

void PlayingState::Draw(sf::RenderWindow& window)
{
	window.clear();

	window.draw(bird->birdSprite);

	window.display();
}