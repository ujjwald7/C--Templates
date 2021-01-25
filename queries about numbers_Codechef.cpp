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

int n,q;

vector<P> factorize(int n)
{
    vector<P>ans;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans.pb({i,cnt});
        }
    }
    if(n > 1){
        ans.pb({n,1});
    }
    return ans;
}

void solve()
{           
    cin>>n>>q;
    vector<P>factors = factorize(n);
    int total_facts=1;
    for(auto x : factors) total_facts *= (x.S + 1);
    for(int i=0;i<q;i++)
    {
        int op,k; cin>>op>>k;
        if(op==1)
        {
            int ans=1;
            for(auto x : factors)
            {
                int cnt=0;
                while(k%x.F==0){
                    k/=x.F;
                    cnt++;
                }
                ans *= (min(cnt,x.S) + 1);
            }
            cout<<ans<<endl;
        }
        if(op==2)
        {
            int ans=1;
            for(auto x : factors)
            {
                int cnt=0;
                while(k%x.F==0){
                    k/=x.F;
                    cnt++;
                }
                if(cnt > x.S){
                    ans=0; break;
                }
                ans *= (x.S - cnt + 1);
            }
            if(k>1) ans=0;
            cout<<ans<<endl;
        }
        if(op==3)
        {
            int ans=1;
            for(auto x : factors)
            {
                int cnt=0;
                while(k%x.F==0){
                    k/=x.F;
                    cnt++;
                }
                if(cnt > x.S){
                    ans=0; break;
                }
                ans *= (x.S - cnt + 1);
            }
            if(k>1) ans=0;
            cout<<total_facts-ans<<endl;
        }
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