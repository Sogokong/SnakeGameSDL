#include "include\LibInclude.h"
#include "include\Snake.h"

constexpr auto SCREEN_WIDTH = 300;
constexpr auto SCREEN_HEIGHT = 300;
constexpr auto SCALE = 15;

SDL_Window* window;
SDL_Renderer* renderer;


int createWindow();


struct Food
{
	int x = 100 - 4;
	int y = 200 - 8;

	void draw(SDL_Renderer* renderer)
	{
		SDL_Rect foodRect{ this->x, this->y, SCALE, SCALE };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 5);
		SDL_RenderFillRect(renderer, &foodRect);
		//std::cout << "x: " << x << ", y: " << y << std::endl;
	}

	void update()
	{
		this->x = (rand() % (SCREEN_WIDTH / SCALE)) * SCALE;
		this->y = (rand() % (SCREEN_HEIGHT / SCALE)) * SCALE;
	}

};

//struct Snake
//{
//	Vector2D body[25 * 25];
//
//	/*int x = 0;
//	int y = 0;*/
//	int vx = 0;
//	int vy = 0;
//	int speed = SCALE;
//	uint32_t accumulator = 0;
//
//	void init()
//	{
//		/*int startPosistion = 5;
//		for (int i = 0; i < 5; i++)
//		{
//			body.[i].x = SCREEN_HEIGHT / (2 * SCALE);
//			body.[i].y = SCREEN_HEIGHT / (2 * SCALE);
//			startPosistion--;
//		}*/
//		body[0].x = SCREEN_WIDTH / 2;
//		body[0].y = SCREEN_HEIGHT / 2;
//	}
//
//
//	void draw(SDL_Renderer* renderer)
//	{
//		SDL_Rect snakeRect{ this->body[0].x, this->body[0].y, SCALE, SCALE };
//		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//		SDL_RenderFillRect(renderer, &snakeRect);
//	}
//
//	void update(uint32_t deltaTime)
//	{
//		this->accumulator += deltaTime;
//		if (accumulator >= 100)
//		{
//			this->accumulator = 0;
//			this->body[0].x += this->vx * this->speed;
//			this->body[0].y += this->vy * this->speed;
//			std::cout << "xHead: " << body[0].x << ", yHead: " << body[0].y << std::endl;
//
//		}
//
//	}
//
//	bool eat(Food pos)
//	{
//		if (this->body[0].x == pos.x && this->body[0].y == pos.y) { return true; }
//		return false;
//
//	}
//
//};



int main()
{
	createWindow();

	bool closeRequest = false;
	bool hasEaten = false;
	Snake snake(10);
	uint32_t currentTime = 0, previousTime, deltaTime;

	while (!closeRequest)
	{
		previousTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = currentTime - previousTime;

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				closeRequest = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					closeRequest = true;
					break;
				case SDLK_w:
					if (snake.vy != 1)
					{
						snake.vx = 0;
						snake.vy = -1;
					}
					break;
				case SDLK_s:
					if (snake.vy != -1)
					{
						snake.vx = 0;
						snake.vy = 1;
					}
					break;
				case SDLK_a:
					if (snake.vx != 1)
					{
						snake.vy = 0;
						snake.vx = -1;
					}
					break;
				case SDLK_d:
					if (snake.vx != -1)
					{
						snake.vy = 0;
						snake.vx = 1;
					}
					break;
				default:
					break;
				}
			}
		}

		//if (snake.eat(food)) { food.update(); }

		snake.update(deltaTime);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		//food.draw(renderer);
		snake.draw(renderer);
		SDL_RenderPresent(renderer);
	}


	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
};

int createWindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL initialization Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	std::cout << "SDL init success" << std::endl;


	window = SDL_CreateWindow(
		"Snake Game",				// Window title
		SDL_WINDOWPOS_CENTERED,		// Initial x position
		SDL_WINDOWPOS_CENTERED,		// Initial y position
		SCREEN_WIDTH,						// Screen width, in pixels
		SCREEN_HEIGHT,						// Screen height, in pixels
		SDL_WINDOW_OPENGL			// Window flag -> usavble with OpenGL context
	);

	// Check if window was successfully created
	if (!window)
	{
		std::cout << "Window initialization Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	std::cout << "SDL window success" << std::endl;


	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// Check if window was successfully created
	if (!renderer)
	{
		std::cout << "Renderer initialization Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	std::cout << "SDL renderer success" << std::endl;
	return 0;
}

