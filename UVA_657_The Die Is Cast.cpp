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
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;

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

int h,w;
char grid[55][55];
bool vis[55][55],vis_pts[55][55];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int sz=0;
vector<int>ans;
vector<P>pts;

void dfs(int x,int y)
{
    vis[x][y]=true;
    if(grid[x][y]=='X') pts.pb({x,y});
    for(int i=0;i<4;i++){
        if(x+dx[i]>=0 and y+dy[i]>=0 and x+dx[i]<h and y+dy[i]<w)
        {      
            if(grid[x+dx[i]][y+dy[i]]!='.' and !vis[x+dx[i]][y+dy[i]])
            {
                // db(sz,x,y,grid[x][y]);
                dfs(x+dx[i],y+dy[i]);
            }
        }
    }
}

void dfs_pts(int x,int y)
{
    vis_pts[x][y]=true;
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]>=0 and y+dy[i]>=0 and x+dx[i]<h and y+dy[i]<w)
        {
            if(grid[x+dx[i]][y+dy[i]]=='X' and !vis_pts[x+dx[i]][y+dy[i]])
            {
                dfs_pts(x+dx[i],y+dy[i]);
            }
        }
    }
}

void solve()
{
    int t=1;
    while(cin>>w>>h)
    {
        if(h==0 and w==0) return;
        ans.clear();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++) cin>>grid[i][j];
        }
        memset(vis,false,sizeof(vis));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
            {
                if(!vis[i][j] and (grid[i][j]=='*' or grid[i][j]=='X'))
                {
                    sz=0;
                    pts.clear();
                    memset(vis_pts,false,sizeof(vis));
                    dfs(i,j);
                    for(auto x:pts){
                        if(!vis_pts[x.F][x.S]){
                            sz++;
                            dfs_pts(x.F,x.S);
                        }
                    }
                    ans.pb(sz);
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"Throw "<<t<<endl;
        for(int i=0;i<ans.size();i++){
            if(i==ans.size()-1) cout<<ans[i];
            else cout<<ans[i]<<" ";
        }
        cout<<endl<<endl;
        t++;
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
    // int cases=1;
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}