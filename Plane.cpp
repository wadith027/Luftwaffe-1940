#include "Plane.h"
//#include "Animation.h"



Plane::Plane(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 1;
	faceRight = true;
	planeBody.setSize(sf::Vector2f(250.75f, 112.5f));
	planeBody.setPosition(0.0f, 10.0f);
	planeBody.setTexture(texture);
}





Plane::~Plane()
{
}
void Plane::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)&&planeBody.getPosition().x>-5)
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)&&planeBody.getPosition().x < 1030)
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f)
	{
		row = 1;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.UpdateMove(row, deltaTime, faceRight);
	planeBody.setTextureRect(animation.uvRect);
	planeBody.move(movement);
}

void Plane::UpdateDead(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	
	animation.UpdateDead(row, deltaTime, faceRight);
	planeBody.setTextureRect(animation.uvRect);
	planeBody.move(movement);
}

void Plane::UpdateHit(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && planeBody.getPosition().x > -5)
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && planeBody.getPosition().x < 1030)
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f)
	{
		row = 3;
	}
	else
	{
		row = 3;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.UpdateHit(row, deltaTime, faceRight);
	planeBody.setTextureRect(animation.uvRect);
	planeBody.move(movement);
}

void Plane::Draw(sf::RenderWindow& window)
{
	window.draw(planeBody);
}