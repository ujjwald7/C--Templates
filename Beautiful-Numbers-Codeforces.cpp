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

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}   

const int maxm=1e6+5;
int fact[maxm];

void filltable()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<maxm;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

bool isValid(int sum,int a,int b)
{
    while(sum)
    {
        int x=sum%10;
        if(x!=a and x!=b) return false;
        sum/=10;
    }
    return true;
}

int power(int x,int k)
{
    int tot=1;
    while(k){
        if(k&1) tot=(tot*x)%MOD;
        x=(x*x)%MOD;
        k>>=1;
    }
    return tot%MOD;
}

int modinverse(int x)
{
    int ans=power(x,MOD-2);
    return ans;
}

void solve()
{  
    int a,b,n; cin>>a>>b>>n;
    int ans=0;
    for(int i=0;i<=n;i++){
        int sum=a*i+(n-i)*b;
        if(isValid(sum,a,b))
        {
            //add nCi to ans
            ans+=(fact[n]%MOD*modinverse(fact[n-i])%MOD*modinverse(fact[i])%MOD)%MOD;
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    filltable();
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}