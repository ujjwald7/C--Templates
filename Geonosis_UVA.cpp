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

void solve()
{
    int n; cin>>n;
    int floyd[n][n];
    int order[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>floyd[i][j];
    }
    for(int i=0;i<n;i++) cin>>order[i];
    int destroy[n];
    bool vis[n]={false};
    for(int i=n-1;i>=0;i--)
    {
        vis[order[i]]=true;
        int ans=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                floyd[j][k]=min(floyd[j][k],floyd[j][order[i]]+floyd[order[i]][k]);
                if(vis[j] and vis[k]) ans+=floyd[j][k];
            }
        }
        destroy[i]=ans;
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=destroy[i];
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