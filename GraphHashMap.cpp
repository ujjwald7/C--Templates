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
    map<string,list<string>> list;
public:
    Graph(int v)
    {
        //V=v;      //no need as hashmap is already dynamic
        //l=new list<int>[V];
    }
    void addgede(string u,string v,bool bidirec=true)
    {
        list[u].pb(v);
        if(bidirec)
        {
            list[v].pb(u);
        }
    }
    void PrintMapList()
    {
        for(auto obj : list)
        {
            cout<<obj.F<<"->";
            for(auto vertex : obj.S)
            {
                cout<<vertex<<",";
            }
            cout<<endl;
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
    Graph g(5);
    //graph g has 5 vertices's 0 to 4
    g.addgede("ABC","DEF");
    g.addgede("DEF","CD");
    g.addgede("CD","ABC");
    g.addgede("CD","RF",false);
    g.addgede("RF","DEF");
    g.addgede("ABC","FG");
    g.PrintMapList();
    return 0;
}