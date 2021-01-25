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

int n; // number of nodes
int m;
map<string,list<string>> graph; // adjacency list of graph
set<string>art_pts;

map<string,bool> visited;
map<string,int> tin, low;
int timer;

void dfs(string v, string p = "*") {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (auto to : graph[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!="*"){
                // db("hi");
                art_pts.insert(v);
            }
            ++children;
        }
    }
    if(p == "*" && children > 1)
        art_pts.insert(v);
}

void find_cutpoints() {
    timer = 0;
    // visited.assign(n+1, false);
    // tin.assign(n+1, -1);
    // low.assign(n+1, -1);
    for (auto i : graph) {
        // cout<<i.F<<endl;
        if (!visited[i.F]){
            // cout<<i.F<<endl;
            dfs (i.F);
        }
    }
}

void solve()
{
    int t=1;
    while(cin>>n){
        if(n==0) return;
        graph.clear();
        tin.clear();
        low.clear();
        visited.clear();
        art_pts.clear();
        for(int i=0;i<n;i++){
            string s; cin>>s;
            tin[s]=-1;
            low[s]=-1;
            visited[s]=false;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            string x,y; cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        if(t!=1) cout<<endl;
        find_cutpoints();
        cout<<"City map #"<<t<<": "<<art_pts.size()<<" camera(s) found"<<endl;
        if(art_pts.size()>0){
            for(auto x: art_pts){
                cout<<x<<endl;
            }
        }
        t++;
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