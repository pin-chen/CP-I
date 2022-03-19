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
		int op;
		int x, y;
		cin >> op;
		if(op == 1){
			cin >> x >> y;
			Union(x,y);
		}else if(op == 2){
			cin >> x >> y;
			arr[x] = find(y);
		}else{
			cin >> x;
			int sum = 0, count = 0, tar = find(x);
			for(int i = 0; i < n; i++){
				if(find(i) == tar){
					sum += i;
					count++;
				}
			}
			cout << count << " " << sum << '\n';
		}
	}
	return 0;
}
