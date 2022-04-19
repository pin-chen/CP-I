#include <bits/stdc++.h>
using namespace std;

vector<int> legal_num;

vector<vector<int>> next_num = {
	{0},
	{0, 1, 2, 3 ,4 ,5 ,6 ,7, 8, 9},
	{2, 3, 5, 6, 8, 9, 0},
	{3, 6, 9},
	{4, 5, 6, 7 ,8 ,9, 0},
	{5, 6, 8, 9, 0},
	{6, 9},
	{7, 8, 9, 0},
	{8, 9, 0},
	{9}
};

void dfs(int now, int d, int num){
	if(d <= 0) return;
	legal_num.push_back(num);
	for(auto x : next_num[now]){
		dfs(x, d - 1, num * 10 + x);
	}
}

int main(){
	int t;
	legal_num.push_back(0);
	dfs(1, 3, 1);
	dfs(2, 3, 2);
	for(int i = 3; i < 10; i++) dfs(i, 2, i);
	sort(legal_num.begin(), legal_num.end());
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int l = lower_bound(legal_num.begin(), legal_num.end(), n) - legal_num.begin();
		if(abs(legal_num[l] - n) < abs(legal_num[l - 1] - n)){
			cout << legal_num[l] << '\n';
		}else{
			cout << legal_num[l - 1] << '\n';
		}
	}
	return 0;
} 
