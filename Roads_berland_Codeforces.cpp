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

struct dsu{
    vector<int>par;
    set<int>supp;
    void init(int n){
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            supp.insert(i);
        }
    }
    int find_par(int x){
        if(x==par[x]) return x;
        else return par[x]=find_par(par[x]);
    }
    bool isCycleic(int a,int b){
        int super_a=find_par(a);
        int super_b=find_par(b);
        if(super_a!=super_b) return false;
        else return true;
    }
    void unite(int a,int b)
    {
        int super_a=find_par(a);
        int super_b=find_par(b);
        if(super_a!=super_b){
            par[super_b]=super_a;
            supp.erase(super_b);
        }
    }
    int uni_super()
    {
        set<int>uni;
        for(auto x: par) uni.insert(x);
        return uni.size();
    }
    vector<int> gimme()
    {
        vector<int>a;
        for(auto x : supp) a.pb(x);
        return a;
    }
}G;

void solve()
{  
    int n; cin>>n;
    G.init(n);
    vector<P> destroy,build;
    for(int i=0,x,y;i<n-1;i++){
        cin>>x>>y; x--; y--;
        if(G.isCycleic(x,y)) destroy.pb(mp(x,y));
        else G.unite(x,y);
    }
    if(G.uni_super()==0){
        cout<<"0"<<endl;
        return;
    }
    vector<int>a=G.gimme();
    for(int i=0;i<a.size()-1;i++){
        build.pb(mp(a[i],a[i+1]));
    }
    cout<<destroy.size()<<endl;
    for(int i=0;i<destroy.size();i++){
        cout<<destroy[i].F+1<<" "<<destroy[i].S+1<<" "<<build[i].F+1<<" "<<build[i].S+1<<endl;
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
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}