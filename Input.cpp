#include "Input.h"
#include "Textures.h"

GameState state = mainMenu;

GameState getGameState(void)
{
	return state;
}

void MainMenuButtonInteraction(sf::Sprite* sprites, sf::RenderWindow& window, sf::Vector2i mouse)
{
	if (mouse.x > 474.f && mouse.x < 948.f && mouse.y > 500.f && mouse.y < 580.f) //Hovering over Exit button
	{
		sprites[T_EXITBUTTON].setScale(0.9f, 0.9f);
		sprites[T_EXITBUTTON].setPosition(sf::Vector2f(498.0f, 504.f));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window.close();
		}
	}

	else
	{
		sprites[T_EXITBUTTON].setScale(1.0f, 1.0f);
		sprites[T_EXITBUTTON].setPosition(sf::Vector2f(474.0f, 500.f));
	}

	if (mouse.x > 474.f && mouse.x < 948.f && mouse.y > 400.f && mouse.y < 480.f) //Hovering over Options button
	{
		sprites[T_OPTIONSBUTTON].setScale(0.9f, 0.9f);
		sprites[T_OPTIONSBUTTON].setPosition(sf::Vector2f(498.0f, 404.f));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state = optionsMenu;
		}
	}

	else
	{
		sprites[T_OPTIONSBUTTON].setScale(1.0f, 1.0f);
		sprites[T_OPTIONSBUTTON].setPosition(sf::Vector2f(474.0f, 400.f));
	}

	if (mouse.x > 474.f && mouse.x < 948.f && mouse.y > 300.f && mouse.y < 380.f) //Hovering over Play button
	{
		sprites[T_PLAYBUTTON].setScale(0.9f, 0.9f);
		sprites[T_PLAYBUTTON].setPosition(sf::Vector2f(498.0f, 304.f));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state = play;
		}
	}

	else
	{
		sprites[T_PLAYBUTTON].setScale(1.0f, 1.0f);
		sprites[T_PLAYBUTTON].setPosition(sf::Vector2f(474.0f, 300.f));
	}
}

void MousePosition(sf::Sprite* sprites, sf::RenderWindow& window)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(window);

	if (state == mainMenu)
	{
		MainMenuButtonInteraction(sprites, window, mouse);
	}

	else if (state == optionsMenu)
	{
		if (mouse.x > 30 && mouse.x < 140 && mouse.y > 15 && mouse.y < 66)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				state = mainMenu;
				for (uint i = 0; i < 58; ++i)
				{
					sprites[T_OPTIONSBUTTON].setScale(1.f, 1.f);
					sprites[T_GAMELOGO].move(sf::Vector2f(0.0f, 10.0f));
					sprites[T_PLAYBUTTON].move(sf::Vector2f(0.f, 10.f));
					sprites[T_OPTIONSBUTTON].move(sf::Vector2f(0.f, 10.f));
					sprites[T_EXITBUTTON].move(sf::Vector2f(0.f, 10.f));

					window.clear();
					GameBackgroundAnimation(sprites, -1.f);
					window.draw(sprites[T_WIDEBG]);
					window.draw(sprites[T_GAMELOGO]);
					window.draw(sprites[T_PLAYBUTTON]);
					window.draw(sprites[T_OPTIONSBUTTON]);
					window.draw(sprites[T_EXITBUTTON]);
					window.display();
				}

				setOptionsClicked(true);
			}
		}
	}

	else if (state == dead)
	{

	}
}

void KeyboardInput(sf::Sprite* sprites)
{
	sf::Vector2f sPos = sprites[T_SPACESHIP].getPosition();
	static float yVelocity = 0.0f;

	if (getGameState() == play)
	{
		if (sPos.y <= 0.0f || sPos.y >= 800.0f - 168.f)
		{
			yVelocity = 0.0f;
			sprites[T_SPACESHIP].setPosition(sPos.x, (sPos.y <= 0.0f) ? 0.0f : 800.f - 168.f);
		}

		setVelocity( yVelocity, sPos.x, sPos.y);

		sprites[T_SPACESHIP].move(sf::Vector2f(0.0, yVelocity));
	}
}

void setVelocity(float& yV, float x, float y)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (yV != 0.f)
		{
			yV += (yV > 0.0f) ? (-0.1f) : (0.1f);
		}

		if (yV > -0.1f && yV < 0.1f)
		{
			yV = 0.0f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		yV -= 0.1f;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		yV += 0.1f;
	}
}