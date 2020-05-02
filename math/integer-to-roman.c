// by bbb89

struct table {
    int val;
    char *str;
};

char * intToRoman(int num){
    char *ret = malloc(1);
    int size = 1;
    int j=0;
    ret [0] = 0;
    struct table ref[] = {{1000, "M"}, {900, "CM"}, 
                          {500, "D"}, {400, "CD"},
                          {100, "C"}, {90, "XC"},
                          {50, "L"}, {40, "XL"},
                          {10, "X"}, {9, "IX"},
                          {5, "V"}, {4, "IV"},
                          {1, "I"}};
    while (num) {
        while (num >= ref[j].val) {
            ret = realloc(ret, size + strlen(ref[j].str));
            size += strlen(ref[j].str);
            strcat(ret, ref[j].str);
            num -= ref[j].val;
        }
        j++;
    }
    return ret;
}