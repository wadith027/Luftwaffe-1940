#include "ExplosionAnimation.h"



ExplosionAnimation::ExplosionAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


ExplosionAnimation::~ExplosionAnimation()
{
}
void ExplosionAnimation::Update(int row, float deltaTIme)
{
	currentImage.y = 0;
	totalTime += deltaTIme;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x == 4)
		{
			currentImage.x = 0;
		}
	}
}