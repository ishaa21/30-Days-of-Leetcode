class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        vector<int> answer(n,0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                leftSum[i] += nums[j];
            }
            
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                rightSum[i] += nums[j];
            }
            
        }

        for(int i = 0; i < n; i++)
        {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
};