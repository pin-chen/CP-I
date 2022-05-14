#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll MAX = 0;

void modify(vector<ll>& arr, int index, ll num){
	int n = arr.size();
	for(int i = index; i <= n; i += i & (-i)){
		arr[i] += num;
	}
}

ll query(vector<ll>& arr, int index){
	ll ans = 0;
	for(int i = index; i > 0; i -= i & (-i)){
		ans += arr[i];
	}
	return ans;
}

const int N = 200000;
vector<ll> bit(MAX+2);
ll sol(vector<ll>& arr){
	int n = arr.size();
	for(int i = 0; i < MAX; i++){
		bit[i] = 0;
	}
	ll num = 0;
	for(int i = n - 1; i >= 0; i--){
		num += query(bit, arr[i] - 1);
		modify(bit, arr[i], 1);
	}
	return num;
}

void next(vector<ll>& arr, vector<pii>& q, int t){
	for(int i = 0; i <= t; i++){
		swap(arr[q[i].first], arr[q[i].second]);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	
	cin >> n >> m >> k;
	vector<ll> arr(n);
	for(auto &x : arr){
		cin >> x;
		MAX = max(MAX, x);
	} 
	vector<pii> q;
	
	int l = 0, r = m - 1;
	
	while(m--){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		q.push_back({x, y});
	}
	
	ll ans = sol(arr);
	
	while(l <= r){
		int m = (l + r) / 2;
		vector<ll> temp(arr.begin(), arr.end());
		next(temp, q, m);
		ll T = sol(temp);
		if(T > k){
			l = m + 1;
			ans = min(ans, T - k);
		}else{
			r = m - 1;
			ans = min(ans, k - T);
		}
	}
	cout << ans << '\n';
	return 0;
}
