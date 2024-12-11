#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
int N; unordered_map<int, ll> dp;
ll f(int N) {
    if(N == 1 || N == 2) return 1;
    if(dp.count(N)) return dp[N]; //1 2 3 4 5 6 10 || 11-20, 7-10, 6, 5, 4, 3, 2
    ll x = N, ret = 0;
    while(x >= 2){
        ll rep = x - N/(N/x+1);
        ret += rep*f(N/x);
        x = N/(N/x+1);
    }
    return dp[N] = ret;
}
int main() {
    cin >> N;
    cout << f(N) << "\n";
}
