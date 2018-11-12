#include "PlaneAnimation.h"



PlaneAnimation::PlaneAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


PlaneAnimation::~PlaneAnimation()
{
}
void PlaneAnimation::UpdateMove(int row, float deltaTIme, bool faceRight)
{
	currentImage.y = 1;
	totalTime += deltaTIme;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x == 2)
		{
			currentImage.x = 0;
		}
	}


	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1)* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	uvRect.top = currentImage.y * uvRect.height;
}
void PlaneAnimation::UpdateDead(int row, float deltaTIme, bool faceRight)
{
	currentImage.y = 0;
	totalTime += deltaTIme;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x == 2)
		{
			currentImage.x = 0;
		}
	}


	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1)* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	uvRect.top = currentImage.y * uvRect.height;
}

void PlaneAnimation::UpdateHit(int row, float deltaTIme, bool faceRight)
{
	currentImage.y = 2;
	totalTime += deltaTIme;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x == 2)
		{
			currentImage.x = 0;
		}
	}


	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1)* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	uvRect.top = currentImage.y * uvRect.height;
}