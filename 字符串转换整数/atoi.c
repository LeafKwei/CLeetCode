#include <stdio.h>

int myAtoi(char *str){
    long long temp = 0;
    int index = 0;
    int nega = 0;

    while(str[index] == ' '){
        index++;
    }

    if(str[index] == '\0'){
        return 0;
    }

    if(str[index] == '-'){
        nega = 1;
        index++;
    }
    else if(str[index] == '+'){
        index++;
    }

    if(str[index] == '\0'){
        return 0;
    }

    while(str[index] == '0'){
        index++;
    }

    if(str[index] == '\0'){
        return 0;
    }

    /* Parse ever char in str */
    while(str[index] >= '0' && str[index] <= '9' && str[index] != '\0'){
        int c = str[index] - '0';
        
        if(nega){
            if((temp * 10 + (-c)) <= (int)0x80000000){
                return (int)0x80000000;
            }
            else{
                temp = temp * 10 + (-c);
            }
        }
        else{
            if((temp * 10 + c) >= (0x7FFFFFFF)){
                return (int)0x7FFFFFFF;
            }
            else{
                temp = temp * 10 + c;
            }
        }

        index++;
    }

    return (int)temp;
}