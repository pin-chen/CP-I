#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int space[n], house[m+k];
    for(auto &x : space){
        cin >> x;
    }
    for(int i = 0; i < m; i++){
        cin >> house[i];
    }
    for(int i = m; i < m+k; i++){
        cin >> house[i];
        house[i] *= sqrt(2);
    }
    int ans = 0;
    sort(space, space + n);
    //for(auto x : space) cout << x << " ";
    //cout << '\n';
    sort(house, house + m + k);
    //for(auto x : house) cout << x << " ";
    //cout << '\n';
    int i = n - 1;
    int j = m + k - 1;
    while(i >= 0 &&  j >= 0){
    	cout << space[i] << " " << house[j] << '\n'; 
        if(space[i] > house[j]){
            ans++;
            i--;
            j--;
        }else{
            j--;
        }
    }
    cout << ans << '\n';
    return 0;
}
