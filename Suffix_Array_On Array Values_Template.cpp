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
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;
const int MOD2=998244353;
ld PI=2*acos(0.0);
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}   

vector<int>suffixes;
int maxms;
vector<int>diff_main;

void radix_sort(vector<pair<pair<int,int>,int>> &a)
{
    int n=a.size();
    {
        vector<int>cnt(n);
        for(auto x:a){
            cnt[x.F.S]++;       //first-based on second index
        }
    
        vector<pair<pair<int,int>,int>>a_new(n);
        vector<int>pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++){
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(auto x:a)
        {
            int i=x.F.S;
            a_new[pos[i]]=x;
            pos[i]++;
        }
    
        a=a_new;
    }
 
    //second linear iteration  based on first index
    {
        vector<int>cnt(n);
        for(auto x:a){
            cnt[x.F.F]++;       //first-based on second index
        }
    
        vector<pair<pair<int,int>,int>>a_new(n);
        vector<int>pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++){
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(auto x:a)
        {
            int i=x.F.F;
            a_new[pos[i]]=x;
            pos[i]++;
        }
    
        a=a_new;
    }
}

int checker(int a,vector<int> b)
{   
    int i=a,j=0;
    while(i<maxms and j<b.size())
    {
        if(diff_main[i]==b[j]){
            i++;
            j++;
        }
        else if(diff_main[i] > b[j]){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(i==diff_main.size() and j!=b.size()){
        return 2;
    }
    return 0;
}

int check_upper(vector<int> &x)
{
    int l = 0,r = suffixes.size() - 1;
    for(int i=0;i<30;i++)
    {
        int mid = l + (r-l)/2;
        if(mid >= suffixes.size()){
            mid = suffixes.size()-1;
        }
        if(mid < 0){
            mid = 0;
        }
        int ok = checker(suffixes[mid],x);
        if(ok==0){
            l = mid+1;
        }
        else if(ok==1){
            r = mid - 1;
        }
        else if(ok==2){
            l = mid+1;
        }
    }
    return l;
}

int check_lower(vector<int>&x)
{
    int l = 0,r = suffixes.size() - 1;
    for(int i=0;i<30;i++)
    {
        int mid = l + (r-l)/2;
        if(mid >= suffixes.size()){
            mid = suffixes.size()-1;
        }
        if(mid < 0){
            mid = 0;
        }
        int ok = checker(suffixes[mid],x);
        if(ok==0){
            r = mid-1;
        }
        else if(ok==1){
            r = mid - 1;
        }
        else if(ok==2){
            l = mid+1;
        }
    }
    return l;
}

//////////////Implementation : https://codeforces.com/problemset/problem/471/D

void solve()
{
    int a,b; cin>>a>>b;
    vector<int>ok(a);
    for(int i=0;i<a;i++){
        cin>>ok[i];
    }
    if(b==1){
        int x; cin>>x;
        int ans = a;
        cout<<ans<<endl;
        return;
    }
    diff_main.pb(-1e15);
    for(int i=1;i<a;i++){
        diff_main.pb(ok[i]-ok[i-1]);
    }
    int n = diff_main.size();
    maxms = n;
    vector<int>pos(n),clas(n);
 
    int k=0;
    //k==0
    {
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++){
            a[i] = {diff_main[i],i} ;
        }
        sort(all(a));
        for(int i=0;i<n;i++){
            pos[i]=a[i].S;
        }
        //assign equivalence classes
        clas[pos[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].F==a[i-1].F){
                clas[pos[i]]=clas[pos[i-1]];
            }
            else{
                clas[pos[i]]=clas[pos[i-1]] + 1;
            }
        }
    }
    while( (1<<k) < n )
    {
        //use previous phase for assessment of (k+1)th phase
 
        vector<pair<pair<int,int>,int>>a(n);
 
        for(int i=0;i<n;i++)
        {
            //take left part and the right part
            a[i] = { {clas[i] , clas[(i+(1<<k))%n]} , i };
        }
        // sort(all(a));
        //replaced with radix_sort
 
        radix_sort(a);
 
        for(int i=0;i<n;i++){
            pos[i]=a[i].S;
        }
        //assign equivalence classes
        clas[pos[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].F==a[i-1].F){
                clas[pos[i]]=clas[pos[i-1]];
            }
            else{
                clas[pos[i]]=clas[pos[i-1]] + 1;
            }
        }
        k++;
    } 
    for(int i=0;i<n;i++){
        suffixes.pb(pos[i]);
    }
    // for(auto x: suffixes){
    //     cout<<x<<" ";
    // }
    vector<int>ok2(b);
    for(int i=0;i<b;i++){
        cin>>ok2[i];
    }
    vector<int>search_diffs;
    for(int i=1;i<b;i++){
        search_diffs.pb(ok2[i]-ok2[i-1]);
    }
    int f1 = check_upper(search_diffs);
    int f2 = check_lower(search_diffs);
    cout<<f1-f2<<endl;
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
 
// 1LL check ?