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

unordered_map<int,int>f1;

int power(int n,int p)
{
    int res=1;
    while(p){
        if(p&1) res*=n;
        n*=n;
        p/=2;
    }
    return res;
}

void Fill(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0){
            int ans=0;
            while(n%i==0){
                n/=i;
                ans++;
            }
            f1[i]=ans;
        }
    }
    if(n>1) f1[n]=1;
}

void solve()
{
    f1.clear();
    int n; cin>>n;
    Fill(n);
    int ans=1;
    for(auto x:f1){
        int temp=power(x.F,x.S+1);
        temp--;
        temp=temp/(x.F-1);
        ans*=temp;
    }
    cout<<ans-n<<endl;
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
    while(t--)
    solve();
    return 0;
}