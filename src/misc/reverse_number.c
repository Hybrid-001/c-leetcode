/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value
 * to go outside the signed 32-bit integer range [-2 31, 2 31 -1\, then return 0;
 *
 * Assume the environment does not allow you to store 64-bit integers(signed or unsigned).
 *
 * Example 1
 * Input : x = 123
 * Output: 321
 *
 *
 * Example 2:
 *  Input : X = -123
 *  Output: -321
 *
 *
 *Example 3:
 *Input : x = 120
 *Output: 21
 *
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int my_atoi(char *);
int return_limit(int);
int reverse(int);

int main(int argc, char * argv[]) {
    printf("The program name is %s\n", argv[0]);
    
    if(argc >= 2) {
        int num = my_atoi(argv[1]);
        printf("The number you have entered is :%d\n", num);
        printf("The number after reverse is  :%d\n", reverse(num));
    }

}

int reverse(int x) {
    int ans = 0;
    int max_int = INT_MAX / 10;
    int min_int = INT_MIN / 10;

    while( x != 0) {
        if((ans < min_int) || (max_int < ans))
            return 0; // Check if updateing res would overflow
        ans = (ans * 10) + ( x % 10);
        x /= 10;
    }

    return ans;

}


int my_atoi(char * s) {
    int sign = 0, end = -2, start = -1, ans = 0, len = strlen(s);
    char * t_s = s;

    for(int i = 0; i < len; i++) {
        switch(*(t_s + i)) {
            case ' ': 
                if(sign != 0 || start > -1)
                    end = i - 1;
                break;
            case '-': 
                if(sign != 0 || start > -1) {
                    end = i - 1;
                }
                else 
                    sign = -1;
                break;
            case '+': 
                if(sign != 0 || start > -1) {
                    end = i - 1;
                } else {
                    sign = 1;
                }
                break;
            case '0': 
                if(sign == 0)
                    sign == 1;
                break;
            case '1':
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
             case '2':
                if(start == -1)
                    start = i;
                if(sign == 0)
                    sign = 1;
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
            default:
                end = i - 1;
        }

        if(end != -2) {
            break;
        }
    }

    if(end == -2)
        end = len -1;
    if(start == -1)
        return 0;

    int times = 1;
    for(int i = 0; i < end - start; i++) {
        if(INT_MAX / 10 >= times)
            times *= 10;
        else 
            return return_limit(sign);
    }

    for(int i = 0; i < end + 1; i++) {
        int cur = (int) *(s + i) - 48;
        if(INT_MAX / times  >= cur && ((INT_MAX - ans) >= (times * cur))) {
            ans = ans + (times * cur);
            times /= 10;
        } else
            return return_limit(sign);
    }


    if(sign < 0)
        return -ans;
    else 
        return ans;
}

int return_limit(int sign) {
    if(sign > 0) 
        return INT_MAX;
    else 
        return INT_MIN;
}
