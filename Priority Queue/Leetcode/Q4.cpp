class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int c = 0, v = 0;
        sort(costs.begin(), costs.end());
        for (v = 0; v < costs.size(); v++)
        {
            if (coins >= costs[v])
            {
                c++;
                coins -= costs[v];
            }
            if (coins <= 0)
                return c;
        }
        return c;
    }
};