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
int N, M;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    if(N == 1 && M == 1) cout << 1 << "\n";
    else if(N == 1 || M == 1) cout << 2 << "\n";
    else cout << 4 << "\n";
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(i%2){
                if(j%2) cout << 4 << " ";
                else if(M == 1) cout << 2 << " ";
                else cout << 3 << " ";
            }else{
                if(j%2) cout << 2 << " ";
                else cout << 1 << " ";
            }
        }
        cout << "\n";
    }
}
