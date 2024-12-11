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
const int MM = 105;
int vis[MM], freq[MM], N;
vector<int> adj[MM];
void dfs(int u, int col){
    for(int v : adj[u]){
        if(!vis[v]){
            vis[v] = col;
            freq[col] += 1;
            dfs(v, col);
        }
    }
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return (a/gcd(a, b))*b;
}
void clearAdjacencyList() {
    for (int i = 0; i < MM; i++) {
        adj[i].clear(); // Clear each vector in the array
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N != 0){
        memset(vis, 0, sizeof(vis)); memset(freq, 0, sizeof(freq)); clearAdjacencyList();
        for(int i = 0, a, b; i < N; ++i){
            cin >> a >> b;
            adj[a].push_back(b);
        }
        int cnt = 1, ans = 1;
        for(int i = 1; i <= N; ++i){if(!vis[i]){dfs(i, cnt); ++cnt;}}
        for(int i = 1; i < cnt; ++i){
            ans = lcm(ans, freq[i]);
        }
        cout << ans << "\n";
        cin >> N;
    }
}
