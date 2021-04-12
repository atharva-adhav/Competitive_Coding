// Topic: Prefix Sum
// https://usaco.guide/silver/prefix-sums?lang=cpp
// https://cses.fi/problemset/task/1650

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
 
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N+1);
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    
    vector<int> pref(N+1);
    for(int i = 1; i <= N; i++)
        pref[i] = (pref[i-1] ^ a[i]);
 
    while(Q--) {
        int st, end;
        cin >> st >> end;
        cout << (pref[end] ^ pref[st-1]) << '\n';
    }
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