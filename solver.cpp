#include<bits/stdc++.h>
#include "mutex"
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
// using namespace __gnu_pbds;
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
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ...STACK Limiter
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
ld PI=2*acos(0.0);
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
// typedef tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
string tostring(int number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
} 

int curId = 1;

class Rider{
    string name;
    int rating;
public:
    Rider(string s,int r){
        name = s;
        rating = r;
    }
    string getRiderName(){
        return name;
    }
    int getRiderRating(){
        return rating;
    }
};

class Driver{
    string name;
    int rating;
    bool isAvailable;
public:
    Driver(string driverName,int driverRating, bool isDriverAvailable)
    {
        name = driverName;
        rating = driverRating;
        isAvailable = isDriverAvailable;
    }

    string getDriverName(){
        return name;
    }
    int getDriverRating(){
        return rating;
    }
    bool getDriverAvailable(){
        return isAvailable;
    }
};

class Location{
public:
    int latitude;
    int longitude;
    Location(int x,int y){
        latitude = x;
        longitude = y;
    }
};

class TripMetaData{
    Location* src;
    Location* dest;
    int driverRating;
    Rider* rider;
public:
    TripMetaData(Location* x,Location* y,Rider* curRider){
        src = x;
        dest = y;
        rider = curRider;
    }

    void setDriverRating(Driver* driver){
        driverRating = driver->getDriverRating();
    }

    int getRiderRating(){
        return rider->getRiderRating();
    }

    int getDriverRating(){
        return driverRating;
    }
};

class DriverManager
{
    DriverManager(){};
    static mutex mtx;
    static DriverManager *DriverManagerInstance;
    map<string,Driver*>driversMap;
public:
    static DriverManager* getDriverManagerInstance()
    {
        if(DriverManagerInstance == nullptr){
            mtx.lock();
            if(DriverManagerInstance == nullptr){
                DriverManagerInstance = new DriverManager();
            }
            mtx.unlock();
        }
        return DriverManagerInstance;
    }

    void addDriver(Driver* d){
        driversMap[d->getDriverName()] = d;
    }
    Driver* getDriver(string name){
        return driversMap[name];
    }

    map<string,Driver*> getAllDriversMap(){
        return driversMap;
    }
};

class RiderManager{
    RiderManager(){}
    static mutex mtx;
    static RiderManager *RiderManagerInstance;
    map<string,Rider*>ridersMap;
public:
    static RiderManager* getRiderManager(){
        mtx.lock();
        if(RiderManagerInstance == nullptr){
            RiderManagerInstance = new RiderManager();
        }
        mtx.unlock();
        return RiderManagerInstance;
    }
    void addRider(Rider* newRider){
        ridersMap[newRider->getRiderName()] = newRider;
    }
    Rider* getRider(string name){
        return ridersMap[name];
    }
};

class PricingStratergy{
public:
    virtual double calculatePrice(TripMetaData* metadata) = 0;
};

class DefaultPricingStratergy : public PricingStratergy{
public:
    double calculatePrice(TripMetaData* metadata){
        cout<<"Based on default stratergy"<<endl;
        return 100.0;
    }
};

class RatingBasedPricingStratergy : public PricingStratergy{
public:
    double calculatePrice(TripMetaData* metadata){
        if(metadata->getRiderRating() > 5){
            return 50.0;
        } else{
            return 200.0;
        }
    }
};

class DriverMatchingStratergy{
public:
    virtual Driver* matchDriver(TripMetaData* metadata) = 0;
};

class NearestDriverMatchingStratergy : public DriverMatchingStratergy{
public:
    Driver* matchDriver(TripMetaData* metadata){
        //take location and return nearest driver to the location
        DriverManager* driverManager = DriverManager::getDriverManagerInstance();
        Driver* assignedDriver = driverManager->getAllDriversMap().begin()->second;
        //setDriverRatingInMetadata
        metadata->setDriverRating(assignedDriver);
        return assignedDriver;
    }
};


class StratergyManager{
    StratergyManager(){};
    static mutex mtx;
    static StratergyManager *StratergyManagerInstance;
public:
    static StratergyManager* getStratergyManagerInstance(){
        mtx.lock();
        if(StratergyManagerInstance == nullptr){
            StratergyManagerInstance = new StratergyManager();
        }
        mtx.unlock();
        return StratergyManagerInstance;
    }

    PricingStratergy* getPricingStratergy(TripMetaData* metadata){
        cout<<"Setting Pricing Stratergy"<<endl;
        return new DefaultPricingStratergy();
    }

    DriverMatchingStratergy* getDriverMatchingStratergy(TripMetaData* metadata){
        cout<<"Matching Driver"<<endl;
        return new NearestDriverMatchingStratergy();
    }
};

class Trip{
    Location* src;
    Location* dest;
    Rider* rider;
    Driver* driver;
    double price;
    int tripId;

public:
    Trip(Location* x,Location* y,Rider *a, Driver* d,double curPrice){
        src = x;
        dest = y;
        rider = a;
        driver = d;
        price = curPrice;
        tripId = curId;
        curId++;
    }

    int getTripId(){
        return tripId;
    }

    void displayTripDetails(){
        cout << "Trip id - " << tripId << endl;
        cout << "Rider - " << rider->getRiderName() << endl;
        cout << "Driver - " << driver->getDriverName() << endl;
        cout << "Price - " << price << endl;
        cout << "Locations - " <<src->latitude<<","<<src->longitude<<" and "<<dest->latitude<<","<<dest->longitude << endl;
    }
};

class TripManager{
    static mutex mtx;
    static TripManager *TripManagerInstance;
    RiderManager* riderManager;
    DriverManager* driverManager;
    TripManager(){
        riderManager = RiderManager::getRiderManager();
        driverManager = DriverManager::getDriverManagerInstance();
    }
    map<int,Trip*>tripsInfo;
    map<int,TripMetaData*>tripsMetadataInfo;

public:
    static TripManager* getTripManagerInstance(){
        mtx.lock();
        if(TripManagerInstance == nullptr){
            TripManagerInstance = new TripManager();
        }
        mtx.unlock();
        return TripManagerInstance;
    }

    map<int,Trip*> getTripsMap(){
        return tripsInfo;
    }

    void CreateTrip(Rider* rider, Location* src, Location* dest) {
        TripMetaData* tripMetadata = new TripMetaData(src,dest,rider);
        StratergyManager* stratergyManager = StratergyManager::getStratergyManagerInstance();
        PricingStratergy* pricingStratergy = stratergyManager->getPricingStratergy(tripMetadata);
        DriverMatchingStratergy* driverMatchingStratergy = stratergyManager->getDriverMatchingStratergy(tripMetadata);

        Driver* assignedDriver = driverMatchingStratergy->matchDriver(tripMetadata);
        double price = pricingStratergy->calculatePrice(tripMetadata);

        Trip* trip = new Trip(src,dest,rider,assignedDriver,price);
        int tripId = trip->getTripId();
        tripsInfo[tripId] = trip;
        tripsMetadataInfo[tripId] = tripMetadata;
    }

};

// Define static members
mutex RiderManager::mtx;
RiderManager* RiderManager::RiderManagerInstance = nullptr;

mutex DriverManager::mtx;
DriverManager* DriverManager::DriverManagerInstance = nullptr;

mutex StratergyManager::mtx;
StratergyManager* StratergyManager::StratergyManagerInstance = nullptr;

mutex TripManager::mtx;
TripManager* TripManager::TripManagerInstance = nullptr;

void solve()
{
    RiderManager* riderManager = RiderManager::getRiderManager();
    Rider* rider1 = new Rider("rider1",5);
    Rider* rider2 = new Rider("rider2",10);
    riderManager->addRider(rider1);
    riderManager->addRider(rider2);
    cout<<riderManager->getRider("rider2")->getRiderRating()<<endl;
    Driver* d1 = new Driver("driver1",5,false);
    Driver* d2 = new Driver("driver2",3,true);
    DriverManager* driverManager = DriverManager::getDriverManagerInstance();
    driverManager->addDriver(d1);
    driverManager->addDriver(d2);
    cout<<driverManager->getDriver("driver1")->getDriverRating()<<endl;

    Location* src = new Location(50,100);
    Location* dest = new Location(100,200);
    TripManager* tripManager = TripManager::getTripManagerInstance();
    tripManager->CreateTrip(rider1,src,dest);
    map<int,Trip*> ok = tripManager->getTripsMap();
    for(auto &x : ok){
        x.second->displayTripDetails();
        cout<<endl;
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
 
// 1LL check ?