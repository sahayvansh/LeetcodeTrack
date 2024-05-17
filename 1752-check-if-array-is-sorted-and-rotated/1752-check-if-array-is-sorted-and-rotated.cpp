class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;  

        // Traverse the array and count the number of breaks
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1)%n]) {
                count++;
            }
        }

        // For the array to be a rotated sorted array, there should be at most one break.
        return count <= 1;
    }
};
