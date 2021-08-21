#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow& _window) :
	State{ _window, BACKGROUND_PATH },
	bird{ new Bird{_window} },
	ground{ new Ground{_window} }
{
	//std::unique_ptr<Bird> b(
	srand(time(NULL));
}

PlayingState::~PlayingState()
{
	/*if (bird != nullptr)
		delete bird;*/
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

	

	if (clock.getElapsedTime().asSeconds() >= 1)
	{
		//std::make_unique(,)
		pipes.push_back(std::make_unique<Pipe>(*window, window->getSize().y - ground->groundSprite.getGlobalBounds().height));
		clock.restart();
	}

	

	for (size_t i = 0; i < pipes.size(); i++)
	{
		if (pipes[i]->topPipeSprite.getPosition().x < -pipes[i]->topPipeSprite.getGlobalBounds().width)
		{
			//printf("out\n %d\n\n", pipes.size());
			//delete[] pipes[i];
			pipes.erase(pipes.begin() + i);
			//printf("out\n %d\n\n", pipes.size());


		}
		else
		{
			pipes[i]->topPipeSprite.move(-GAME_SPEED, 0);
			pipes[i]->bottomPipeSprite.move(-GAME_SPEED, 0);
		}
		

		
	}

	sf::IntRect groundAnimationRect(ground->groundSprite.getTextureRect());
	groundAnimationRect.left += GAME_SPEED;
	ground->groundSprite.setTextureRect(groundAnimationRect);
}

void PlayingState::Draw()
{
	State::Draw();



	/*window->draw(pipe.topPipeSprite);
	window->draw(pipe.bottomPipeSprite);*/

	for ( auto& pipe : pipes )
	{
		window->draw(pipe->topPipeSprite);
		window->draw(pipe->bottomPipeSprite);
	}

	window->draw(ground->groundSprite);


	window->draw(bird->birdSprite);


	

	//window->setView(sf::View())

	/*for (size_t i = 0; i < pipes.size(); i++)
	{
		window->draw(pipes[i].topPipeSprite);
		window->draw(pipes[i].bottomPipeSprite);
	}*/


	window->display();


	/*for (size_t i = 0; i < pipes.size(); i++)
	{
		if (pipes[i].topPipeSprite.getPosition().x < 0)
		{
			pipes.erase(pipes.begin() + i);
			printf("out\n %d\n\n", pipes.size());
		}
	}*/
}