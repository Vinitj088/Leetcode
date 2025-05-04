class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> count(100, 0);  // Use an array for direct indexing
        int ans = 0;

        for (auto& domino : dominoes) {
            int a = min(domino[0], domino[1]);
            int b = max(domino[0], domino[1]);
            int key = a * 10 + b;

            ans += count[key];
            count[key]++;
        }

        return ans;
    }
};
