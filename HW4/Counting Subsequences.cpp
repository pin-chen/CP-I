#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		for(int i = 1; i < n; i++){
			arr[i] += arr[i - 1];
		}
		map<ll, int> dif47;
		dif47[0] = 1;
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += dif47[arr[i] - 47];
			dif47[arr[i]]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
