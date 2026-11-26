int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize,
                    int** returnColumnSizes) {

    int m = matSize;
    int n = matColSize[0];

    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** result = malloc(r * sizeof(int*));
    *returnColumnSizes = malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;

            int newRow = index / c;
            int newCol = index % c;

            result[newRow][newCol] = mat[i][j];
        }
    }

    *returnSize = r;
    return result;
}