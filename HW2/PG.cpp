#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	
	cin.ignore();
	int index = 0;
	while(n--){
		string s;
		getline(cin, s);
		list<char> arr;
		index = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '<'){
				auto x = arr.begin();
				index--;
				if(index < 0){
					index = 0;
				}else if(index == arr.size()-1){
					arr.pop_back();
				}else{
					advance(x, index);
					arr.erase(x);
				}
			}else if(s[i] == '['){
				index = 0;
			}else if(s[i] == ']'){
				index = arr.size();
			}else{
				if(index == arr.size()){
					arr.push_back(s[i]);
				}else{
					auto x = arr.begin();
					advance(x, index);
					arr.insert(x, s[i]);
				}
				index++;
			}
		}
		for(auto x : arr){
			cout << x;
		}
		cout << '\n';
	}
	
	return 0;
}
