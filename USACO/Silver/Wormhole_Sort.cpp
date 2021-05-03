// Topic: DFS, Binary Search
// https://usaco.guide/silver/dfs?lang=cpp
// http://www.usaco.org/index.php?page=viewproblem2&cpid=992
// Level: Medium

// Use binary search for width, then check for each network of connected component if the destination index and
// inital index are in same networks

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

const int MAX_N = 1e5+2;
int N, M;
vector<int> p, component;
vector<pair<int, int>> adj[MAX_N];

void dfs(int u, int label, int minW) {
    component[u] = label;
    for(auto &to : adj[u]) {
        if(to.second < minW || component[to.first] != -1) continue;
        dfs(to.first, label, minW);
    }
}

bool ok(int curr_wid) {
    fill(component.begin(), component.end(), -1);
    int label = -1;

    for(int i = 0; i < N; i++) {
        if(component[i] != -1) continue;
        dfs(i, ++label, curr_wid);
    }

    for(int i = 0; i < N; i++) {
        if(component[i] != component[p[i]]) return false;
    }
    return true;
}

void solve() {
    cin >> N >> M;
    p.resize(N); component.resize(N);
    for(auto &x : p) {
        cin >> x;
        x--;
    }
    for(int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int lo = 1, hi = (int)1e9+1;
    int top = hi, sol = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(ok(mid)) {
            sol = max(sol, mid);
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    if(sol == top)
        cout << -1;
    else
        cout << sol;
}

int main() 
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    IOS;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}