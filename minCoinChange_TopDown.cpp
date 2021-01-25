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

int minCoinChangeTopDown(int n,int a[],int x,int dp[])
{
    if(x==0)
        return 0;
    if(dp[x]!=0)
        return dp[x];
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if((x-a[i])>=0)
            ans=min(ans,minCoinChangeTopDown(n,a,x-a[i],dp)+1);
    }
    dp[x]=ans;
    return dp[x];
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
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cin>>x;
    int dp[100]={0};
    cout<<minCoinChangeTopDown(n,a,x,dp);
    return 0;
}

