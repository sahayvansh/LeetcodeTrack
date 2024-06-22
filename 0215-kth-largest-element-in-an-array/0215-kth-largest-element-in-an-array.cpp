class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minh(nums.begin(),nums.begin()+k);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>minh.top()){
                minh.pop();
                minh.push(nums[i]);
            }
        }
        return minh.top();
    }
};