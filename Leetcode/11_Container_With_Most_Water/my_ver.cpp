class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int lp = 0;
        int rp = height.size() - 1;
        int area = 0;
        while(lp < rp) {
            area = min(height[lp], height[rp]) * (rp - lp);
            if (area > max) max = area;
            if (height[lp] > height[rp]) {
                rp--;
            } else if (height[lp] < height[rp]) {
                lp++;
            } else if (height[lp] == height[rp]) {
                if (height[lp + 1] > height[rp - 1]) {
                    lp++;
                } else {
                    rp--;
                }
            }
        }
        return max;
    }
};