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

map<int,set<P>>hashes;
//only done for first 3 lowercase letters
const int prime = 3;
const int prime2 = 31;
const int maxm = 6*1e6+5;
vector<int>pows1(maxm),pows2(maxm);

void precomp()
{
    pows1[0] = pows2[0] = 1;
    for(int i=1;i<maxm;i++){
        pows1[i] = (pows1[i-1]*prime)%MOD;
        pows2[i] = (pows2[i-1]*prime2)%MOD2;
    }
}

long long compute_hash1(string const& s) 
{
    long long hash_value = 0;
    for (char c : s) {
        hash_value = ((hash_value*prime)%MOD + (c - 'a' + 1)) % MOD;
    }
    return hash_value;
}

long long compute_hash2(string const& s) 
{
    long long hash_value = 0;
    for (char c : s) {
        hash_value = ((hash_value*prime2)%MOD2 + (c - 'a' + 1)) % MOD2;
    }
    return hash_value;
}

void solve()
{   
    precomp();
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int val = compute_hash1(s);
        int val2 = compute_hash2(s);
        hashes[(int)s.size()].insert({val,val2});
    }
    for(int i=0;i<m;i++)
    {
        string s; cin>>s;
        int ok1 = compute_hash1(s);
        int ok2 = compute_hash2(s);
        bool f = false;
        for(int j=0;j<s.length();j++)
        {
            for(int k='a';k<='c';k++){
                if(s[j]!=k)
                {
                    int new_ok1 = ok1;
                    int new_ok2 = ok2;
                    new_ok1 = ((new_ok1 + pows1[s.length()-1-j]*(k-s[j]))%MOD + MOD)%MOD;
                    new_ok2 = ((new_ok2 + pows2[s.length()-1-j]*(k-s[j]))%MOD2 + MOD2)%MOD2;
                    if(hashes[(int)s.size()].count({new_ok1,new_ok2})){
                        f = true;
                        break;
                    }
                }
            }
            if(f) break;
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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