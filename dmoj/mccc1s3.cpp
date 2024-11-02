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
const int MM = 2e5+5;
struct node{
	int ch[26], id;
} t[MM];
string s; int q, idx = 1, id = 1, mp[MM];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> q;
	for(char x : s){
		t[idx].id = id;
		t[idx-1].ch[x-'a'] = idx;
		++idx;
	}
	mp[1] = idx-1; t[0].id = -1; ++id;
	for(int i = 0; i < q; ++i){
		char cmd; cin >> cmd;
		if(cmd == 'C'){
			int x; char c;
			cin >> x >> c;
			if(!t[mp[x]].ch[c-'a']){
				t[idx].id = id;
				t[mp[x]].ch[c-'a'] = idx;
				++idx;
			}
			mp[id] = t[mp[x]].ch[c-'a'];
			++id;
		}else{
			string si;
			cin >> si;
			int cur = 0;
			for(char x : si){
				if(!t[cur].ch[x-'a']) break;
				cur = t[cur].ch[x-'a'];
			}
			cout << t[cur].id << "\n";
		}
	}
}