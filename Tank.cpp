#include "Tank.h"
#include "TankAnimation.h"



Tank::Tank(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):

	animation(texture, imageCount, switchTime)
	{
		this->speed = speed;
		row = 0;
		faceRight = true;
		body.setSize(sf::Vector2f(300.0f, 200.0f));
		//shape.setFillColor(sf::Color::Green);
		body.setPosition(1300.0f, 560.0f);
		//sf::Texture playertexture;
		//playertexture.loadFromFile("sprite.png");
		body.setTexture(texture);
	}




Tank::~Tank()
{
}
void Tank::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))

		//movement.x -= speed * deltaTime;
	//float x;
	//x = body.getPosition().x;
	if (body.getPosition().x <= -300.0f)body.setPosition(1390.0f, 560.0f);
	//if (body.getPosition().x == 600.0f)
	//{


	//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))

	movement.x -= speed * deltaTime;


	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 3;
		if (movement.x > 0.0f)
			faceRight = true;
		else faceRight = false;

	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}
void Tank::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

