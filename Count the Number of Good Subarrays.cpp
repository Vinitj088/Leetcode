class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        int left = 0;
        long long pairs = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; ++right) {
            // Update the frequency of the current element
            if (freq.find(nums[right]) != freq.end()) {
                pairs += freq[nums[right]];
            }
            freq[nums[right]]++;

            // Shrink the window from the left until the number of pairs is less than k
            while (pairs >= k) {
                count += (n - right); // All subarrays ending at right are good
                freq[nums[left]]--;
                pairs -= (freq[nums[left]]);
                left++;
            }
        }

        return count;
    }
};
