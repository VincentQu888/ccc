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
string S; unordered_map<char, int> mp; const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S; ll ans = 1;
    for(char x : S) mp[x] += 1;
    for(int i = 0; i < 26; ++i) ans = (ans * (mp[(char)(i + 'a')]+1))%mod;
    cout << ans << "\n";
}
