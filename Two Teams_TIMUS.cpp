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

int n;
vector<vector<int>> graph;
vector<bool>vis(1005,false);
vector<int>dist(1005,0);
set<int>team1;

void dfs(int src,int pt)
{
    if(pt>1) pt=0;
    vis[src]=true;
    dist[src]=pt;
    for(auto x: graph[src]){
        if(!vis[x]) dfs(x,pt+1);
    }
}

void solve()
{
    cin>>n;
    graph.resize(n+5);
    for(int i=1;i<=n;i++)
    {
        int x;
        while(cin>>x){
            if(x==0) break;
            graph[i].pb(x);
            graph[x].pb(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size()==0){
            cout<<"0"<<endl;
            return;
        }
        if(!vis[i]) dfs(i,0);
    }   
    for(int i=1;i<=n;i++){
        if(dist[i]%2==0) team1.insert(i);
    }
    cout<<team1.size()<<endl;
    for(auto x: team1) cout<<x<<" ";
    cout<<endl;
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