#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	vector<char> st;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '<'){
			st.push_back(s[i]);
		}else if(st.size() != 0){
			st.pop_back();
		}
	}
	for(int i = 0; i < st.size(); i++){
		cout << st[i];
	}
	
	return 0;
} 
