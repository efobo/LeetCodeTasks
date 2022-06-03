// 304. Range Sum Query 2D - Immutable
//

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v;
        for (int i = 0; i < (n + 1); i++) 
        {
            v.push_back(0);
        }
        sum.push_back(v);
        for (int i = 1; i < (m + 1); i++)
        {
            v.clear();
            int s = 0;
            v.push_back(0);
            for (int j = 1; j < (n + 1); j++)
            {
                s += matrix[i-1][j-1];
                v.push_back(sum[i-1][j] + s);
            }
            sum.push_back(v);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, { 5, 6, 3, 2, 1 }, { 1, 2, 0, 1, 5 }, { 4, 1, 0, 1, 7 }, { 1, 0, 3, 0, 5 }};
    NumMatrix* obj = new NumMatrix(matrix);
    // 8
    int param_1 = obj->sumRegion(2, 1, 4, 3);
    cout << "param1 = " << param_1 << endl;
    // 11
    int param_2 = obj->sumRegion(1, 1, 2, 2);
    cout << "param2 = " << param_2 << endl;
    // 12
    int param_3 = obj->sumRegion(1, 2, 2, 4);
    cout << "param3 = " << param_3 << endl;
}

