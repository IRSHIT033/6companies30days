#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2== str2 + str1)  ? str1.substr(0, __gcd(str1.length(), str2.length())): "";
    }
};
  
