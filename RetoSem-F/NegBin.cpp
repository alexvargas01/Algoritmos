#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string String(int n) 
{ 
    string str; 
    stringstream ss; 
    ss << n; 
    ss >> str; 
    return str; 
} 

long long int NegToDecimal(string n) 
{ 
    string num = n; 
    long long int val = 0; 
  
    long long int base = 1; 
  
    long long int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            val += base; 
        base = base * (-2); 
    } 
  
    return val; 
} 

string DecimalToNeg(long long int n, int base) 
{ 
    if (n == 0) 
        return "0"; 
  
    string converted = ""; 
    while (n != 0) 
    { 

        long long int carry = n % base; 
        n /= base; 
  
        if (carry < 0) 
        { 
            carry += (-base); 
            n += 1; 
        } 
  
        converted = String(carry) + converted; 
    } 
  
    return converted; 
} 

int main(){

    string s1, s2;
    cin>>s1;
    cin>>s2;

    long long int iR = NegToDecimal(s1) + NegToDecimal(s2);

    cout<<DecimalToNeg(iR,-2)<<endl;


    return 0;
}