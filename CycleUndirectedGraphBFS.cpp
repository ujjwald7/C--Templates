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

    bool isCyclicBfs(int src)
    {
        queue<int>q;
        map<int,bool>visited;
        map<int,int>parent;
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto neighbour: l[node]){
                if(visited[neighbour]==true&&parent[node]!=neighbour)
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    q.push(neighbour);
                    parent[neighbour]=node;
                }
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
    g.addgede(4,3);
    cout<<g.isCyclicBfs(1);
    return 0;
}