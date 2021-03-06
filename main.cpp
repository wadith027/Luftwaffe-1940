#include"Loader.h"




int main()
{
	srand(time(0));

	RenderWindow window(sf::VideoMode(1280, 720), "Luftwaffe 1940", sf::Style::Close | sf::Style::Resize);	
	//RenderWindow window(sf::VideoMode(SCREEN_DIM), "Luftwaffe 1940", sf::Style::Close | sf::Style::Fullscreen);
	Load();
	int deadanimation = 0;
	int soldierFlag = 0, soldierdelay = 0;
	Soldier soldier(&playerTexture, sf::Vector2u(8, 8), 0.15f, 200.0f);
	Missile missile(&missileTexture, 500.0f);
	Plane plane(&planeTexture, sf::Vector2u(4, 3), 0.15f, 300.0f);
	Bomb bomb(&bombTexture, 450.0f);
	Menu menu(window.getSize().x, window.getSize().y);
	PauseMenu Pausemenu(window.getSize().x, window.getSize().y);
	Explosion explosion(&ExplosionTexture, sf::Vector2u(5, 5), 5.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	Clock time;
	Clock stageTime;
	int hitcount = 0;
	int state = menustate;
	int bombflag = 0, bombdelay = 0;
	int soldierSideFlag = 1;
	int counter = 0;
	bool planeIsHit = false;
	MenuMusic.play();
	int planeHitUpdate = 0;
	unsigned int gameStage = 1;
	bool changeLevel = true;
	int deadSoldierCount = 0;
	


	fstream scoreRead;
	int bestScore;
	scoreRead.open("highscore.txt", fstream::in);
	scoreRead>>bestScore;
	cout <<"best Score"<< bestScore << endl;
	scoreFont.loadFromFile("arcadefont.TTF");
	int scoreVal = 0;
	Clock gameTime;
	Clock warnTime;
	Clock saveTime;
	int gTime=0;
	bool isPlaneDead = false;
	int pauseGameTime;

	bool gameResponse = false;
	int mouseReturn;
	while (window.isOpen())
	{
		if (gameTime.getElapsedTime().asSeconds() >= 1 && state ==gamestate)
		{
			gameTime.restart().asSeconds();
			gTime++;
			cout <<"GameTime = "<< gTime << endl;
		}
		deltaTime = clock.restart().asSeconds();
		if (state == menustate)
		{
			if (time.getElapsedTime().asSeconds() <= SPLASH_DURATION)
			{

				window.draw(splash);
				window.display();
			}
			else
			{

				sf::Event event;
				while (window.pollEvent(event)) {

					if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left))
					{
						if (Mouse::isButtonPressed(Mouse::Left))
							cout << "You have click on " << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
							mouseReturn = menu.mouseCheck(window);										
							if (mouseReturn == 0) {
								cout << "New Game button has been Pressed" << endl;
								MenuMusic.stop();
								InGameMusic.play();
								state = gamestate;
								RESET
							}
							if (mouseReturn == 1) {

								cout << "Load button has been Pressed" << endl;
								LOAD

							}
							if (mouseReturn == 2)
							{
								cout << "Instruction" << endl;
								state = instuctionState;
							}
							if (mouseReturn == 3) {
								cout << "exit pressed" << endl;
								exit(0);
							}
						

					}


					if (event.type == event.Closed)
						window.close();
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:
						{
							if (menu.GetPressedItem() == 0)
							{
								std::cout << "Play button has been pressed" << std::endl;
								state = gamestate;
								RESET
								MenuMusic.stop();
								InGameMusic.play();
							}
							if (menu.GetPressedItem() == 1)
							{
								std::cout << "Load button has been pressed" << std::endl;
								LOAD
							}
							if (menu.GetPressedItem() == 2)
							{
								cout << "Instruction button has been pressed" << endl;
								state = instuctionState;
							}
							
							if (menu.GetPressedItem() == 3)
							{
								cout << "Exit button has been pressed" << endl;
								exit(0);
							}
							break;
						}
						}

						break;
					case sf::Event::Closed:
						window.close();

						break;

					}

				}

				window.draw(menuBackground);
				menu.draw(window);
				window.display();
			}
		}
		else if (state == gamestate)
		{
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == event.Closed)
					window.close();
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Key::Escape:
						state = pausestate;
						InGameMusic.stop();
						pauseGameTime = gTime;
						break;
					case sf::Keyboard::Key::Y:
						soldier.body.setPosition(rand() % 1280, 610.0f);						
						soldierArray.push_back(soldier);
						break;

					}
				}
			}

			//bomb drop
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && bomb.bombbody.getPosition().y <= 40.0f &&gameResponse == true)
			{

				bomb.bombbody.setPosition(plane.planeBody.getPosition().x + 100.3f, 41.0f);
				bombSound.play();
			}
			 
			//soldier adding 

			if (changeLevel == true && stageTime.getElapsedTime().asSeconds() > 3)
			{

				for (int i = 0;i < gameStage * SOLDIER_PER_STAGE - deadSoldierCount;i++)
				{
					soldier.body.setPosition((rand() % 1280 + rand() % 1280 + rand() % 1280 + rand() % 1280) % 1280, 610.0f);

					soldierArray.push_back(soldier);
					missileArray.push_back(missile);
				}
			}
			if (stageTime.getElapsedTime().asSeconds() > 3)
				changeLevel = false;
			//game level handler
			if (deadSoldierCount == gameStage * SOLDIER_PER_STAGE)
			{
				gameStage++;
				deadSoldierCount = 0;

				changeLevel = true;
				stageTime.restart().asSeconds();
			}
			if (gameStage > MAX_STAGE) state = gameoverstate;

			if (bomb.bombbody.getPosition().y > 40)
			{
				bomb.Update(deltaTime);
			}

			if (bomb.bombbody.getPosition().y > 720.0f || stageTime.getElapsedTime().asSeconds() < 3)
			{
				bomb.bombbody.setPosition(0.0f, -100.0f);
			}
			float planey = 0.0f;
			//missile hit
			counter = 0;
			for (missileIter = missileArray.begin();missileIter != missileArray.end();missileIter++)
			{
				if (missileArray[counter].missilebody.getPosition().y <= 100.0f && missileArray[counter].missilebody.getPosition().y >= 10.0f && (missileArray[counter].missilebody.getPosition().x <= (plane.planeBody.getPosition().x + 200.6f)) && (missileArray[counter].missilebody.getPosition().x >= plane.planeBody.getPosition().x))
				{
					planeIsHit = true;
					bombBlast.play();
					hitcount++;
					missileArray[counter].missilebody.setPosition(soldierArray[counter].body.getPosition().x + 50.0f, 830.0f);
					printf("Plane Hit Count= %d\n", hitcount);
					break;
				}
				counter++;
			}

			if (planeIsHit == true && isPlaneDead == false)
			{
				plane.UpdateHit(deltaTime);
				planeHitUpdate++;
			}
			else {
				if (hitcount >= PLANE_LIFE)
				{
					isPlaneDead = true;
					plane.UpdateDead(deltaTime);

					deadanimation++;
					if (deadanimation >= 250)state = gameoverstate;

				}
				else
					plane.Update(deltaTime);
			}
			if (planeHitUpdate >= 100)
			{
				planeIsHit = false;
				planeHitUpdate = 0;
			}
			BG_DRAW
			if(stageTime.getElapsedTime().asSeconds() > 3)bomb.Draw(window);
			window.draw(score);	 
			window.draw(scoreNumber);
			LIFE_DRAW
			FUEL_DRAW
			if (gameTime.getElapsedTime().asSeconds() >= 150)
			state = gameoverstate;
			window.draw(fuelInd);

			//Stage Draw

			if (stageTime.getElapsedTime().asSeconds() < 4)
			{
				stageNumber.setString(to_string(gameStage));
				TEXT_BLINK(stageNumber)				
				TEXT_BLINK(stage)
				gameResponse = false;
			}
			else gameResponse = true;
			plane.Draw(window);
			counter = 0;
			if (gameResponse == true)
			{
				for (soldierIter = soldierArray.begin(); soldierIter != soldierArray.end();soldierIter++)
				{
					window.draw(soldierArray[counter].body);
					if (counter % 2 == 0)soldierArray[counter].updateMoveRight(deltaTime);
					else soldierArray[counter].updateMoveLeft(deltaTime);
					if (soldierArray[counter].body.getPosition().x >= plane.planeBody.getPosition().x - 10 && soldierArray[counter].body.getPosition().x <= plane.planeBody.getPosition().x + 10 && missile.isfire == false)
					{
						if (missileArray[counter].missilebody.getPosition().y <= 720);
						else
							missileArray[counter].missilebody.setPosition(soldierArray[counter].body.getPosition().x + 50, 530.0f);
						missileArray[counter].isfire = true;

					}

					counter++;
				}
			}
			
			//missile fire

			counter = 0;
			for (missileIter = missileArray.begin(); missileIter != missileArray.end();missileIter++)
			{
				if (missileArray[counter].isfire == true)
				{
					if (missileArray[counter].missilebody.getPosition().y < 600)window.draw(missileArray[counter].missilebody);
					if (plane.planeBody.getPosition().x + 125.0f < missileArray[counter].missilebody.getPosition().x && missileArray[counter].missilebody.getPosition().y <= 600)
						missileArray[counter].UpdateLeft(deltaTime);
					else if (plane.planeBody.getPosition().x + 125.0f > missileArray[counter].missilebody.getPosition().x&& missileArray[counter].missilebody.getPosition().y <= 600)
						missileArray[counter].UpdateRight(deltaTime);
					else missileArray[counter].Update(deltaTime);

				}
				if (missileArray[counter].missilebody.getPosition().y < 0)
				{
					missileArray[counter].isfire = false;
					missileArray[counter].missilebody.setPosition(0, 730);
				}
				counter++;
			}
			//missile hit



			//soldier dead

			counter = 0;
			for (soldierIter = soldierArray.begin(); soldierIter != soldierArray.end();soldierIter++)
			{
				//if (bomb.bombbody.getGlobalBounds().intersects(soldierArray[counter].body.getGlobalBounds()))
				if (bomb.bombbody.getPosition().y >= 620 && bomb.bombbody.getGlobalBounds().intersects(soldierArray[counter].body.getGlobalBounds()))
				{
					soldierArray[counter].soldierAlive = false;


				}
				counter++;
			}

			//delete soldier
			counter = 0;
			for (soldierIter = soldierArray.begin(); soldierIter != soldierArray.end();soldierIter++)
			{
				if (soldierArray[counter].soldierAlive == false)
				{
					deadSoldierCount++;
					
					
					
					cout << "Dead Soldier Count = " << deadSoldierCount << endl;
					soldierArray.erase(soldierIter);
						scoreVal = scoreVal + 5;
					scoreNumber.setString(to_string(scoreVal));
					cout << "Score =" << scoreVal << endl;
					break;
				}
				counter++;
			}

			if (bomb.bombbody.getPosition().y >= 610.0f && bomb.bombbody.getPosition().y <= 720.0f)
			{
				bombflag = 0;
				bombdelay = 0;
				explosion.explosionBody.setPosition(bomb.bombbody.getPosition().x - 90.0f, 570.0f);

				if (bombflag == 0)
				{
					explosion.Draw(window);
					explosion.Update(deltaTime);
				}
				if (bombdelay >= 300)
				{
					bombflag = 1;
					explosion.explosionBody.setPosition(100.0f, 810.0f);
				}
				bombdelay++;
			}
			window.display();

		}
		else if (state == gameoverstate)
		{
			Event event;

			while (window.pollEvent(event))
			{
				if (event.type == event.Closed)
					window.close();
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Space:
					{
						state = menustate;
						MenuMusic.play();
						InGameMusic.stop();
						RESET
						break;
					}

					}

				}
			}

			//highScore

			if (scoreVal > bestScore)
			{
				bestScore = scoreVal;
				fstream scoreOut;
				scoreOut.open("highscore.txt", fstream::in | fstream::out | fstream::trunc);
				scoreOut << bestScore << endl;				
			}
			
			window.draw(gameover);
			window.draw(scoreDisplay);
			scoreNumber.setPosition(605.0f, 260.0f);
			window.draw(scoreNumber);
			highscoreNumber.setString(to_string(bestScore));


			if (scoreVal == bestScore)
			{
				TEXT_BLINK(highscoreDisplay)
					TEXT_BLINK(highscoreNumber)
			}
			else
			{
				window.draw(highscoreDisplay);
				window.draw(highscoreNumber);
			}
			window.display();
		}
		else if (state == pausestate)
		{
			bombSound.stop();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::MouseMoved || Mouse::isButtonPressed(Mouse::Left))
				{
					if (Mouse::isButtonPressed(Mouse::Left))
						cout << "You have click on " << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
					mouseReturn = Pausemenu.mouseCheck(window);
					
					if (mouseReturn == 0)
					{
						state = gamestate;
					}
						if (mouseReturn == 1)
						{
							cout << "save" << endl;
							SAVE
								saveTime.restart().asSeconds();
						
						}
						if (mouseReturn == 2)
						{
							state = gamestate;
							RESET
							InGameMusic.stop();
							InGameMusic.play();
						}
						if (mouseReturn == 3)
						{
							cout << "exit pressed" << endl;
							state = menustate;
							InGameMusic.stop();
							MenuMusic.play();
							RESET
						}
				}



				if (event.type == event.Closed)
					window.close();
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						Pausemenu.MoveUp();
						break;

					case sf::Keyboard::Down:
						Pausemenu.MoveDown();
						break;

					case sf::Keyboard::Return:

					{
						if (Pausemenu.GetPressedItem() == 0)
						{
							state = gamestate;
							InGameMusic.play();
							gTime = pauseGameTime;

						}
						if (Pausemenu.GetPressedItem() == 1)
						{
						    SAVE
							saveTime.restart().asSeconds();
						}
						if (Pausemenu.GetPressedItem() == 2)
						{
							state = gamestate;
							RESET
							InGameMusic.stop();
							InGameMusic.play();
						}
						if (Pausemenu.GetPressedItem() == 3)
						{
							cout << "exit pressed" << endl;
							state = menustate;
							InGameMusic.stop();
							MenuMusic.play();
							RESET
						}

						break;
					}


					}

					break;
				case sf::Event::Closed:
					window.close();

					break;

				}
			}
			window.draw(menuBackground);
			if(saveTime.getElapsedTime().asSeconds()<3)TEXT_BLINK(saved)
			Pausemenu.draw(window);
			window.display();
		}
		else if (state == instuctionState)
		{
			Event event;
			while (window.pollEvent(event))
				{
				switch (event.type)
					{
						case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Escape:
							state=menustate;
							break;
						}
					}
				}
		
			window.draw(instructions);
			window.display();
		}
	}
	window.clear();
	return 0;
}


