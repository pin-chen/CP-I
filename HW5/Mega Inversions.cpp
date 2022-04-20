#include <bits/stdc++.h>
#define ll long long
#define MAX 200005
using namespace std;

int lowbit(int x){
	return x & (-x);
}

void modify(vector<ll>& arr, int index, ll num){
	int n = arr.size();
	for(int i = index; i <= n; i += lowbit(i)){
		arr[i] += num;
	}
}

ll query(vector<ll>& arr, int index) {
	ll ans = 0;
	for (int i = index; i > 0; i -= lowbit(i)){
		ans += arr[i];
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> arr(n);
	vector<ll> bit1(n + 1), bit2(n + 1);
	for(auto &x : arr) cin >> x;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += query(bit2, arr[i] - 1);
		ll num = query(bit1, arr[i] - 1);
		modify(bit1, arr[i], 1);
		modify(bit2, arr[i], num);
	}
	cout << ans << '\n';
}
