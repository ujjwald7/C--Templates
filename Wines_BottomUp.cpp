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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007  //10^9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int profit(int wines[],int start,int end,int year,int dp[][100])
{
    if(start>end)
        return 0;
    if(dp[start][end]!=0)
        return dp[start][end];
    int op1,op2;
    op1=wines[start]*year+profit(wines,start+1,end,year+1,dp);
    op2=wines[end]*year+profit(wines,start,end-1,year+1,dp);
    return dp[start][end]=max(op1,op2);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int n;
    cin>>n;
    int wines[n];
    for(int i=0;i<n;i++)
        cin>>wines[i];
    int dp[100][100]={0};
    cout<<profit(wines,0,n-1,1,dp)<<endl;
    return 0;
}

