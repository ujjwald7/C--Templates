#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mp make_pair
#define endl "\n"
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007  //1e9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

class Graph
{
    map<int,list<int>>l;
public:
    Graph(int v)
    {
        //V=v;
        //l=new list<int>[V];
    }

    void addgede(int u,int v,bool bidirec=true)
    {
        l[u].pb(v);
        if(bidirec)
        {
            l[v].pb(u);
        }
    }

    void PrintAdjList()
    {
        for(auto i : l)
        {
            cout<<i.F<<"->";
            for(int vertex : i.S)
            {
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }

    void bfsSSSP(int src)   //Single Source Shortest Path
    {
        queue<int>q;
        map<int,int>distance;
        map<int,int>parent;
        for(auto i : l){
            distance[i.F]=INT_MAX;  //set all to infinity
        }
        q.push(src);
        distance[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            //check the neighbors of the current node 
            for(int neighbour : l[node])
            {
                if(distance[neighbour]==INT_MAX){
                    q.push(neighbour);
                    distance[neighbour]=distance[node]+1;
                    parent[neighbour]=node;
                }
            }
        }
        //Print shortest distance of each vertex from src
        for(auto i : l)
        {
            int node=i.F;
            cout<<"Shortest Distance of "<<node<<" from "<<src<<" is :"<<distance[node]<<endl;
        };
    }
};

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    Graph g(6);
    //graph g has 6 vertices's 0 to 5
    g.addgede(0,1);
    g.addgede(1,2);
    g.addgede(0,4);
    g.addgede(2,4);
    g.addgede(2,3);
    g.addgede(3,5);
    g.addgede(3,4);
    //g.PrintAdjList();
    g.bfsSSSP(0);
    return 0;
}