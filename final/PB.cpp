#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
#define ppi pair<pii, int>

using namespace std;
int n, m ,q;
char table[501][501];

pii ward[101];

void bfs(pii start, int num){
	int dis[n][n] = {};
	dis[start.f][start.s] = 1;
	queue<pii> q;
	q.push(start);
	while(q.size() != 0){
		pii now = q.front();
		q.pop();
		if(now.f - 1 >= 0 && table[now.f - 1][now.s] == '.' && dis[now.f - 1][now.s] == 0){//(-1,0)
			q.push({now.f - 1, now.s});
			dis[now.f - 1][now.s] = dis[now.f][now.s] + 1; 
		}
		if(now.f + 1 < n && table[now.f + 1][now.s] == '.' && dis[now.f + 1][now.s] == 0){//(1,0)
			q.push({now.f + 1, now.s});
			dis[now.f + 1][now.s] = dis[now.f][now.s] + 1; 
		}
		if(now.s - 1 >= 0 && table[now.f][now.s - 1] == '.' && dis[now.f][now.s - 1] == 0){//(0,-1)
			q.push({now.f, now.s - 1});
			dis[now.f][now.s - 1] = dis[now.f][now.s] + 1; 
		}
		if(now.s + 1 < n && table[now.f][now.s + 1] == '.' && dis[now.f][now.s + 1] == 0){//(0,1)
			q.push({now.f, now.s + 1});
			dis[now.f][now.s + 1] = dis[now.f][now.s] + 1; 
		}
	}
	vector<pii> arr;
	for(int i = 0; i < m; i++){
		if(dis[ward[i].f][ward[i].s] == 0) continue;
		arr.push_back({dis[ward[i].f][ward[i].s], i});
	}
	sort(arr.begin(), arr.end());
	
	if(arr.size() > num){
		cout << arr[num].s + 1 << '\n';
	}else{
		cout << "-1\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> table[i][j];
		}
	}
	
	for(int i = 0; i < m; i++){
		cin >> ward[i].f >> ward[i].s;
		ward[i].f--;
		ward[i].s--;
	}
	
	for(int i = 0; i < q; i++){
		int x, y, z;
		cin >> x >> y >> z;
		bfs({x - 1, y - 1}, z - 1);
	}
	
	return 0;
}
