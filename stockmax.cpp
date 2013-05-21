#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
int main()
{

	int t,n,a;
	cin >> t;
	for(int i =0;i<t;i++)
	{
		cin >> n;
		vector<int> v;
		for(int j=0;j<n;j++)
		{
			cin >> a;
			v.push_back(a);
		}
		int maxVal = v[n-1];
		long long ans = 0;
		for(int k=n-2;k>=0;k--)
		{   
			ans+=max(0,maxVal-v[k]);
			if(v[k]> maxVal)
				maxVal = v[k];

		}
		cout << ans<<endl;
	}
	return 0;
}
