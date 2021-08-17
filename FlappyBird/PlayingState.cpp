#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow& _window) : 
	State{ _window, BACKGROUND_PATH }, 
	bird{ new Bird{_window} }
{
	
}

PlayingState::~PlayingState()
{
	if (bird != nullptr)
		delete bird;
}

void PlayingState::ProcessInput(sf::Event& inputEvent, float deltaTime)
{
	if (inputEvent.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			bird->Fly();
		}
	}
}

void PlayingState::Update(float deltaTime)
{
	if (bird->birdState == Bird::BirdState::Falling)
	{
		bird->birdSprite.move(0, GRAVITY * 0.25);
	}
	else if(bird->birdState == Bird::BirdState::Flying)
	{
		if (bird->flyingTime.getElapsedTime().asSeconds() < 0.25)
		{
			bird->birdSprite.move(0, -GRAVITY * 0.25);
		}
		else
		{
			bird->birdState = Bird::BirdState::Falling;
		}
	}
}

void PlayingState::Draw()
{
	State::Draw();

	window->draw(bird->birdSprite);

	window->display();
}