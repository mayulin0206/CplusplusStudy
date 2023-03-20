//reference link 
//https://zhuanlan.zhihu.com/p/401503400
//https://blog.csdn.net/K346K346/article/details/52638088

#include <iostream>
#include <vector>

using namespace std;

#define LAYER  1024
#define EDDNUM 20

int eggThrowCnt(int high, int eggNum){
	int dp[EDDNUM][LAYER] = {0};
	for (int i = 1; i < LAYER; ++i)
	{
		dp[1][i] = i;
	}
	for (int i = 1; i < EDDNUM; ++i)
	{
		dp[i][1] = 1;
		dp[i][0] = 0;
	}
	for (int i = 2; i < EDDNUM; ++i)
	{
		for (int j = 2; j < LAYER; ++j)
		{
			int k = 1;
			int minNum = 1 + max(dp[i - 1][k - 1] , dp[i][j - k] + 1);
			for(; k <= j; k++)
			{
				minNum = min(minNum, 1 + max(dp[i - 1][k - 1] , dp[i][j - k]));
			}
			dp[i][j] = minNum;
		}
	}
	cout<<dp[eggNum][high]<<endl;
}
int main(int argc, char const *argv[])
{
	eggThrowCnt(100,2);
	return 0;
}
