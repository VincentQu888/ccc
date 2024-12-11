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
int N; string a, s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> a >> s;
    int ans = 0, l = 0, r = 0;
    for(int i = 0; i < N; ++i) if(a[i] == s[i]) ++l;
    for(int i = N-2; i >= 0; --i){
        if(a[i] == s[i]) --l;
        if(a[i+1] == s[i]) ++r;
        ans = max(ans, l+r);
    }
    cout << ans << "\n";
}
