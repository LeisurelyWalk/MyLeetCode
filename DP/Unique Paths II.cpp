using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		
		vector<vector<int> > dp(row+1, vector<int>(col+1, 0));
		dp[1][1] = 1;
		for (int i = 1; i < row+1; i++)
		{
			for (int j = 1; j < col+1; j++)
			{
				if (obstacleGrid[i-1][j-1] == 1)
				{
					dp[i][j] = 0;
				}
				else {
					dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[row][col];
	}
};
