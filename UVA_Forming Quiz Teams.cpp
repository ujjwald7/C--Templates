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

int n,target;
ld dp[1<<16];
ld dist[20][20];

ld checker(int mask)
{
    if(mask==target) return 0;
    if(dp[mask]!=0){
        return dp[mask];
    }
    ld ans=1e9;
    int i,j;
    for(i=0;i<2*n;i++){
        if(!(mask&(1<<i))){
            break;
        }
    }
    for(j=i+1;j<2*n;j++){
        if(!(mask&(1<<j))){
            ans=min(ans,dist[i][j]+checker(mask|(1<<i)|(1<<j)));
        }
    }
    return dp[mask]=ans;
}

void solve()
{
    int r=1;
    while(cin>>n)
    {
        if(n==0) return;
        target=(1<<(2*n))-1;
        int x[2*n],y[2*n];
        for(int i=0;i<2*n;i++){
            string s; cin>>s;
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<2*n-1;i++){
            for(int j=i+1;j<2*n;j++){
                dist[i][j]=hypot(x[j]-x[i],y[j]-y[i]);
                dist[j][i]=hypot(x[j]-x[i],y[j]-y[i]);
            }
        }
        memset(dp,0,sizeof dp);
        cout<<"Case "<<r<<": "<<fixed<<setprecision(2)<<checker(0)<<endl;
        r++;
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