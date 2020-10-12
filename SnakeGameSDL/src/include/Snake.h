#pragma once
#include "LibInclude.h"
#include "include\Vector2D.h"

class Snake
{
	Vector2D* body = (Vector2D*)malloc(sizeof(Vector2D) * 5);
	int scale;

public:
	int vx = 0;
	int vy = 0;

	Snake(int scale);
	~Snake();
	void draw(SDL_Renderer* renderer);
	void update(uint32_t deltaTime);
};

