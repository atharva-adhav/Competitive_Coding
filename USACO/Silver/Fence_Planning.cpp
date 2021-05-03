// Topic: DFS
// https://usaco.guide/silver/dfs?lang=cpp
// http://www.usaco.org/index.php?page=viewproblem2&cpid=944

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

struct node {
    int x, y;
};

const long long MAX_VAL = 1e16;
vector<struct node> coordinates;
vector<vector<int>> adj;
vector<int> visited;
int x_min, y_min, x_max, y_max;

void dfs(int u) {
    visited[u] = 1;
    x_min = min(x_min, coordinates[u].x); x_max = max(x_max, coordinates[u].x);
    y_min = min(y_min, coordinates[u].y); y_max = max(y_max, coordinates[u].y);
    for(int to : adj[u]) {
        if(!visited[to])
            dfs(to);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    coordinates.resize(N); visited = vector<int>(N);
    adj = vector<vector<int>>(N);
    for(int i = 0; i < N; i++) {
        cin >> coordinates[i].x >> coordinates[i].y;
    }
    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    long long ans = MAX_VAL;
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            x_min = y_min = INT_MAX;
            x_max = y_max = INT_MIN;
            dfs(i);
            long long peri = 2 * ((x_max - x_min) + (y_max - y_min));
            ans = min(ans, peri);
        }
    }
    cout << ans;
}

int main() 
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    IOS;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}