// Topic: Prefix Sum
// https://usaco.guide/silver/prefix-sums?lang=cpp
// http://www.usaco.org/index.php?page=viewproblem2&cpid=595


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
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void solve() {
    int N;
    cin >> N;
    vector<int> a(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    vector<int> pref(N+1);
    for(int i = 1; i <= N; i++) {
        pref[i] = pref[i-1] + a[i];
    }

    int max_size = 0;
    for(int L = N; L >= 1; L--) {
        for(int i = 1; i+L-1 <= N; i++) {
            if((pref[i+L-1] - pref[i-1]) % 7 == 0) {
                max_size = L;
                break;
            }
        }
        if(max_size > 0)
            break;
    }
    cout << max_size;
}

int32_t main() 
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    IOS;

    solve();
    return 0;
}