#include <bits/stdc++.h>
using namespace std;

//single source shortest path algo

class graph{
    map<int,vector<int>> adj;
    vector<int> dist;
    queue<int> q;
    
    public:
    
    void addedge(int n){

        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    void print(){

        for(auto x:adj)
        {
            cout<<x.first<<"->";
            for(auto y:x.second)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }

    void bfs()
    {
        cout<<"bfs ";
        int src=1;
        for(auto x:adj)
        {
            int node=x.first;
            dist[node]=INT_MAX;
        }
        
        q.push(src);
        dist[src]=0;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto x:adj[node])
            {
                if(x==INT_MAX)
                {
                    q.push(x);
                    dist[x]=dist[node]+1;
                }
            }
        }
    }
     
     void print_level()
     {
         for(auto x:adj)
         {
            int node=x.first;
            int d=dist[node];
            cout<<"distance of "<<node<<" from src is "<<d<<endl;
         }
         cout<<endl;
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
       g.print();
       g.bfs();
       g.print_level();
       

       return 0;
}