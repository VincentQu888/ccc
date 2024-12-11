#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define int long long
int N; map<int, int> mp; deque<int> dq;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i = 0, x; i < N; ++i){
		cin >> x;
		mp[x] += 1;
	}
	for(auto it : mp) dq.push_back(it.first);
	int a = 0, b = 0, mn = dq.front(), mx = dq.back();
	while(dq.size() >= 2){
		if(a <= b) mn = dq.front();
		else mx = dq.back();
		while(a <= b && dq.size() >= 2){
			a += mp[dq.front()]; int temp = mp[dq.front()];
			dq.pop_front();
			mp[dq.front()] += temp;
		}
		if(a <= b) mn = dq.front();
		else mx = dq.back();
		while(b < a && dq.size() >= 2){
			b += mp[dq.back()]; int temp = mp[dq.back()];
			dq.pop_back();
			mp[dq.back()] += temp;
		}
		if(a <= b) mn = dq.front();
		else mx = dq.back();
	}
	if(a >= b) cout << "Slavko" << "\n";
	else cout << "Mirko" << "\n";
	cout << mn << " " << mx << "\n";
}
