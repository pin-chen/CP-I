#include <bits/stdc++.h>
#define pii pair<int, int>
#define pip pair<int, pii>
#define fst first
#define sec second
using namespace std;
int r, c;
int arr[1001][1001];
int ans = 0;
int Min;
vector<vector<int>> tag;

void bfs(int x, int y){
	priority_queue<pip, vector<pip>, greater<pip>> pq;
	pq.push(make_pair(arr[x][y], make_pair(x, y)));
	ans = arr[x][y];
	int t = x;
	while(pq.size()!=0){
		pip now = pq.top();
		pq.pop();
		ans = max(now.fst, ans);
		if(tag[now.sec.fst][now.sec.sec] != 0) continue;
		if(t!=0 && ans >= Min) return;
		if(now.sec.sec == c - 1) return;
		tag[now.sec.fst][now.sec.sec] = 1;
		x = now.sec.fst;
		y = now.sec.sec;
		if(x+1<r) pq.push(make_pair(arr[x+1][y], make_pair(x+1, y)));
		if(x-1>=0) pq.push(make_pair(arr[x-1][y], make_pair(x-1, y)));
		if(y+1<c) pq.push(make_pair(arr[x][y+1], make_pair(x, y+1)));
		if(y-1>=0) pq.push(make_pair(arr[x][y-1], make_pair(x, y-1)));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> arr[i][j];
		}
	}
	ans = 0;
	tag.clear();
	tag.resize(r);
	for(int i = 0; i < r; i++) tag[i].resize(c);
	bfs(0,0);
	Min = ans;
	for(int i = 1; i < r; i++){
		ans = 0;
		tag.clear();
		tag.resize(r);
		for(int i = 0; i < r; i++) tag[i].resize(c);
		bfs(i,0);
		Min = min(Min, ans);
	}
	cout << Min << '\n';
	return 0;
}
