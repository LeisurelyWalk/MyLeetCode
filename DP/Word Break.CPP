#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> helper(string s, vector<string>& wordDict, int i)
	{
		vector<int>res;
		for (int i = 0; i < wordDict.size(); i++)
		{
			string str = wordDict[i];
			int k = s.size() - 1;
			int m = str.size() - 1;
			while (s[k]==str[m])
			{
				k--;
				m--;
				if (k < 0 || m < 0)
					break;
			}
			if(k+1!=s.size-1)
				res.push_back(k + 1);
		}
	}
	bool wordBreak(string s, vector<string>& wordDict) {

	}
};
int main()
{
	return 0;
}
