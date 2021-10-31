#include <bits/stdc++.h>
using namespace std;

//topological sort

class graph{

    map<int,vector<int>> adj;

    public:

    void add_edge(int  n)
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
        }
    }

    void dfs(int n,int src,vector<bool> &visited,list<int> &ordering)
    {

        visited[src]=true;
        
        for(auto it:adj[src])
        {
            if(!visited[it])
            {
                dfs(n,it,visited,ordering);
            }
        } 
        ordering.push_front(src);
        return;
    }

    void topological_sort(int n)
    {
        vector<bool> visited(n+1,false);

        list<int> ordering;

        for(auto it:adj)
        {
            int node=it.first;
            if(!visited[node])
            {
                dfs(n,node,visited,ordering);
            }
        }

        for(auto x:ordering)
        cout<<x<<" ";
    }

};

int main() {
     ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n;
       cin>>n;
      graph g;
      g.add_edge(n);
      g.topological_sort(n);      

       
       return 0;
}