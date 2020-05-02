// by KieranOwens

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    } else if (x == 0) {
        return true;
    } else {
        int a, b, digits = floor(log10(x) + 1);
        int equal = true, i = 0, j = digits - 1;
        while (equal && i <= j) {
            a = x / pow(10, i);
            b = x / pow(10, j);
            if (a % 10 != b % 10) equal = false;
            i++;
            j--;
        }
        return equal;
    }
}