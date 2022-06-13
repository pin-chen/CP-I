#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	pii s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i].f >> s[i].s;
	}
	
	int dp[m + 1] = {};
	
	for(int i = 0; i < n; i++){
		for(int j = m; j >= s[i].f; j--){
			dp[j] = max(dp[j], dp[j - s[i].f + s[i].s);
		}
	}
	
	cout << dp[m] << '\n';
	return 0;
}
