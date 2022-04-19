#include <bits/stdc++.h>
#define int long long
using namespace std;

int pow1(int base, int p, int m){
	int ans = 1;
	while(p){
		if(p & 1) ans = (ans * base) % m;
		base = (base * base) % m;
		p >>= 1;
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << pow1((a * ( a + 1) / 2) % a, b, a) % a << '\n';
	return 0;
}
