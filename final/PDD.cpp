#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, int> dp;
	int x, y;
	dp[0] = 0;
	
	pii s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i].f >> s[i].s;
	}
	sort(s, s + n);
	for(int i = n - 1; i >= 0; i--){
		x = s[i].f;
		y = s[i].s;
		vector<pii> new_e;
		for(auto &tmp : dp){
			if(tmp.f + x > m) continue;
			if(dp.find(tmp.f + x) != dp.end()){
				new_e.push_back({tmp.f + x, max(dp[tmp.f + x], tmp.s + y)});
			}else{
				new_e.push_back({tmp.f + x, tmp.s + y});
			}
		}
		for(auto N : new_e){
			dp[N.f] = N.s;
		}
	}
	cout << (*dp.rbegin()).s << '\n';
	return 0;
}
