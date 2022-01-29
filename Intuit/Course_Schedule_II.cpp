class Solution {
public:
vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(vector<int>& arr: pre){
            graph[arr[1]].push_back(arr[0]);
            indegree[arr[0]]++;
        }
        queue<int> kyu;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) kyu.push(i);
        }
        
        vector<int> ans;
        while(kyu.size() != 0){
            int vtx = kyu.front();
            kyu.pop();
            ans.push_back(vtx);
            for(int nbr : graph[vtx]){
                if(--indegree[nbr] == 0) kyu.push(nbr);
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }
};
