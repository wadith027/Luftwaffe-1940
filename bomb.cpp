#include "bomb.h"
#include"Plane.h"



Bomb::Bomb(sf::Texture* texture, float speed)
{
	bombbody.setSize(sf::Vector2f(30.0f, 90.0f));
	bombbody.setPosition(0.0f, -100.0f);
	bombbody.setTexture(texture);
	this->speed = speed;
}


Bomb::~Bomb()
{
}

void Bomb::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	movement.y += speed * deltaTime;

	bombbody.move(movement);


}
void Bomb::Draw(sf::RenderWindow& window)
{
	window.draw(bombbody);
}