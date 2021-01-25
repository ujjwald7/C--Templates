#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mp make_pair
#define endl "\n"
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int maxm=2*1e6;
vector<int>Euler_Phi(maxm+1,0);
int dp[maxm+1]={0},depth[maxm+1]={0};

void phi_sieve()
{
    Euler_Phi[0]=0;
    Euler_Phi[1]=1;
    for(int i=2;i<=maxm;i++) Euler_Phi[i]=i;
    for(int i=2;i<=maxm;i++){
        if(Euler_Phi[i]==i){
            for(int j=i;j<=maxm;j+=i) Euler_Phi[j]-=Euler_Phi[j]/i;
        }
    }
    for(int i=2;i<=maxm;i++){
        depth[i]=1+depth[Euler_Phi[i]];
        dp[i]=dp[i-1]+depth[i];
    }
}

void solve()
{
    int m,n; cin>>m>>n;
    int ans=0;
    ans=dp[n]-dp[m-1];
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
    phi_sieve();
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}