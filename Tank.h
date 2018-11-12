#pragma once
#include<SFML/Graphics.hpp>
#include"TankAnimation.h"
class Tank


{

public:

	Tank(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	//Tank();
	~Tank();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;
private:
	TankAnimation animation;
	unsigned int row;
	float speed;
	bool faceRight;

};
/*
#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
class Soldier
{

public:


	Soldier(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Soldier();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;
private:

	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;


};


*/
