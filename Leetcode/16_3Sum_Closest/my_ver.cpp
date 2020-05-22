class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int min_diff = INT_MAX;
        int closest = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            int lb = i + 1;
            int ub = len - 1;
            while (lb < ub) {
                if (abs(nums[lb] + nums[ub] + nums[i] - target) < min_diff) {
                    min_diff = abs(nums[lb] + nums[ub] + nums[i] - target);
                    closest = nums[lb] + nums[ub] + nums[i];
                }
                if (nums[lb] + nums[ub] + nums[i] > target) {
                    ub--;
                } else if (nums[lb] + nums[ub] + nums[i] < target) {
                    lb++;
                } else {
                    return target;
                }
            }
        }
        return closest;
    }
};