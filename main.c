#include "Includes.h"

typedef struct{
	Coord pos;
	Direction dir;
}Snake;

void drawGrid(char** grid, Length gridLen, uint scale){
	for (uint y = 0; y < gridLen.y; y++){
		for (uint x = 0; x < gridLen.x; x++){
			switch(grid[x][y]){
				case 's':
				setColor(GREEN);
				fillSquare(x * scale, y * scale, scale);
				break;
				case 'a':
				setColor(RED);
				fillSquare(x * scale, y * scale, scale);
				break;
				case ' ':
				setColor(BLACK);
				fillSquare(x * scale, y * scale, scale);
				break;
			}
			//printf("%d\n", x);
			//printf("%u, %u\n", x, y);
		}
	}
}

Coord randomApple(Length gridLen, Snake snake)
{
	Coord apple;
	do{
		apple.x = rand() % gridLen.x;
		apple.y = rand() % gridLen.y;
	}while(coordSame(apple, snake.pos));
	return apple;
}

int main(int argc, char const *argv[])
{
	const uint scale = 10;
	const Length window = {800, 600};
	const Length gridLen = coordDiv(window, scale);
	init(window);

	char **grid = malloc(gridLen.x * sizeof(char*));
	for(uint i = 0; i < gridLen.x; i++){
		grid[i] = malloc(gridLen.y * sizeof(char));
	} //


	for(uint y = 0; y < gridLen.y; y++){
		for(uint x = 0; x < gridLen.x; x++){
			grid[x][y] = ' ';
		}
	}

	Snake snake = {
		.pos = coordDiv(gridLen, 2),
		.dir = DIR_R
	};

	Coord apple = randomApple(gridLen, snake);

	// grid[tileSnake.x][tileSnake.y] = 's';
	// grid[80][40] = 'a';

	grid[snake.pos.x][snake.pos.y] = 's';
	grid[apple.x][apple.y] = 'a';

	const u8 dirKeyCode[4] = {
		SDL_SCANCODE_W,
		SDL_SCANCODE_D,
		SDL_SCANCODE_S,
		SDL_SCANCODE_A
	};

	const char dirKeyChar[4] = {
		'W',
		'D',
		'S',
		'A'
	};

	uint frameCount = 0;
	while(1){
		Ticks frameStart = getTicks();
		clear();

		for(uint i = 0; i < 4; i++){
			if(keyPressed(dirKeyCode[i])){
				snake.dir = i;
				printf("Key %c pressed\n", dirKeyChar[i]);
			}
		}

		if(frameCount > FPS/4){
			frameCount = 0;

			grid[snake.pos.x][snake.pos.y] = ' ';
			snake.pos = coordShift(snake.pos, snake.dir, 1);
			snake.pos.x = clamp(snake.pos.x, 0, gridLen.x);
			snake.pos.y = clamp(snake.pos.y, 0, gridLen.y);
			grid[snake.pos.x][snake.pos.y] = 's';
			if (apple.x == snake.pos.x && apple.y == snake.pos.y){
				apple = randomApple(gridLen, snake);
				grid[apple.x][apple.y] = 'a';
			}
		}
		drawGrid(grid, gridLen, scale);
		frameCount++;
		draw();
		events(frameStart + TPF);
	}

	return 0;
}
