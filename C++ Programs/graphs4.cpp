#include <bits/stdc++.h>
using namespace std;

//dfs

class graph{
     map<int, vector<int>> adj;
      map<int,bool> visited;
       int a,b,c;

       public:

       void addedge(int n)
       {
           for(int i=0;i<n;i++)
       {
           cin>>a>>b;
           adj[a].push_back(b);
           adj[b].push_back(a);
           visited[a]=false;
           visited[b]=false;
       }
       }

       void printgraph()
       {
         for( auto it:adj)
       {
           cout<<it.first<<" - ";
           for(auto it1:it.second)
           cout<<it1<<" ";
          

           cout<<endl;
       }

       }

       void dfs(int edges,int src)
       {
        
          visited[src]=true;
          cout<<src<<" -> ";
            for(auto x=adj[src].begin();x!=adj[src].end();x++)
            {
                if(!visited[*x])
                {
                    dfs(edges,*x);
                }
            }
       
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

       g.addedge(n);
       
       g.dfs(n,1);

       return 0;
}
