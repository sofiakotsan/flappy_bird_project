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
	printf("1\n");
}

void PlayingState::Update()
{
	
}

void PlayingState::Draw(sf::RenderWindow& window)
{
	//window.clear();

	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.clear();
	window.draw(shape);
	window.display();*/

	printf("2\n");

}