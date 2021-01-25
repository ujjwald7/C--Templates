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

int minStepsTopDown(int n,int dp[])
{
    if(n==1)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    int a,b,c;
    a=b=c=INT_MAX;
    if(n%3==0)
        a=minStepsTopDown(n/3,dp);
    if(n%2==0)
        b=minStepsTopDown(n/2,dp);
    c=minStepsTopDown(n-1,dp);
    int ans;
    ans = min(a,min(b,c))+1;
    return dp[n]=ans;
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
    int dp[100]={0};
    cout<<minStepsTopDown(n,dp)<<endl;
    return 0;
}

