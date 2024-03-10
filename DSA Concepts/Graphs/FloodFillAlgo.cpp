// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void dfsTraversal(vector<vector<int>> &image, vector<vector<int>> &output, int i, int j, int newColor, vector<vector<int>> &visited)
    {
        visited[i][j] = 1;
        output[i][j] = newColor;

        // [i - 1, j][i + 1, j][i, j - 1][i, j + 1]
        vector<vector<int>> moves = {{0, -1}, {0, +1}, {-1, 0}, {1, 0}};

        for (int k = 0; k < moves.size(); k++)
        {
            int nRow = i + moves[k][0];
            int nCol = j + moves[k][1];

            if (nRow >= 0 && nRow < image.size() && nCol >= 0 && nCol < image[0].size() && !visited[nRow][nCol] && image[nRow][nCol] == image[i][j])
            {
                dfsTraversal(image, output, nRow, nCol, newColor, visited);
            }
        }

        return;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> output = image;
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));

        dfsTraversal(image, output, sr, sc, newColor, visited);

        return output;
    }
};