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
#define all(x) x.begin(), x.end()
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;
const int MOD2=998244353;
ld PI=2*acos(0.0);
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int maxm = 2*1e5+5;   //nodes in graph

// 000000000000000 - based indexing

vector<vector<int>>graph,up;
int enter[maxm],leave[maxm];
vector<int>depths(maxm,0);
int timer,n,l;

void dfs(int v, int p)
{
    enter[v] = timer;
    timer++;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : graph[v]) {
        if (u != p){
            depths[u] = depths[v] + 1;
            dfs(u, v);
        }
    }
    leave[v] = timer;
    timer++;
}

bool is_ancestor(int u, int v)
{
    return enter[u] <= enter[v] && leave[u] >= leave[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(n));
    memset(enter,0,sizeof enter);
    memset(leave,0,sizeof leave);
    up.assign(n, vector<int>(l + 1));
    depths[root] = 0;
    dfs(root, root);
}

void solve()
{
    int q; cin>>n>>q;
    graph.resize(n+2);
    for(int i=1;i<=n-1;i++){
        int x; cin>>x;
        x--;
        graph[x].pb(i);
        graph[i].pb(x);
    }
    preprocess(0);
    for(int i=0;i<q;i++)
    {
        int x,levs;
        cin>>x>>levs;
        x--;
        if(depths[x] < levs){
            cout<<"-1"<<endl;
            continue;
        }
        int ans = x;
        for(int j=0;j<=l;j++)
        {
            if(levs&(1<<j)){
                ans = up[ans][j];
                if(ans==-1) break;
            }
        }
        cout<<ans+1<<endl;
    }
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
 
// 1LL check ?

