#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;

int main(){
	int n, k;
	int keys[maxn];
	int w[maxn], s[maxn], c[maxn];
	vector<int> returnKeys;
	cin >> n >> k;
	int i;
	for (i = 0; i < n; i++)
		keys[i] = i + 1;
	for (i = 0; i < k; i++)
		cin >> w[i] >> s[i] >> c[i];
	int time = 1;
	for (; time < 10101; time++){
		//ÏÈ»¹Ô¿³×
		returnKeys.clear();
		for (i = 0; i < k; i++){
			if ((s[i] + c[i]) == time)
				returnKeys.push_back(w[i]);
		}
		sort(returnKeys.begin(), returnKeys.end());
		int j;
		for (i = 0; i < returnKeys.size(); i++){
			for (j = 0; j < n; j++){
				if (keys[j] == 0){
					keys[j] = returnKeys[i];
					break;
				}
			}
		}
		//½èÔ¿³×
		for (i = 0; i < k; i++){
			if (s[i] == time){
				for (j = 0; j < n; j++){
					if (keys[j] == w[i]){
						keys[j] = 0;
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		cout << keys[i] << ' ';
	
	return 0;
}