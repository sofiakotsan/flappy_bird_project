#include "PlayingState.h"

PlayingState::PlayingState(sf::RenderWindow& _window, std::shared_ptr<bool>& _birdIntersected) :
	State{ _window, BACKGROUND_PATH },
	bird{ new Bird{_window} },
	ground{ new Ground{_window} },
	birdIntersected{ _birdIntersected }
{
	//std::unique_ptr<Bird> b(
	//birdIntersected

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

	/*if (bird->birdSprite.getTextureRect().intersects(ground->groundSprite.getTextureRect()))
	{
		printf("intersects\n");
	}*/

	if (bird->birdSprite.getGlobalBounds().intersects(ground->groundSprite.getGlobalBounds()) )
	{
		//printf("intersects\n");
		*birdIntersected = true;

	}

	if (clock.getElapsedTime().asSeconds() >= 1)
	{
		pipes.push_back(std::make_unique<Pipe>(*window, window->getSize().y - ground->groundSprite.getGlobalBounds().height));
		clock.restart();
	}

	for (size_t i = 0; i < pipes.size(); i++)
	{
		if (pipes[i]->topPipeSprite.getPosition().x < -pipes[i]->topPipeSprite.getGlobalBounds().width)
		{
			pipes.erase(pipes.begin() + i);
		}
		else
		{
			pipes[i]->topPipeSprite.move(-GAME_SPEED, 0);
			pipes[i]->bottomPipeSprite.move(-GAME_SPEED, 0);

			if (bird->birdSprite.getGlobalBounds().intersects(pipes[i]->topPipeSprite.getGlobalBounds()) || 
				bird->birdSprite.getGlobalBounds().intersects(pipes[i]->bottomPipeSprite.getGlobalBounds()))
			{
				printf("intersects\n");
				printf("%d", *birdIntersected);
				printf("1\n");

				*birdIntersected = true;
				printf("2\n");


			}
		}
	}

	sf::IntRect groundAnimationRect(ground->groundSprite.getTextureRect());
	groundAnimationRect.left += GAME_SPEED;
	ground->groundSprite.setTextureRect(groundAnimationRect);


}

void PlayingState::Draw()
{
	State::Draw();

	for ( auto& pipe : pipes )
	{
		window->draw(pipe->topPipeSprite);
		window->draw(pipe->bottomPipeSprite);
	}
	window->draw(ground->groundSprite);
	window->draw(bird->birdSprite);

	window->display();
}