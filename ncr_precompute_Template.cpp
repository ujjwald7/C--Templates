const int maxm = 1e6+5;
int facts[maxm];
int invfacts[maxm];
int numbersinverse[maxm];

void precomp()
{
    facts[0] = facts[1] = 1;
    for(int i=2;i<maxm;i++){
        facts[i] = (i*facts[i-1])%MOD;
    }
    numbersinverse[0] = numbersinverse[1] = 1;
    for(int i=2;i<maxm;i++){
        numbersinverse[i] = numbersinverse[MOD%i]*(MOD-MOD/i)%MOD;
    }

    invfacts[0] = invfacts[1] = 1;
    for(int i=2;i<maxm;i++){
        invfacts[i] = (numbersinverse[i]*invfacts[i-1])%MOD;
    }
}

int ways(int n,int r)
{
    int f1 = facts[n];
    int f2 = invfacts[r];
    int f3 = invfacts[n-r];
    f1 = (f1*f2)%MOD;
    f1 = (f1*f3)%MOD;
    return f1;
}
