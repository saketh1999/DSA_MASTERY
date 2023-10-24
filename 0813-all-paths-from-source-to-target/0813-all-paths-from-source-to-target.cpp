class Solution {
private:

void dfs(vector<vector<int>>& graph, vector<int>&visited, vector<int> &path,int v,int target)
{
    
    path.push_back(v);
    if(v==target)
  {
    res.push_back(path);
    return ;
  }  
    visited[v]=1;

    for(auto x : graph[v])
    {
        if(visited[x]==0)
        {
            dfs(graph,visited,path,x,target);
            path.pop_back();
            visited[x]=0;
        }
    }
}
public:
 vector<vector<int> > res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<int>visited(graph.size(),0);
        vector<int> path;
      

        dfs(graph,visited,path,0,target);
        return res;
    }
};