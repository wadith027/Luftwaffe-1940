#pragma once
#include<SFML/Graphics.hpp>
#include"PlaneAnimation.h"
class Plane
{
public:
	Plane(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Plane();
	void Update(float deltaTime);
	void UpdateDead(float deltaTime);
	void UpdateHit(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape planeBody;
	bool faceRight;
private:

	PlaneAnimation animation;
	unsigned int row;
	float speed;
	

};