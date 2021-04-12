// https://usaco.guide/silver/prefix-sums?lang=cpp

class Solution {
public:

    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] + nums[i];
        
        // for(auto &x : pref)
        //     cout << x << ' ';
        // cout << endl;
        
        int left, right;
        right = pref[n-1] - pref[0];
        if(right == 0)
            return 0;
        for(int i = 1; i < n-1; i++) {
            left = pref[i-1];
            right = pref[n-1] - pref[i];
            cout << left << ' ' << right << '\n';
            if(left == right)
                return i;
        }
        left = pref[n-2];
        if(left == 0)
            return n-1;
        return -1;
    }
};