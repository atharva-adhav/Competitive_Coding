//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits>
#include <limits.h>
#include <iomanip>
#include <algorithm>
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

const int MAX_N = 5e3+2;
unordered_map<int, int> adj[MAX_N];

int dfs(int u, int p, int val, int k) {
    int ans = 0;
    for(auto to : adj[u]) {
        if(to.first == p) continue;
        if(min(val, to.second) >= k) {
            ans += 1+dfs(to.first, u, min(val, to.second), k);
        }
    }
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < N-1; i++) {
        int a, b, r;
        cin >> a >> b >> r;
        adj[a][b] = r;
        adj[b][a] = r;;
    }

    for(int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        cout << dfs(v, -1, INT_MAX, k) << '\n';
    }
}

int main() 
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    IOS;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}