// Topic: DFS
// https://usaco.guide/silver/dfs?lang=cpp
// http://www.usaco.org/index.php?page=viewproblem2&cpid=668

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
    int x, y, p;
};

const int MaxN = 202;
vector<int> adj[MaxN];

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

vector<int> visited;
int dfs(int u) {
    visited[u] = 1;
    int ret = 0;
    for(int to : adj[u]) {
        if(!visited[to]) {
            ret += dfs(to);
        }
    }
    return ret+1;
}

void solve() {
    int N;
    cin >> N;
    vector<struct node> graph(N);
    for(int i = 0; i < N; i++) {
        int x, y, p;
        cin >> graph[i].x >> graph[i].y >> graph[i].p;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            double dist = distance(graph[i].x, graph[i].y, graph[j].x, graph[j].y);
            if(dist <= (graph[i].p * 1.0))
                adj[i].push_back(j);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        visited = vector<int>(N);
        ans = max(ans, dfs(i));
    }
    cout << ans;
}

int main() 
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    IOS;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}