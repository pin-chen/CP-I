#include <bits/stdc++.h>
#define pii pair<int, int>
#define fst first
#define sec second
using namespace std;

void discompute(vector<vector<pii>>& adj, vector<int>& spiders, vector<int>& dis){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(auto x : spiders){
		pq.push({0, x});
		dis[x] = 0;
	}
	while(pq.size() != 0){
		pii now = pq.top();
		pq.pop();
		for(auto next : adj[now.sec]){
			int d = now.fst + next.sec;
			if(dis[next.fst] == -1){
				dis[next.fst] = d;
				pq.push({d, next.fst});
			}else{
				if(d >= dis[next.fst]) continue;
				dis[next.fst] = d;
				pq.push({d, next.fst});
			}
		}
	}
}

bool farpath(vector<vector<pii>>& adj, vector<int>& dis, const int S, const int E, const int allow, const int t){
	if(dis[S] < allow) return false;
	if(dis[E] < allow) return false;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, S});
	vector<int> meter(dis.size(), -1);
	while(pq.size() != 0){
		pii now = pq.top();
		pq.pop();
		if(now.fst > t) return false;
		for(auto next : adj[now.sec]){
			if(dis[next.fst] < allow) continue;
			if(next.fst == E) return true;
			int d = now.fst + next.sec;
			if(meter[next.fst] == -1){
				meter[next.fst] = d;
				pq.push({d, next.fst});
			}else{
				if(d >= meter[next.fst]) continue;
				meter[next.fst] = d;
				pq.push({d, next.fst});
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, t, S, E, num;
	cin >> n >> m >> t;
	vector<vector<pii>> adj(n);
	vector<int> spiders;
	vector<int> dis(n, -1);
	for(int i = 0; i < m; i++){
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}
	cin >> S >> E;
	cin >> num;
	spiders.resize(num);
	for(auto& x : spiders) cin >> x;
	discompute(adj, spiders, dis);
	const int inf = 1000000000;
	int l = 0, r = inf;
	int ans = 0;
	while(l <= r){
		int m = (l + r) / 2;
		if(farpath(adj, dis, S, E, m, t)){
			ans = max(m, ans);
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
