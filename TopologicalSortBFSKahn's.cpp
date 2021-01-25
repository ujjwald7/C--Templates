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
    int V;
    map<int,list<int>>l;
public:

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
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(int vertex : l[i])
            {
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
    //Kahn's Algorithm

    void TopologicalSortBFS()
    {
        queue<int>q;
        map<int,bool>visited;
        map<int,int>indegree;
        for(auto i: l){
            int node=i.F;
            visited[node]=false;
            indegree[node]=0;
        }
        //Initialise the indegrees of all nodes
        for(auto i: l)
        {
            int u=i.F;
            for(auto v: l[u]){
                indegree[v]++;
            }
        }
        //Find out all the nodes with 0 indegree
        for(auto i : l)
        {
            int node=i.F;
            if(indegree[node]==0){
                q.push(node);
            }
        }
        //Start With the Algorithm
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<"-->";
            for(int neighbour : l[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
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
    g.addgede(0,1,false);
    g.addgede(1,2,false);
    g.addgede(0,4,false);
    g.addgede(2,4,false);
    g.addgede(2,3,false);
    g.addgede(3,5,false);
    g.addgede(3,4,false);
    g.TopologicalSortBFS();
    return 0;
}