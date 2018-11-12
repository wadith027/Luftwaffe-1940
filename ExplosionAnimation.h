#pragma once
#include<SFML/Graphics.hpp>
#include"bomb.h"
class ExplosionAnimation
{
public:
	ExplosionAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~ExplosionAnimation();
	void Update(int row, float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape planeBody;
public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};