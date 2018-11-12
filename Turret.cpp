#include "Turret.h"
#include"TurretAnimation.h"




Turret::Turret(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):

	animation(texture, imageCount, switchTime)
{
	//this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(220.0f, 220.0f));
	//shape.setFillColor(sf::Color::Green);
	body.setPosition(1060.0f, 500.0f);
	//sf::Texture playertexture;
	//playertexture.loadFromFile("sprite.png");
	body.setTexture(texture);
}


Turret::~Turret()
{
}
void Turret::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))

		//movement.x -= speed * deltaTime;
	//float x;
	//x = body.getPosition().x;
	//if (body.getPosition().x >= 1280.0f)body.setPosition(-90.0f, 610.0f);
	//if (body.getPosition().x == 600.0f)
	//{


	//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))

	 


	 

	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	//body.move(movement);

}

void Turret::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}



/*
#include "Soldier.h"



Soldier::Soldier(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 3;
	faceRight = true;
	body.setSize(sf::Vector2f(110.0f, 110.0f));
	//shape.setFillColor(sf::Color::Green);
	body.setPosition(0.0f, 610.0f);
	//sf::Texture playertexture;
	//playertexture.loadFromFile("sprite.png");
	body.setTexture(texture);
}


Soldier::~Soldier()
{
}
void Soldier::Update1(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))

		//movement.x -= speed * deltaTime;
	//float x;
	//x = body.getPosition().x;
	if (body.getPosition().x >= 1280.0f)body.setPosition(-90.0f, 610.0f);
	//if (body.getPosition().x == 600.0f)
	//{


	//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))

	movement.x += speed * deltaTime;


	if (movement.x == 0.0f)
	{
		row = 2;
	}
	else
	{
		row = 2;
		if (movement.x > 0.0f)
			faceRight = true;
		else faceRight = false;

	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}
void Soldier::Update2(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))

		//movement.x -= speed * deltaTime;
	//float x;
	//x = body.getPosition().x;
	if (body.getPosition().x >= 1280.0f)body.setPosition(-90.0f, 610.0f);
	//if (body.getPosition().x == 600.0f)
	//{


	//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))

	//movement.x += speed * deltaTime;


	if (movement.x == 0.0f)
	{
		row = 2;
	}
	else
	{
		row = 2;
		if (movement.x > 0.0f)
			faceRight = true;
		else faceRight = false;

	}
	//animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}
void Soldier::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

*/
