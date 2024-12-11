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
const int MM = 256+5;
struct L{int x1, y1, x2, y2, x3, y3;};
vector<L> ans;
int n, x, y, cnt = 0;
bool filled[MM][MM];
void solve(int xl, int yl, int xr, int yr, int tx, int ty){
	int xmid = (xl+xr)/2, ymid = (yl+yr)/2;
	if(xl+1 == xr){
		if(filled[xl][yl]){ans.push_back({xr, yl, xr, yr, xl, yr});}
		if(filled[xr][yl]){ans.push_back({xl, yl, xr, yr, xl, yr});}
		if(filled[xl][yr]){ans.push_back({xr, yl, xr, yr, xl, yl});}
		if(filled[xr][yr]){ans.push_back({xr, yl, xl, yl, xl, yr});}
		filled[xl][yl] = true; filled[xl][yr] = true; filled[xr][yr] = true; filled[xr][yl] = true;
		return;
	}
	if(xl <= tx && tx <= xmid && yl <= ty && ty <= ymid){
		ans.push_back({xmid+1, ymid, xmid, ymid+1, xmid+1, ymid+1});
		filled[xmid+1][ymid] = true; filled[xmid][ymid+1] = true; filled[xmid+1][ymid+1] = true;
		solve(xl, yl, xmid, ymid, tx, ty);
		solve(xl, ymid+1, xmid, yr, xmid, ymid+1);
		solve(xmid+1, yl, xr, ymid, xmid+1, ymid);
		solve(xmid+1, ymid+1, xr, yr, xmid+1, ymid+1);
	}else if(xl <= tx && tx <= xmid && ymid+1 <= ty && ty <= yr){
		ans.push_back({xmid+1, ymid+1, xmid+1, ymid, xmid, ymid});
		filled[xmid+1][ymid+1] = true; filled[xmid+1][ymid] = true; filled[xmid][ymid] = true;
		solve(xl, yl, xmid, ymid, xmid, ymid);
		solve(xl, ymid+1, xmid, yr, tx, ty);
		solve(xmid+1, yl, xr, ymid, xmid+1, ymid);
		solve(xmid+1, ymid+1, xr, yr, xmid+1, ymid+1);
	}else if(xmid+1 <= tx && tx <= xr && yl <= ty && ty <= ymid){
		ans.push_back({xmid, ymid, xmid, ymid+1, xmid+1, ymid+1});
		filled[xmid][ymid] = true; filled[xmid][ymid+1] = true; filled[xmid+1][ymid+1] = true;
		solve(xl, yl, xmid, ymid, xmid, ymid);
		solve(xl, ymid+1, xmid, yr, xmid, ymid+1);
		solve(xmid+1, yl, xr, ymid, tx, ty);
		solve(xmid+1, ymid+1, xr, yr, xmid+1, ymid+1);
	}else{
		ans.push_back({xmid, ymid, xmid, ymid+1, xmid+1, ymid});
		filled[xmid][ymid] = true; filled[xmid][ymid+1] = true; filled[xmid+1][ymid] = true;
		solve(xl, yl, xmid, ymid, xmid, ymid);
		solve(xl, ymid+1, xmid, yr, xmid, ymid+1);
		solve(xmid+1, yl, xr, ymid, xmid+1, ymid);
		solve(xmid+1, ymid+1, xr, yr, tx, ty);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x >> y;
	filled[x][y] = true;
	solve(0, 0, (int)pow(2, n)-1, (int)pow(2, n)-1, x, y);
	for(L nxt : ans) cout << nxt.x1 << " " << nxt.y1 << " " << nxt.x2 << " " << nxt.y2 << " " << nxt.x3 << " " << nxt.y3 << "\n";
}
