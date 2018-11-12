#include "Player.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 3;
	faceRight = true;
	body.setSize(sf::Vector2f(110.0f, 110.0f));
	//shape.setFillColor(sf::Color::Green);
	body.setPosition(0.0f,610.0f);
	//sf::Texture playertexture;
	//playertexture.loadFromFile("sprite.png");
	body.setTexture(texture);
}


Player::~Player()
{
}
void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	
		//movement.x -= speed * deltaTime;
	//float x;
	//x = body.getPosition().x;
		if(body.getPosition().x>=1280.0f)body.setPosition(-90.0f, 610.0f);
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
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}