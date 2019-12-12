#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum GameState
{
	mainMenu,
	optionsMenu,
	play,
	dead
};

void setVelocity(float& yV, float x, float y);
void MainMenuButtonInteraction(sf::Sprite* sprites, sf::RenderWindow& window, sf::Vector2i mouseCoords);
void MousePosition(sf::Sprite* sprites, sf::RenderWindow& window);
void KeyboardInput(sf::Sprite* sprites);
GameState getGameState(void);