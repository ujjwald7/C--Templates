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
#define MOD 1000000007  //1e9+7

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
    int n;
    cin>>n;
    int a[1000000]={0};
    int lastocc[1000000]={0};
    int ans[1000000]={0};
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ld sum=0;
    ans[0]=0;
    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1]+(i-lastocc[a[i]]);
        lastocc[a[i]]=i;
        sum+=ans[i];
    }
    ld FinalAns=(2*(sum)-n)/(n*n);         //since large numbers may be present 2*(sum)==(2*(sum-n))+n
    cout<<fixed<<setprecision(6)<<FinalAns<<endl;
    return 0;
}