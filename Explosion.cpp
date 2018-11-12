#include "Explosion.h"
//#include "Animation.h"



Explosion::Explosion(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	explosionBody.setSize(sf::Vector2f(220.0f, 220.0f));
	explosionBody.setPosition(500.0f, 500.0f);
	explosionBody.setTexture(texture);
}
Explosion::~Explosion()
{
}
void Explosion::Update(float deltaTime)
{	

	animation.Update(row, deltaTime);
	explosionBody.setTextureRect(animation.uvRect);
	 
}


void Explosion::Draw(sf::RenderWindow& window)
{
	window.draw(explosionBody);
}