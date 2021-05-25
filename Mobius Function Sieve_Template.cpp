#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+7;
int miu[M],vs[M];
void pre()
{
	int n=1e5;
	for(int i=1;i<=n;i++)miu[i]=1,vs[i]=0;
	for(int i=2;i<=n;i++)
	{
		if(vs[i])continue;
		for(int j=i;j<=n;j+=i)
		{
			vs[j]=1;
			if((j%(i*i))==0)miu[j]=0;
			else miu[j]=-miu[j];
		}
	}
/*The following is a linear sieve
    mu[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i])
        {
            primes[++cnt] = i;
            mu[i] = -1;
        }
        for(int j = 1; primes[j] <= n/i; j++)
        {
            vis[primes[j]*i] = 1;
            if(i % primes[j] == 0) break;
            else mu[i*primes[j]] = -mu[i];
        }
    }*/
}
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	pre();
  	int n;
  	cin>>n;
  	cout<<miu[n];
	return 0;
}