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

const int maxm=2*1e3;
const int cha=6;
int dp[maxm][maxm][cha];
int a[maxm],b[maxm];

int dp_checker(int i,int j,int n,int m,int k)
{
    if(i>=n || j>=m) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int op1,op2,op3,op4;
    op1=op2=op3=op4=INT_MIN;
    if(a[i]==b[j]) op1=dp_checker(i+1,j+1,n,m,k)+1;
    if(k>0) op2=dp_checker(i+1,j+1,n,m,k-1)+1;
    op3=dp_checker(i,j+1,n,m,k);
    op4=dp_checker(i+1,j,n,m,k);
    return dp[i][j][k]=max(max(op1,op2),max(op3,op4));
}

void solve()
{	
    memset(dp,-1,sizeof dp);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    cout<<dp_checker(0,0,n,m,k)<<endl;
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