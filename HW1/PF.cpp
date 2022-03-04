#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	set<pair<int,int>> person;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		person.insert(make_pair(b,a));
	}
	int ans = 0;
	for(int i = t - 1; i >= 0; i--){
		auto x = person.lower_bound(make_pair(i, 0));
		auto Max = x;
		for(; x != person.end(); x++){
			if(Max->second < x -> second) Max = x;
		}
		if(Max != person.end()){
			ans += Max->second;
			person.erase(Max);
		}
	}
	cout << ans << '\n';
	
	return 0;
} 

