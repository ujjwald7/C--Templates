#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

vector<int>path_ans;
int n; 
vector<int>path_order;

class Graph
{
    map<int,list<int>>l;
public:
    Graph(int v)
    {
        // V=v;
        // l=new list<int>[V];
    }

    void addgede(int u,int v,bool bidirec=true)
    {
        l[u].pb(v);
        if(bidirec)
        {
            l[v].pb(u);
        }
    }

    int leafcounter()
    {
        int ans=0;
        for(auto x:l){
            if(x.S.size()==1) ans++;
        }
        return ans;
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

    void traveller()
    {
        int src=1;
        path_ans.pb(1);
        bfsSSSP(src,path_order[0]);
        for(int i=0;i<path_order.size()-1;i++){
            bfsSSSP(path_order[i],path_order[i+1]);
        }
        bfsSSSP(path_order[path_order.size()-1],1);
        if(path_ans.size()>2*n-1){
            cout<<"-1"<<endl;
            return;
        }
        for(auto x: path_ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    void bfsSSSP(int src,int here)   //Single Source Shortest Path
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
            // cout<<node<<" ";
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
        // for(auto i : l)
        // {
        //     int node=i.F;
        //     cout<<"Shortest Distance of "<<node<<" from "<<src<<" is :"<<distance[node]<<endl;
        // };
        // db("hi");
        vector<int>temp;
        for(int i=here;i!=parent[i];i=parent[i]){
            // db(i);
            temp.pb(i);
        }
        reverse(temp.begin(),temp.end());
        for(auto x:temp){
            // db(x);
            path_ans.pb(x);
        }
        // cout<<endl;
    }
};

void solve()
{      
    cin>>n;
    Graph g(n);
    for(int i=0,x,y;i<n-1;i++){
        cin>>x>>y;
        g.addgede(x,y);
    }
    int k=0;
    k=g.leafcounter();
    for(int i=0;i<k;i++){
        int x; cin>>x;
        path_order.pb(x);
        // db(x);
    }
    // g.initfloyd();
    g.traveller();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<floyd[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    // int cases=1;
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
