    // http://www.usaco.org/index.php?page=viewproblem2&cpid=968
    
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
    int comp[MAXN];
    string type;

    void dfs(int u, char t, int cmp, int p) {
        comp[u] = cmp;
        for(int to : adj[u]) {
            if(to == p || type[to] != t) continue;
            dfs(to, t, cmp, u);
        }
    }

    void solve() {
        int N, M;
        cin >> N >> M;
        cin >> type;
        for(int i = 0; i < N-1; i++) {
            int a, b; 
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(comp[i] == 0) 
                dfs(i, type[i], ++cnt, i);
        }

        for(int i = 0; i < M; i++) {
            int a, b; string s;
            cin >> a >> b >> s;
            a--; b--; 

            int ok = 0;
            if(comp[a] == comp[b] && s[0] == type[a]) 
                ok = 1;
            else if(comp[a] != comp[b])
                ok = 1;

            cout << ok;
        }
        cout << '\n';
    }

    int main() 
    {
        freopen("milkvisits.in", "r", stdin);
        freopen("milkvisits.out", "w", stdout);
        IOS;

        int t = 1;
    // cin >> t;
        while(t--) {
            solve();
        }
        return 0;
    }