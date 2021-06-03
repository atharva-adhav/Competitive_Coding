// Question: https://dmoj.ca/problem/ccc16s3

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

const int MAXN = 1e5+2;
vector<int> adj[MAXN];
unordered_set<int> pho;
bool valid[MAXN];
int root, dist[MAXN];

void dfs(int u, int p) {
    if(pho.find(u) != pho.end())
        valid[u] = true;
    for(int to : adj[u]) {
        if(p == to) continue;
        dfs(to, u);
        valid[u] |= valid[to];    
    }
}



void solve() {
    int N, M;
    cin >> N >> M;
    for(int i = 0, a; i < M; i++) {
        cin >> a;
        pho.insert(a);
        if(i == 0)
            root = a;
    }
    for(int i = 0, a, b; i < N-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(root, -1);
    int valid_nodes = 0;
    for(int i = 0; i < N; i++) {
        if(valid[i])
            valid_nodes++;
    }

    queue<int> q;
    memset(dist, -1, sizeof(dist));
    dist[root] = 0;
    q.push(root);
    int max_node = -1, max_dist = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int to : adj[u]) {
            if(valid[to] && dist[to] == -1) {
                q.push(to);
                dist[to] = dist[u] + 1;
                if(dist[to] > max_dist) {
                    max_dist = dist[to];
                    max_node = to;
                }
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    dist[max_node] = 0;
    q.push(max_node);
    max_dist = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int to : adj[u]) {
            if(valid[to] && dist[to] == -1) {
                q.push(to);
                dist[to] = dist[u] + 1;
                if(dist[to] > max_dist) {
                    max_dist = dist[to];
                    max_node = to;
                }
            }
        }
    }

    cout << max_dist + (valid_nodes - max_dist - 1) * 2 << '\n';
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