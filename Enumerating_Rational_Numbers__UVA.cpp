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

map<int,pair<int,int>>factors;
int cnt;

int totient_phi(int n)
{
    if(n==1) return 2;
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            res-=res/i;
        }
    }
    if(n>1){
        res-=res/n;
    }
    return res;
}

void solve()
{
    int k;
    while(cin>>k){
        if(k==0) return;
        if(k==1){
            cout<<"0/1"<<endl;
            continue;
        }
        int n=1,temp_k=k;
        cnt=1;
        while(k>0){
            //factors.clear();
            int smol=totient_phi(n);
            if(k-smol<=0) break;
            k-=smol;
            n++;
        }
        int num=1,denum;
        denum=n;
        for(int i=1;i<=n;i++){
            if(k==0){
                break;
            }
            if(__gcd(i,n)==1){
                k--;
                num=i;
            }
        }
        cout<<num<<"/"<<denum<<endl;
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