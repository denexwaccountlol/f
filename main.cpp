#include <SFML/Graphics.hpp>
#include <ctime>
#include "Textures.h"
#include "Input.h"
#include "Bullet.h"
#include "Text.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1422, 800), "Space Shooter", sf::Style::Close);
	sf::Event event;
	sf::Font pixelFont;
	sf::Texture textures[T_SIZE];
	sf::Text texts[TEXSIZ];
	sf::Sprite sprites[T_SIZE];
	std::clock_t shotTime = 0.5;
	Bullet bullets[BULLET_LIM];

	pixelFont.loadFromFile("pixelFont.ttf");
	LoadTextures(textures);
	InitSprites(sprites, textures);
	InitText(texts, pixelFont);
	//SetScoreText(texts, BULLET_LIM, getBulletsLeft(bullets, BULLET_LIM));
	
	for (uint i = 0; i < TEXSIZ; ++i)
	{
		texts[i].setFont(pixelFont);
	}

	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (((double)(clock() - shotTime) / CLOCKS_PER_SEC) > 0.2f)
			{
				Shoot(bullets, BULLET_LIM, sprites[T_SPACESHIP]);
				shotTime = clock();
			}
		}

		SetScoreText(texts, BULLET_LIM, getBulletsLeft(bullets, BULLET_LIM));
		MousePosition(sprites, window);
		KeyboardInput(sprites);

		window.clear();
		Draw(sprites, window);
		UpdateBullets(bullets, window, BULLET_LIM);
		DisplayText(texts, window);

		if (getGameState() == play)
		{
			window.draw(sprites[T_SPACESHIP]);
		}

		window.display();
	}

	return 0;
}