#include "Menu.h"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;
RenderWindow window;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arcadefont.TTF"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(50);
	menu[0].setFillColor(sf::Color::Red);
	
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width*3/5, height / (MAX_NUMBER_OF_ITEMS + 2) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(50);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Load");
	menu[1].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 2));

	menu[2].setFont(font);
	menu[2].setCharacterSize(50);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Instruction");
	menu[2].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 3));

	menu[3].setFont(font);
	menu[3].setCharacterSize(50);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 4));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
/*int Menu::mouseCheck(sf ::RenderWindow &window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		IntRect rect(menu[i].getPosition().x - (menu[i].getGlobalBounds().width) / 2, menu[i].getPosition().y - (menu[i].getGlobalBounds().height) / 2, menu[i].getGlobalBounds().width, menu[i].getGlobalBounds().height);
		if (rect.contains(Mouse::getPosition(window))) {
			lastItemIndex = selectedItemIndex;
			menu[selectedItemIndex].setFillColor(Color::Black);			 
			selectedItemIndex = i;
			menu[selectedItemIndex].setFillColor(Color::Red);			 
			if (Mouse::isButtonPressed(Mouse::Left)) return selectedItemIndex;
			return -1;
		}
	}
	return -2;
}*/
int Menu::mouseCheck(sf::RenderWindow &window) {
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		IntRect rect(menu[i].getPosition().x, menu[i].getPosition().y, 300,50 );
		 
		if(rect.contains(Mouse::getPosition(window)))
		 {
			 lastItemIndex = selectedItemIndex;
			 menu[selectedItemIndex].setFillColor(Color::Black);
			 selectedItemIndex = i;
			 menu[selectedItemIndex].setFillColor(Color::Red);
			 if (Mouse::isButtonPressed(Mouse::Left)) return selectedItemIndex;
			 //return -1;
		 }
	
	
	}
	return -2;
}
 