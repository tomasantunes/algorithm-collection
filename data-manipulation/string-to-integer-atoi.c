/*
by KieranOwens

int myAtoi(char * str){
    int i = 0, sign = 1, flag = 0;
    long nb = 0;
    while (isspace(*(str + i))) i++;          // skip white space
    if (*(str + i) == '-') {                  // identify negative '-' sign
        sign = -1;
        i++;
    } else if (*(str + i) == '+') {           // or skip positive '+' sign
        i++;
    }
    if (!isdigit(*(str + i))) {               // return 0 if non-numeric char seen
        return 0;                             // otherwise, 
    } else {
        while (isdigit(*(str + i)) && !flag) {// while input is numeric
            if (nb * 10 > INT_MAX) {          // end process once # > INT_MAX
                flag = 1;
            }
             nb *= 10;                        // grow base 10 number with each digit
             nb += *(str + i) - '0';          // ASCII to digit conversion
             i++;
        }
        if (flag || nb > INT_MAX) {           // limit output to INT_MAX
            return sign * INT_MAX - 1 * (sign == -1);
        } else {
            return sign * nb;                 // otherwise, return signed #
        }
    }
}
*/

//by Larry2019
int myAtoi(char * str)
{
    long result = 0;
    sscanf(str, "%ld", &result);
    if (result < INT_MIN)
        return INT_MIN;
    else if (result > INT_MAX)
        return INT_MAX;
    return result;
}


/*
// by ssh3389
int myAtoi(char * str){
    int index = 0;
    int ret = 0;
    bool positive = true;
    
    while (str[index] == ' ') ++index;
    
    if (str[index] == '-') {
        ++index;
        positive = false;
    } else if (str[index] == '+') {
        ++index;
    }
    
    while (str[index] >= '0' && str[index] <= '9') {
        if (positive && ret > INT_MAX / 10) return INT_MAX;
        if (positive && ret == INT_MAX / 10 && str[index] - '0' > INT_MAX % 10) return INT_MAX;
        if (!positive && ret < INT_MIN / 10) return INT_MIN;
        if (!positive && ret == INT_MIN / 10 && str[index] - '0' > -(INT_MIN % 10)) return INT_MIN;
            
        ret *= 10;
        if (positive) ret += str[index++] - '0';
        else ret -= str[index++] - '0';
    }
    
    return ret;
}
*/