
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;

        int n = servers.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
            available.push({servers[i], i});

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            if (available.empty())
                time = max(time, busy.top().first);

            while (!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();
                available.push({servers[idx], idx});
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans.push_back(idx);
            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};
