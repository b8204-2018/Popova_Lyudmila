#include "pch.h"
#include <iostream>

int main()
{
	int a, b;
	int *p1, *p2;
	printf("a= ");
	scanf_s("%d", &a);
	printf("b= ");
	scanf_s("%d", &b);
	p1 = &a;
	p2 = &b;
	*p1 = *p2 + *p1;
	*p2 = *p1 - *p2;
	*p1 = *p1 - *p2;
	printf("%d %d", a, b);
	return 0;

}


