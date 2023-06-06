#include <bits/stdc++.h>

 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)

{

     int left_colm = 0;
    int top_row = 0;
    int right_colm = m - 1;
    int bottom_row = n - 1;

    while (top_row < bottom_row && left_colm < right_colm) {
        int temp = mat[top_row][left_colm];

        // Rotate top row
        for (int i = left_colm + 1; i <= right_colm; i++) {
            swap(temp, mat[top_row][i]);
        }
        top_row++;

        // Rotate right column
        for (int i = top_row; i <= bottom_row; i++) {
            swap(temp, mat[i][right_colm]);
        }
        right_colm--;

        // Rotate bottom row
        for (int i = right_colm; i >= left_colm; i--) {
            swap(temp, mat[bottom_row][i]);
        }
        bottom_row--;

        // Rotate left column
        for (int i = bottom_row; i >= top_row; i--) {
            swap(temp, mat[i][left_colm]);
        }
        left_colm++;
        // as we haven't changed the first element yet
        mat[top_row - 1][left_colm - 1] = temp;
    }

}