#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow& _window) : 
	State{ _window, BACKGROUND_PATH }, 
	bird{ new Bird{_window} }, 
	pipe{ _window }
{
	pipes.push_back(Pipe(_window));
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
		bird->birdSprite.move(0, GRAVITY * 0.2);
	}
	else if(bird->birdState == Bird::BirdState::Flying)
	{
		if (bird->flyingTime.getElapsedTime().asSeconds() < FLYING_TIME)
		{
			bird->birdSprite.move(0, -FLAP_SPEED * 0.2);
		}
		else
		{
			bird->birdState = Bird::BirdState::Falling;
			bird->flyingTime.restart();
		}
	}
}

void PlayingState::Draw()
{
	State::Draw();

	window->draw(bird->birdSprite);

	/*window->draw(pipe.topPipeSprite);
	window->draw(pipe.bottomPipeSprite);*/

	for ( auto& pipe : pipes )
	{
		window->draw(pipe.topPipeSprite);
		window->draw(pipe.bottomPipeSprite);
	}

	//window->setView(sf::View())

	/*for (size_t i = 0; i < pipes.size(); i++)
	{
		window->draw(pipes[i].topPipeSprite);
		window->draw(pipes[i].bottomPipeSprite);
	}*/

	window->display();
}