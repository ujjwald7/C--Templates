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
const int MOD=1e6+3;
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

int multiplicity_factorial(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}

void solve()
{           
    int n,k; cin>>n>>k;
    if(n <= 63 and k > (1LL<<n)){
        cout<<"1 1"<<endl;
        return;
    }
    int temp_k = k;
    int p = multiplicity_factorial(k-1,1LL*2);  //gcd of num and denum 
    // db(k-1-__builtin_popcountll(k - 1));
    // cout<<p<<endl;
    n%=(MOD-1);
    k%=(MOD-1);
    p%=(MOD-1);
    if(n < 0) n += (MOD-1); 
    if(k < 0) k += (MOD-1);
    if(p < 0) p += (MOD-1);
    int exp_pow = n*(k-1) - p;
    exp_pow%=(MOD-1);
    if(exp_pow < 0) exp_pow+=(MOD-1);
    int denum = mod_exp(1LL*2,exp_pow,MOD);
    int numer;
    // db(temp_k);
    if(temp_k-1 >= MOD){
        numer = 0;
    }
    else{
        // db(n,k,p);
        int prod = 1;
        int init = mod_exp(1LL*2,n,MOD);
        int inverse = invFermat(mod_exp(1LL*2,p,MOD)%MOD,MOD);
        if(inverse < 0) inverse += MOD;
        for(int i=1;i<=temp_k-1;i++)
        {
            // int peeps = (inverse*i)%MOD;
            inverse = (inverse * (init - i)%MOD)%MOD;
            // cout<<inverse<<endl;
        }
        numer = inverse;
    }
    // db(numer,"hi");
    numer = (denum - numer)%MOD;
    if(numer < 0) numer += MOD;
    denum%=MOD;
    if(denum < 0) denum += MOD;
    cout<<numer<<" "<<denum<<endl;
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