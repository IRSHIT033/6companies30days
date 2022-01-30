class Solution
{
    public:
    void djikstra(unordered_map<int,vector<pair<int,double>>>& graph, vector<double>& prob, int start)
    {
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        
        prob[start]=1;
        while(!pq.empty())
        {
            double probu=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            for(auto p:graph[u])
            {
                int v=p.first;
                double probv=p.second;
                
                double maybe=probv*probu;
                if(maybe>prob[v])
                {
                    prob[v]=maybe;
                    pq.push({prob[v],v});
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        unordered_map<int,vector<pair<int,double>>>graph;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});   
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});   
        }

        vector<double>prob(n,0);
        djikstra(graph,prob,start);
        return prob[end];
    }
};
