#include "PauseMenu.h"
using namespace sf;
using namespace std;


PauseMenu::PauseMenu(float width, float height)
{
	if (!font.loadFromFile("arcadefont.TTF"))
	{
		// handle error
	}

	Pausemenu[0].setFont(font);
	Pausemenu[0].setCharacterSize(50);
	Pausemenu[0].setFillColor(sf::Color::Red);
	Pausemenu[0].setString("Resume");
	Pausemenu[0].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 1));

	Pausemenu[1].setFont(font);
	Pausemenu[1].setCharacterSize(50);
	Pausemenu[1].setFillColor(sf::Color::Black);
	Pausemenu[1].setString("Save");
	Pausemenu[1].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 2));

	Pausemenu[2].setFont(font);
	Pausemenu[2].setCharacterSize(50);
	Pausemenu[2].setFillColor(sf::Color::Black);
	Pausemenu[2].setString("Restart");
	Pausemenu[2].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 3));

	Pausemenu[3].setFont(font);
	Pausemenu[3].setCharacterSize(50);
	Pausemenu[3].setFillColor(sf::Color::Black);
	Pausemenu[3].setString("Return to MainMenu");
	Pausemenu[3].setPosition(sf::Vector2f(width * 3 / 5, height / (MAX_NUMBER_OF_ITEMS + 2) * 4));

	selectedItemIndex = 0;
}


PauseMenu::~PauseMenu()
{
}

void PauseMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Pausemenu[i]);
	}
}

void PauseMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		Pausemenu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		Pausemenu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void PauseMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		Pausemenu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		Pausemenu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
int PauseMenu::mouseCheck(sf::RenderWindow &window) {

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		IntRect rect(Pausemenu[i].getPosition().x, Pausemenu[i].getPosition().y, 300, 50);

		if (rect.contains(Mouse::getPosition(window)))
		{
			lastItemIndex = selectedItemIndex;
			Pausemenu[selectedItemIndex].setFillColor(Color::Black);
			selectedItemIndex = i;
			Pausemenu[selectedItemIndex].setFillColor(Color::Red);
			if (Mouse::isButtonPressed(Mouse::Left)) return selectedItemIndex;
			//return -1;
		}


	}
	return -2;
}