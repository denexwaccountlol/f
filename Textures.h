#pragma once

#define T_SIZE 9

#define T_WIDEBG 0
#define T_PLAYBUTTON 1
#define T_OPTIONSBUTTON 2
#define T_EXITBUTTON 3
#define T_BACKBUTTON 4
#define T_GAMELOGO 5
#define T_OPTIONSLOGO 6
#define T_SPACESHIP 7
#define T_FULLHEART 8

#include <SFML/Graphics.hpp>

typedef unsigned int uint;

void LoadTextures(sf::Texture* textures);
void InitSprites(sf::Sprite* sprites, sf::Texture* textures);
void Draw(sf::Sprite* sprites, sf::RenderWindow& window);
void setOptionsClicked(bool c);
void GameBackgroundAnimation(sf::Sprite* sprites, float speed);