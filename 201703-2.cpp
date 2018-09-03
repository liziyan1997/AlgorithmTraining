#include<iostream>
using namespace std;
const int maxn = 1005;
int stu[maxn];
int n, m;

int findStu(int p){
	int i;
	for (i = 0; i < n; i++){
		if (stu[i] == p)
			return i;
	}
}

void goForward(int s){
	int tmp = stu[s - 1];
	stu[s - 1] = stu[s];
	stu[s] = tmp;
}

void goBack(int s){
	int tmp = stu[s + 1];
	stu[s + 1] = stu[s];
	stu[s] = tmp;
}


int main(){
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++){
		stu[i] = i + 1;
	}
	for (i = 0; i < m; i++){
		int p, q;
		cin >> p >> q;
		int s = findStu(p);
		if (q > 0){
			while (q != 0){
				q--;
				goBack(s++);
			}
		}
		else{
			while (q != 0){
				q++;
				goForward(s--);
			}
		}
	}
	for (i = 0; i < n; i++){
		cout << stu[i] << ' ';
	}
	return 0;
}