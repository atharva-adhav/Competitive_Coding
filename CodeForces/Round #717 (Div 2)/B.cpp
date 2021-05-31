// Topic: Bruteforce
// https://codeforces.com/contest/1516
// Level: Easy-Medium
// Rating: 1500

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
    vector<int> a(N);
    for(auto &x : a)
        cin >> x;

    vector<int> dp(N);
    dp[0] = a[0];
    for(int i = 1; i < N; i++) {
        dp[i] = (dp[i-1] ^ a[i]);
    }

    // checking if final 2 numbers can be equal
    for(int i = 0; i < N-1; i++) {
        if((dp[N-1] ^ dp[i]) == dp[i]) {
            cout << "YES\n";
            return;
        }
    }

    if(N == 2) {
        cout << "NO\n";
        return;
    }


    // checking if final 3 numbers can be equal
    int curr_xor = a[0];
    for(int i = 1; i < N-1; i++) {
        curr_xor = a[i] ^ curr_xor;
        int k = curr_xor ^ dp[N-1];
        int new_xor = 0;
        for(int j = 0; j < i; j++) {
            new_xor  = new_xor ^ a[j];
            if((curr_xor ^ new_xor) == k && new_xor == k) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    IOS;

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}