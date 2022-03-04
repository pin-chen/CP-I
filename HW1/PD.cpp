#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	string s;
	while(cin >> s){
		bool start = 0;
		bool zero = 1;
		int num = 0;
		unsigned long long int ans = 0;
		for(int i = 0; i < s.size(); i++){
			if(start == false){
				if( s[i] == 'x' || s[i] == 'X'){
					if(i && s[i-1] == '0'){
						start = 1;
						cout << "0" << s[i];
					}
				}
				continue;
			}
			
			if(isdigit(s[i])  ){
				num++;
				cout << s[i]; 
				ans *= 16;
				ans += s[i] - '0';
				if(zero && ans == 0) num--;
				else zero =false;
				if(num >= 8){
					start = 0;
					zero =1;
					cout << " " << ans << '\n';
					ans = 0;
					num = 0;
				}
			}else if(( s[i] >= 'a' && s[i] <= 'f' )){
				num++;
				zero =false;
				cout << s[i]; 
				ans *= 16;
				ans += s[i] - 'a' + 10;
				if(num >= 8){
					start = 0;
					zero =1;
					cout << " " << ans << '\n';
					ans = 0;
					num = 0;
				}
			}else if(( s[i] >= 'A' && s[i] <= 'F' )){
				num++;
				zero =false;
				cout << s[i]; 
				ans *= 16;
				ans += s[i] - 'A' + 10;
				if(num >= 8){
					start = 0;
					zero =1;
					cout << " " << ans << '\n';
					ans = 0;
					num = 0;
				}
			}else{
				start = 0;
				zero =1;
				cout << " " << ans << '\n';
				ans = 0;
				num = 0;
				continue;
			}
		}
		if(start){
			start = 0;
			zero =1;
			cout << " " << ans << '\n';
			ans = 0;
			num = 0;
		}
			
	}
	
	return 0;
} 
