#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
int main()
{
int N,K;
cin >> N >> K;
long long m;
vector<long long> arr;
for(int i =0;i<N;i++)
{
cin >> m;
arr.push_back(m);
}
//vector<vector<long long > >dp(N+1,vector<long long>(K+1,0));
vector<long long> dp1(K+1,0);
vector<long long> dp2(K+1,0);
for(int i = 1;i<=N;i++)
{
long long  maxval  =-1;

for(int j = 0;j<=K;j++)
{
if(maxval < dp2[j])
  maxval = dp2[j];
}
dp1[0] = maxval;
for(int j=1;j<=min(i,K);j++)
{
dp1[j] = dp2[j-1]+arr[i-1];
}
for(int j=0;j<=K;j++)
{
dp2[j] = dp1[j];
}
}
long long maxval = 0;
for(int i =0;i<=K;i++)
{
if(maxval < dp2[i])
 maxval = dp2[i];
}
cout << maxval <<endl;
return 0;
}
