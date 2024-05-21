class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            int n = nums.size();
           	//doing using hashmap since we have to return original index. sorting and applying 2 pointer wont work for this
            unordered_map<int, int> mpp;
            for (int i = 0; i < n; i++)
            {
                mpp[nums[i]]=i;
            }
            for (int i = 0;i<n;i++){
                int rem=target-nums[i];
                if (mpp.count(rem) && mpp[rem]!=i){
                    return {i,mpp[rem]};
                }
            }
            return {};
        }
};