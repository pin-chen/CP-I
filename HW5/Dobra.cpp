#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isvalid(string& s){
	bool isL = false, isAB = false;
	int numAB = 0;
	for(auto x : s){
		if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
			if(isAB){
				numAB++;
			}else{
				isAB = true;
				numAB = 1;
			}
		}else{
			if(x == 'L') isL = true;
			if(!isAB){
				numAB++;
			}else{
				isAB = false;
				numAB = 1;
			}
		}
		if(numAB >= 3) return false;
	}
	return isL;
}

void solve(ll& ans, string& s, vector<int>& ch, int index){
	if(index >= s.size()){
		if(isvalid(s)){
			ll num = 1;
			for(auto x : ch) num *= x;
			ans += num;
		} 
		return;
	}
	if(s[index] != '_') solve(ans, s, ch, index + 1);
	else{
		s[index] = 'L';
		solve(ans, s, ch, index + 1);
		s[index] = 'B';
		ch[index] = 20;
		solve(ans, s, ch, index + 1);
		s[index] = 'A';
		ch[index] = 5;
		solve(ans, s, ch, index + 1);
		s[index] = '_';
		ch[index] = 1;
	}	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<int> ch(101, 1);
	ll ans = 0;
	solve(ans, s, ch, 0);
	cout << ans << '\n';
	return 0;
}
