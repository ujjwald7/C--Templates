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

int grid[1027][1027]={0};

void Update(int x,int y,int val,int size)
{
    while(x<=size){
        int y1=y;
        while(y1<=size){
            grid[x][y1]+=val;
            y1+=(y1&(-y1));
        }
        x+=(x&(-x));
    }
}

int Sum(int x,int y,int n)
{
    int res=0;
    while(x>0){
        int y1=y;
        while(y1>0){
            res+=grid[x][y1];
            y1-=(y1&(-y1));
        }
        x-=(x&(-x));
    }
    return res;
}

int Query(int x1,int x2,int y1,int y2,int n)
{
    int ans=Sum(x2,y2,n)-Sum(x2,y1-1,n)-Sum(x1-1,y2,n)+Sum(x1-1,y1-1,n);
    return ans;
}

void solve()
{   
    int n; cin>>n;
    grid[0][0]=0;
    memset(grid, 0, sizeof(grid[0][0]) * 1027 * 1027);
    string s;
    while(cin>>s){
        if(s=="END") break;
        if(s=="SET"){
            int x,y,num; cin>>x>>y>>num;
            Update(x+1,y+1,num,n);
        }
        if(s=="SUM"){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int ans=Query(x1+1,x2+1,y1+1,y2+1,n);
            cout<<ans<<endl;
        }
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