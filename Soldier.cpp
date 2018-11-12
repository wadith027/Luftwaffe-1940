#include "Soldier.h"
#include "Plane.h"



Soldier::Soldier(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
	 
{
	this->speed = speed;	 
	row = 3;
	faceRight = true;
	body.setSize(sf::Vector2f(110.0f, 110.0f));
	body.setPosition(0.0f, 610.0f);
	body.setTexture(texture);
}


Soldier::~Soldier()
{
}
void Soldier::updateMoveLeft(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	row = 2;
	if (body.getPosition().x <= -100.0f)body.setPosition(1340, 610.0f);
	movement.x -= speed * deltaTime;	
	faceRight = false;
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}
void Soldier::updateMoveRight(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	row = 2;
	if (body.getPosition().x >= 1280.0f)body.setPosition(-90.0f, 610.0f);
	movement.x += speed * deltaTime;
	faceRight = true;
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}
void Soldier::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	 
}

 