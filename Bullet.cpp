#include "Bullet.h"

Bullet::Bullet(void)
{
	bullet.setFillColor(sf::Color::Yellow);
	bullet.setOutlineColor(sf::Color::Yellow);
	bullet.setSize(sf::Vector2f(16.f, 8.f));
}

float Bullet::GetX(void) const
{
	return bullet.getPosition().x;
}

void Bullet::setFree(bool val)
{
	free = val;
}

void Bullet::SetPos(float x, float y)
{
	bullet.setPosition(sf::Vector2f(x, y));
}

bool Bullet::isFree(void) const
{
	return free;
}

void Bullet::Move(void)
{
	bullet.move(sf::Vector2f(8.0f, 0.0f));
}

void Bullet::Shoot(float sY)
{
	if (free)
	{
		free = false;
		bullet.setPosition(sf::Vector2f(320.f, 80.f + sY));
	}
}

bool NextFree(Bullet* bullets, uint& pos, uint limit)
{
	for (uint i = 0; i < limit; ++i)
	{
		if (bullets[i].isFree())
		{
			pos = i;
			return true;
		}
	}

	return false;
}

void Shoot(Bullet* bullets, size_t limit, sf::Sprite spaceship)
{
	uint pos;

	if (NextFree(bullets, pos, limit))
	{
		bullets[pos].Shoot(spaceship.getPosition().y);
	}
}

sf::RectangleShape Bullet::getBullet(void) const
{
	return bullet;
}

void UpdateBullets(Bullet* bullets, sf::RenderWindow& window, size_t limit)
{
	for (uint i = 0; i < limit; ++i)
	{
		if (bullets[i].GetX() > 1422.f)
		{
			bullets[i].setFree(true);
		}
	}

	for (uint i = 0; i < limit; ++i)
	{
		if (!bullets[i].isFree())
		{ 
			bullets[i].Move();
			window.draw(bullets[i].getBullet());
		}
	}
}

int getBulletsLeft(Bullet* bullets, size_t limit)
{
	int left = 0;

	for (uint i = 0; i < limit; ++i)
	{
		if (bullets[i].isFree())
		{
			left++;
		}
	}

	return left;
}