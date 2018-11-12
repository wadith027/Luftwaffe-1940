#pragma once
#include<SFML/Graphics.hpp>
#include"Plane.h"
class Bomb
{
public:
	Bomb(sf::Texture* texture,float speed);
	~Bomb();
	void Update(float deltaTime);
	void fire(float speed);

	void Draw(sf::RenderWindow& window);
	sf::RectangleShape bombbody;

private:
	float speed;
};

