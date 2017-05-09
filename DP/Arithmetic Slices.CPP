#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int N = A.size();
		int count = 0;
		if (N < 3)
			return 0;
		int ds = 2;
		int tr = A[1]-A[0];
		vector<int> dp(N, 0);
		for (int i = 2; i < N; i++)
		{
			int temp = A[i] - A[i - 1];
			if (temp == tr)
			{
				ds++;
				if (ds == 3)
				{
					dp[i] = 1;
				}
				else {
					dp[i] = dp[i - 1] + 1;
				}
			}
			else {
				tr = temp;
				ds = 2;
			}
			count += dp[i];
		}
		return count;
	}
};
int main()
{
	vector<int>num = { 1, 3, 5, 7, 9 };
	Solution s0;
	int res = s0.numberOfArithmeticSlices(num);

	return 0;
}
