#include<iostream>
using namespace std;

int mostSeat[20];
int seat[105];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < 20; i++)
		mostSeat[i] = 5;
	for (int i = 0; i < 100; i++){
		seat[i] = 0;
	}
	int kase = 0;
	while (kase++ < n){
		int tickets;
		cin >> tickets;
		for (int i = 0; i < 20; i++){
			int first = 5 * i;
			//如果可以分配一起就分配一起
			if (tickets <= mostSeat[i]){
				for (int j = first; j < first + 5; j++){
					if (seat[j] == 0&&(--tickets)>=0){
						seat[j] = 1;
						cout << (j + 1) << ' ';
					}
				}
				cout << '\n';
				break;
			}
		}//如果没有完成分配就依次进行分配
		if (tickets > 0){
			for (int i = 0; i < 100; i++){
				if (seat[i] == 0&&(--tickets) >= 0){
					seat[i] = 1;
					cout << (i + 1) << ' ';
				}
			}
			cout << '\n';
		}
		
		//重新计算mostSeat
		for (int i = 0; i < 20; i++){
			int first = 5 * i;
			mostSeat[i] = 0;
			for (int j = first; j < first + 5; j++){
				if (seat[j] == 0)
					mostSeat[i]++;
			}
		}
/*
		cout << "mostSeat: ";
		for (int i = 0; i < 20; i++){
			cout << mostSeat[i] << ' ';
		}
		cout << '\n';*/
	}
	//system("pause");

	return 0;
}