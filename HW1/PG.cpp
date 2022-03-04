#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, p;
	cin >> n >> m >> p;
	double c[n];
	double d[m];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < m; i++){
		cin >> d[i];
	}
	
	double r[n*m] = {};
	int k = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			r[k++] = c[i]/d[j];
		}
	}
	
	sort(r, r + k);
	
	for(int i = 0; i < k - 1; i++){
		double cur = r[i];
		double next = r[i + 1];
		if(cur + cur * p / 100 < next){
			cout << "Time to change gears!\n";
			return 0;
		}
	}
	cout << "Ride on!\n";
	return 0;
} 
