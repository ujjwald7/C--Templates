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

int n,a,d;

struct DSU{
    vector<int>par;
    vector<int>rank;
    int comps;
    void init(int n){
        par.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
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
}G;

void solve()
{
    cin>>n>>d>>a;
    G.init(n+3);
    char ans[105][105];
    bool vis[105][105]={false};
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++) ans[i][j]='0';
    }
    int cost=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x; cin>>x;
            if(x!='0')
            {
                if(G.get_superparent(i)!=G.get_superparent(j)){
                    // ans[i][j]='a';
                    // db("hi");
                    ans[i][j]='1';
                    ans[j][i]='1';
                    G.unite(i,j);
                }
                else{
                    if(ans[i][j]=='1') continue;
                    // flag=true;
                    // db(i,j);
                    ans[i][j]='d';
                    ans[j][i]='d';
                    if(!vis[i][j]) cost+=d;
                    vis[i][j]=true;
                    vis[j][i]=true;
                }
            }
        }
    }
    // if(flag) cost+=d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(i!=j and G.get_superparent(i)!=G.get_superparent(j))
            {
                cost+=a;
                ans[i][j]='a';
                ans[j][i]='a';
                G.unite(i,j);
            }
            if(ans[i][j]=='1') ans[i][j]='0';
        }
    }
    cout<<cost<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<ans[i][j];
        cout<<endl;
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