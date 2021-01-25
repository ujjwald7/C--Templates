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
const int MOD1=1e9+6;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int maxm=1e7+5;
vector<int>phi(maxm+1,0);
vector<bool>primes(maxm+1,true);
int cnt[maxm+1]={0};

void phi_sieve()
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2;i<=maxm;i++) phi[i]=i;
    for(int i=2;i<=maxm;i++){
        if(phi[i]==i){
            for(int j=i;j<=maxm;j+=i) phi[j]-=phi[j]/i;
        }
    }
}

void primecounter()
{
    primes[0]=primes[1]=false;
    for(int i=2;i*i<=maxm;i++){
        if(primes[i]){
            for(int j=i*i;j<=maxm;j+=i) primes[j]=false;
        }
    }
    for(int i=2;i<=maxm;i++){
        cnt[i]=cnt[i-1];
        if(primes[i]) cnt[i]++;
    }
}

int power(int a,int b)
{
    int res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return res%MOD;
}

void solve()
{
    int n; cin>>n;
    int f=cnt[n]-phi[n];
    int tot=phi[n];
    if(f<=0){
        cout<<"1"<<endl;
        return;
    }
    int fact=1;
    for(int i=2;i<=f;i++){
        fact=(fact*i)%(MOD1);
    }
    int ans=power(tot,fact);
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
    phi_sieve();
    primecounter();
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}