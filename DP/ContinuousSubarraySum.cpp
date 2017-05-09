#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int len = nums.size();
		if (len < 2)
			return false;
		map<int, int> sum;
		int tp=0;
		sum[0] = -1;
		for (int i = 0; i < len; i++)
		{
			tp += nums[i];

			if (k != 0)
				tp = tp%k;
			if (sum.find(tp) != sum.end() && sum[tp] < i - 1)
				return true;
			else if(sum.find(tp) == sum.end())
				sum[tp] = i;
		}
		return false;
	}
};
int main()
{
	Solution so;
	vector <int> nums = { 0,0 };
	int k = 0;
	cout << so.checkSubarraySum(nums, k);


	return 0;
}
