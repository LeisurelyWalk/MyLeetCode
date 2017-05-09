#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> nums(26, 0);
		vector<int> str(p.size(), 0);
		for (int i = 0; i < p.size(); i++)
			str[i] = p[i] - 'a';

		for (int i = 0; i < p.size();i++)
		{
			int k = i;
			int len = 1;
			while (k < p.size() - 1 && (str[k] == str[k + 1] - 1 || str[k] == str[k + 1] + 25))
			{
				k++;
				len++;
			}
			if (len > nums[str[i]])
				nums[str[i]] = len;
		}
		int res = 0;
		for (int i = 0; i < nums.size();i++)
		{
			res += nums[i];
		}
		return res;
	}
};
int main()
{
	Solution s0;
	string str = "zab";
	cout << s0.findSubstringInWraproundString(str);
	return 0;
}
