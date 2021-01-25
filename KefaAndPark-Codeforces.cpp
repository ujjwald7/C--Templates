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
const int MOD=1e9+7;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int maxm=1e6;
int a[maxm],n,m;
map<int,list<int>>graph;
int ans=0;
map<int,bool>leaf,visited;
map<int,int>dist;

void dfs(int src)
{
    visited[src]=true;
    dist[src]+=a[src-1];
    for(auto x: graph[src]){
        if(!visited[x]){
            dist[x]+=dist[src];
            dfs(x);
        }
    }
    if(graph[src].size()==0) leaf[src]=true;
}

void solve()
{	
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        graph[x].pb(y);
    }
    dist[1]=a[0];
    dfs(1);
    for(auto x: leaf){
        if(dist[x.F]<=m) ans++;
        db(x.F,dist[x.F]);
    }
    cout<<ans<<endl;
}   
	
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}