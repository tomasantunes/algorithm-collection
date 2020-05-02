// by chrischen99244

char * longestCommonPrefix(char ** strs, int strsSize){
	if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    int flag = 0;
    int i, j;
    for (i = 0; flag == 0; i++) { // ith letter
        for (j = 0; j < strsSize-1; j++) { // jth strings
            if (strs[j][i] != strs[j+1][i]) {
                flag = 1;
                break;
            }
            if (strs[j][i] == '\0' && j == strsSize-2) {
                flag = 1;
                break;
            }
        }
    }
    char* CommonPrefix = calloc(i, sizeof(char));
    strncpy(CommonPrefix, strs[j], i-1);
    return CommonPrefix;
}