class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; //prune
            if (nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue; //prune
            for (int j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break; //prune
                if (nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) continue; //prune
                int lb = j + 1;
                int ub = len - 1;
                while (lb < ub) {
                    if (nums[i] + nums[j] + nums[lb] + nums[ub] > target) {
                        do { ub--; } while (lb < ub && nums[ub] == nums[ub + 1]);
                    } else if (nums[i] + nums[j] + nums[lb] + nums[ub] < target) {
                        do { lb++; } while (lb < ub && nums[lb] == nums[lb - 1]);
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[lb], nums[ub]});
                        do { ub--; } while (lb < ub && nums[ub] == nums[ub + 1]);
                        do { lb++; } while (lb < ub && nums[lb] == nums[lb - 1]);
                    }
                }
            }
        }
        return result;
    }
};