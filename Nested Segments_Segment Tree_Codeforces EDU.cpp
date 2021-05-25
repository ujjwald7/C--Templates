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
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

struct segtree
{
    int sz;
    vector<int>values;
 
    void init(int n){
        sz=1;
        while(sz<n) sz*=2;
        values.assign(2*sz,0);
    }
 
    void build(int n,int x,int lx,int rx)
    {
        if(rx-lx == 1){
            if(lx < n){
                values[x]=0;
            }
            return;
        }
 
        int mid=(lx+rx)/2;
        build(n,2*x+1,lx,mid);
        build(n,2*x+2,mid,rx);
        values[x]=values[2*x+1]+values[2*x+2];
    }
 
    int query(int l,int r,int x,int lx,int rx)
    {
        if(lx>=r or rx<=l) return 0;
        if(lx>=l and rx<=r) return values[x];

        int mid=(lx+rx)/2;

        int left=query(l,r,2*x+1,lx,mid);
        int right=query(l,r,2*x+2,mid,rx);

        return left+right;
    }
 
    void set(int i,int x,int lx,int rx)
    {
        if(rx-lx == 1){
            values[x]=1;
            return;
        }
        int mid=(lx+rx)/2;
 
        if(mid > i){
            set(i,2*x+1,lx,mid);
        }
        else{
            set(i,2*x+2,mid,rx);
        }
        values[x]=values[2*x+1]+values[2*x+2];
    }
};
 
void solve()
{
    int n; cin>>n;
    segtree tree;
    tree.init(2*n);
    unordered_map<int,P>vals;
    unordered_map<int,pair<bool,bool>>vis;
    vector<int>a(2*n);
    for(int i=0;i<2*n;i++){
    	cin>>a[i];
    	a[i]--;
    	if(!vis[a[i]].F){
    		vals[a[i]].F=i;
    		vis[a[i]].F=true;
    	}
    	else{
    		vals[a[i]].S=i;
    		vis[a[i]].S=true;
    	}
    }
    // vis.clear();
    tree.build(2*n,0,0,tree.sz);
    vector<int>ans(n,0);
    for(int i=0;i<2*n;i++)
    {
    	if(vals[a[i]].S==i)
    	{	
    		ans[a[i]] = tree.query(vals[a[i]].F,vals[a[i]].S,0,0,tree.sz);
    		tree.set(vals[a[i]].F,0,0,tree.sz);
    	}
    }
    for(auto x : ans) cout<<x<<" ";
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