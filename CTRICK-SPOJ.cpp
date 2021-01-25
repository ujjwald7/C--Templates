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

void Update(int idx,int val,int *BIT,int size)
{
    while(idx<=size){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int free_me(int *BIT,int idx)
{
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return res;
}

int binary_s(int val,int *BIT,int *a,int n)
{
    int s=1,e=n;
    while(s<e)
    {
        int mid=(s+e)/2;
        int me=free_me(BIT,mid);
        if(me>val){
            e=mid-1;
        }
        else if(me<val){
            s=mid+1;
        }
        else{
            e=mid-1;
            if(a[mid]==0) return mid;
        }
    }
    return s;
}

void solve()
{   
    int n; cin>>n;
    int BIT[n+1]={0},a[n+1]={0};
    for(int i=1;i<=n;i++) Update(i,1,BIT,n);
    int free_cells=n;
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        int free=i+1;
        int before=free_me(BIT,cur-1);
        int total=before+free;
        int cell=total%free_cells;
        if(cell==0) cell=free_cells;
        int ret=binary_s(cell,BIT,a,n);
        a[ret]=i;
        free_cells--;
        cur=ret;
        Update(ret,-1,BIT,n);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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