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

int n,cap; 
const int maxm=1e4;
int dp[maxm][maxm]={0};

int dp_checker(int i,int *wt,int *val,int cap,int curr)
{
    if(i==n) return 0;
    if(dp[i][curr]!=0) return dp[i][curr];
    int op1,op2;
    op1=op2=INT_MIN;
    if(curr+wt[i]<=cap){
        op1=val[i]+dp_checker(i,wt,val,cap,curr+wt[i]);
    }
    op2=dp_checker(i+1,wt,val,cap,curr);
    return dp[i][curr]=max(op1,op2);
}

void solve()
{	
    cin>>n>>cap;
    int wt[n],val[n];
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
    cout<<dp_checker(0,wt,val,cap,0)<<endl;
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