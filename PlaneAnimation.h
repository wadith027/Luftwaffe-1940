#pragma once
#include<SFML/Graphics.hpp>
class PlaneAnimation
{
public:
	PlaneAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~PlaneAnimation();
	void UpdateMove(int row, float deltaTIme, bool faceRight);
	void UpdateDead(int row, float deltaTIme, bool faceRight);
	void UpdateHit(int row, float deltaTIme, bool faceRight);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};
