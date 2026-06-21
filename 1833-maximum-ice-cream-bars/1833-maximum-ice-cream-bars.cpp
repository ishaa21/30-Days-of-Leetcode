class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(),costs.end());
        vector<int> freq(maxCost + 1,0);
        int count = 0;
        for(int c : costs)
        {
            freq[c]++;
        }

        for(int cost = 1; cost <= maxCost; cost++)
        {
            if(freq[cost] == 0) continue;
            int buy = min(freq[cost], coins/cost);
            coins -= buy * cost;
            count += buy;
            if(coins < cost) break;
        }
        return count;
    }
};