/*  9. Palindrome Number
 *
 * Given an integer x, return true if x is palindrome integer.
 *  An integer is a palindrome when it reads the same backward as forward.
 *
 *   For example, 121 is a palindrome while 123 is not.
 *
 *
 *   Example 1:
 *      Input : x = 121
 *      Output: true
 *      Explanation: 121 reads as 121 from left to right and from right
 *                  to left
 *   Example 2:
 *      Input: x = -121 
 *      Output: false
 *      Explanation: From left to right, it reads -121. From right to left, 
 *      it becomes 121-. Therefore it is not a palindrome.
 *
 *   Example 3:
 *      Input: x = 10
 *      Output : false
 *      Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 *
 *      -2 31 <= x <= 2 31 - 1
 *
 *  Follow up: Could you solve it without converting the integer to a string?
  *
 */




#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

bool is_palindrome_number(int);
bool is_palindrome_number_b(int);
int my_atoi(char * s);
int my_atoi_b(char * s);
int return_limit(int);
// When you compile, please use follow command 
// gcc -o output_file_name source_code.c -lm


int main(int argc, char * argv[]) {
    int *values = (int *)malloc(sizeof(int) * 10);
    int i;
    for(i = 0; i < 10; i++) {
        if(i != 0) {
            values[i] = 121 * i * 2 + i;
        } else {
            values[i] = 121 + i;
        }
    }

    for( i = 0; i < 10; i++) {
        printf("values[%d] is %d\n", i, values[i]);
        if(is_palindrome_number(values[i])) {
            printf("It is the true palindrome number!\n");
        } else {
            printf("It not the palindrome number!\n");
        }
    }

    
    printf("This is the solution B : \n");

    for( i = 0; i < 10; i++) {
        printf("values[%d] is %d\n", i, values[i]);
        if(is_palindrome_number_b(values[i])) {
            printf("It is the true palindrome number!\n");
        } else {
            printf("It not the palindrome number!\n");
        }
    }
    
    free(values);

    printf("################################################!\n");
    printf("Program name %s\n", argv[0]);

    if(argc == 2) {
        printf("Check what you input is the palindrome number\n");
        int my_input = my_atoi_b(argv[1]);
        if(is_palindrome_number(my_input)) {
            printf("What is the number you input %d is palindrome number!\n", my_atoi_b(argv[1])); 
        } else {
            printf("What is the number you input %d is not palindrome number!\n", my_atoi_b(argv[1])); 
        }
    } else if(argc > 2) {
        printf("Too many arguments supplied. \n");
    } else {
        printf("One argument expected. \n");
    }
    
    return 0;
}

bool is_palindrome_number(int x) {
    if(x < 0 || ((x % 10) == 0 && x != 0)) {
        return false;
    }

    int rev = 0;
    while(x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return x == rev || (rev / 10) == x;

}


bool is_palindrome_number_b(int x) {
    if(x < 0) {
        return false;
    }

    long long d = 10;
    while(x / d != 0) {
        // To find the number of digits in the number
        d *= 10;
    }

    int power;
    power = log10(d); // The power of 10, which in fact is the number of digits
    int number = x;
    int inverse = 0;
    int component;
    for(int i = 0; i < power; i++) {
        while(number > 0) {
            component = number % 10;
            inverse += component * pow(10, power - 1);
            number = number / 10;
            power--;
        }
    }

    if(inverse == x) {
        return true;
    } else {
        return false;
    }

}



int my_atoi(char * s) {
    if(!s) {
        return 0;
    }   

    int temp = 0;
    long int ret = 0;
    int i = 0;
    int sign = 1;
    while(i < strlen(s) && s[i] == ' ') {
        i++;
        if( i == strlen(s)) {
            return 0;
        }
    }

    if(s[i] == '+' || s[i] == '-') {
        if(s[i] == '-') {
            sign = -1;
        }

        i++;
    }

    while( i < strlen(s) && s[i] >= '0' && s[i] <= '9') {
        temp = (int) (s[i] - '0');
        ret = ret * 10 + temp;
        if(INT_MAX < (ret * sign) ) {
            return INT_MAX;
        } 
        if(INT_MIN > (ret * sign)) {
            return INT_MIN;
        }
        i++;
    }
    
    return ret * sign;

}

int my_atoi_b(char * s) {
    int ans = 0, sign = 0, len = strlen(s), start = -1, end = -2;
    char * t_s = s;

    for(int i = 0; i < len; i++) {
        switch(*(t_s + i)) {
            case ' ':
                if(start > -1 || sign != 0)
                    end = i - 1;
                break;
            case '-':
                if(sign != 0 || start > -1) 
                    end = i - 1;
                else 
                    sign = -1;
                break;
            case '+':
                if(sign != 0 || start > -1)
                    end = i - 1;
                else 
                    sign = 1;
                break;
            case '0': 
                if(sign == 0) 
                    sign = 1;
                break;
            case '1': 
                if(start == -1) {
                    start = i;
                }
                if(sign == 0) 
                    sign = 1;
                break;
            case '2':
                if(start == -1) {
                    start = i;
                }
                if(sign == 0) {
                    sign = 1;
                }
                break;
            case '3':
                if(start == -1)
                    start = i;
                if(sign == 0) 
                    sign = 1;
                break;
            case '4':
                if(start == -1) 
                    start = i;
                if(sign == 0)
                    sign = 1;
                break;
            case '5':
                if(start == -1) 
                    start = i;
                if(sign == 0)
                    sign = 1;
                break;
            case '6':
                if(start == -1)
                    start = i;
                if(sign == 0)
                    sign = 1;
                break;
            case '7':
                if(start == -1)
                    start = i;
                if(sign == 0)
                    sign = 1;
                break;
            case '8':
                if(start == -1)
                    start = i;
                if(sign == 0)
                    sign = 1;
                break;
            case '9':
                if(start == -1)
                    start = i;
                if(sign == 0)
                    sign = 1;
                break;
            default:
                end = i - 1;
            }

            if(end != -2)
                break;
        }

    if(start == -1)
        return 0;
    if(end == -2)
        end = len - 1;
    

    int times = 1;
    for(int i = 0; i < end - start; i++) {
        if(INT_MAX / 10 >= times) 
            times *= 10;
        else 
            return return_limit(sign);
    }

    for(int i = start; i < end + 1; i++) {
        int cur = (int) *(s + i) - 48;
        if(INT_MAX / times >= cur && INT_MAX - ans >= (times * cur)) {
            ans += (times * cur);
            times /= 10;
        }

        else 
            return return_limit(sign);
    }

    if(sign < 0) 
        return -ans;
 
    return ans;
}

int return_limit(int sign){
    if(sign > 0)
        return INT_MAX;
    else 
        return INT_MIN;
}

