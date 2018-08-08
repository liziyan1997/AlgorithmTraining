/*
UVa 1590 IP Networks
Author:Gary Lee
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int ipAddr[4][MAX];
int n;

int isSame(int *arr){
	int a = *arr;
	for (int i = 1; i < n; i++)
		if (a != *(arr + i))
			return 0;
	return 1;
}

int getMask(int *arr){
	int mask=0;
	int tempAddr[MAX];
	for (int i = 7; i>=0; i--){
		for (int j = 0; j < n; j++){
			tempAddr[j] = *(arr + j)&(1 << i);
		}
		int flag = 1;
		for (int j = 1; j < n; j++){
			if (tempAddr[0] != tempAddr[j])
				flag = 0;	
		}
		if (flag)
			mask += (1 << i);
	}
	return mask;
}

int main(){
	int mask[4] = {0,0,0,0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d.%d.%d.%d", &ipAddr[0][i], &ipAddr[1][i], &ipAddr[2][i], &ipAddr[3][i]);
		//printf("%d %d %d %d", ipAddr[i][0], ipAddr[i][1], ipAddr[i][2], ipAddr[i][3]);
	}
	if (isSame(ipAddr[0])){
		mask[0] = 255;
		if (isSame(ipAddr[1])){
			mask[1] = 255;
			if (isSame(ipAddr[2])){
				mask[2] = 255;
				mask[3] = getMask(ipAddr[3]);
			}
			else
				mask[2] = getMask(ipAddr[2]);
		}
		else
			mask[1] = getMask(ipAddr[1]);
	}
	else
		mask[0] = getMask(ipAddr[0]);

	printf("%d.%d.%d.%d\n", ipAddr[0][0] & mask[0], ipAddr[1][0] & mask[1], ipAddr[2][0] & mask[2], ipAddr[3][0] & mask[3]);
	printf("%d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
	system("pause");
	return 0;
}