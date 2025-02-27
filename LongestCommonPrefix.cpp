class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the array is empty, return empty string
        if (strs.empty()) {
            return "";
        }
        
        // If there's only one string, return that string
        if (strs.size() == 1) {
            return strs[0];
        }
        
        // Start with the first string as the initial prefix
        string prefix = strs[0];
        
        // Compare with each subsequent string
        for (int i = 1; i < strs.size(); i++) {
            // While current string doesn't start with prefix
            while (strs[i].find(prefix) != 0) {
                // Reduce prefix length by 1 from the end
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, return ""
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};
