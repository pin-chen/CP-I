#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct countV{
	int numV[7];
};

int lowbit(int x){
	return x & (-x);
}

void modify(vector<countV>& bit, int index, int minV, int addV){
	int n = bit.size();
	for(int i = index; i <= n; i += lowbit(i)){
		bit[i].numV[minV]--;
		bit[i].numV[addV]++;
	}
}

ll query(vector<countV>& bit, vector<int>& V, int index){
	//cout << "--------\n";
	ll ans = 0;
	//cout << "x";
	for(int i = index; i > 0; i -= lowbit(i)){
		for(int j = 1; j < 7; j++){
			//cout << i << " " << j << " " << V[j] << " " << bit[i].numV[j] << '\n';
			ans += (ll) V[j] * bit[i].numV[j];
		}
	}
	//cout << "--------\n";
	return ans;
}

void create(vector<countV>& bit, vector<int>& V, string& s){
	for(int i = 1; i < s.size(); i++){
		modify(bit, i, 0, int(s[i]) - int('0'));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, x, y;
	char op;
	string s;
	vector<countV> bit;
	vector<int> V(7);
	cin >> n >> q;
	bit.resize(n + 1);
	for(int i = 1; i < 7; i++){
		cin >> V[i];
	}
	cin >> s;
	s = " " + s;
	create(bit, V, s);
	while(q--){
		cin >> op >> x >> y;
		switch(op){
			case '1':{
				modify(bit, x, int(s[x]) - int('0'), y);
				s[x] = '0' + y;
	 			break;
			}
			case '2':{
				V[x] = y;
				break;
			}
			case '3':{
				cout << query(bit, V, y) - query(bit, V, x - 1) << '\n';
				break;
			}
		}
	}
		
	return 0;
}
