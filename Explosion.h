#pragma once
#include<SFML/Graphics.hpp>
#include"ExplosionAnimation.h"
class Explosion
{
public:
	Explosion(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Explosion();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape explosionBody;
private:

	ExplosionAnimation animation;
	unsigned int row;
	float speed;
	bool faceRight;

};
