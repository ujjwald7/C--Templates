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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k=log2(n);
    int sparse[n+1][k+1],sparse_min[n+1][k+1];
    for(int i=0;i<n;i++) sparse[i][0]=a[i];
    for(int j=1;j<=k;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            sparse[i][j]=max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=0;i<n;i++) sparse_min[i][0]=a[i];
    for(int j=1;j<=k;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            sparse_min[i][j]=min(sparse_min[i][j-1],sparse_min[i+(1<<(j-1))][j-1]);
        }
    }
    int q; cin>>q;
    while(q--)
    {
        int l,r; cin>>l>>r;
        double op1,op2,op3,op4;  //range-left, in-range, range-right, and quickest burner
        op1=op2=op3=op4=INT_MIN;
        //find in-range
        int range=r-l+1;
        range=log2(range);
        op4=min(sparse_min[l][range],sparse_min[r-(1<<range)+1][range]);
        op2=max(sparse[l][range],sparse[r-(1<<range)+1][range]);
        op2=op4+((op2-op4)/2);
        //find range-left
        if(l>0)
        {                    
            int r1=l-1,r2=l-1;  //r1=no. of elements , r2=right counter
            r1=log2(r1);
            op1=max(sparse[0][r1],sparse[r2-(1<<r1)+1][r1]);
            op1+=op4;
        }
        //find range-right
        if(r<n-1)
        {
            int no_of_ele=n-r-1;
            int lc=r+1;
            int lr=n-1; //left and right counters;
            int f=lr-lc+1;
            f=log2(f);
            op3=max(sparse[lc][f],sparse[lr-(1<<f)+1][f]);
            op3+=op4;
        }
        double ans=max(op1,max(op2,op3));
        cout<<fixed<<setprecision(1)<<ans<<endl;
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