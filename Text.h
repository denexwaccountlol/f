#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define TEXSIZ 4

#define AMMO 0
#define GAMEOVER 1
#define MAINMENU 2
#define RETRY 3

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Bullet.h"

typedef unsigned int uint;

void InitText(sf::Text* texts, sf::Font font);
void DisplayText(sf::Text* texts, sf::RenderWindow& window);
void SetScoreText(sf::Text* text, uint bMax, uint bLeft);