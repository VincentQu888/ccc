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
const int MM = 1e6+5;
int N, p[MM], d[MM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N; 
	for(int i = 0; i < N; ++i){
		cin >> p[i];
		if(p[i] < i+1){d[p[i]-1] += 1; d[i+1] -= 1;}
		else if(p[i] > i+1){d[i] += 1; d[p[i]] -= 1;}
	}
	int sum = 0, ans = 0;
	for(int i = 0; i < N; ++i){
		sum += d[i];
		if(sum) ++ans;
	}
	cout << ans << "\n";
}
