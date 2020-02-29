#pragma once

#include "Framework/GameObject.h"
#include "Companion.h"

class Player : public GameObject
{
private:
	Companion companion;

public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);
	Companion* getCompanion() { return &companion; }
	

};