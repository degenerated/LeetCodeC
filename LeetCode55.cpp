// LeetCode55.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		bool res = true;
		int size = nums.size();
		if (size == 0) return res;
		int tar = 0;
		int i = 0;
		for (int i = 0; i <= tar; i++) {
			tar=max(i+nums[i],tar);
			if (tar >= size - 1) return true;
			if (i == tar) return false;
		}
		return res;
	}
};
int main()
{
	int sou[] = { 2,3,1,1,4 };
	vector<int>vsou(sou, sou + 5);
	Solution a;
	cout << a.canJump(vsou);
    return 0;
}

