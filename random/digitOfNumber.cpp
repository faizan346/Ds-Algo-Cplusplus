#include<bits/stdc++.h>
using namespace std;

int baseToDecimalNumber(int num, int base) {
    int decimalNumber = 0;
    int exp = 1;
    while(num > 0) {
        decimalNumber += num%10 * exp;
        num = num/10;
        exp = exp*base;
    }
   // cout << decimalNumber << endl;
    return decimalNumber;
    //alternate
    // int digit = 1;
    // int exp = 1;
    // while(num/digtit) {
    //     decimalNumber += (num/digit %10) * exp;
    //     digit = digit*10;
    //     exp = exp*base;
    // }
}

int decimalToBaseNumber(int num, int base) {
    int baseNumber = 0;
    int digit = 1;
    while(num > 0) {
        baseNumber += num%base * digit;
        num = num/base;
        digit = digit * 10;
    }
   // cout << baseNumber << endl;
    return baseNumber; // still is a decimal number but looks like base number. and we can use them accordingly like for adding two numbers and sub or mul
    //alternate
    // int exp = 1;
    // int digit = 1;
    // while(num/exp) {
    //     baseNumber += (num/exp % base) * digit;
    //     exp = exp*base;
    //     digit = digit * 10;
    // }digitAddition%basedigitAddition%base
}

int addNumberofAnyBase(int a, int b, int base) {
    int num = 0;
    int digit = 1;
    int carry = 0;
    while(a > 0 || b > 0 || carry > 0) { //keep adding in number until no number to add
        int digitSum = (a%10 + b%10 + carry);
        num += digit * (digitSum%base);
        carry = digitSum/base;
        a = a/10;
        b = b/10;
        digit = digit * 10;
    }
   // cout << num << endl;
    return num;
}

int subNumberofAnyBase(int big, int small, int base) {
    int num = 0;
    int digit = 1;
    int borrow = 0;
    while(big > 0) {
        int db = big%10;
        big = big/10;
        int ds = small%10;
        small = small/10;
        db = db + borrow;
        if(db < ds) {
            num += digit * (db + base - ds);
            borrow = -1;
        } else {
            num += digit * (db - ds);
            borrow = 0;
        }
        digit = digit * 10;
    }
    //cout << num << endl;
    return num;
}
int mulNumberOfAnyBase(int a, int b, int base) {
    int mulDigit = 1;
    int mulNumber = 0;
    while(b > 0) {
        int t = a;
        int num = 0;
        int carry = 0;
        int digit = mulDigit;
        while(t > 0) {
            int digitMul = (t%10) * (b%10)+ carry;
            num += digit * (digitMul%base);
            carry = digitMul/base;
            t = t/10;
            digit = digit * 10;
        }
        b = b/10;
        mulNumber += addNumberofAnyBase(mulNumber, num, base);
        mulDigit = mulDigit * 10;
    }
    cout << mulNumber << endl;
    return mulNumber;
}

int main() {
    // suppose we want certain digit of some number of base 10, 2 ,8 or whatever
    //we are going to divide that number as num/base^digit % base , num is a decimal num
    int i= 2;
    while(i--) {
        // int num,base;
        // cin >> num >> base;
        // baseToDecimalNumber(decimalToBaseNumber(num,base),base);
        int a,b,base;
        cin >> a >> b >> base;
        // addNumberofAnyBase(a,b,base);
        // subNumberofAnyBase(a,b,base);
        mulNumberOfAnyBase(a,b,base);
    }
    return 0;
}