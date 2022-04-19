#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t[4];
	for(int i = 0; i < 4; i++){
		double x;
		cin >> x;
		t[i] = x * 1000;
	}
	double x;
	cin >> x;
	int win = x * 1000;
	sort(t, t+4);
	int sum1 = t[0] + t[1] + t[2];
	int sum2 = t[1] + t[2] + t[3];
	if(sum1 / 3 > win){
		cout << "impossible\n";
	}else if(sum2 / 3 <= win){
		cout << "infinite\n";
	}else{
		int ans = win * 3 - t[1] - t[2];
		int x = ans % 10;
		ans /= 10;
		int x1 = ans % 10 + (x >=5);
		ans/=10;
		int x2 = ans % 10 + x1/10;
		ans/= 10;
		ans += x2/10;
		cout << ans << '.' << x2%10 << x1%10 << '\n'; 
	}
	return 0;
}
