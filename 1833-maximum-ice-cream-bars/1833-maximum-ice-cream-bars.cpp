class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int canBuy = 0;
        for(int cost : costs)
        {
            if(coins >= cost)
            {
                coins -= cost;
                canBuy++;
            }
            else
            {
                break;
            }
            
        }
        return canBuy;
    }
};