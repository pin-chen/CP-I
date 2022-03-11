#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	bool TF[n];
	for(int i = 0; i < n; i++){
		char x;
		cin >> x;
		if(x == 'T'){
			TF[i] = 1;
		}else{
			TF[i] = 0;
		}
	}
	cin.ignore();
	string s;
	getline(cin, s);
	
	stack<bool> st;
	
	int num = 0;
	
	for(int i = 0; i < s.size(); i += 2){
		if(s[i] == '*'){
			bool x = st.top();
			st.pop();
			bool y = st.top();
			st.pop();
			st.push(x && y);
		}else if(s[i] == '-'){
			bool x = st.top();
			st.pop();
			st.push(!x);
		}else if(s[i] == '+'){
			bool x = st.top();
			st.pop();
			bool y = st.top();
			st.pop();
			st.push(x || y);
		}else{
			st.push(TF[num++]);
		}
	}
	if(st.top() == 1){
		cout << "T\n";
	}else{
		cout << "F\n";
	}
	return 0;
}
