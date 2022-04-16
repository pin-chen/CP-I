#include <bits/stdc++.h>
#define pii pair<int, int>
#define pip pair<int, pii>
#define fst first
#define sec second
using namespace std;

int n, m;
int arr[502][502] = {};
int tag[502][502] = {};
int count1 = 0;
bool TF = false;
void dfs(int x, int y, int h){
	if(tag[x][y] == 0) return;
	if(arr[x][y] < h){
		TF = false;
		return;
	}
	if(tag[x][y] != -1) return;
	if(arr[x][y] > h){
		return;
	}
	
	tag[x][y] = 10;
	count1++;
	dfs(x+1, y, h);
	dfs(x-1, y, h);
	dfs(x, y+1, h);
	dfs(x, y-1, h);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
			tag[i][j] = -1;
		}
	}
	for(int i = 1; i <= m; i++){
		tag[n + 1][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		tag[i][m + 1] = 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			count1 = 0;
			TF = true;
			dfs(i, j, arr[i][j]);
			ans += TF * count1;
		}
	}
	cout << ans << '\n';
	return 0;
}
