#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
	}
	sort(arr, arr+n);
	int Min = n;
	for(int i = 0; i < n; i++){
		Min = min (Min, (n - i -1 + arr[i]));
	}
    cout << Min << '\n';
    return 0;
}
