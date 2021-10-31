#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

//to check whether a graph is connected components or not

class graph{
  int adj[100][100];
  
  public:

  void add_edge(int n,int e)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      adj[i][j]=0;
    }
    int e1,e2;
    for(int i=0;i<e;i++)
    {
      cin>>e1>>e2;
      adj[e1][e2]=1;
    }
  }

  void bfs(int n,int src)
  {
    cout<<"The bfs of all the reachable nodes starting from the node "<<src<<" is"<<endl;
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    int node;
    while(!q.empty())
    {
      node = q.front();
      cout<<node<<" -> ";
      q.pop();

      for(int i=1;i<=n;i++)
      {
        if(adj[node][i]==1 && !visited[n])
        {
          q.push(i);
          visited[i]=true;
        }
      }
    }
    cout<<endl;
  }

  void dfs(int n,int src,vector<bool> &visited)
  {
  
     visited[src]=true;

     for(int i=1;i<=n;i++)
     {
       if(adj[src][i]==1 && !visited[n])
       {
         dfs(n,i,visited);
       }
     }
  }

  int components(int n)
  {
    vector<bool> visited(n+1,false);
    int count=0;
    for(int i=1;i<=n;i++)
    {
      if(! visited[i])
      {
        dfs(n,i,visited);
        count++;
      }
    }
    return count;
  }
  
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       int n,e,x;
       cin>>n;
       cin>>e;
       graph g;
       g.add_edge(n,e);
       cin>>x;
       g.bfs(n,x);
       if(g.components(n)>1)
       cout<<"The graph is not connected"<<endl;
       else
       {
         cout<<"The graph is connected"<<endl;
       }
       
     
    return 0;
}
