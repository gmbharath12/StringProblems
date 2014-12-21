//
//  main.c
//  StringProblems
//
//  Created by Bharath G M on 06/19/14.
//  Copyright (c) 2013 Bharath G M. All rights reserved.
//

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

void BruteForce(char *x /* pattern */,
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

//The Sieve of Eratosthenes

void findPrimeNumbers()
{
    #define LIMIT 100

    int primes[100], i, j;
    for (i = 2; i < LIMIT; i++)
    {
        primes[i] = 1;
    }
    
    for (i = 2; i < LIMIT; i++)
    {
        if (primes[i])
        {
            for (j = i; i*j < LIMIT; j++)
            {
                primes[i*j] = 0;
            }
        }
    }
    
    printf("\n First n Prime numbers \n ");
    for (i = 2; i < LIMIT; i++)
    {
        if (primes[i])
        {
            printf("\n %d \n", i);
        }
    }
}

int divide(int x, int y)
{
    int quotient = 0;
    while (x >= y) {
        x  -=  y; // (if numerator is not equal or less than the divisor)
        quotient++;
    }
    return quotient;
}


# define NO_OF_CHARS 256
# define bool int

/* Function removes duplicate characters from the string
 This function work in-place and fills null characters
 in the extra space left */
char *removeDups(char *str)
{
    bool bin_hash[NO_OF_CHARS] = {0};
    int ip_ind = 0, res_ind = 0;
    char temp;
    
    /* In place removal of duplicate characters*/
    while(*(str + ip_ind))
    {
        temp = *(str + ip_ind);
        if(bin_hash[temp] == 0)
        {
            bin_hash[temp] = 1;
//            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }
    
    /* After above step string is stringiittg.
     Removing extra iittg after string*/
    *(str+res_ind) = '\0';   
    
    return str;
}

bool areAnagram(char *str1, char *str2)
{
    
     int lengthString1 = (int) strlen(str1);
     int lengthString2 = (int) strlen(str2);
    
    if (lengthString1 != lengthString2)
    {
        return 0;
    }
    
    int array[NO_OF_CHARS] = {0};
    int i;
    
    while (*str1)
    {
        array[*str1]++;
        str1++;
    }
    while (*str2)
    {
        array[*str2]--;
        str2++;
    }
    
//    // For each character in input strings, increment count in
//    // the corresponding array array
//    for (i = 0; str1[i] && str2[i];  i++)
//    {
//        array[str1[i]]++;
//        array[str2[i]]--;
//    }
//    
//    // If both strings are of different length. Removing this condition
//    // will make the program fail for strings like "aaca" and "aca"
//    if (str1[i] || str2[i])
//        return 0;
    
    // See if there is any non-zero value in an array
    for (i = 0; i < NO_OF_CHARS; i++)
        if (array[i])
            return 0;
    return 1;
}

//Adds 2 numbers without using arithmetic operator
int addTwoNumbers(int x, int y)
{
    
    int carry;
    
    while (y != 0)
    {
        carry = x & y;
        x = x^y;
        y = carry << 1 ;
    }
    return x;
    
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
    BruteForce(pattern,(unsigned int)strlen(pattern),string,(unsigned int)strlen(teststring));
    
    //string unique or not
    char s1[] = "adhijkl";
	uniqueCharsA(s1);
    char s2[] = "adhiiii";
	uniqueCharsA(s2);

    char a[] = "-1234";
    int integerValue = stringToInterger(a);
    printf("Integer Value of String \"%s\" is %d\n", a,integerValue);
    
    findPrimeNumbers();
    
    int x = 250;
    int y = 5;
    
    //works fine for all positive numbers, but not for negative numbers
    int r = divide(x ,y);
    printf("%d\n" , r);

//    char* dup = "here";
//    removeDups(dup);
    char str1[] = "geeksforgeeks";
    char str2[] = "forgeeksgeeks";
    
    if ( areAnagram(str1, str2) )
        printf("The two strings are anagram of each other");
    else
        printf("The two strings are not anagram of each other");
    
    return 0;

    int sum = addTwoNumbers(5,3);
    
    printf("\n Sum = %d \n \n", sum);

}
