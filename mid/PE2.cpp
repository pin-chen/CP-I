#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> num;
vector<int> sum;
vector<int> arr;
vector<int> fa;

vector<int> live;

int MAX = 0, SUM = 0;

int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void Union(int a, int b){
	int ra = find(a);
	int rb = find(b);
	if(ra != rb){
		if(num[ra] > num[rb]){
			fa[rb] = ra;
			sum[ra] += sum[rb];
			num[ra] += num[rb];
		}else{
			fa[ra] = rb;
			sum[rb] += sum[ra];
			num[rb] += num[ra];
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> d;
	vector<char> ops;
	sum.resize(n);
	num.resize(n);
	fa.resize(n);
	arr.resize(n);
	live.resize(n);
	for(auto &x : live) x = 1;
	for(auto &x : num) x = 1;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum[i] = arr[i];
		fa[i] = i;
	}
	while(q--){
		char op;
		cin >> op;
		switch(op){
			case 'D':{
				int x;
				cin >> x;
				if(live[x]){
					ops.push_back(op);
					d.push_back(x);
				}
				live[x] = 0;
				break;
			}
			case 'Q':{
				char op2;
				cin >> op2;
				ops.push_back(op2);
				break;
			}
		}
	}
	
	int z = 0;
	int r = n;
	set<int> temp;
	while(z < n){
		if(live[z] == 0){
			r = n;
		}else if(r == n){
			r = z;
		}else{
			Union(r, z);
		}
		z++;
	}
	
	for(int i = 0; i < n; i++){
		if(live[find(i)]){
			temp.insert(find(i));
		}
	}
	
	for(auto &x : temp){
		SUM += sum[x] * num[x];
		MAX = max(MAX, sum[x] * num[x]);
	}
	
	
	stack<int> ans;
	
	int R = d.size() - 1;
	for(int i = ops.size() - 1; i >= 0; i--){
	
		switch(ops[i]){
			case 'D':{
				int x = d[R];
				if( x - 1 >= 0 && live[x - 1]){
					SUM -= sum[find(x - 1)] * num[find(x - 1)];
					Union(x, x - 1);
				}
				if( x + 1 < n && live[x + 1]){
					SUM -= sum[find(x + 1)] * num[find(x + 1)];
					Union(x, x + 1);
				}
				live[x] = 1;
				MAX = max(MAX, sum[find(x)] * num[find(x)]);
				SUM += sum[find(x)] * num[find(x)];
				R--;
				break;
			}
			case 'S':{
				ans.push(SUM);
				break;
			}
			case 'M':{
				ans.push(MAX);
				break;
			}
		}
	}
	
	while(ans.size() != 0){
		cout << ans.top() << '\n';
		ans.pop();
	}
	
	
	return 0;
}
