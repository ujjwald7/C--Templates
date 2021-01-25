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
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

set<int>uni;

void dp_checker(int i,int j,int n,int *a,int *b)
{
    if(i==n){
        if(j>0){
            int temp=0;
            for(int k=0;k<j;k++){
                temp+=b[k];
            }
            uni.insert(temp);
        }
        return;
    }
    dp_checker(i+1,j,n,a,b);
    b[j]=a[i];
    dp_checker(i+1,j+1,n,a,b);
}

void solve()
{	
    int n; cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    dp_checker(0,0,n,a,b);
    if(uni.count(0)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    uni.clear();
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