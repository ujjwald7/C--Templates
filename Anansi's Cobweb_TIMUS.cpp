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

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int comps;

struct dsu{
    vector<int>par;
    void init(int n){
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        comps=n;
    }
    int find_par(int x){
        if(x==par[x]) return x;
        else return par[x]=find_par(par[x]);
    }
    void unite(int a,int b){
        int super_par_a=find_par(a);
        int super_par_b=find_par(b);
        if(super_par_b!=super_par_a){
            par[super_par_b]=super_par_a;
            comps--;
        }
    }
}G;

void solve()
{  
    int n,m; cin>>n>>m;
    G.init(n);
    vector<P>edges;
    for(int i=0,x,y;i<m;i++){
        cin>>x>>y;
        x--;y--;
        edges.pb(mp(x,y));
    }
    int q; cin>>q;
    vector<bool>queries(m,true);
    vector<int>str,ans;
    for(int i=0,x;i<q;i++){
        cin>>x; x--;
        queries[x]=false;
        str.pb(x);
    }
    for(int i=0;i<m;i++){
        if(queries[i]){
             G.unite(edges[i].F,edges[i].S);
            // db(edges[i].F,edges[i].S);
        }
    }
    for(int i=q-1;i>=0;i--){
        ans.pb(comps);
        G.unite(edges[str[i]].F,edges[str[i]].S);
    }
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]==0) ans[i]=1;
        cout<<ans[i];
        if(i>0) cout<<" ";
    }
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
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}