class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idxMap;  
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (idxMap.count(complement)) {
            return {idxMap[complement], i};
        }
        idxMap[nums[i]] = i;
    }
    return {}; 
        
    }
};