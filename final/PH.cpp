#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int, int>
#define pip pair<pair, pii>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, w;
	cin >> n >> w;
	int x[n];
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	int y[2 * w - 1];
	for(int i = 0; i < 2 * w - 1; i++){
		cin >> y[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ans += y[x[i] + x[j]];
		}
	}
	cout << ans << '\n';
	return 0;
}
