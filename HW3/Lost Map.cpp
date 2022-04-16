#include <bits/stdc++.h>
#define pii pair<int, int>
#define pip pair<int, pii>
#define fst first
#define sec second
using namespace std;
int arr[2501][2501];
vector<int> tag;
vector<pii> ans;
priority_queue<pip, vector<pip>, greater<pip>> pq;
int n;
void bfs(){
	int num = 0;
	tag[0] = 1;
	for(int i = 1; i < n; i++){
		pq.push(make_pair(arr[0][i], make_pair(0, i)));
	}
	while(num < n - 1){
		pip now = pq.top();
		pq.pop();
		if(tag[now.sec.sec] != 0) continue;
		tag[now.sec.sec] = 1;
		num++;
		ans.push_back(now.sec);
		int x = now.sec.sec;
		for(int i = 0; i < n; i++){
			if(i == x) continue;
			pq.push(make_pair(arr[x][i], make_pair(x, i)));
		}
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	tag.resize(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	bfs();
	for(auto x : ans){
		cout << x.fst + 1 << " " << x.sec + 1;
		cout << '\n';
	}
	return 0;
}
