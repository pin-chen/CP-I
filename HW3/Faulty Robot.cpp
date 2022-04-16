#include <bits/stdc++.h>
#define pii pair<int, int>
#define fst first
#define sec second
using namespace std;
vector<vector<int>> adj;
vector<int> tag;
vector<int> ans;
int n, m;
void dfs(int now, bool bug){
	if(tag[now] != 0) return;
	bool end = true;
	for(auto next : adj[now]){
		if(next < 0){
			end = false;
			tag[now] = 1;
			dfs(-next, bug);
			tag[now] = 0;
		}else if(bug == false){
			tag[now] = 1;
			dfs(next, true);
			tag[now] = 0;
		}
	}
	if(end){
		ans[now] = 1;
	} 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	adj.resize(n + 1);
	tag.resize(n + 1);
	ans.resize(n + 1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		if(a < 0){
			adj[-a].push_back(-b);
		}else{
			adj[a].push_back(b);
		}
	}
	
	dfs(1, false);
	int num = 0;
	for(auto x : ans){
		num += x;
	}
	cout << num << '\n';
	return 0;
}
