class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int s1len = nums1.size();
        int s2len = nums2.size();
        int totallen = s1len + s2len;
        int lowb = 0, upb = s1len;
        int s1d = (lowb + upb) / 2; // the leftmost pos of right part
        int s2d = (totallen / 2) - s1d; // the leftmost pos of right part
        
        int s1l = (s1d - 1) < 0 ? INT_MIN : nums1[s1d - 1];
        int s2l = (s2d - 1) < 0 ? INT_MIN : nums2[s2d - 1];
        int s1r = s1d < s1len ? nums1[s1d] : INT_MAX;
        int s2r = s2d < s2len ? nums2[s2d] : INT_MAX;
        
        while (max(s1l, s2l) > min(s1r, s2r)) { // break cond: 
            if (s1l > s2r) { // left move
                if (upb == s1d) {
                    upb--;
                } else {
                    upb = s1d;
                }
            } else if (s2l > s1r) { // right move
                if (lowb == s1d) {
                    lowb++;
                } else {
                    lowb = s1d;
                }
            }
            s1d = (lowb + upb) / 2;
            s2d = (totallen / 2) - s1d;
            
            s1l = (s1d - 1) < 0 ? INT_MIN : nums1[s1d - 1];
            s2l = (s2d - 1) < 0 ? INT_MIN : nums2[s2d - 1];
            s1r = s1d < s1len ? nums1[s1d] : INT_MAX;
            s2r = s2d < s2len ? nums2[s2d] : INT_MAX;
        }

        if (totallen % 2) {
            return min(s1r, s2r);
        } else {
            return (max(s1l, s2l) + min(s1r, s2r)) / (double)2;
        }
    }
};