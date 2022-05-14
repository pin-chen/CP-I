#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fst first
#define sec second
using namespace std;

vector<int> arr;
vector<int> rank;
int find(int x){
	if(arr[x] == x){
		return x;
	}
	return find(arr[x]);
}

void Union(int u, int v, int d){
	int ru = find(u);
	int rv = find(v);
	if(ru != rv){
		if(d < 0){
			arr[ru] = rv;
			
		}else{
			arr[rv] = ru;
		}
	}
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n, q;
	cin >> n >> q;
	arr.resize(n + 1);
	for(int i = 1; i <= n; i++){
		arr[i] = i;
	}
	while(q--){
		char op;
		cin >> op;
		switch(op){
			case '1':{
				int u, v, d;
				cin >> u >> v >> d;
				Union(u, v, d);
				break;
			}
			case '2':{
				int v;
				cin >> v;
				if(arr[v] == v){
					cout << "nothing\n";
				}else{
					cout << arr[v] << '\n';
				}
				
				break;
			}
		}
	}
	return 0;
} 
