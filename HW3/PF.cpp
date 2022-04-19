#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> num;
vector<ll> sum;
vector<int> id;
vector<int> fa;
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

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, q;
	while(cin >> n >> q){
		n++;
		id.resize(n);
		num.resize(n);
		fa.resize(n);
		sum.resize(n);
		for(int i = 1; i < n; i++){
			id[i] = i;
			fa[i] = i;
			sum[i] = i;
			num[i] = 1;
		}
		for(int i = 0; i < q; i++){
			int op;
			int x, y;
			cin >> op;
			if(op == 1){
				cin >> x >> y;
				Union(id[x], id[y]);
			}else if(op == 2){
				cin >> x >> y;
				int fx = find(id[x]);
				int fy = find(id[y]);
				if(fx != fy){
					sum[fx] -= x;
					num[fx]--;
					int new_index = sum.size();
					id[x] = new_index;
					fa.push_back(new_index);
					sum.push_back(x);
					num.push_back(1);
					Union(id[x], id[y]);
				}
			}else{
				cin >> x;
				int index = find(id[x]);
				cout << num[index] << " " << sum[index] << '\n';
			}
		}
	}
	return 0;
}
