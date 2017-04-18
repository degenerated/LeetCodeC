// LeetCode58.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		int size = s.length();
		int res = 0;
		for (int i = 0; i < size; i++) {
			if(s[i]==0){
				i++;
				while (i<size-1&&s[i+1] == ' ') i++; 
				if (i < size-1)res = 0;
			}
			else res++;
		}
		return res;
	}
};
int main()
{
	Solution a;
	string s = "Hello World";
	cout << a.lengthOfLastWord(s);
    return 0;
}

