//Smith Number

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count(int n) {
    char s[12];
    sprintf(s, "%d", n);
    int i, sum = 0;
    for(i = 0; s[i]; i++)
        sum += s[i]-'0';
    return sum;
}
int C(int n) {
    int i, ans;
    int digits1 = count(n), digits2 = 0, flag = 1;
    ans = n;
    for(i = 2; i <= (int)sqrt(n); i++) {
        if(n%i == 0) {
            int time = 0;
            while(n%i == 0) {
                time++;
                n /= i;
            }
            digits2 += time*count(i);
            flag = 0;
        }
    }
    if(n != 1)
        digits2 += count(n);
    if(digits1 == digits2 && flag == 0) {
        printf("%d\n", ans);
        return 1;
    }
    return 0;
}
int main() {
    int i;
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(i = n+1; ; i++)
            if(C(i) == 1)
                break;
    }
    return 0;
}

/*
JAVA 


import java.util.Scanner;
import java.util.ArrayList;
public class SmithNumber {
    static int getAddition(int num) {
        int digit, sum = 0;
        while (num > 0) {
            // last digit of num
            digit = num % 10;
            sum = sum + digit;
            num = num / 10;
        }
        // System.out.println("num sum: "+sum);
        return sum;
    }

    // Following are the steps to find all prime factors.
    // 1) While n is divisible by 2, print 2 and divide n by 2.
    // 2) After step 1, n must be odd. Now start a loop from i = 3 to the square
    // root of n. While i divides n, print i, and divide n by i. After i fails to
    // divide n, increment i by 2 and continue.
    // 3) If n is a prime number and is greater than 2, then n will not become 1 by
    // the above two steps. So print n if it is greater than 2.

    //function to find prime factores of a number
    static int primeFactors(int num)
    {
        ArrayList<Integer> factorsArrList = new ArrayList<Integer>();

        int sum = 0;

        while(num%2 == 0)
        {
            // System.out.println(2+ " *1 ");
            factorsArrList.add(2);
            num /= 2;
        }

        for (int i=3; i <= Math.sqrt(num); i+=2)
        {
            while(num%i == 0)
            {
                // System.out.println(i+ " *2 ");
                factorsArrList.add(i);
                num /= i;
            }
        }

        if(num > 2)
            factorsArrList.add(num);

        for (int i = 0; i < factorsArrList.size(); i++) {
            // System.out.println(factorsArrList.get(i));
            sum = getAddition(factorsArrList.get(i)) + sum;
        }
        
        // System.out.println("factors sum: "+sum);
        return sum;
    }
    public static void main(String[] args) {
        int num = 4937770;
        boolean check=true;

        while(check)
        {
            System.out.println(num);
            int addition = getAddition(num);
            int addition2 = primeFactors(num);

            if(addition == addition2)
            {
                System.out.println(num+" is a Smith Number");
                check = false;
                break;
            }
            else
            {
                ++num;
            }

        }
        // int addition = getAddition(num);
        // // System.out.println(addition);
        // int addition2 = primeFactors(num);

        // if(addition == addition2)
        //     System.out.println(num+" is a Smith Number");
        // else
        // {
        //     int newNum = num++;
        // }
    }
}


*/