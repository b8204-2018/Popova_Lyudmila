#include "pch.h"
#include "Darts.h"
#include <iostream>

int main()
{
	float x, y;
	int point = 1;
	scanf_s("%f %f", &x, &y);
	printf("Score: %d", Darts_Score(x, y));
	return 0;
}