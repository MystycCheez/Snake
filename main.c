#include "Includes.h"

typedef struct{
	Coord pos;
	Direction dir;
}Snake;

void drawGrid(char grid[], Length gridLen, uint scale){
	for (int i = 0; i < gridLen.x * gridLen.y; i++){
		switch(grid[i]){
			case 's':
			setColor(GREEN);
			fillSquare((i % gridLen.x) * scale, (i / gridLen.x) * scale, scale);
				break;
			case 'a':
			setColor(RED);
			fillSquare((i % gridLen.x) * scale, (i / gridLen.x) * scale, scale);
				break;
			case ' '
			setColor(BLACK);
			fillSquare((i % gridLen.x) * scale, (i / gridLen.x) * scale, scale);
				break;
		}
	}
	printf("line 21\n");
}

void randomApple(char **grid, Snake snake)
{

}

int main(int argc, char const *argv[])
{
	const uint scale = 10;
	const Length window = {800, 600};
	const Length gridLen = coordDiv(window, scale);
	init(window);

	char **grid = calloc(gridLen.x, sizeof(char*));
	for(uint i = 0; i < gridLen.x; i++)
		grid[i] = calloc(gridLen.y, sizeof(char));

	for(uint y = 0; y < gridLen.y; y++){
		for(uint x = 0; x < gridLen.x; x++){
			grid[x][y] = ' ';
		}
	}

	Snake snake = {
		.pos = coordDiv(gridLen, 2),
		.dir = DIR_R
	};

	grid[snake.pos.x][snake.pos.y] = 's';


	while(1){
		Ticks frameStart = getTicks();
		clear();

		if (keyPressed(SDL_SCANCODE_W)){
			snakeVector = -1 * gridLen.x;
		}
		if (keyPressed(SDL_SCANCODE_A)){
			snakeVector = -1;
		}
		if (keyPressed(SDL_SCANCODE_S)){
			snakeVector = gridLen.x;
		}
		if (keyPressed(SDL_SCANCODE_D)){
			snakeVector = 1;
		}

		grid[tileSnake + snakeVector] = 's';
		grid[tileSnake] = ' ';
		tileSnake += snakeVector;
		drawGrid(grid, gridLen, scale);

		draw();
		events(frameStart + TPF);
	}

	return 0;
}
