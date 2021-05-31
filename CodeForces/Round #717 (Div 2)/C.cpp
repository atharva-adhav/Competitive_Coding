// Topic: DP, Bitset
// https://codeforces.com/contest/1516
// Rating: 1700

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
#include <bitset>
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

const int MAX_VAL = 2e5+5;

bool bad(vector<int> a) {
    int sum = 0;
    for(int v : a)
        sum += v;

    // checking if sum is odd
    if(sum % 2 == 1)
        return false;
    
    bitset<MAX_VAL> b;
    b[0] = 1;
    // stores all the combinations of sum
    for(int v : a)
        b |= (b << v);

    return b[sum/2]; // if there exists a way to get summation equals to sum/2, then its bad
}

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    for(auto &x : a) {
        cin >> x;
    }

    if(bad(a)) {
        pair<int, int> mn(30, 0);
        for(int i = 0; i < N; i++)
            mn = min(mn, {__builtin_ctz(a[i]), i+1}); // finding the number which has a set bit from right the earliest
        cout << "1\n" << mn.second;
    }
    else
        cout << 0;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    IOS;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


