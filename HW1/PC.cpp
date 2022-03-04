#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n && n){
		cin.ignore();
		string s;
		map<string, set<string>> dish;
		for(int i = 0; i < n; i++){
			
			getline(cin, s);
			stringstream ss;
			ss << s;
			string x, y;
			ss >> y;
			while(ss >> x){
				dish[x];
				dish[x].insert(y);
			}
		}
		for(auto x : dish){
			cout << x.first;
			for(auto z : x.second){
				cout << " " << z; 
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
