#include <bits/stdc++.h>
using namespace std;
int main(){
	int ans = 0;
	int n;
	cin >> n;
	int h[n];
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	
	stack<pair<int,int>> st;
	for(int i = 0; i < n; i++){
		int bottom = h[i];
		while(st.size() > 0){
			
			pair<int, int> last = st.top();
			st.pop();
			
			cout << "bottom:" << bottom << '\n';
			cout << "last.first :" << last.first  << '\n';
			cout << "last.second :" << last.second  << '\n';
			cout << "h[i]:" << h[i] << '\n';
			bottom = min(last.second, bottom);
			
			cout << "bottom:" << bottom << '\n';
			
			if(last.first > h[i]){
				st.push(make_pair(last.first, bottom));
				ans = max(ans, h[i] - bottom);
				cout << ans << '\n';
				break;
			}
			ans = max(ans, last.first - bottom);
			cout << ans << '\n';
		}
		st.push(make_pair(h[i], h[i]));
		cout << "h[i] x" << h[i] << '\n';
	}
	
	cout << ans << '\n';
	return 0;
} 
