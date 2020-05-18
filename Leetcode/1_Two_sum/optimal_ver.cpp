class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // num, index
        for (int i = 0;; i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return vector<int>{it->second, i};
            }
            map[nums[i]] = i;
        }
        return vector<int> {0, 0};
    }
};