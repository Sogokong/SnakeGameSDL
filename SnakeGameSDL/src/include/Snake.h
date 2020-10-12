#pragma once
#include "Sdl_Include.h"
class Snake
{
	int x = 0;
	int y = 0;
	int scale;

public:
	int vx = 0;
	int vy = 0;

	Snake(int scale);
	~Snake();
	void draw(SDL_Renderer* renderer);
	void update(uint32_t deltaTime);
};

