// Topic: DFS
// https://usaco.guide/silver/dfs?lang=cpp
// https://cses.fi/problemset/task/1682
// Level: Medium

// If the vertex 1 can reach every other vertex and also the vertex can be reached by every other vertex, then the answer is true

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
vector<int> adj[MAX_N], adj2[MAX_N], visited;

void dfs(int u) {
    visited[u] = 1;
    for(int to : adj[u]) {
        if(!visited[to])
            dfs(to);
    }
}

void dfs2(int u) {
    visited[u] = 1;
    for(int to : adj2[u]) {
        if(!visited[to])
            dfs2(to);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    visited = vector<int>(N+1);
    dfs(1);
    for(int i = 2; i <= N; i++) {
        if(!visited[i]) {
            cout << "NO\n" << 1 << ' ' << i;
            return;
        }
    }

    visited = vector<int>(N+1);
    dfs2(1);
    for(int i = 2; i <= N; i++) {
        if(!visited[i]) {
            cout << "NO\n" << i << ' ' << 1;
            return;
        }
    }
    cout << "YES";
}

int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    IOS;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}