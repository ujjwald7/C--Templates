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
#define MOD 1000000007  //1e9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int LaddersOptimised(int n,int k)
{
    int dp[100]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
        dp[i]= 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int n,k;
    cin>>n>>k;
    cout<<LaddersOptimised(n,k);
    return 0;
}