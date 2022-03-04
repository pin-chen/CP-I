#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>&a, pair<int,int>&b){
	if(a.first == b.first){
		return a.second > b.second;
	}else{
		return a.first < b.first;
	}
}

int main(){
	int n, t;
	cin >> n >> t;
	pair<int, int> person[n];
	for(int i = 0; i < n; i++){
		cin >> person[i].second >> person[i].first;
	}
	sort(person, person + n, cmp);
	for(int i = 0; i < n; i++){
		cout << person[i].first << " " << person[i].second;
		cout << '\n';
	}
	queue<pair<int,int>> q;
	int Max = 0;
	int cur = 0;
	for(int i = 0; i < n; i++){
		if(q.size() <= person[i].first){
			q.push(person[i]);
			cur += person[i].second;
		}else{
			int x = t - person[i].first;
			while(--x){
				cur -= q.front().second;
				q.pop();
			}
			q.push(person[i]);
			cur += person[i].second;
		}
		Max = max(Max, cur);
	}
	cout << Max << '\n';
	
	return 0;
} 

