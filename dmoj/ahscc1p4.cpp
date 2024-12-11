#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
const int MM = 2e5+5;
int N, Q, a[MM];
unordered_set<int> d;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		if(i > 0 && a[i-1] > a[i]) d.emplace(i-1);
	}
	if(a[N-1] > a[0]) d.emplace(N-1);
	for(int j = 0, i, x; j < Q; ++j){
		cin >> i >> x; --i;
		if(i < N-1 && a[i] > a[i+1]) d.erase(i);
		if(i >= 1 && a[i-1] > a[i]) d.erase(i-1);
		if((i == N-1 || i == 0) && a[N-1] > a[0]) d.erase(N-1);
		a[i] = x;
		if(i < N-1 && a[i] > a[i+1]) d.emplace(i);
		if(i >= 1 && a[i-1] > a[i]) d.emplace(i-1);
		if((i == N-1 || i == 0) && a[N-1] > a[0]) d.emplace(N-1);
		if(d.size() > 1) cout << -1 << "\n";
		else if(d.size() == 1){
			for(int y : d) cout << min(y+1, N-(y+1)) << "\n";
		}else cout << 0 << "\n";
	}
}
