/* remove the billboard at ith position .. find the minimum profit removed dp[i] = min(dp[i-j] check last k+1 elems) + arr[i]*/ 
#include<queue>
#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#define mp make_pair
int main()
{
	int N,K;
	cin >> N >> K;
	long long m;
	vector<long long> arr;
	long long totalProfit = 0;
	for(int i =0;i<N;i++)
	{
		cin >> m;
		arr.push_back(m);
		totalProfit += m;
	}
	vector<long long> dp(N+1,0);
	set<pair<long long,long long> > q;
	arr.push_back(0);
	dp[0] = arr[0];
	for(int i = 0;i<min(K+1,N+1);i++)
	{

		q.insert(mp(arr[i],i));
		dp[i] = arr[i];
	}
	for(int i = K+1;i<=N;i++)
	{
		set<pair<long long,long long> >::iterator it = q.begin();
		while((*it).second < i-K-1){
			q.erase(it);
			it = q.begin();

		}

		dp[i] = (*it).first+arr[i];
		q.insert(mp(dp[i],i));
	}
	cout << totalProfit-dp[N] <<endl;
	return 0;
}
