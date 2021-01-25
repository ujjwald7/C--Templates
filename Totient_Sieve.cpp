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
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N=1e6;
int p[N+1]={0};

void PrimeSieve(int *p)
{
    p[0]=0;
    p[1]=1;
    p[2]=2;
    for(int i=3;i<=N;i+=2)
    {
        p[i]=i;
    }
    for(int i=2;i<=N;i+=2) p[i]=2;
    for(int i=3;i*i<=N;i+=2)
    {
        if(p[i])
        {
            for(int j=i*i;j<=N;j=j+2*i)
            {
                p[j]=min(p[j],i);
            }
        }
    }
    return;
}

void solve()
{	
    int n; cin>>n;
    set<int>uni;
    int temp=n;
    while(n>1){
        uni.insert(p[n]);
        n/=p[n];
    }
    int ans=temp;
    for(auto x:uni){
        ans*=(x-1);
        ans/=x;
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
    PrimeSieve(p);
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}