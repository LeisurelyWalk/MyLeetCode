#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int> > dp(len, vector<int>(len, 0));
		for (int i=len-1; i >=0; i--)
		{
			for (int j = i ; j < len; j++)
			{
				if (i == j)
					dp[i][j] = nums[i];
				else {
					dp[i][j] = (nums[i] - dp[i + 1][j]) > (nums[j] - dp[i][j - 1]) ? (nums[i] - dp[i + 1][j]) : (nums[j] - dp[i][j - 1]);
				}
			}
		}
		return dp[0][ len - 1] >= 0;
	}
};
int main()
{
	vector<int>nums = { 1,5,233,7 };
	Solution s0;
	cout << s0.PredictTheWinner(nums);
	return 0;
}
