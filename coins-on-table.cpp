#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
int n,m,k;
vector<vector<char> > input;
vector<vector<bool> > visited;
vector<vector<int> > arr;
int minOp = INT_MAX;
void dfs(int x , int y, int ops,int length)
{
	if(visited[x][y] || minOp < ops || length >k)
		return;
	if(arr[x][y] <=ops )
		return;
	if(x == 0&& y==0)
	{
		if(length <=k && minOp > ops)
			minOp = ops;
		return;
	}
	visited[x][y] = true;
	arr[x][y] = ops;
	if(x < n-1)
		dfs(x+1,y,ops+(input[x+1][y]!='U'?1:0),length+1);
	if(y<m-1)
		dfs(x,y+1,ops+(input[x][y+1]!='L'?1:0),length+1);
	if(x>0)
		dfs(x-1,y,ops+(input[x-1][y]!='D'?1:0),length+1);
	if(y>0)
		dfs(x,y-1,ops+(input[x][y-1]!='R'?1:0),length+1);
	visited[x][y] = false;
}
int main()
{
	cin >> n >>m >>k;
	char s;
	input = vector<vector<char> >(n,vector<char>(m));
	visited = vector<vector<bool> >(n,vector<bool>(m,false));
	arr = vector<vector<int> >(n,vector<int>(m,INT_MAX));
	int x,y;
	for(int i =0;i<n;i++)
	{
		for(int j =0 ;j<m;j++)
		{
			cin >> s;
			input[i][j] = s;
			if(s == '*')
			{
				x = i;
				y = j;
			}
		}
	}
	dfs(x,y,0,0);
	if(minOp==INT_MAX)
		minOp = -1;
	cout << minOp <<endl;
	return 0;
}
