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
const int MM = 2e3+5;
int N; int a[MM][MM]; vector<pair<char, int>> ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) cin >> a[i][j];
    }
    for(int i = 0; i < N; ++i){
        if(a[i][0] == 1){
            ans.push_back({'R', i+1});
            for(int j = 0; j < N; ++j){
                a[i][j] = !a[i][j];
            }
        }
    }
    for(int j = 0; j < N; ++j){
        if(a[0][j] == 1){
            ans.push_back({'C', j+1});
            for(int i = 0; i < N; ++i) a[i][j] = !a[i][j];
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(a[i][j] != 0){cout << -1 << "\n"; return 0;}
        }
    }
    cout << ans.size() << "\n";
    for(pair<char, int> x : ans) cout << x.first << " " << x.second << "\n";
}   