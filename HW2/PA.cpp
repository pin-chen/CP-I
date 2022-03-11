#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n] = {};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            arr[n] |= x;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}


