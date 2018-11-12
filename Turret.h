#pragma once
#include<SFML/Graphics.hpp>
#include"TurretAnimation.h"
class Turret
{
public:
	Turret(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	~Turret();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;
private:

	TurretAnimation animation;
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
	void Update1(float deltaTime);
	void Update2(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;
private:

	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;


};


*/

