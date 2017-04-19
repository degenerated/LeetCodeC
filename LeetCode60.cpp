// LeetCode60.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		//check start;
		vector<char> tmp;
		int cnt = 1;
		int j = 0;
		for (int i = 1; i <= n; i++) {
			tmp.push_back(i + '0');
			cnt *= i;
		}
		k--;
		cnt /= n;
		n--;
		while(1){
			j = k / cnt;
			k = k%cnt;
			res += tmp[j];
			tmp.erase(tmp.begin() + j);
			if (tmp.size() == 0)return res;
			cnt /= n;
			n--;
		}
		return res;
	}
};
int main()
{
	Solution a;

	cout << a.getPermutation(4, 2);
    return 0;
}

