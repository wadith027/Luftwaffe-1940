#pragma once
#include<SFML/Graphics.hpp>
#include"Soldier.h"
//#include"Animation.h"
class Missile
{
public:
	Missile(sf::Texture* texture,float speed);
	~Missile();
	void Update(float deltaTime);
	//void fire(float speed);
	void UpdateLeft(float deltaTime);
	void UpdateRight(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape missilebody;
	float speed;
	bool isfire = false;

private:
	
	//Soldier soldier;
//	Animation animation;
	
	//bool faceRight;
};

