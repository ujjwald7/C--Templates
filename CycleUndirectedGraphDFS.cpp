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

    bool isCyclicdfsHelper(int node,map<int,bool>&visited,int parent)
    {
        //Whenever to come to a node, make it visited
        visited[node]=true;
        //To find out a node which is neighbour of current node and not yet visited
        for(int neighbour:l[node])
        {
            if(!visited[neighbour]){
                bool CycleDetected = isCyclicdfsHelper(neighbour,visited,node);
                if(CycleDetected){
                    return true;
                }
            }
            //if neighbour is visited
            else if(neighbour!=parent){
                return true;
            }
        }
        return false;
    }

    bool isCyclicdfs(int src)
    {
        map<int,bool>visited;
        //finding cycles in a dfs tree
        for(auto i:l)
        {
            int node=i.F;
            if(!visited[node]){
                bool ans = isCyclicdfsHelper(node,visited,node);
                if(ans)
                    return true;
            }
        }
        return false;
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
    g.addgede(1,2);
    g.addgede(1,4);
    g.addgede(2,3);
    g.addgede(3,4);
    cout<<g.isCyclicdfs(0);
    return 0;
}