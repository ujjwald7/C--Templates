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

void Update(int idx,int *BIT,int size,int val)
{
    while(idx<=size){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int query(int r,int *BIT)
{
    int ans=0;
    while(r>0){
        ans+=BIT[r];
        r-=(r&(-r));
    }
    return ans;
}

void solve()
{
    int n,f=1;
    while(cin>>n){
        if(n==0) return;
        if(f!=1) cout<<endl;
        cout<<"Case "<<f<<":"<<endl;
        int a[n+1],BIT[n+1]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
            Update(i,BIT,n,a[i]);
        }
        string act;
        while(cin>>act)
        {
            if(act=="END") break;
            int x,y;
            if(act=="S"){
                cin>>x>>y;
                Update(x,BIT,n,y-a[x]);
                a[x]=y;
            }
            if(act=="M"){
                cin>>x>>y;
                int ans=query(y,BIT)-query(x-1,BIT);
                cout<<ans<<endl;
            }
        }
        f++;
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