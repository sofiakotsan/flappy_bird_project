#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow& window) : bird{ new Bird{window} }
{
	printf("%f, %f", bird->birdSprite.getOrigin().x, bird->birdSprite.getOrigin().y);
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