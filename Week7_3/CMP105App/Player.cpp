#include "Player.h"

Player::Player()
{
	setPosition(200, 200);
	setSize(sf::Vector2f(100, 100));
	for (int n = 0; n < 3; n++) {
		bullet[n] = NULL;
	}
}


Player::~Player()
{
	for (int n = 0; n < 3; n++) {
		if (bullet[n] != NULL)
		{
			delete bullet[n];
		}
	}
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		int x = rand() % 600;
		int y = rand() % 400;
		setPosition((float)x, (float)y);
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		
		for (int n = 0; n < 3; n++) {
			if (bullet[n] == NULL)
			{
				bullet[n] = new Bullet;
				bullet[n]->setPosition(getPosition() + sf::Vector2f(getSize().x / 2, getSize().y / 2));
				break;
			}
		}
	}
}

void Player::update(float dt) 
{
	for (int n = 0; n < 3; n++) {
		if (bullet[n] != NULL)
		{
			bullet[n]->update(dt);
		}
	}
}