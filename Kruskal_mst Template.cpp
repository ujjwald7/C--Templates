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

struct DSU{
    vector<int>par;
    vector<int>rank;
    int comps;
    void init(int n){
        par.resize(n);
        rank.resize(n);
        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=1;
        }
        comps=n;
    }
    int get_superparent(int x){
        if(x==par[x]) return par[x];
        return par[x]=get_superparent(par[x]);
    }
    void unite(int x,int y)
    {
        int super_par_a=get_superparent(x);
        int super_par_b=get_superparent(y);
        //union by rank
        if(rank[super_par_a]<rank[super_par_b]){
            par[super_par_a]=super_par_b;
            rank[super_par_b]+=rank[super_par_a];
        }
        else{
            par[super_par_b]=super_par_a;
            rank[super_par_a]+=rank[super_par_b];
        }
    }
    bool has_cycle(int x,int y){
        int super_par_a=get_superparent(x);
        int super_par_b=get_superparent(y);
        if(super_par_a==super_par_b)
            return true;
        return false;
    }
};

int kruskal_mst(vector<vector<int>>graph,int n)
{
    //vector<vector<int>>graph;
    //send a graph with {w,x,y} and sort on basis of w;

    //removing rank storage for DSU improves time ***max case
    sort(graph.begin(),graph.end());
    int ans=0;
    DSU R;
    R.init(n);
    for(int i=0;i<graph.size();i++)
    {
        int wt=graph[i][0];
        int curr_x=graph[i][1];
        int curr_y=graph[i][2];
        if(R.get_superparent(curr_x)!=R.get_superparent(curr_y)){
            ans+=wt;
            R.unite(curr_x,curr_y);
        }
    }
    return ans;
}


void solve()
{      
    int n,m; cin>>n>>m;
    vector<vector<int>>graph;
    // graph.resize(n);
    for(int i=0,x,w,y;i<m;i++){
        cin>>x>>y>>w;
        graph.pb({w,x,y});
    }
    cout<<kruskal_mst(graph,n)<<endl;
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
