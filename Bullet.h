#pragma once

#include <SFML/Graphics.hpp>

#define BULLET_LIM 4

typedef unsigned int uint;

class Bullet
{
private:
	sf::RectangleShape bullet;
	bool free = true;

public:
	Bullet(void);

	bool isFree(void) const;
	void setFree(bool val);
	void Move(void);
	void Shoot(float sY);
	void SetPos(float x, float y);
	float GetX() const;
	sf::RectangleShape getBullet(void) const;
};

void UpdateBullets(Bullet* bullets, sf::RenderWindow& window, size_t limit);
bool NextFree(Bullet* bullets, uint& pos, uint limit);
void Shoot(Bullet* bullets, size_t limit, sf::Sprite spaceship);
int getBulletsLeft(Bullet* bullets, size_t limit);