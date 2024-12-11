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
int N, A, B;
auto compare = [](pii a, pii b) {
    return A*a.first+B*a.second > A*b.first+B*b.second;
};
priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B;
    pq.push({1, 1}); int ans = 0;
    for(int i = 0; i < N; ++i){
        pii cur = pq.top();
        ans += A*cur.first + B*cur.second;
        pq.push({cur.first, cur.second+1}); 
        if(cur.second == 1) pq.push({cur.first+1, cur.second});
        pq.pop();
    }
    cout << ans << "\n";
}
