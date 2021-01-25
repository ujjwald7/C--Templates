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

void solve()
{  
    int n; cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    int k=log2(n);
    int sparse[n+1][k+1];
    for(int i=0;i<n;i++){
        sparse[i][0]=a[i];
    }
    for(int j=1;j<=k;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            sparse[i][j]=min(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        int range=r-l+1;
        range=log2(range);
        int ans=min(sparse[l][range],sparse[r-(1<<range)+1][range]);
        cout<<ans<<endl;
    }
}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}