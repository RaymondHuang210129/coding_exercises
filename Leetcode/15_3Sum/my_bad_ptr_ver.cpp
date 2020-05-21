class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (auto it = nums.begin(); it < nums.end() - 2; it++) {
            if (it != nums.begin() && *it == *prev(it)) continue;
            if (*it > 0) break;
            auto low_it = it + 1;
            auto high_it = nums.end() - 1;
            while (low_it < high_it) {
                if (*low_it + *high_it > -*it) {
                    high_it -= 1;
                } else if (*low_it + *high_it < -*it) {
                    low_it += 1;
                } else {
                    result.push_back({*it, *low_it, *high_it});
                    do {high_it -= 1;} while (high_it > low_it && *high_it == *(high_it + 1));
                    do {low_it += 1;} while ( high_it > low_it && *low_it == *(low_it - 1));
                }
            }  
        }
        return result;
    }
};