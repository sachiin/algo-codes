#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
#define MAX 100001
long long N ;
int treesmall[MAX];
int treelarge[MAX];
int readsmall(int idx){
	int sum = 0;
	while (idx > 0){
		sum += treesmall[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int readlarge(int idx){
	int sum = 0;
	while (idx <=N){
		sum += treelarge[idx];
		idx += (idx & -idx);
	}
	return sum;
}
void updatesmall(int idx ,int val){
	while (idx <=N ){
		treesmall[idx] += val;
		idx += (idx & -idx);
	}
}
void updatelarge(int idx ,int val){
	while (idx > 0 ){
		treelarge[idx] += val;
		idx -= (idx & -idx);
	}
}
int main()
{
	int a;
	cin >> N;
	memset(treelarge,0,sizeof(treelarge));
	memset(treesmall,0,sizeof(treesmall));
	vector<int> input(N);
	vector<int> temp(N);
	vector<long long> small(N);
	vector<long long> large(N);
	for(int i =0;i<N;i++)
	{
		cin >> a;
		input[i] = a;
		temp[i] = a;
	}
	sort(temp.begin(),temp.end());
	vector<int>::iterator it = unique(temp.begin(),temp.end());
	temp.resize(distance(temp.begin(),it));
	for(int i =0;i<N;i++)
	{
		int rank = (int)(lower_bound(temp.begin(),temp.end(),input[i])-temp.begin());
		input[i] = rank+1;
	}

	temp = vector<int>(N+1,-1);
	for(int i =0;i<N;i++)
	{
		small[i] = readsmall(input[i]-1);
		if(temp[input[i]]==-1){
			updatesmall(input[i],1);
			temp[input[i]]=small[i];
		}
		else{
			small[i]-= temp[input[i]];
		}
	}
	temp = vector<int>(N+1,-1);
	for(int i=N-1;i>=0;i--)
	{
		large[i] = readlarge(input[i]+1);
		if(temp[input[i]]==-1){
			updatelarge(input[i],1);
			temp[input[i]] = large[i];
		}
	}
	long long result = 0;
	for(int i = 0 ;i< N;i++)
	{

		result+=small[i]*large[i];
	}
	cout << result <<endl;
	return 0;
}
