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
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void solve() {
    int N;
    cin >> N;
    vector<int> pos(7, -1);
    long long sum = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum += a;
        if(pos[sum%7] == -1)
            pos[sum%7] = i;
        else
            ans = max(ans, i - pos[sum%7]);
    }
    cout << ans;
}

int main() 
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    IOS;

    solve();
    return 0;
}