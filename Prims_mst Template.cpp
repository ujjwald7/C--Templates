#include<bits/stdc++.h>
using namespace std;
#define int long long unsigned int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
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

int prims_mst(vector<vector<P>>graph,int n)
{
    vector<bool>visited(n+1,false);
    int ans=0;
    priority_queue<P,vector<P>,greater<P>>pq;
    pq.push({0,1});      //it's weight with itself and src node=second
    while(!pq.empty())
    {
        auto best=pq.top();
        int wt=best.F;
        int to=best.S;
        pq.pop();
        if(visited[to]) continue;
        ////if not visited then include in mst
        ans+=wt;
        visited[to]=true;
        for(auto edge:graph[to]){
            if(!visited[edge.F]) pq.push({edge.S,edge.F});
        }
    }
    return ans;
}

void solve()
{      
    int n,m; cin>>n>>m;
    vector<vector<P>>graph;
    graph.resize(n+1);
    for(int i=0,x,y,w;i<m;i++){
        cin>>x>>y>>w;
        graph[x].pb({y,w});
        graph[y].pb({x,w});    
    }
    cout<<prims_mst(graph,n)<<endl;
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
