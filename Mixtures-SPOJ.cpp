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
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int maxm=1e3;
int dp[maxm][maxm]={0};

int smoke(int i,int j,int *a)
{
    int tot=0;
    for(int k=i;k<=j;k++) tot=(tot+a[k])%100;
    return tot;
}

int dp_checker(int i,int j,int *a)
{
    if(i>=j) return 0;  
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],dp_checker(i,k,a)+dp_checker(k+1,j,a)+smoke(i,k,a)*smoke(k+1,j,a));
    }
    return dp[i][j];
}

void solve()
{	
    int n; cin>>n;
    int a[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<dp_checker(0,n-1,a)<<endl;
}   
	
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}