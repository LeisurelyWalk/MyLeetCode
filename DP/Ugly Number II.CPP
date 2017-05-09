#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 6)
			return n;
		vector<int> num = { 1,2,3,4,5,6 };
		int Max = 6;
		int id2 = 2;
		int id3 = 1;
		int id5 = 0;
		int i = 6;
		while (i < n)
		{
			while (num[id2] * 2 <= Max)
				id2++;
			while (num[id3] * 3 <= Max)
				id3++;
			while (num[id5] * 5 <= Max)
				id5++;
			Max = min(num[id2] * 2, min(num[id3] * 3, num[id5] * 5));
			num.push_back(Max);
			i++;
		}
		return Max;
	}
};
int main()
{
	Solution s0;
	cout << s0.nthUglyNumber(12) << endl;
	return 0;
}
