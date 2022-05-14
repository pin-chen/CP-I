#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fst first
#define sec second
using namespace std;
vector<int> H;
vector<int> W;
int n;

int get_color(int front, int end){
	return (W[end] - W[front]);
}

int32_t main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n;
	H.resize(n);
	W.resize(n + 1);
	W[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> H[i];
		H[i] = H[i] * 2 / 3;
	}
	for(int i = 1; i <= n; i++){
		cin >> W[i];
		W[i] += W[i - 1];
	}
	int ans = 0;
	int pop_index = 0;
	vector<pii> q;
	for(int i = 0; i < n; i++){
		pop_index = i;
		if(q.empty()){
			q.push_back({H[i], pop_index});
			continue;
		}
		while(!q.empty() && q.back().fst > H[i]){
			pii p = q.back();
			q.pop_back();
			pop_index = p.sec;
			ans = max(ans, p.fst * get_color(p.sec, i) );
		}
		q.push_back({H[i], pop_index});
	}
	while(!q.empty()){
		pii p = q.back();
		q.pop_back();
		pop_index = p.sec;
		ans = max(ans, p.fst * get_color(p.sec, n));
	}
	cout << ans << '\n';
	return 0;
}
