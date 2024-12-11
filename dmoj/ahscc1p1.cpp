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
int N, X;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> X >> N;
    cout << (80*(N+1) - N*X > 100 ? -1 : max(80*(N+1) - N*X, 0)) << "\n";
}
