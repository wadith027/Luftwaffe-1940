#pragma once
#include<SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);
	~Animation();
	void Update(int row, float deltaTime, bool faceRight);
	void UpdateDead(int brow, float deltaTime, bool faceRight);
public:

	sf :: IntRect uvRect;
	sf::Vector2u currentImage;



private: 
	sf::Vector2u imageCount;
	int deadDelay=0;

	float totalTime;
	float switchTime;

};

