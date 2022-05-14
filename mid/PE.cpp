#include <bits/stdc++.h>
#define ll long long
using namespace std;

int lowbit(int x){
	return x & (-x);
}

void modify(vector<ll>& bit, int index, int num){
	int n = bit.size();
	for(int i = index; i <=n; i += lowbit(i)){
		bit[i] += num;
	}
}

ll query(vector<ll>& bit, int index){
	ll ans = 0;
	for(int i = index; i > 0; i -= lowbit(i)){
		ans += bit[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<ll> bit;
	vector<ll> arr;
	bit.resize(n + 2);
	arr.resize(n + 2);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		modify(bit, i, arr[i]);
	}
	set<int> shut;
	shut.insert(n+1);
	while(q--){
		char op;
		cin >> op;
		switch(op){
			case 'D':{
				int index;
				cin >> index;
				modify(bit, index + 1, 0 - arr[index+1]);
				arr[index+1] = 0;
				shut.insert(index + 1);
				break;
			}
			case 'Q':{
				char op2;
				cin >> op2;
				if(op2 == 'S'){
					ll ans = 0;
					int prev = 0;
					for(auto x : shut){
						if(prev == 0){
							prev = x;
						}else{
							ans += (x - prev - 1) * (query(bit, x) - query(bit, prev));
							prev = x;
						}
					}
					cout << ans << '\n';
				}else if(op2 == 'M'){
					ll ans = 0;
					int prev = 0;
					for(auto x : shut){
						if(prev == 0){
							prev = x;
						}else{
							ans = max(ans, ( x - prev - 1) *  (query(bit, x) - query(bit, prev) ) );
							prev = x;
						}
					}
					cout << ans << '\n';
				}
				break;
			}
		}
	}
	
	return 0;
} 
