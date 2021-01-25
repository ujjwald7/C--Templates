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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007  //10^9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif                                  //file end
    int t;
    cin>>t;
    while(t--)
    {
        int c1,c2,c3,c4;
        cin>>c1>>c2>>c3>>c4;
        int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        int rick=0;
        int car=0;
        for(int i=0;i<n;i++)
        {
            rick+=min(a[i]*c1,c2);
        }
        rick=min(rick,c3);
        for(int i=0;i<m;i++)
        {
            car+=min(b[i]*c1,c2);
        }
        car=min(car,c3);
        int ans;
        ans=min(car+rick,c4);
        cout<<ans<<endl;
    }
    return 0;
}  
