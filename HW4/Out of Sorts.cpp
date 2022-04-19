#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n, m, a, c, x;
	cin >> n >> m >> a >> c >> x;
	ll arr[n];
	arr[0] = ( (ll) a * x + c ) % m;
	//cout << arr[0] << " ";
	for(int i = 1; i < n; i++){
		arr[i] = (a * arr[i - 1] + c) % m;
		//cout << arr[i] << " ";
	}
	//cout << '\n';
	int ans = 0;
	for(int i = 0; i < n; i++){
		int l = 0, r = n - 1;
		//cout << "------\n";
		while(r - l >= 0 ){
			int m = (l + r) / 2;
			//cout << l << " " << r << " " << m << '\n';
			if(arr[m] == arr[i]){
				ans++;
				break;
			}else if(arr[i] > arr[m]){
				l = m + 1;
			}else{
				r = m - 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
} 
