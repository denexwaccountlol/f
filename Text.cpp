#include "Text.h"

void InitText(sf::Text* texts, sf::Font font)
{
	texts[AMMO].setCharacterSize(48);
	texts[AMMO].setPosition(sf::Vector2f((BULLET_LIM >= 10 && BULLET_LIM < 100) ? 1250.f : 1300.f, 10.0f));
	texts[GAMEOVER].setCharacterSize(120);
	texts[GAMEOVER].setString("GAME OVER");
	texts[GAMEOVER].setPosition(sf::Vector2f(400.f, 300.f));
	texts[RETRY].setCharacterSize(48);
	texts[RETRY].setString("RETRY");
	texts[RETRY].setPosition(sf::Vector2f(650.f, 430.f));
	texts[MAINMENU].setCharacterSize(48);
	texts[MAINMENU].setString("MAIN MENU");
	texts[MAINMENU].setPosition(sf::Vector2f(590.f, 500.f));
}

void SetScoreText(sf::Text* text, uint bMax, uint bLeft)
{
	char buf[20];
	sprintf(buf, "%d/%d", bLeft, bMax);
	text[AMMO].setString(buf);
}

void DisplayText(sf::Text* texts, sf::RenderWindow& window)
{
	GameState state = getGameState();

	if (state == play)
	{
		window.draw(texts[AMMO]);
	}

	if (state == dead)
	{
		window.draw(texts[AMMO]);
		window.draw(texts[GAMEOVER]);
		window.draw(texts[RETRY]);
		window.draw(texts[MAINMENU]);
	}
}