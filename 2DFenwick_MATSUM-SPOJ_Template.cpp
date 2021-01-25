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

const int maxm=1025;
int BIT[maxm][maxm]={0},n,m,c;

void Update(int i,int j,int val)
{
    int temp=i;
    while(j<=n)
       { 
            i=temp;
            while(i<=n)
               {
                   BIT[i][j]+=val;
                   i+=(i&(-i));
               }
               j+=(j&(-j));
        }
}

void Update_Point(int i,int j,int val)
{
    Update(i,j,val);
}

int Sum(int i,int j)
{
    int ans=0;
    int temp=i;
    while(j>0)
       { 
            i=temp;
            while(i>0)
               {
                   ans+=BIT[i][j];
                   i-=(i&(-i));
               }
               j-=(j&(-j));
        }
    return ans;
}


// int Range_Sum(int i,int j)
// {
//     int ans=Sum(r)-Sum(l-1);
//     return ans;
// }

void solve()
{   
    cin>>n;
    memset(BIT,0,sizeof(BIT));
    string s;
    int a[n+1][n+1]={0};
    while(cin>>s)
    {
        if(s=="END"){
            cout<<endl;
            return;
        }
        if(s=="SET"){
            int x,y,num; cin>>x>>y>>num;
            x++;y++;
            Update_Point(x,y,-a[x][y]+num);
            a[x][y]=num;
        }
        else{
           int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
           x1++;y1++;x2++;y2++;
           int ans=Sum(x2,y2);
           ans+=Sum(x1-1,y1-1);
           ans-=Sum(x2,y1-1);
           ans-=Sum(x1-1,y2);
           cout<<ans<<endl;
        }
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
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}
