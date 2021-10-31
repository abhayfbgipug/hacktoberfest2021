#include <bits/stdc++.h>
using namespace std;

//bfs

class graph{
     map<int, vector<pair<int,int>>> adj;
       int a,b,c;

       public:

       void addedge(int n)
       {
           for(int i=0;i<n;i++)
       {
           cin>>a>>b>>c;
           adj[a].push_back({b,c});
           adj[b].push_back({a,c});
       }
       }

       void printgraph()
       {
         for( auto it:adj)
       {
           cout<<it.first<<" - ";
           for(auto it1:(it.second))
           cout<<"("<<it1.first<<" , "<<it1.second<<"),";

           cout<<endl;
       }

       }

       void bfs(int src)
       {
          map<int, bool> visited;
          queue<int> q;

          q.push(src);
          visited[src]=true;
           int cost=0;
          while(!q.empty())
          {
             int node =q.front();
             q.pop();
             cout<<node<<" -> ";
             for(pair<int,int> x:adj[node])
             {
               auto y=x.first;
               
               if(!visited[y])
                {
                  q.push(y);
                  visited[y]=true;
                  cost+=x.second;
                }
             }
        }
        cout<<endl<<cost<<endl;
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
       
       for(int i=1;i<7;i++)
       {
         g.bfs(i);
       }

       return 0;
}
