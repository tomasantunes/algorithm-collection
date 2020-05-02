// by chinagogoya

char* convert(char* s, int numRows) {
    int Ii,Ij;
    int CycleNum, Num = 0;
    int Size = 0;
    char *pS;
    pS = s;
    CycleNum = 2 * numRows -2;
    if (numRows == 1) return s;
    Size = strlen (s);
    pS = NULL;
    pS = malloc (1000);
    for (Ii = 0; Ii < numRows;Ii++) {
        for (Ij = 0;Ii + Ij < Size;Ij += CycleNum) {
            *(pS + Num) = *(s + Ii + Ij);
            Num++;
            if (Ii !=0 && Ii != numRows - 1 &&
                Ij + CycleNum - Ii < Size) {
                *(pS + Num) = *(s + Ij + CycleNum - Ii);
                Num++;
            }

        }
    }
    *(pS + Num) = '\0';
    return pS;   
}