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
const int MM = 2e6+5;
string s; char a[MM];
int psaa[MM], psab[MM], cnta = 0, cntb = 0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s; psaa[0] = 0; psab[0] = 0;
    for(int i = 0; i < s.length(); ++i){
        a[i] = s[i]; a[i+s.length()] = s[i];
        if(a[i] == 'A') ++cnta;
        else if(a[i] == 'B') ++cntb;
    }
    int cntc = s.length()-cnta-cntb;
    for(int i = 0; i < 2*s.length(); ++i){
        if(a[i] == 'A') psaa[i+1] = psaa[i] + 1;
        else psaa[i+1] = psaa[i];
        if(a[i] == 'B') psab[i+1] = psab[i] + 1;
        else psab[i+1] = psab[i];
    }
    int ans = INF;
    for(int i = 0; i < s.length(); ++i){
        ans = min(ans, cnta - (psaa[i+cnta]-psaa[i]) + cntb - (psab[i+cnta+cntb]-psab[i+cnta]) - min(psaa[i+cnta+cntb]-psaa[i+cnta], psab[i+cnta]-psab[i]));
        ans = min(ans, cnta - (psaa[i+cnta]-psaa[i]) + (psaa[i+cnta+cntc]-psaa[i+cnta]) + (psab[i+cnta+cntc]-psab[i+cnta]) - min(psaa[i+cnta+cntc]-psaa[i+cnta], cnta - (psaa[i+cnta]-psaa[i]) - (psab[i+cnta]-psab[i])));
    }
    cout << ans << "\n";
}