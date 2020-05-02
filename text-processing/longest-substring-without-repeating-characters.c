/*
by gzrjzcx

int lengthOfLongestSubstring(char* s) {
    int count=1;
    int max_count=1;
    int j_start=0;
    
    if(!s[0])
        return 0;
    else if(!s[1])
        return max_count;
    
    for(int i=1; s[i]; i++)
    {
        for(int j=j_start; j<i; j++)
        {
            if(s[i] != s[j])
                count++;
            else
                j_start = j+1;         
        }
        if(max_count < count)
            max_count = count;
        count = 1;
    }
    return max_count;
}
*/

// by youxuan
int isInclude(char *s, char a) {
    while (*s != '\0') {
        if (*s == a) {
            return 1;
        }
        s++;
    }
    return 0;
}

void clear(char *s) {
    while (*s != '\0') {
        *s = '\0';
        s++;
    }
}

int lengthOfLongestSubstring(char *s) {
    int i = 0, max = 0;
    int index = 0;
    char p[strlen(s) > 0 ? strlen(s)+1 : 1];


    while (s[i] != '\0') {

        if (!isInclude(p, s[i + index])) {
            p[index] = s[i + index];
            p[index+1] = '\0';
            index++;

            if (index >= max) {
                max = index;
            }

            if (s[index + i] == '\0') {
                break;
            }
        } else {
            index = 0;
            clear(p);
            i++;
        }

    }
    return max;

}