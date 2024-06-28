class Solution {
public:
    vector<int> euclidean(vector<vector<int>>& points){
        vector<int> ans;
        for(int i=0;i<points.size();i++){
            int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            ans.push_back(dist);
        }
        return ans;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closest;
        vector<int> dist = euclidean(points);
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<points.size(); i++){
            pq.push({dist[i], i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            closest.push_back(points[pq.top().second]);
            pq.pop();
        }

        return closest;
    }
};