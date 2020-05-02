// by llbarclayll

char * longestPalindrome(char * s){
    int SIZE = strlen(s);
    if(SIZE<2) return s;
    bool tbl[SIZE][SIZE];
    memset(tbl, false, sizeof(tbl));
    int start = 0, end = 0, max = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <= i; j++){
            if(s[i]==s[j]&&(i-j<=2 || tbl[j+1][i-1]))
                tbl[j][i] = true;
            if(tbl[j][i] && max < i - j + 1){
                max = i - j + 1;
                start = j;
                end = i;
            }
        }
    }
    char* result = (char*)malloc((end+1-start+1)*4);
    strncpy(result, s+start, end+1-start);
    result[end-start+1]='\0';
    return result;
}