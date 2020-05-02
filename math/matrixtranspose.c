static void matrixTranspose(int r, int c, int src[r][c], int dst[c][r])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dst[j][i] = src[i][j];
}