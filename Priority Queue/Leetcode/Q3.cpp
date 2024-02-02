class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int k)
    {
        double res = 0, n = classes.size(), v = 0;
        priority_queue<pair<double, int>> pq;
        for (auto x : classes)
            pq.push({((double)(x[0] + 1) / (x[1] + 1)) - ((double)(x[0]) / (x[1])), v++});
        while (k--)
        {
            int v = pq.top().second;
            int p = classes[v][0]++, t = classes[v][1]++;
            pq.pop();
            pq.push({((double)(p + 2) / (t + 2)) - ((double)(p + 1) / (t + 1)), v});
        }
        for (auto x : classes)
        {
            res += ((double)x[0]) / x[1];
        }
        return res / n;
    }
};