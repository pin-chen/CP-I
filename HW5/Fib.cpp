#include <bits/stdc++.h>
#define int long long
#define square vector<vector<int>>

using namespace std;
square mult(square& A, square& B){
	square C;
	int n = A.size();
	int m = B.size();
	int l = B[0].size();
	C.resize(n);
	for(int i = 0; i < n; i++){
		C[i].resize(l);
		for(int j = 0; j < m; j++){
			for(int k = 0; k < l; k++){
				C[i][k] += A[i][j] * B[j][k];
			}
		}
	}
	return C;
}

square pow1(square base, int num){
	square ans;
	int n = base.size();
	int m = base[0].size();
	ans.resize(n);
	for(int i = 0; i < n; i++){
		ans[i].resize(m);
		ans[i][i] = 1;
	}
	while(num){
		if(num & 1)  ans = mult(ans, base);
		base = mult(base, base);
		num >>= 1;
	}
	return ans;
}

int fib(int n){
	square A = {
		{1, 1},
		{1, 0}
	};
	if(n <= 1) return n;
	return pow1(A ,n-1)[0][0];
}

int32_t main(){
	
	return 0;
} 
