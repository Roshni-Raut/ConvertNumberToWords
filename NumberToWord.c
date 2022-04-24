#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *one_digit[] ={ "zero", "one ", "two ", "three ", "four ", "five ", "six ", "seven ","eight ", "nine "};
char *two_digit[] ={ "", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ","sixteen ", "seventeen ", "eighteen", "nineteen"};
char *tens_multiple[] ={ "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ","eighty ", "ninety "};

//return 10-99
char * toDigit (char *num)
{
    char *res;
    strcpy (res, "");
    if (*num == '1')
    {
        int sum = *num - '0' + *(num + 1) - '0';
        strcat (res, two_digit[sum]);
    }
    else
    {
        int i = *num - '0';
        strcat (res, i ? tens_multiple[i] : " ");
        ++num;
        if (*num != '0')
	    strcat (res, one_digit[*num - '0']);
    }
    return res;
}

void convert (char *num)
{
  int len = strlen (num);
    if (len == 0){
        printf ("empty string\n");
        return;
    }
    if (len > 16){
        printf ("Length more than 16 is not supported\n");
        return;
    }
    printf ("\n%s:", num);
    if (len == 1){
        printf ("%s\n ", one_digit[*num - '0']);
        return;
    }
    
    while (*num != '\0')
    {
        if(*num!='0'){
            if(len==16)
                printf("%squadrillion ",one_digit[*num-'0']);
            else if(len==15)
                printf("%shundred ",one_digit[*num-'0']);
            else if(len==14){
                printf("%strillion ",toDigit(num));
                len=13;
                num++;
            }
            
            else if(len==13)
                printf("%strillion ",one_digit[*num-'0']);
            else if(len==12)
                printf("%shundred ",one_digit[*num-'0']);
            else if(len==11){
                printf("%sbillion ",toDigit(num));
                len=10;
                num++;
            }
            
            else if(len==10)
                printf("%sbillion ",one_digit[*num-'0']);
            else if(len==9)
                printf("%shundred ",one_digit[*num-'0']);
            else if(len==8){
                printf("%smillion ",toDigit(num));
                len=7;
                num++;
            }
            
            else if (len == 7 && *num != '0')
    	        printf ("%smillion ", one_digit[*num - '0']);
            else if (len == 6 && *num != '0')
    	        printf ("%shundred ", one_digit[*num - '0']);
            else if ((len == 5) && *num != '0')
    	    {
    	        printf ("%sthousand ", toDigit (num));
    	        len = 4;
    	        num++;
    	    }
            else if (len == 4 && *num != '0')
    	        printf ("%sthousand ", one_digit[*num - '0']);
            else if (len == 3 && *num != '0')
    	        printf ("%shundred ", one_digit[*num - '0']);
            else if (len == 2 && *num != '0')
    	    {
    	        printf ("%s ", toDigit (num));
    	        len = 1;
    	        num++;
    	    }
            else if (len==1)
    	        printf ("%s ", one_digit[*num - '0']);
        }
      len--;
      num++;
    }
}

int main (void)
{
  convert ("5450003003300404");
  convert ("4511");
  convert ("89");
  convert ("21");
  convert ("002");
  return 0;
}
