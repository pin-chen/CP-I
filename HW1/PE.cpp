#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			pq.push(x);
		}
		int ans = 0;
		while(pq.size() > 1 ){
			int sum = 0;
			sum += pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			ans += sum;
			pq.push(sum);
		}
		
		cout << ans << '\n';
	}
		
	
	return 0;
} 
