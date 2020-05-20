class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int nums[20];
        int i;
        for (i = 0; x > 0; i++) {
            nums[i] = x % 10;
            x /= 10;
        }
        i--;
        for (int j = 0; j < (i + 1) / 2; j++) {
            if (nums[j] != nums[i - j]) return false;
        }
        return true;
    }
};
