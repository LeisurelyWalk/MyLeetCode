#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto n : nums)
			sum += n;
		if (sum % 2 != 0)
			return false;
		int max = sum / 2;
		vector<int>dp(max + 1, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			int temp = nums[i];
			for (int j = max; j > 0; j--)
			{
				if (temp  <= j)
					dp[j] = dp[j]>(dp[j - temp]+temp)?dp[j]: (dp[j - temp] + temp);
			}
		}
		return dp[max] == max;
	}
};
int main()
{
	vector<int> nums = { 1,5,11,5 };
	Solution s0;
	cout << s0.canPartition(nums);

	return 0;
}
