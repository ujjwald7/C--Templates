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

const int maxm=1e6+1;
int fact[maxm+5];

void filltables()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<maxm+5;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
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
    return ans%MOD;
}

void solve()
{  
    int n; cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a.pb(x);
    }
    int ans=1,cnt=0;
    for(int i=0;i<n;i++){
        ans=(ans*fact[cnt+a[i]-1])%MOD;
        ans=(ans*modinverse(fact[cnt]))%MOD;
        ans=(ans*modinverse(fact[a[i]-1]))%MOD;
        cnt+=a[i];
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
    int t; cin>>t;
    int r=1;
    filltables();
    while(t--){
        cout<<"Case "<<r<<": ";
        r++;
        solve();}
    return 0;
}