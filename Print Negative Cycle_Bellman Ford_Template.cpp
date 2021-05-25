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

struct node
{
    int from;
    int to;
    int cost;    
};

const int maxm = 2500 + 5;
vector<vector<P>>graph;
vector<int>dist(maxm,1e15);
vector<int>ans;
vector<int>par(maxm,-1);
int resp = -1;

void solve()
{
    int n,m; cin>>n>>m;
    vector<node>edges;
    graph.resize(n+2);
    for(int i=0;i<m;i++){
        int x,y,c; cin>>x>>y>>c;
        edges.pb({x,y,c});
    }
    dist[1] = 0;
    for(int i=0;i<n-1;i++){
        for(auto x : edges){
            if(dist[x.from] + x.cost < dist[x.to]){
               dist[x.to] = dist[x.from] + x.cost; 
               par[x.to] = x.from;
            }
        }
    }
    bool cycle = false;
    for(auto x : edges)
    {
        if(dist[x.from] + x.cost < dist[x.to]){
               cycle = true;
               resp = x.from;
               par[x.to] = x.from;
        }
    }
    if(!cycle){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        resp = par[resp];
    }
    for(int i=resp;;i = par[i]){
        ans.pb(i);
        if(i==resp and ans.size() > 1) break;
    }
    reverse(all(ans));
    for(auto x : ans){
        cout<<x<<" ";
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