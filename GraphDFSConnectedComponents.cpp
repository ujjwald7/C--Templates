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

    void addedge(int u,int v,bool bidirec=true)
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

    void dfsHelper(int node,map<int,bool>&visited)
    {
        //Whenever to come to a node, make it visited
        visited[node]=true;
        cout<<node<<" ";

        //To find out a node which is neighbour of current node and not yet visited
        for(int neighbour:l[node])
        {
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }

    void dfs(int src)
    {
        map<int,bool>visited;
        int component=1;
        dfsHelper(src,visited);

        //to check for any disconnected sub graphs which have not been visited
        for(auto neighbour : l)
        {
            int edge=neighbour.F;
            if(!visited[edge]){         //Access A DFS Forest
                cout<<endl;
                dfsHelper(edge,visited);
                component++;
            }
        }
        cout<<endl<<"The Current graph has "<<component<<" components"<<endl;
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
    Graph g;
    //graph g has 6 vertices's 0 to 5
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,4);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(3,4);
    g.addedge(6,7);
    //g.PrintAdjList();
    g.dfs(0);
    return 0;
}