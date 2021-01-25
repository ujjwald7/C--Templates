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

const int maxm=5*1e3+1;
int dp[maxm][maxm]={0};
int baby_glue[maxm],baby_blue[maxm];

int dp_checker(int i,int j,int a,int b,int n)
{
    if(i>=n and j>=n) return 0;
    if(i>=n) return baby_blue[j];
    if(j>=n) return baby_glue[i];
    if(dp[i][j]!=0) return dp[i][j];
    int op1,op2;
    op1=op2=INT_MIN;
    if(baby_glue[i]>=baby_blue[j]){
        if(a>0) op1=dp_checker(i+1,j+1,a-1,b,n)+baby_glue[i];
        else op1=dp_checker(i+1,j+1,a,b-1,n)+baby_blue[j];
    }
    else{
        if(b>0) op1=dp_checker(i+1,j+1,a,b-1,n)+baby_blue[j];
        else op1=dp_checker(i+1,j+1,a-1,b,n)+baby_glue[i];
    }
    op2=dp_checker(i+1,j+1,a,b,n);
    return dp[i][j]=max(op1,op2);
}

void solve()
{	
    int n,a,b; cin>>n>>a>>b;
    for(int i=0;i<n;i++) cin>>baby_glue[i];
    for(int i=0;i<n;i++) cin>>baby_blue[i];
    cout<<dp_checker(0,0,a,b,n)<<endl;
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