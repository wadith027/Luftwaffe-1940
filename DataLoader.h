#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include"player.h"
#include"missile.h"
#include"Soldier.h"
#include"Plane.h"
#include"PlaneAnimation.h"
#include<vector>
#include<iostream>
#include"Tank.h"
#include"TankAnimation.h"
#include"Turret.h"
#include"TurretAnimation.h"
#include"bomb.h"
#include"Menu.h"
#include"PauseMenu.h"
#include"Explosion.h"
#include"ExplosionAnimation.h"
#include <random>
#include<sstream>
using namespace std;
using namespace sf;
enum state
{
	menustate, gamestate, gameoverstate, pausestate

};
void dataLoader()
{

	//srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Luftwaffe 1940", sf::Style::Close | sf::Style::Resize);
	//sf::CircleShape shape(100.f);
	//sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
	//shape.setFillColor(sf::Color::Green);
	//player.setPosition(200.0f, 200.0f);
	sf::Texture playertexture;
	sf::Texture missileTexture;
	sf::Texture backgroundTexture;
	sf::Texture planeTexture;
	sf::Texture tankTexture;
	sf::Texture gameoverTexture;
	Texture turretTexture;
	Texture bombTexture;
	Texture menuBackgroundTexture;
	Texture splashTexture;
	Texture gameoveTexture;
	sf::Texture ExplosionTexture;
	Texture lifeTextureOne;
	Texture lifeTextureTwo;
	Texture lifeTextureThree;
	Texture lifeTextureFour;
	Texture lifeTextureFive;

	// life add
	lifeTextureOne.loadFromFile("life1.png");
	lifeTextureTwo.loadFromFile("life2.png");
	lifeTextureThree.loadFromFile("life3.png");
	lifeTextureFour.loadFromFile("life4.png");
	lifeTextureFive.loadFromFile("life5.png");

	bombTexture.loadFromFile("bomb.png");
	gameoverTexture.loadFromFile("gameover.png");
	menuBackgroundTexture.loadFromFile("MenuBackground.png");


	//gameoverTexture.loadFromFile("gameover.png");
	planeTexture.loadFromFile("plane.png");
	tankTexture.loadFromFile("Tank.png");
	backgroundTexture.loadFromFile("background.png");
	turretTexture.loadFromFile("Turret.png");
	splashTexture.loadFromFile("splash.png");
	ExplosionTexture.loadFromFile("explosion.png");
	sf::Sprite background;
	sf::Sprite menuBackground;
	Sprite splash;
	Sprite gameover;

	sf::Sprite lifeOne;
	sf::Sprite lifeTwo;
	sf::Sprite lifeThree;
	sf::Sprite lifeFour;
	sf::Sprite lifeFive;

	// LIFE Scaling
	lifeOne.setTexture(lifeTextureOne);
	lifeOne.setScale(0.04f, 0.04f);
	lifeOne.setPosition(1030, 0);
	//lifeOne.setTextureRect(sf::IntRect(620, 0, 50, 50));
	lifeTwo.setTexture(lifeTextureTwo);
	lifeTwo.setScale(0.04f, 0.04f);
	lifeTwo.setPosition(1080, 0);
	//lifeTwo.setTextureRect(sf::IntRect(570, 0, 50, 50));
	lifeThree.setTexture(lifeTextureThree);
	lifeThree.setScale(0.04f, 0.04f);
	lifeThree.setPosition(1130, 0);
	//lifeThree.setTextureRect(sf::IntRect(520, 0, 50, 50));
	lifeFour.setTexture(lifeTextureFour);
	lifeFour.setScale(0.04f, 0.04f);
	lifeFour.setPosition(1180, 0);
	//lifeFour.setTextureRect(sf::IntRect(470, 0, 50, 50));
	lifeFive.setTexture(lifeTextureFive);
	lifeFive.setScale(0.04f, 0.04f);
	lifeFive.setPosition(1230, 0);
	//lifeFive.setTextureRect(sf::IntRect(420, 0, 50, 50));

	//life scaling end
	gameover.setTexture(gameoverTexture);
	gameover.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	splash.setTexture(splashTexture);
	splash.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	menuBackground.setTexture(menuBackgroundTexture);
	menuBackground.setTextureRect(sf::IntRect(0, 0, 1280, 720));

	background.setTexture(backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, 1280, 720));

	int deadanimation = 0;
	int soldierFlag = 0, soldierdelay = 0;

	sf::Music InGameMusic;
	if (!InGameMusic.openFromFile("ingamemusic.ogg"))
		printf("Error\n"); // error
	sf::Music MenuMusic;
	if (!MenuMusic.openFromFile("menumusic.ogg"))
		printf("Error\n"); // error


	missileTexture.loadFromFile("missile.png");
	playertexture.loadFromFile("sprite.png");



	Soldier soldier(&playertexture, sf::Vector2u(8, 8), 0.15f, 150.0f);

	Missile missile(&missileTexture, 500.0f);
	Plane plane(&planeTexture, sf::Vector2u(4, 3), 0.15f, 300.0f);

	Bomb bomb(&bombTexture, 450.0f);
	Menu menu(window.getSize().x, window.getSize().y);
	PauseMenu Pausemenu(window.getSize().x, window.getSize().y);
	Explosion explosion(&ExplosionTexture, sf::Vector2u(5, 5), 0.15f, 130.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	Clock time;
	Clock stageTime;



	int hitcount = 0;

	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("bomb.wav"))
	{
		printf("Error\n");
	}

	sf::Sound bombSound;

	bombSound.setBuffer(buffer);

	sf::SoundBuffer collisionBuffer;

	if (!collisionBuffer.loadFromFile("collision.wav"))
	{
		printf("Error\n");
	}

	sf::Sound bombBlast;


	bombBlast.setBuffer(collisionBuffer);

	int state = menustate;
	state = gamestate;
	cout << state << endl;
	int bombflag = 0, bombdelay = 0;
	int soldierSideFlag = 1;
	//class soldier soldier1;
	vector<Soldier>::const_iterator soldierIter;
	vector<Soldier>soldierArray;
	vector<Missile>::const_iterator missileIter;
	vector<Missile>missileArray;
	int counter = 0;


	//soldier.body.setPosition(rand() % 1280, 610.0f);
	//missile.missilebody.setPosition(soldier.body.getPosition().x, 610.0f);
	//missileArray.push_back(missile);
	//soldier.body.setPosition(rand() % 1280, rand()%720);
	//soldierArray.push_back(soldier);
	//soldier.body.setPosition(rand() % 1280, 610.0f);

	//soldier.body.setPosition(rand() % 1280, rand()%720);
	//soldierArray.push_back(soldier);

	bool planeIsHit = false;
	//MenuMusic.play();
	int planeHitUpdate = 0;
	unsigned int gameStage = 1;
	bool changeLevel = true;
	int deadSoldierCount = 0;
	//STAGE FONT
	sf::Font stageFont;
	sf::Text stage;
	stageFont.loadFromFile("ClearSans.ttf");
	stage.setFont(stageFont);
	stage.setCharacterSize(50);
	stage.setFillColor(sf::Color::White);




	Font scoreFont;
	scoreFont.loadFromFile("ClearSans.ttf");
	Text score;
	int scoreVal = 0;
	Text scoreNumber;

	scoreNumber.setFont(scoreFont);
	scoreNumber.setCharacterSize(40);
	scoreNumber.setFillColor(sf::Color::Yellow);
	scoreNumber.setString(to_string(scoreVal));
	scoreNumber.setPosition(sf::Vector2f(1170.0f, 60.0f));

	score.setFont(scoreFont);
	score.setCharacterSize(40);
	score.setFillColor(sf::Color::Yellow);
	score.setString("Score");
	score.setPosition(sf::Vector2f(1040.0f, 60.0f));

	bool gameResponse = false;
}
