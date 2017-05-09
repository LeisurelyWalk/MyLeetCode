#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int maxpre = nums[0];
		int minpre = nums[0];
		int resmax = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int tempmaxpre = max(max(maxpre*nums[i], minpre*nums[i]), nums[i]);
			int tempminpre = min(min(maxpre*nums[i], minpre*nums[i]), nums[i]);
			resmax = max(tempmaxpre, resmax);
			maxpre = tempmaxpre;
			minpre = tempminpre;
		}
		return resmax;
	}
};
int main()
{

	return 0;
}
