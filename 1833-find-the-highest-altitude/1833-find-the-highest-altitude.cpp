class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0, current = 0;
        for(int i = 0; i < gain.size(); i++)
        {
            current += gain[i];
            max = std::max(current, max);
        }
        return max;
    }
};