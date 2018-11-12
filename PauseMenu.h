#pragma once

#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 4
class PauseMenu
{

public:
	PauseMenu(float width, float height);
	~PauseMenu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int mouseCheck(sf::RenderWindow &window);
	int GetPressedItem() { return selectedItemIndex; }
	int selectedItemIndex, lastItemIndex;
private:
	//int selectedItemIndex;
	sf::Font font;
	sf::Text Pausemenu[MAX_NUMBER_OF_ITEMS];

};

