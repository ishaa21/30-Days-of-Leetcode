class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0 ; i < nums.size(); i++)
        {
            int num = nums[i];
            int more = target - nums[i];
            if(mpp.find(more) != mpp.end())
            {
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};