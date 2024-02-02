class Solution
{
public:
    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        return a.second > b.second;
    }
    vector<string> sort_by_value(map<string, int> &m, int k)
    {
        vector<pair<string, int>> v;
        for (auto hi : m)
            v.push_back(hi);
        sort(v.begin(), v.end(), cmp);
        for (auto hi : v)
        {
            cout << hi.first << " " << hi.second << endl;
        }
        vector<string> res;
        int prev = v[0].second;
        vector<string> result;
        for (auto hi : v)
        {
            if (hi.second != prev)
            {
                vector<string> t = res;
                sort(t.begin(), t.end());
                res.clear();
                for (auto hi : t)
                {
                    result.push_back(hi);
                }
                prev = hi.second;
            }
            res.push_back(hi.first);
        }
        sort(res.begin(), res.end());
        for (auto hi : res)
        {
            result.push_back(hi);
        }
        vector<string> final_result;
        for (auto hi : result)
        {
            if (k == 0)
                break;
            final_result.push_back(hi);
            k--;
        }
        return final_result;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }
        return sort_by_value(m, k);
    }
};