#pragma once

//char* arrayChar2D;

//x = array index % number of columns; // dont delete these, this is for reference
//y = array index / number of columns;


char* arrayChar2D(int width, int height){
	char* array = calloc(width * height, sizeof(char));
	return array;
}
short* arrayShort2D(int width, int height){
	short* array = calloc(width * height, sizeof(char));
	return array;
}
