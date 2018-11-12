#include "missile.h"
#include"Soldier.h"


Missile::Missile(sf::Texture* texture, float speed)
{
	missilebody.setSize(sf::Vector2f(30.0f, 80.0f));
	missilebody.setPosition(0.0f, 730.0f);
	missilebody.setTexture(texture);
	this->speed = speed;
}




Missile :: ~Missile()
{
}
void Missile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	 
	movement.y -= speed * deltaTime;	
	
	missilebody.move(movement);
}
void Missile::UpdateLeft(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	movement.y -= speed * deltaTime;
	movement.x -= 100 * deltaTime;	

	missilebody.move(movement);
}
void Missile::UpdateRight(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y -= speed * deltaTime;
	movement.x += 100 * deltaTime;
	missilebody.move(movement);
}
void Missile::Draw(sf::RenderWindow& window)
{
	window.draw(missilebody);
}


