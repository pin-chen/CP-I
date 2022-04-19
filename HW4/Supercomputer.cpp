#include <bits/stdc++.h>
using namespace std;

int lowbit(int x){
	return x & (-x);
}

void modify(vector<int>& bit, int index, int num){
	int n = bit.size();
	for(int i = index; i <= n; i += lowbit(i)){
		bit[i] += num;
	}
}

int query(vector<int>& bit, int index){
	int ans = 0;
	for(int i = index; i > 0; i -= lowbit(i)){
		ans += bit[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> bit;
	vector<bool> arr;
	bit.resize(n + 1);
	arr.resize(n + 1);
	while(k--){
		char op;
		cin >> op;
		int l, r;
		switch(op){
			case 'F':{
				cin >> l;
				arr[l] = !arr[l];
				modify(bit, l, arr[l] ? 1 : -1);
				break;
			}
			case 'C':{
				cin >> l >> r;
				cout << query(bit, r) - query(bit, l - 1) << '\n';
				break;
			}
		}
	}
	return 0;
}
