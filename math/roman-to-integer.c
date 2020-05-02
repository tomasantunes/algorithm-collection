// by 0101011

int romanToInt(char * s){
    int value = 0;
       
    for(int i = 0; i <= strlen(s); i++){
        if(s[i] == 'I'){
            if(s[i + 1] == 'V' || s[i + 1] == 'X'){
                value -= 1;
            }
            else{
                value += 1;
            }
        }
        else if(s[i] == 'X'){
            if(s[i + 1] == 'L' || s[i + 1] == 'C'){
                value -= 10;
            }
            else{
                value += 10;
            }
        }else if(s[i] == 'C'){
            if(s[i + 1] == 'D' || s[i + 1] == 'M'){
                value -= 100;
            }
            else{
                value += 100;
            }
        }else if(s[i] == 'V'){
            value += 5;
        }else if(s[i] == 'L'){
            value += 50;
        }else if(s[i] == 'D'){
            value += 500;
        }else if(s[i] == 'M'){
            value += 1000;
        }else if(value < 1 || value > 3999){
            return 0;
        }
            
    }
    return value;
}