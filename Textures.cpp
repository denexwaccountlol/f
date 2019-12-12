#include "Textures.h"
#include "Input.h"

bool optionsClicked = true;

void LoadTextures(sf::Texture* textures)
{
	textures[T_WIDEBG].loadFromFile("Textures\\wide_space_bg.png");
	textures[T_PLAYBUTTON].loadFromFile("Textures\\PlayButton.png");
	textures[T_OPTIONSBUTTON].loadFromFile("Textures\\OptionsButton.png");
	textures[T_EXITBUTTON].loadFromFile("Textures\\ExitButton.png");
	textures[T_BACKBUTTON].loadFromFile("Textures\\BackButton.png");
	textures[T_GAMELOGO].loadFromFile("Textures\\GameLogo.png");
	textures[T_OPTIONSLOGO].loadFromFile("Textures\\OptionsLogo.png");
	textures[T_SPACESHIP].loadFromFile("Textures\\spaceship.png");
	textures[T_FULLHEART].loadFromFile("Textures\\fullheart.png");
}

void InitSprites(sf::Sprite* sprites, sf::Texture* textures)
{
	sprites[T_WIDEBG].setTexture(textures[T_WIDEBG]);
	sprites[T_WIDEBG].setScale(sf::Vector2f(0.740625f, 0.741f));
	sprites[T_PLAYBUTTON].setTexture(textures[T_PLAYBUTTON]);
	sprites[T_PLAYBUTTON].setPosition(sf::Vector2f(474.0f, 300.0f));
	sprites[T_OPTIONSBUTTON].setTexture(textures[T_OPTIONSBUTTON]);
	sprites[T_OPTIONSBUTTON].setPosition(sf::Vector2f(474.0f, 400.0f));
	sprites[T_EXITBUTTON].setTexture(textures[T_EXITBUTTON]);
	sprites[T_EXITBUTTON].setPosition(sf::Vector2f(474.0f, 500.f));
	sprites[T_BACKBUTTON].setTexture(textures[T_BACKBUTTON]);
	sprites[T_GAMELOGO].setTexture(textures[T_GAMELOGO]);
	sprites[T_GAMELOGO].setPosition(sf::Vector2f(334.5f, 150.f));
	sprites[T_OPTIONSLOGO].setTexture(textures[T_OPTIONSLOGO]);
	sprites[T_OPTIONSLOGO].setPosition(sf::Vector2f(515.f, 150.f));
	sprites[T_SPACESHIP].setTexture(textures[T_SPACESHIP]);
	sprites[T_SPACESHIP].setScale(sf::Vector2f(1.f, 1.f));
	sprites[T_SPACESHIP].setPosition(sf::Vector2f(100.f, 270.f));
	sprites[T_FULLHEART].setTexture(textures[T_FULLHEART]);
	sprites[T_FULLHEART].setScale(sf::Vector2f(2.0f, 2.0f));
	sprites[T_FULLHEART].setPosition(sf::Vector2f(1000.f, 10.f));
}

void setOptionsClicked(bool c)
{
	optionsClicked = c;
}

void Draw(sf::Sprite* sprites, sf::RenderWindow& window)
{
	GameState state = getGameState();

	if (state == mainMenu)
	{
		GameBackgroundAnimation(sprites, -1.0);
		window.draw(sprites[T_WIDEBG]);
		window.draw(sprites[T_PLAYBUTTON]);
		window.draw(sprites[T_OPTIONSBUTTON]);
		window.draw(sprites[T_EXITBUTTON]);
		window.draw(sprites[T_GAMELOGO]);
	}

	else if (state == optionsMenu)
	{
		GameBackgroundAnimation(sprites, -1.0);
		if (optionsClicked)
		{
			sprites[T_OPTIONSBUTTON].setPosition(sf::Vector2f(474.f, 400.f));

			for (uint i = 0; i < 58; ++i)
			{
				sprites[T_OPTIONSBUTTON].setScale(1.f, 1.f);
				sprites[T_GAMELOGO].move(sf::Vector2f(0.0f, -10.0f));
				sprites[T_PLAYBUTTON].move(sf::Vector2f(0.f, -10.f));
				sprites[T_OPTIONSBUTTON].move(sf::Vector2f(0.f, -10.f));
				sprites[T_EXITBUTTON].move(sf::Vector2f(0.f, -10.f));

				window.clear();
				GameBackgroundAnimation(sprites, -1.f);
				window.draw(sprites[T_WIDEBG]);
				window.draw(sprites[T_GAMELOGO]);
				window.draw(sprites[T_PLAYBUTTON]);
				window.draw(sprites[T_OPTIONSBUTTON]);
				window.draw(sprites[T_EXITBUTTON]);
				window.display();
			}
			optionsClicked = false;
		}

		window.draw(sprites[T_WIDEBG]);
		window.draw(sprites[T_OPTIONSLOGO]);
		window.draw(sprites[T_BACKBUTTON]);
	}

	else if (state == play)
	{
		GameBackgroundAnimation(sprites, -5.0);
		window.draw(sprites[T_WIDEBG]);
		
		for (uint i = 1; i <= 3; ++i)
		{
			window.draw(sprites[T_FULLHEART]);
			sprites[T_FULLHEART].setPosition(1200.f - 35.f * i * 2, 15.f);
		}
	}

	else if (state == dead)
	{
		window.draw(sprites[T_WIDEBG]);

		for (uint i = 1; i <= 3; ++i)
		{
			window.draw(sprites[T_FULLHEART]);
			sprites[T_FULLHEART].setPosition(1200.f - 35.f * i * 2, 15.f);
		}
	}
}

void GameBackgroundAnimation(sf::Sprite* sprites, float speed)
{
	sf::Vector2f bgpos = sprites[T_WIDEBG].getPosition();

	if (bgpos.x < (-1421.f))
	{
		sprites[T_WIDEBG].setPosition(sf::Vector2f(0.0f, 0.0f));
	}

	else
	{
		sprites[T_WIDEBG].move(sf::Vector2f(speed, 0.0f));
	}
}