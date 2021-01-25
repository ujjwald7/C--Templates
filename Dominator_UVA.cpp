#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(x) x.begin(), x.end()
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;
ld pi=2*acos(0.0);

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int grid[101][101];
int temp_grid[101][101];
int n;
bool vis[101],ans[101];

void dfs1(int src)
{
    vis[src]=true;
    ans[src]=true;
    for(int i=0;i<n;i++){
        if(!vis[i] and grid[src][i]==1) dfs1(i);
    }
}

void dfs2(int src,int flag)
{
    if(src==flag) return;
    vis[src]=true;
    for(int i=0;i<n;i++){
        if(!vis[i] and grid[src][i]==1) dfs2(i,flag);
    }
}

void solve()
{       
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>grid[i][j];
    }
    char ans_grid[101][101];
    memset(vis,false,sizeof vis);
    memset(ans,false,sizeof ans);
    dfs1(0);
    for(int i=0;i<n;i++){
        if(vis[i]) ans_grid[0][i]='Y';
        else ans_grid[0][i]='N';
    }
    for(int i=1;i<n;i++)
    {
        memset(vis,false,sizeof vis);
        dfs2(0,i);
        for(int j=0;j<n;j++){
            if(vis[j]==false){
                if(ans[j]) ans_grid[i][j]='Y';
                else ans_grid[i][j]='N';  
            }
            else ans_grid[i][j]='N';
            // db(ans_grid[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n+1;j++){
            if(j==0 || j==2*n) cout<<"+";
            else cout<<"-";
        }
        cout<<endl;
        for(int j=0;j<n;j++){
            cout<<"|"<<ans_grid[i][j];
        }
        cout<<"|";
        cout<<endl;
    }
    for(int j=0;j<2*n+1;j++){
        if(j==0 || j==2*n) cout<<"+";
        else cout<<"-";
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
    int cases=1;
    int t; cin>>t;
    while(t--){
        cout<<"Case "<<cases<<":";
        cout<<endl;
        cases++;
        solve();
    }
    return 0;
}