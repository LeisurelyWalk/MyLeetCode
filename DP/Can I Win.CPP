#include<iostream>
#include <vector>
#include<map>
using namespace std;
class Solution {
public:
	map<int, int>mymap;
	bool helper(int used, int des, int maxch)
	{
		if (des <= 0)
			return false;
		if (mymap.find(used) == mymap.end())
		{
			for (int i = 1; i <= maxch; i++)
			{
				if (!(used&(1 << i)))
				{
					int tp = helper(used | (1 << i), des - i, maxch);
					if (!tp)
					{
						mymap.emplace(used, 1);
						return true;
					}

				}
			}
			mymap[used] = 0;
		}
		return mymap[used];
	}
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int sum = (maxChoosableInteger + 1)*maxChoosableInteger / 2;
		if (desiredTotal > sum)
			return false;
		if (desiredTotal <= 0)
			return true;
		return helper(0, desiredTotal, maxChoosableInteger);
	}
};
int main()
{
	Solution s0;
	cout << s0.canIWin(10,11);

	return 0;
}
