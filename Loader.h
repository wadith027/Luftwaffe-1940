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
#include<fstream>
#include<stdio.h>
#include"Definitions.h"


using namespace std;
using namespace sf;
enum state
{
	menustate, gamestate, gameoverstate, pausestate,instuctionState

};
int deadSoldierCount = 0;
int planeHitUpdate = 0;
unsigned int gameStage = 1;
int deadanimation = 0;
int soldierFlag = 0, soldierdelay = 0;
float deltaTime = 0.0f;
int bombflag = 0, bombdelay = 0;
int soldierSideFlag = 1;
int counter = 0;
bool planeIsHit = false;
int hitcount = 0;





extern RenderWindow window;
sf::Texture missileTexture;
sf::Texture backgroundTexture1;
sf::Texture backgroundTexture2;
sf::Texture backgroundTexture3;
sf::Texture backgroundTexture4;
sf::Texture backgroundTexture5;
Texture fuelTextureOne;
Texture fuelTextureTwo;
Texture fuelTextureThree;
Texture fuelTextureFour;
Texture fuelTextureFive;

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
Texture playerTexture;
Texture instructionTexture;

sf::Sprite gamebackground1;
Sprite gamebackground2;
Sprite gamebackground3;
Sprite gamebackground4;
Sprite gamebackground5;
sf::Sprite menuBackground;
Sprite splash;
Sprite gameover;
Sprite instructions;

sf::Sprite lifeOne;
sf::Sprite lifeTwo;
sf::Sprite lifeThree;
sf::Sprite lifeFour;
sf::Sprite lifeFive;
sf::Font stageFont;
sf::Text stage;

sf::Sprite fuelOne;
sf::Sprite fuelTwo;
sf::Sprite fuelThree;
sf::Sprite fuelFour;
sf::Sprite fuelFive;
sf::Music InGameMusic;

sf::Music MenuMusic;
sf::SoundBuffer buffer;
sf::Sound bombSound;
sf::SoundBuffer collisionBuffer;
sf::Sound bombBlast;
vector<Soldier>::const_iterator soldierIter;
vector<Soldier>soldierArray;
vector<Missile>::const_iterator missileIter;
vector<Missile>missileArray;
Text fuelWarning;
Font warningFont;

Text damageWarning;
Font scoreFont;
Text score;
Text scoreNumber;
int scoreVal = 0;
Texture fuelIndicator;
sf::Sprite fuelInd;
Text scoreDisplay;
Text highscoreDisplay;
Text highscoreNumber;
Text saved;
Text stageNumber;



void Load()
{
	instructionTexture.loadFromFile("instructions.png");
	instructions.setTexture(instructionTexture);
	instructions.setTextureRect(sf::IntRect(BG_DIMENSIONS));

	lifeTextureOne.loadFromFile("life1.png");
	lifeTextureTwo.loadFromFile("life2.png");
	lifeTextureThree.loadFromFile("life3.png");
	lifeTextureFour.loadFromFile("life4.png");
	lifeTextureFive.loadFromFile("life5.png");

	fuelTextureOne.loadFromFile("fueltank1.png");
	fuelTextureTwo.loadFromFile("fueltank2.png");
	fuelTextureThree.loadFromFile("fueltank3.png");
	fuelTextureFour.loadFromFile("fueltank4.png");
	fuelTextureFive.loadFromFile("fueltank5.png");


	bombTexture.loadFromFile("bomb.png");
	gameoverTexture.loadFromFile("gameover.png");
	menuBackgroundTexture.loadFromFile("MenuBackground.png");
	planeTexture.loadFromFile("plane.png");
	tankTexture.loadFromFile("Tank.png");
	backgroundTexture1.loadFromFile("gameBackground1.png");
	backgroundTexture2.loadFromFile("gameBackground2.png");
	backgroundTexture3.loadFromFile("gameBackground3.png");
	backgroundTexture4.loadFromFile("gameBackground4.png");
	backgroundTexture5.loadFromFile("gameBackground5.png");
	turretTexture.loadFromFile("Turret.png");
	splashTexture.loadFromFile("splash.png");
	ExplosionTexture.loadFromFile("explosion.png");
	missileTexture.loadFromFile("missile.png");
	playerTexture.loadFromFile("sprite.png");


	fuelOne.setTexture(fuelTextureOne);
	fuelOne.setScale(FUEL_SCALE);
	fuelOne.setPosition(FUEL_POS);
	fuelTwo.setTexture(fuelTextureTwo);
	fuelTwo.setScale(FUEL_SCALE);
	fuelTwo.setPosition(FUEL_POS);
	fuelThree.setTexture(fuelTextureThree);
	fuelThree.setScale(FUEL_SCALE);
	fuelThree.setPosition(FUEL_POS);
	fuelFour.setTexture(fuelTextureFour);
	fuelFour.setScale(FUEL_SCALE);
	fuelFour.setPosition(FUEL_POS);
	fuelFive.setTexture(fuelTextureFive);
	fuelFive.setScale(FUEL_SCALE);
	fuelFive.setPosition(FUEL_POS);
	lifeOne.setTexture(lifeTextureOne);
	lifeOne.setScale(LIFE_SCALE);
	lifeOne.setPosition(LEFT_IND_X, 0);
	lifeTwo.setTexture(lifeTextureTwo);
	lifeTwo.setScale(LIFE_SCALE);
	lifeTwo.setPosition(LEFT_IND_X + 50, 0);
	lifeThree.setTexture(lifeTextureThree);
	lifeThree.setScale(LIFE_SCALE);
	lifeThree.setPosition(LEFT_IND_X + 100, 0);
	lifeFour.setTexture(lifeTextureFour);
	lifeFour.setScale(LIFE_SCALE);
	lifeFour.setPosition(LEFT_IND_X + 150, 0);
	lifeFive.setTexture(lifeTextureFive);
	lifeFive.setScale(LIFE_SCALE);
	lifeFive.setPosition(LEFT_IND_X + 200, 0);
	gameover.setTexture(gameoverTexture);
	gameover.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	splash.setTexture(splashTexture);
	splash.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	menuBackground.setTexture(menuBackgroundTexture);
	menuBackground.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	gamebackground1.setTexture(backgroundTexture1);
	gamebackground1.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	gamebackground2.setTexture(backgroundTexture2);
	gamebackground2.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	gamebackground3.setTexture(backgroundTexture3);
	gamebackground3.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	gamebackground4.setTexture(backgroundTexture4);
	gamebackground4.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	gamebackground5.setTexture(backgroundTexture5);
	gamebackground5.setTextureRect(sf::IntRect(BG_DIMENSIONS));
	MenuMusic.openFromFile("menumusic.ogg");
	InGameMusic.openFromFile("ingamemusic.ogg");

	scoreNumber.setFont(scoreFont);
	scoreNumber.setCharacterSize(40);
	scoreNumber.setFillColor(sf::Color::Yellow);
	scoreNumber.setString(to_string(scoreVal));
	scoreNumber.setPosition(sf::Vector2f(LEFT_IND_X + 130, 60.0f));

	score.setFont(scoreFont);
	score.setCharacterSize(40);
	score.setFillColor(sf::Color::Yellow);
	score.setString("Score");
	score.setPosition(sf::Vector2f(LEFT_IND_X, 60.0f));


	stageFont.loadFromFile("arcadefont.TTF");
	stage.setFont(stageFont);
	stage.setCharacterSize(50);
	stage.setFillColor(sf::Color::White);
	stage.setString("Stage ");
	stage.setPosition(550.0f, 250.0f);



	warningFont.loadFromFile("arcadefont.ttf");
	fuelWarning.setFont(warningFont);
	fuelWarning.setCharacterSize(40);
	fuelWarning.setFillColor(sf::Color::Red);
	fuelWarning.setString("FUEL SHORTAGE!");
	fuelWarning.setPosition(sf::Vector2f(475.0f, 0.0f));



	damageWarning.setFont(warningFont);
	damageWarning.setCharacterSize(40);
	damageWarning.setFillColor(sf::Color::Red);
	damageWarning.setString("DAMAGE CRITICAL");
	damageWarning.setPosition(sf::Vector2f(850.0f, 0.0f));
	buffer.loadFromFile("bomb.wav");
	bombSound.setBuffer(buffer);
	collisionBuffer.loadFromFile("collision.wav");
	bombBlast.setBuffer(collisionBuffer);

	fuelIndicator.loadFromFile("fuelindicator.png");

	fuelInd.setTexture(fuelIndicator);
	fuelInd.setScale(0.07f, 0.07f);
	fuelInd.setPosition(1130, 130);


	scoreDisplay.setFont(warningFont);
	scoreDisplay.setCharacterSize(40);
	scoreDisplay.setFillColor(sf::Color::Yellow);
	scoreDisplay.setString("Score ");
	scoreDisplay.setPosition(sf::Vector2f(475.0f, 260.0f));


	highscoreDisplay.setFont(warningFont);
	highscoreDisplay.setCharacterSize(40);
	highscoreDisplay.setFillColor(sf::Color::Yellow);
	highscoreDisplay.setString("Best ");
	highscoreDisplay.setPosition(sf::Vector2f(475.0f, 160.0f));


	highscoreNumber.setFont(warningFont);
	highscoreNumber.setCharacterSize(40);
	highscoreNumber.setFillColor(sf::Color::Yellow);
	highscoreNumber.setPosition(sf::Vector2f(605.0f, 160.0f));

	saved.setFont(warningFont);
	saved.setCharacterSize(50);
	saved.setFillColor(sf::Color::Yellow);
	saved.setPosition(sf::Vector2f(605.0f, 30.0f));
	saved.setString("SAVED");
	stageNumber.setFont(stageFont);
	stageNumber.setCharacterSize(50);
	stageNumber.setFillColor(sf::Color::White);
	stageNumber.setPosition(710.0f, 250.0f);

}

