// Transpose Matrix
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> res;
    vector<int> vec;

        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            vec.push_back(matrix[j][i]);
        }
        res.push_back(vec);
        vec.clear();
    }
    return res;
}

void printMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



int main()
{
    vector<vector<int>> matrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    vector<vector<int>> ans = transpose(matrix);
    printMatrix(ans);

    cout << endl;

    matrix = {{1, 2, 3}, { 4, 5, 6 }};
    ans = transpose(matrix);
    printMatrix(ans);
}
