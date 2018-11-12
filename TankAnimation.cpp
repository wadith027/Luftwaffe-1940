#include "TankAnimation.h"



TankAnimation::TankAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRect.width = (texture->getSize().x+70.0f )/ float(imageCount.x);
	uvRect.height = (texture->getSize().y-9.0f) / float(imageCount.y);

}


TankAnimation::~TankAnimation()
{
}
void TankAnimation::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x == 5)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y*uvRect.height;
	if (faceRight)
	{
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1)*abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}




}
 