//
//  main.c
//  StringProblems
//
//  Created by Bharath G M on 06/19/14.
//  Copyright (c) 2013 Bharath G M. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
    char *str1 = str;
    char *end = str;
    char temp;
    if (str)
    {
        while (*end)
        {
            ++end;
        }
        --end;
        while (str1 < end)
        {
            temp = *str1;
            *str1++ = *end;
            *end-- = temp;
        }
        printf("Str = %s",str);
    }
}

void isPalindrome (char str[],int  length)
{
    
    if (length<=0)
        printf(" palindrome");
  else  if (str[0] == str[length-1])
    {
        
         isPalindrome (str+1, length-2);/*Recursive call as the function isPalindrome
                                               is called again within itself*/
    }
    else printf("\n not palindrome");
}

void stringSubstring(char *x /* pattern */,
                int m   /* length of the pattern */,
                char *y /* actual string being searched */,
                int n   /* length of this string */)
{
    int i, j;
    printf("\nstring    : [%s]"
           "\nlength    : [%d]"
           "\npattern   : [%s]"
           "\nlength    : [%d]\n", y,n,x,m);
    
    
    /* Searching */
    for (j = 0; j <= (n - m); ++j)
    {
        for (i = 0; i < m && x[i] == y[i + j]; ++i)
            ;
        if (i >= m)
        {
            printf("\n Match found at\n\n->[%d]\n->[%s]\n",j,y+j);
        }
    }
}

int stringToInterger(char a[])
{
    int sign, offset, n;
    int i;
    if (a[0] == '-')
    {
        offset = 1;
        sign = -1;
    }
    else
    {
        offset = 0;
        sign = 1;
    }
    for (i = offset; a[i] != '\0'; i++)
    {
        n = n * 10 + (a[i] - '0');
    }
    if (sign == -1)
    {
        n = -n;
    }
    
    return n;
}

void uniqueCharsA(char *s)
{
	int arr[256]={0};
    
    
	while(*s) {
		arr[*s]++ ;
		if(arr[*s] > 1) {
			printf("%c is not unique\n", *s);
			return;
		}
		s++;
	}
	printf("unique\n");
	return ;
}

int main(int argc, const char * argv[])
{
    char string[100];
    printf("C Program for Reversing a String\n");
    printf("Enter a string\n");
    scanf("%s",string);
    reverse(string);
    isPalindrome(string,9);
    
    char *teststring  = "hereroheroero";
    char *pattern = "hero";
    
    //to find a substring
    stringSubstring(pattern,(unsigned int)strlen(pattern),string,(unsigned int)strlen(teststring));
    
    //string unique or not
    char s1[] = "adhijkl";
	uniqueCharsA(s1);
    char s2[] = "adhiiii";
	uniqueCharsA(s2);
	
    char a[] = "-1234";
    int integerValue = stringToInterger(a);
    printf("Integer Value of String \"%s\" is %d\n", a,integerValue);

}

