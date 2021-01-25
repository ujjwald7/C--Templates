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

    void dfsHelper(int node,map<int,bool>&visited,list<int>&ordering)
    {
        //Whenever to come to a node, make it visited
        visited[node]=true;

        //To find out a node which is neighbour of current node and not yet visited
        for(int neighbour:l[node])
        {
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);
            }
        }
        //Add just one line for Topological Sorting
        //At this point all the children of the current node have been visited
        //So we can add current node to the list
        ordering.push_front(node);
    }

    void DFSTopologicalSort(){
        map<int,bool>visited;
        list<int>ordering;
        for(auto i : l){
            //i is a pair (node,list of nodes)
            int node=i.F;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);
            }
        }
        //Print all the elements in ordering/dependency order
        for(auto element : ordering){
            cout<<element<<"-->";
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
    //g.PrintAdjList();
    g.DFSTopologicalSort();
    return 0;
}