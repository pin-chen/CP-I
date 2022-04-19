#include <bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x){
	return x & (-x);
}

void modify(vector<int>& bit, int index, int num){
	if(index == 0) {
		bit[0] += num;
		return;
	}
	int n = bit.size();
	for(int i = index; i <= n; i += lowbit(i) ){
		bit[i] += num;
	} 
}

int query(vector<int>& bit, int index){
	int ans = 0;
	for(int i = index; i > 0; i -= lowbit(i) ){
		ans += bit[i];
	}
	if(index != -1) ans += bit[0];
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> bit;
	int n, q;
	cin >> n >> q;
	bit.resize(n);
	while(q--){
		char op;
		cin >> op;
		int index, num;
		switch(op){
			case '+':{
				cin >> index >> num;
				modify(bit, index, num);
				break;
			}
			case '?':{
				cin >> index;
				cout << query(bit, index - 1) << '\n';
				break;
			}
		}
	}
	return 0;
} 
