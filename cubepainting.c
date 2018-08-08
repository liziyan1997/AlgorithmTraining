/*
*UVa253 Cube Painting
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20], cube1[10], cube2[10];
int rev[6][6] = { { 0, 1, 2, 3, 4, 5 }, { 1, 5, 2, 3, 0, 4 }, { 2, 1, 5, 0, 4, 3 }, { 3, 1, 0, 5, 4, 2 },
{ 4, 0, 2, 3, 5, 1 }, { 5, 4, 2, 3, 1, 0 } };
/*rev用于改变反转后顺序*/
int isSame();
int main()
{
	while (scanf("%s", str) != EOF)
	{
		if (strlen(str) != 12){
			printf("Wrong input\n");
			system("pause");
			return 0;
		}
		for (int i = 0; i < 6; i++){
			cube1[i] = str[i];
			cube2[i] = str[i + 6];
		}
		cube1[6] = cube2[6] = '\0';
		if (isSame())
			printf("Same cube.\n");
		else 
			printf("Not same cube.\n");
	}
	return 0;
}

int isSame()
{
	char tempCube[10];
	for (int i = 0; i<6; i++){
		for (int j = 0; j<6; j++){
			tempCube[j] = cube1[rev[i][j]];
		}
		tempCube[6] = '\0';
		for (int j = 0; j<4; j++)
		{
			if (strcmp(tempCube, cube2) == 0) 
				return 1;
			char ch;
			ch = tempCube[1];
			tempCube[1] = tempCube[2];
			tempCube[2] = tempCube[4];
			tempCube[4] = tempCube[3];
			tempCube[3] = ch;
			
		}
	}
	return 0;
}
