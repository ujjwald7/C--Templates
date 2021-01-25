const int p = 31; 
const int m = 1e9 + 9;
int S;
vector<long long> p_pow;
bitset<1000005>bits;

void set_hash(string s)
{
    p_pow.resize(s.length());
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;
}

void rabin_karp(string const& s, string const& t) {
    // const int p = 31; 
    // const int m = 1e9 + 9;
    // int S = s.size(), T = t.size();

    // vector<long long> p_pow(max(S, T)); 
    // p_pow[0] = 1; 
    // for (int i = 1; i < (int)p_pow.size(); i++) 
    //     p_pow[i] = (p_pow[i-1] * p) % m;
    int S = s.size();
    int T=t.size();

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    bits.reset();
    set<int>occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            bits.set(i,1);
    }
    // return occurences;
}