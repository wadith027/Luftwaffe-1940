#pragma once
#define PLANE_LIFE 5
#define SOLDIER_PER_STAGE 3
#define MAX_STAGE 5
#define SPLASH_DURATION 4
#define FUEL_SCALE 0.08f,0.08f
#define LIFE_SCALE 0.04f, 0.04f
#define LEFT_IND_X 1030.0f
#define FUEL_POS 1030.0f, 100.0f
#define BG_DIMENSIONS 0, 0, 1280, 720
#define SCREEN_DIM 1920,1080

#define TEXT_BLINK(text) {\
    int flashTime = gameTime.getElapsedTime().asMilliseconds();\
    if ((flashTime / 200) % 2 == 0)\
        window.draw(text);\
}
#define RESET {\
    plane.planeBody.setPosition(0.0f, 10.0f);\
	gTime=0;\
    hitcount = 0;\
    soldierFlag = 0;\
    soldierSideFlag = 1;\
    scoreVal = 0;\
    scoreNumber.setString(to_string(scoreVal));\
    stageTime.restart().asSeconds();\
    gameTime.restart().asSeconds();\
    warnTime.restart().asSeconds();\
    counter = 0;\
    soldierArray.clear();\
    missileArray.clear();\
    deadanimation = 0;\
    planeHitUpdate = 0;\
    changeLevel = true;\
    gameStage = 1;\
    deadSoldierCount = 0;\
    isPlaneDead = false;\
    scoreNumber.setPosition(sf::Vector2f(LEFT_IND_X+130, 60.0f));\
    plane.faceRight = true;\
}	


#define LIFE_DRAW {\
\
if (hitcount == 0) {\
	window.draw(lifeOne);\
	window.draw(lifeTwo);\
	window.draw(lifeThree);\
	window.draw(lifeFour);\
	window.draw(lifeFive);\
}\
else if (hitcount == 1) {\
	window.draw(lifeTwo);\
	window.draw(lifeThree);\
	window.draw(lifeFour);\
	window.draw(lifeFive);\
}\
else if (hitcount == 2) {\
	window.draw(lifeThree);\
	window.draw(lifeFour);\
	window.draw(lifeFive);\
}\
else if (hitcount == 3) {\
	window.draw(lifeFour);\
	window.draw(lifeFive);\
	TEXT_BLINK(damageWarning)\
}\
else if (hitcount == 4) {\
	window.draw(lifeFive);\
	TEXT_BLINK(damageWarning)\
}\
}

#define FUEL_DRAW {\
if (gTime < 30)\
{\
	window.draw(fuelFive);\
}\
if (gTime >= 30 && gTime < 60)\
	window.draw(fuelFour);\
if (gTime >= 60 && gTime < 90)\
	window.draw(fuelThree);\
if (gTime >= 90 && gTime < 120)\
{\
	window.draw(fuelTwo);\
	TEXT_BLINK(fuelWarning)\
}\
if (gTime >= 120 && gTime < 150)\
{\
	window.draw(fuelOne);\
	TEXT_BLINK(fuelWarning)\
}\
}
#define SAVE {\
    std::fstream writeFile;\
    writeFile.open("savedFile.txt", fstream::in | fstream::out | fstream::trunc);\
    int n = plane.planeBody.getPosition().x;\
    writeFile << n << endl;;\
    writeFile << hitcount << endl;\
    writeFile << scoreVal << endl;\
    writeFile << changeLevel << endl;\
    writeFile << gameStage << endl;\
    writeFile << deadSoldierCount << endl;\
    writeFile << isPlaneDead << endl;\
	writeFile << pauseGameTime<<endl;\
	writeFile << plane.faceRight<<endl;\
    writeFile.close();\
}
#define BG_DRAW {\
if (gameStage == 1)window.draw(gamebackground1);\
if (gameStage == 2)window.draw(gamebackground2);\
if (gameStage == 3)window.draw(gamebackground3);\
if (gameStage == 4)window.draw(gamebackground4);\
if (gameStage >= 5)window.draw(gamebackground5);\
}


 
#define LOAD {\
state = gamestate;\
scoreNumber.setPosition(sf::Vector2f(LEFT_IND_X + 130, 60));\
MenuMusic.stop();\
InGameMusic.play();\
std::fstream readFile;\
int n;\
float gTIme;\
int i = 0;\
readFile.open("savedFile.txt", fstream::in);\
i = 0;\
readFile >> n >> hitcount >> scoreVal >> changeLevel >> gameStage >> deadSoldierCount >> isPlaneDead>>gTime>>plane.faceRight;\
cout << n << endl << hitcount << endl << scoreVal << endl << changeLevel << endl << gameStage << endl << deadSoldierCount << endl << isPlaneDead << endl;\
plane.planeBody.setPosition(n, 10);\
changeLevel = true;\
soldierArray.clear();\
missileArray.clear();\
scoreNumber.setString(to_string(scoreVal));\
readFile.close();\
}
