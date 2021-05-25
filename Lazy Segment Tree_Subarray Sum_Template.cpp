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

struct items
{
    int seg,pref,suf,sum;
    bool operator==(items &b){
        return (seg==b.seg and pref==b.pref and suf==b.suf and sum==b.sum);
    }
};
 
struct segtree
{
    items NEUTRAL_ELEMENT={0 ,0 , 0 ,0};
    items no_operation = {(int)1e12,(int)1e12,(int)1e12,(int)1e12};
 
    items single(int v){
        if(v>0) return {v,v,v,v};
        return {0,0,0,v};
    }
 
    items merge(items a,items b)
    {
        return
        {
            max(a.seg,max(b.seg , a.suf + b.pref)) ,
            max(a.pref,a.sum+b.pref),
            max(b.suf , b.sum + a.suf),
            a.sum + b.sum 
        };
    }
 
    int sz; 
    vector<items>values;
    vector<items>lazy;
 
    void init(int n)
    {
        sz=1;
        while(sz<n) sz*=2;
        values.resize(2*sz);
        lazy.resize(2*sz);
    }
 
    void build(vector<int> &a, int x,int lx,int rx)
    {
        if(rx-lx == 1){
            if(lx<(int)a.size()){
                values[x]=single(a[lx]);
            }
            return;
        }
 
        int mid=(lx+rx)/2;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
 
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }

    items operation(items a,items b,int len)
    {
        if(b==no_operation){
            return a;
        }
        if(b.sum > 0){
            b.seg = b.sum*len;
            b.pref = b.sum*len;
            b.suf = b.sum*len;
            b.sum = b.sum*len;
        }
        else{
            b.sum = b.sum*len;
            b.seg = 0;
            b.pref = 0;
            b.suf = 0;
        }
        return b;
    }

    void propagate(int x,int lx,int rx)
    {
        if(rx-lx==1) return;
        int mid = (lx+rx)/2;
        lazy[2*x+1] = operation(lazy[2*x+1],lazy[x],1);
        values[2*x+1] = operation(values[2*x+1],lazy[x],mid-lx);
        lazy[2*x+2] = operation(lazy[2*x+2],lazy[x],1);
        values[2*x+2] = operation(values[2*x+2],lazy[x],rx-mid);
        lazy[x] = no_operation;
    }
 
    void set(int l,int r,int v,int x,int lx,int rx)
    {
        propagate(x,lx,rx);
        if(lx>=r or rx<=l) return;
        if(lx>=l and rx<=r){
            lazy[x] = operation(lazy[x],single(v),1);
            values[x] = operation(values[x],single(v),rx-lx);
            return;
        }
 
        int mid=(lx+rx)/2;
        set(l,r,v,2*x+1,lx,mid);
        set(l,r,v,2*x+2,mid,rx);
 
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
 
    items query(int l,int r,int x,int lx,int rx)
    {
        propagate(x,lx,rx);
        if(lx>=r or rx<=l) return NEUTRAL_ELEMENT;
        if(lx>=l and rx<=r) return values[x];
 
        int mid=(lx+rx)/2;
 
        items s1=query(l,r,2*x+1,lx,mid);
        items s2=query(l,r,2*x+2,mid,rx);
 
        return merge(s1,s2);
    }
};

//Implementation : https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/A
 
void solve()
{
    int n,m; cin>>n>>m;
    vector<int>a(n,0);
    segtree tree;
    tree.init(n);
    tree.build(a,0,0,tree.sz);
    for(int i=0;i<m;i++)
    {
        int l,r,v; cin>>l>>r>>v;
        tree.set(l,r,v,0,0,tree.sz);
        cout<<tree.query(0,tree.sz,0,0,tree.sz).seg<<endl;
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