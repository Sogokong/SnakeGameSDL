#include "include\Snake.h"

Snake::Snake(int scale)
{
	this->scale = scale;
};

Snake::~Snake()
{
	this->scale = 0;
};

void Snake::draw(SDL_Renderer* renderer)
{
	//SDL_Rect snakeRect{ this->body[0].x, this->body[0].y, SCALE, SCALE };
	SDL_Rect snakeRect{ this->x, this->y, this->scale, this->scale };
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &snakeRect);
};

uint32_t accumulator = 0;

void Snake::update(uint32_t deltaTime)
{
	accumulator += deltaTime;
	if (accumulator >= 100)
	{
		accumulator = 0;
		this->x += this->vx * this->scale;
		this->y += this->vy * this->scale;
		//std::cout << "xHead: " << this->x << ", yHead: " << this->y << std::endl;

	}
};
