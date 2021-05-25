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

const int maxm = 3*1e5+5;
vector<P>comps[maxm];

//IMPLEMENTATIONNNNNNNNNNNNNNNNNN : https://codeforces.com/contest/1515/submission/115072881
                            //    : https://codeforces.com/contest/1515/submission/115072736
 
struct DSU{
    vector<int>par;
    vector<int>exp;
    vector<int>rank;

    void init(int n){
        par.resize(n+2);
        exp.resize(n+2);
        rank.resize(n+2);
        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i] = 1;
            // rank[i].before=0;
        }
    }
 
    int get_superparent(int x){
        if(x==par[x]) return x;
        return par[x] = get_superparent(par[x]);
    }
 
    void unite(int x,int y,int del)
    {
        int parent_a = get_superparent(y);
        int parent_b = get_superparent(x);
        if(parent_a == parent_b){
            return;
        }
        if(rank[parent_a]>=rank[parent_b]){
            swap(parent_a,parent_b);
        }
        rank[parent_b]+=rank[parent_a];
        exp[parent_b] += exp[parent_a] - del;
        // assert(exp[parent_b] >= 0);
        if(((int)comps[parent_b].size()) < ((int)comps[parent_a].size())){
            swap(comps[parent_b],comps[parent_a]); //O(1) operation
        }
        for(auto r:comps[parent_a]){
            comps[parent_b].pb(r);
        }
        par[parent_a]=parent_b;
        return;
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
    int n,m,x; cin>>n>>m>>x;
    G.init(n+2);
    vector<int>ash(n+2);
    for(int i=1;i<=n;i++){
        cin>>ash[i];
        G.exp[i] += ash[i];
    }
    for(int i=0;i<m;i++){
        int p,q; cin>>p>>q;
        comps[p].pb({q,i});
        comps[q].pb({p,i});
    }
    vector<int>ans;
    set<P,greater<P>>ok;
    for(int i=1;i<=n;i++){
        ok.insert({G.exp[i],i});
    }
    while(ok.size())
    {
        if(ans.size()==n-1) break;
        auto fr = *ok.begin();
        ok.erase(ok.begin());
        // db(fr.F,fr.S);
        // break;
        while(!comps[fr.S].empty())
        {
            auto edge = comps[fr.S].back();
            comps[fr.S].pop_back();
            if(G.has_cycle(fr.S,edge.F)){
                continue;
            }
            if(G.exp[G.get_superparent(fr.S)] + G.exp[G.get_superparent(edge.F)] < x){
                continue;
            }
            ans.pb(edge.S);
            int par = G.get_superparent(edge.F);
            ok.erase({G.exp[par],par});
            G.unite(fr.S,edge.F,x);
            par = G.get_superparent(fr.S);
            // G.rank[par].exp -= x;
            ok.insert({G.exp[par],par});
            break;
        }
    }
    if(ans.size()!=n-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(auto r: ans){
        cout<<r+1<<endl;
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