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

int Bottom_Up_enemy(vector<int>unique,map<int,int>m)
{
    int dp[unique.size()]={0};
    dp[0]=unique[0]*m[unique[0]];
    if(unique[1]-unique[0]>1){
        dp[1]=unique[1]*m[unique[1]]+dp[0];
    }
    else{
        dp[1]=unique[1]*m[unique[1]];
    }    
    for(int i=2;i<unique.size();i++)
    {
        int ans=unique[i]*m[unique[i]];
        if(unique[i]-unique[i-1]>1){
            ans+=dp[i-1];
            ans=max(ans,dp[i-2]);
        }
        else{
            ans+=dp[i-2];
            ans=max(ans,dp[i-1]);
        }
        dp[i]=ans;
    }
    return dp[unique.size()-1];
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
    vector<int>a;
    vector<int>unique;
    map<int,int>m;
    for(int i=0,x;i<n;i++){
        cin>>x;
        a.pb(x);
        m[x]++;
    }
    for(auto element:m){
        unique.pb(element.F);
    }
    cout<<Bottom_Up_enemy(unique,m)<<endl;
    return 0;
}