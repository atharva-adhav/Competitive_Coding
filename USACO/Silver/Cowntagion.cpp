// http://www.usaco.org/index.php?page=viewproblem2&cpid=1062

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
int d[MAXN];


void solve() {
    int N;
    cin >> N;
    for(int i = 0, a, b; i < N-1; i++) {
        cin >> a >> b;
        d[a]++; d[b]++;
    }
    int ans = N-1;
    for(int i = 1; i <= N; i++) {
        if(d[i] > 1 || i == 1) {
            int children = d[i];
            if(i != 1)
                children--;
            
            int log_c = 0, pow = 1;
            while(pow < children+1) {
                log_c++; pow *= 2;
            }
            ans += log_c;
        }
    }
    cout << ans << '\n';
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