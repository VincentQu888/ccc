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
const int MM = 2e5+5;
int N, D, a[MM], subtree_size[MM], pointers[MM], step[MM]; 
auto comp = [](int a, int b){return step[a] > step[b];};
bool removed[MM];
vector<int> adj[MM]; vector<pii> paths[MM], ctree[MM];
priority_queue<int, vector<int>, decltype(comp)> pq(comp);

int get_size(int cur, int prev){
    subtree_size[cur] = 1;
    for(int next : adj[cur]){
        if(next != prev && !removed[next]){
            subtree_size[cur] += get_size(next, cur);
        }
    }
    return subtree_size[cur];
}

int get_centroid(int cur, int prev, int tree_size){
    for(int next : adj[cur]){
        if(next != prev && !removed[next] && subtree_size[next]*2 > tree_size){
            return get_centroid(next, cur, tree_size);
        }
    }
    return cur;
}

void build(int cur){
    int sz = get_size(cur, -1);
    int centroid = get_centroid(cur, -1, sz);
    removed[centroid] = true;
    paths[centroid].push_back({centroid, 0});
    ctree[centroid].push_back({centroid, 0});
    queue<pair<int, pii>> q; q.emplace(make_pair(centroid, make_pair(-1, 0))); 
    while(!q.empty()){
        int u = q.front().first, par = q.front().second.first, tempd = q.front().second.second; 
        q.pop();
        for(int v : adj[u]){
            if(v != par && !removed[v]){
                q.emplace(make_pair(v, make_pair(u, tempd+1)));
                paths[centroid].push_back({v, tempd+1});
                ctree[v].push_back({centroid, tempd+1});
            }
        }
    }

    for(int next : adj[centroid]){
        if(!removed[next]) build(next);
    }
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    memset(pointers, 0, sizeof(pointers)); memset(step, INF, sizeof(step));
	cin >> N >> D;
	for(int i = 1; i <= N; ++i) cin >> a[i]; 
	for(int i = 0, u, v; i < N-1; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	build(1); 
    memset(removed, 0, sizeof(removed));
    
	pq.push(1); step[1] = 0;
	while(!pq.empty()){ //jstu find distance to immediate centroid and add as u lbikmc!!!
		int u = pq.top(); pq.pop();
        for(int i = ctree[u].size()-1; i >= 0; --i){
            int centroid = ctree[u][i].first, cdist = ctree[u][i].second;
            for(; pointers[centroid] < paths[centroid].size() && paths[centroid][pointers[centroid]].second+cdist <= D; ++pointers[centroid]){
                int v = paths[centroid][pointers[centroid]].first;
                if(step[u]+a[v] < step[v]){
                    step[v] = step[u]+a[v];
                    pq.push(v);
                }
            }
        }
	}

    for(int i = 1; i < N; ++i) cout << step[i] << " ";
    cout << step[N] << "\n";
}
