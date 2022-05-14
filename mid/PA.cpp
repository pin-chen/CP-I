#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fst first
#define sec second
using namespace std;

int gcd1(int a, int b, int& x, int& y);

void inverse(int a, int p){
	//cout << a << " " << p << '\n';
	int x, y;
	int g = gcd1(a, p, x, y);
	//cout << x  << " "<< y << '\n';
	//cout << g << '\n';
	if(g != 1){
		cout << "-1\n"; 
	}else{
		int r = (x % p + p) % p;
		cout << r << '\n';
	}
}

int gcd1(int a, int b, int& x, int& y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd1(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int a, p;
		cin >> a >> p;
		inverse(a, p);
	}
	return 0;
} 
