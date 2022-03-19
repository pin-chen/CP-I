#include <bits/stdc++.h>
using namespace std;


vector<int> arr;
vector<int> Rank;
int find(int x){
	if(arr[x] == x)
		return x;
	return arr[x] = find(arr[x]);
}

void Union(int a, int b){
	int ra = find(a);
	int rb = find(b);
	if(ra != rb){
		if(Rank[ra] > Rank[rb]){
			arr[rb] = ra;
			Rank[ra] += Rank[rb];
		}else{
			arr[ra] = rb;
			Rank[rb] += Rank[ra];
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	n++;
	Rank.resize(n);
	arr.resize(n);
	for(int i = 1; i < n; i++){
		arr[i] = i; 
		Rank[i] = 1;
	}
	for(int i = 0; i < q; i++){
		char op;
		int x, y;
		cin >> op >> x >> y;
		if(op == '?'){
			if(find(x) == find(y)){
				cout << "yes\n";
			}else{
				cout << "no\n";
			}
		}else{
			Union(x,y); 
		}
		
	}
	//int t = find(1);
	/*
	if(Rank[t] == n - 1){
		cout << "Connected\n";
	}else{
		for(int i = 2; i < n; i++){
			if(find(i) != t){
				cout << i << '\n';
			}
		}
	}*/
	
	return 0;
}
