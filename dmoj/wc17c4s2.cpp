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
const int MM = 1e5+5;
int N, M, K, step[MM], step2[MM];
vector<pii> adj[MM];
queue<int> q;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	memset(step, INF, sizeof(step)); memset(step2, INF, sizeof(step));
	for(int i = 0, a, b; i < M; ++i){
		cin >> a >> b;
		adj[a].push_back({b, 0});
		adj[b].push_back({a, 1});
	}
	step[1] = 0; step2[1] = 0; q.emplace(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(pii v : adj[u]){
			if(step[u]+1 < step[v.first] && v.second == 0){
				step[v.first] = step[u]+1;
				q.emplace(v.first);
			}
			if(step2[u]+1 < step2[v.first] && v.second == 1){
				step2[v.first] = step2[u]+1;
				q.emplace(v.first);
			}
		}
	}
	cin >> K; int ans = 0;
	for(int i = 0, s; i < K; ++i){
		cin >> s;
		ans += step[s]; ans += step2[s];
		if(ans >= INF){cout << -1 << "\n"; return 0;}
	}
	cout << ans << "\n";
}
