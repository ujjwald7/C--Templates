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

const int maxm = 4*1e6+5;
int node_cnt = 0;

struct node{
    int left,right;
    node(){
        left = -1;
        right = -1;
    }
};

vector<node>trie(maxm);

void add(int r)
{
    int pos = 0;
    for(int i=31;i>=0;i--)
    {
        int bit = r&(1<<i);
        if(bit)
        {
            if(trie[pos].right==-1){
                trie[pos].right = ++node_cnt;
                trie[node_cnt] = node();
            }
            pos = trie[pos].right;
        }
        else{
            if(trie[pos].left==-1){
                trie[pos].left = ++node_cnt;
                trie[node_cnt] = node();
            }
            pos = trie[pos].left;
        }
    }
    return;
}

int query(int prefs)
{
    int ans = 0;
    int pos = 0;
    for(int i=31;i>=0;i--)
    {
        int bit = prefs&(1<<i);
        if(bit)
        {
            if(trie[pos].left!=-1){
                ans = (ans|(1<<i));
                pos = trie[pos].left;
            }
            else{
                pos = trie[pos].right;
            }
        }
        else{
            if(trie[pos].right!=-1){
                ans = (ans|(1<<i));
                pos = trie[pos].right;
            }
            else{
                pos = trie[pos].left;
            }
        }
    }
    return ans;
}

void solve()
{
    int n; cin>>n;
    trie.clear();
    node_cnt = 0;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int pref = 0;
    int ans = 0;
    trie[0] = node();
    add(0);
    for(int i=0;i<n;i++){
        pref ^= a[i];
        add(pref);
        ans = max(ans,query(pref));
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
    // int cases=1;
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
 
// 1LL check ?