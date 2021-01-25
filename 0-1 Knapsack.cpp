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

int dp[1000][1000]={0};

int Knapsack(int i,int *size,int *val,int n,int s,int cur)
{
    if(i==n || cur==s) return 0;
    if(dp[i][cur]!=0) return dp[i][cur];
    int op1=INT_MIN,op2=INT_MIN;
    if(cur+size[i]<=s){
        op1=Knapsack(i+1,size,val,n,s,cur+size[i])+val[i];
    }
    op2=Knapsack(i+1,size,val,n,s,cur);
    return dp[i][cur]=max(op1,op2);
}

void solve()
{	
    int n,s; cin>>n>>s;
    int size[n],val[n];
    for(int i=0;i<n;i++) cin>>size[i];
    for(int i=0;i<n;i++) cin>>val[i];
    Knapsack(0,size,val,n,s,0);
    cout<<dp[0][0]<<endl;
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