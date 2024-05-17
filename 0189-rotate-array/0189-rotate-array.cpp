class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the bounds of the array length
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
