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

const int maxm=1e5+5;
int dp[maxm][2][2][2];
int a[maxm][3],n;

int checker(int pos,int app,int mang,int org)
{
    if(pos>=n) return 0;
    if(dp[pos][app][mang][org]!=-1) return dp[pos][app][mang][org];
    int ans=INT_MAX;
    int op1,op2;
    if(app){
        op1=a[pos][1]+checker(pos+1,0,1,0);
        op2=a[pos][2]+checker(pos+1,0,0,1);
    }
    if(mang){
        op1=a[pos][0]+checker(pos+1,1,0,0);
        op2=a[pos][2]+checker(pos+1,0,0,1);
    }
    if(org){
        op1=a[pos][1]+checker(pos+1,0,1,0);
        op2=a[pos][0]+checker(pos+1,1,0,0);
    }
    ans=min(op1,op2);
    // db(pos,ans);
    return dp[pos][app][mang][org]=ans;
}

void solve()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin>>a[i][j];
    }
    int op1=a[0][0]+checker(1,1,0,0);
    // memset(dp,-1,sizeof dp);
    int op2=a[0][1]+checker(1,0,1,0);
    // memset(dp,-1,sizeof dp);
    int op3=a[0][2]+checker(1,0,0,1);
    int ans=min(op1,min(op2,op3));
        // db(op1,op2,op3,ans);
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
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}