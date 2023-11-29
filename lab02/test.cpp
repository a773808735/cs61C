#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int result = 0;
    int knightDialer(int n)
    {
        vector<vector<int>> tmp(4, vector<int>(3, -1));
        tmp[0] = {1, 2, 3};
        tmp[1] = {4, 5, 6};
        tmp[2] = {7, 8, 9};
        tmp[3] = {-1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; ++j)
            {
                result += dfs(tmp, n, i, j);
            }
        }
        return result;
    }
    int dfs(const vector<vector<int>> &tmp, int n, int i, int j)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (i < 0 || i > 3)
        {
            return 0;
        }
        else if (j < 0 || j > 2)
        {
            return 0;
        }
        else if (tmp[i][j] == -1)
            return 0;
        else
        {
            return 1 + dfs(tmp, n - 1, i - 2, j - 1) + dfs(tmp, n - 1, i + 2, j - 1) + dfs(tmp, n - 1, i - 2, j + 1) + dfs(tmp, n - 1, i + 2, j + 1) + dfs(tmp, n - 1, i - 1, j - 2) + dfs(tmp, n - 1, i + 1, j - 2) + dfs(tmp, n - 1, i - 1, j + 2) + dfs(tmp, n - 1, i + 1, j + 2);
        }
    }
};

int main()
{
    Solution s;
    cout << s.knightDialer(2);
}