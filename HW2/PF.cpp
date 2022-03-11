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
			bottom = min(last.second, bottom);
			if(last.first > h[i]){
				st.push(make_pair(last.first, bottom));
				ans = max(ans, h[i] - bottom);
				break;
			}
			ans = max(ans, last.first - bottom);
		}
		st.push(make_pair(h[i], h[i]));
	}
	
	cout << ans << '\n';
	return 0;
} 
