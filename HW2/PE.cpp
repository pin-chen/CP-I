#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin.ignore();
	getline(cin,s);
	stack<char> st;
	for(int i = 0; i < n; i++){
		char x = s[i];
		if(x == ' '){
			continue;
		}else if(x == '{'){
			st.push(x);
		} else if(x == '['){
			st.push(x);
		} else if(x == '('){
			st.push(x);
		} else if(x == ')'){
			if(st.size() == 0){
					cout << x << " " << i << '\n';
					return 0;	
				}
			if(st.top() == '('){
				
				st.pop();
			}else{
				cout << x << " " << i << '\n';
				return 0;
			}
		} else if(x == ']'){
			if(st.size() == 0){
					cout << x << " " << i << '\n';
					return 0;	
				}
			if(st.top() == '['){
				st.pop();
			}else{
				cout << x << " " << i << '\n';
				return 0;
			}
		} else if(x == '}'){
			if(st.size() == 0){
					cout << x << " " << i << '\n';
					return 0;	
				}
			if(st.top() == '{'){
				st.pop();
			}else{
				cout << x << " " << i << '\n';
				return 0;
			}
		} 
	}
	cout << "ok so far\n";
	return 0;
}
