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

int Top_Down_Jumps(int *a,int size,int *dp,int index)
{
    if(index>=size-1){
        return 0;
    }
    if(dp[index]!=0){
        return dp[index];
    }
    int ans=INT_MAX;
    for(int i=1;i<=a[index];i++)
    {
        if(a[index+i]!=0){
            ans=min(ans,Top_Down_Jumps(a,size,dp,index+i)+1);
        }    
    }
    dp[index]=ans;
    return ans;
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[10000]={0};
    cout<<Top_Down_Jumps(a,n,dp,0)<<endl;
    return 0;
}