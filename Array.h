#pragma once

//char* arrayChar2D;

//x = array index % number of columns; // dont delete these, this is for reference
//y = array index / number of columns;


char* arrayChar(int width, int height){
	char* array = calloc(width * height, sizeof(char));
	return array;
}
short* arrayShort(int width, int height){
	short* array = calloc(width * height, sizeof(char));
	return array;
}
char** arrayChar2D(int width, int height){
	char** array = calloc(width, sizeof(char));
	for(int i = 0; i < width; i++){
		array[i] = calloc(height, sizeof(char));
	}
	return array;
}
