class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create hash map to store number:index pairs
        unordered_map<int, int> numMap;
        
        // Iterate through the vector
        for (int i = 0; i < nums.size(); i++) {
            // Calculate complement
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                // Return indices when solution found
                return {numMap[complement], i};
            }
            
            // Add current number and index to map
            numMap[nums[i]] = i;
        }
        
        // Problem guarantees a solution exists
        return {};  // Empty vector if no solution (won't be reached)
    }
};
