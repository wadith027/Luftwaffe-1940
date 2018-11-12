#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#define MAX_NUMBER_OF_ITEMS 4
using namespace sf;

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	//void mouseColorChange(int mouseCheck);
	int mouseCheck(sf::RenderWindow &window);
	int GetPressedItem() { return selectedItemIndex; }
	sf::Text menu[MAX_NUMBER_OF_ITEMS]; 
	int selectedItemIndex, lastItemIndex;
private:
	
	sf::Font font;
	 

};
 

