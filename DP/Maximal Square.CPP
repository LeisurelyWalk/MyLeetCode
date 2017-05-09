#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int res = 0;
		int row = matrix.size();
		if (row == 0)
			return 0;
		int col = matrix[0].size();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] -= '0';
				if (matrix[i][j] == 1)
				{
					if (j >= 1 && i >= 1 && matrix[i - 1][j] == matrix[i - 1][j - 1] && matrix[i][j - 1] == matrix[i - 1][j - 1] && matrix[i - 1][j - 1] >= 1)
					{
						int tp = sqrt(matrix[i - 1][j - 1]);
						matrix[i][j] = 3 * matrix[i - 1][j - 1] - 2 * (tp - 1)*(tp - 1) - 2 * (tp - 1) + 1;
						res = max(int(matrix[i][j]), res);
					}
					else if (j >= 1 && i >= 1 && matrix[i - 1][j - 1] >= 1&& matrix[i - 1][j] >= 1&& matrix[i][j - 1] >= 1)
					{
						matrix[i][j] = 4;
						res = max(int(matrix[i][j]), res);
					}
					else if (j<1 || i<1)
					{
						matrix[i][j] = 1;
						res = max(1, res);
					}
				}
				else {
					matrix[i][j] = 0;
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution s0;
	vector<vector<char> >nums = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
	//vector<vector<char> >nums = { { '1','1','1','1' },{ '1','1','1','1' },{ '1','1','1','1' } };
	int res = s0.maximalSquare(nums);
	return 0;
}
