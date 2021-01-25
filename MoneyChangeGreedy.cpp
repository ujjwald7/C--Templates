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

int money_change(int coins[],int size,int money)
{
    int ans=0;
    while(money>0)
    {
        int idx=upper_bound(coins,coins+size,money)-coins-1;
        cout<<coins[idx]<<"+";
        money-=coins[idx];
        ans++;
    }
    cout<<endl;
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
    int coins[]={1,2,5,10,20,50,100,500,2000};
    int t=sizeof(coins)/sizeof(int);
    cout<<money_change(coins,t,n)<<endl;
    return 0;
}