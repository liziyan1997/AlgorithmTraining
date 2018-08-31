#include<iostream>
#include<string>
using namespace std;
const int maxn = 31;
int color[maxn][maxn];
int clear[maxn][maxn];


int main(){
	int n, m;
	cin >> n>>m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> color[i][j];
			clear[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int count_i=0,count_j=0;
			int temp_i=i+1, temp_j=j+1;
			while (temp_i < n&&color[i][j] == color[temp_i][j]){
				count_i++;
				temp_i++;
			}
			while (temp_j < m&&color[i][j] == color[i][temp_j]){
				count_j++;
				temp_j++;
			}
			if (count_i > 1){
				temp_i = i;
				while (count_i >= 0){
					clear[temp_i][j] = 0;
					count_i--;
					temp_i++;
				}
			}
			if (count_j > 1){
				temp_j = j;
				while (count_j >= 0){
					clear[i][temp_j] = 0;
					count_j--;
					temp_j++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << color[i][j]*clear[i][j]<<' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
	
}