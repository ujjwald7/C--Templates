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
const int MOD=1e6+3;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int maxm=1e2+1;
int dp[maxm][3][maxm];
int n,k; 

int dp_checker(int cur,int prev,int cnt)
{
    if(cur==n){
        if(cnt==k) return 1;
        return 0;
    }
    if(dp[cur][prev][cnt]!=-1) return dp[cur][prev][cnt];
    int ans=0;
    if(prev==1){
        ans=(ans+dp_checker(cur+1,1,cnt+1))%MOD;
    }
    else{
        ans=(ans+dp_checker(cur+1,1,cnt))%MOD;
    }
    ans=(ans+dp_checker(cur+1,0,cnt))%MOD;
    return dp[cur][prev][cnt]=ans;
}

void solve()
{	
    memset(dp,-1,sizeof dp);
    cin>>n>>k;
    int ans=(dp_checker(1,1,0)+dp_checker(1,0,0))%MOD;
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
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}