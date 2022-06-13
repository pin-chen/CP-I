#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pss pair<string, string>
#define pip pair<pair, pii>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int k[n], y[m];
	string c[n], a[m], b[m];
	map<string, int> company;
	for(int i = 0; i < n; i++){
		cin >> c[i] >> k[i];
		company[c[i]] = k[i];
	}
	/*
	for(auto x : company){
		cout << x.f << " " << x.s << '\n';
	}
	*/
	map<pss, int> table;
	string ans = "";
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i] >> y[i];
		if(table.find({a[i], b[i]}) != table.end()){
			if ( table[{a[i], b[i]}] + company[b[i]] <= y[i]){
				ans.push_back('1');
				table[ {a[i], b[i]} ] = max(table[ {a[i], b[i]} ], y[i]);
			}else{
				ans.push_back('0');
				table[ {a[i], b[i]} ] = max(table[ {a[i], b[i]} ], y[i]);
			}
		}else{
			ans.push_back('1');
			table[ {a[i], b[i]} ] = y[i];
		}
		/*
		for(auto x : table){
			cout << x.f.f << " " << x.f.s << " " << x.s << '\n';
		}
		cout << " ------------ \n";
		*/
	}
	cout << ans << '\n';
	
	return 0;
}
