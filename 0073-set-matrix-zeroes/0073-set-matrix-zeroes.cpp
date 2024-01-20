class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        bool zfr = false, zfc = false; // To check if first row/col contains a 0

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Use first cell as indicator off presence of 0
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    zfr = (i == 0) || zfr;
                    zfc = (j == 0) || zfc;
                }
            }
        }

        for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++)
                    if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
                        matrix[i][j] = 0;
        }

        if (zfr)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (zfc)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};