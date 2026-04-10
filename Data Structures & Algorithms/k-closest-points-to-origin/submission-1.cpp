class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;


        vector<vector<int>>ans;
        int dist=0;
        for(int i=0;i<points.size();i++){
            dist=(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);

            pq.push({dist,i});
            if (pq.size()>k)pq.pop();
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int index = it.second;
            ans.push_back({points[index][0], points[index][1]});
        }
        return ans;
    }
};
