#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int count = 0;
	void dfs(int id, int sum, int S, int N,vector<int>&nums)
	{
		if (id == N)
		{
			if (sum == S)
				count++;
			else
				return;
			return;
		}
		for (int i = -1; i < 2; i+=2)
		{
			dfs(id + 1, sum + i*nums[id], S, N,nums);
		}
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int N = nums.size();
		int sum = 0;
		for (int i = -1; i < 2; i+=2)
		{
			dfs(1, sum + i*nums[0], S, N, nums);
		}
		return count;
	}
};
int main()
{
	Solution s0;
	vector<int> num = { 1,1,1,1,1 };
	cout << s0.findTargetSumWays(num, 3);

	return 0;
}
