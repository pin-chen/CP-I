#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 100001;
const ll K = 1000000000000000000;
vector<ll> fib;

void sol(int n, ll k){
	if(n == 1) cout << "N\n";
	else if(n == 2) cout << "A\n";
	else{
		ll x = fib[n - 2];
		if(k <= x){
			sol(n - 2, k);
		}else{
			sol(n - 1, k - x);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fib.resize(N);
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i < N; i++){
		fib[i] = fib[i - 2] + fib[i - 1];
		if(fib[i] > K) fib[i] = K + 1;
	}
	int n;
	ll k;
	cin >> n >> k;
	sol(n, k);
	return 0;
} 
