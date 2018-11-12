#pragma once
#include<SFML/Graphics.hpp>
#include"soldierAnimation.h"
#include<vector>
using namespace sf;
using namespace std;
class Soldier
{

public:
	 
 
	Soldier(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	 
	~Soldier();
 
	void updateMoveRight(float deltaTime);
	void updateMoveLeft(float deltaTime);
	void updateStandStill(float deltaTime);
	void UpdateDead(float deltaTime);
	void Draw(sf::RenderWindow& window);
	bool soldierAlive = true;
	unsigned int row;
	sf::RectangleShape body;
private:
	
	Animation animation;
	
	float speed;
	bool faceRight;
	vector<Soldier>::const_iterator soldieriter;
	vector<Soldier>soldierarray;
	
};
 