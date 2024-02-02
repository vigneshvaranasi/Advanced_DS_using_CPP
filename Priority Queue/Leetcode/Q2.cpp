class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> p;
    int M;
    KthLargest(int k, vector<int> &nums)
    {
        M = k;
        for (int x : nums)
        {
            p.push(x);
            if (p.size() > k)
            {
                p.pop();
            }
        }
    }
    int add(int val)
    {
        p.push(val);
        if (p.size() > M)
        {
            p.pop();
        }
        return p.top();
    }
};