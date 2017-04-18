// LeetCode59.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n,vector<int>(n,0));
		int rs = 0;
		int re = n - 1;
		int cs = 0;
		int ce = n - 1;
		int dir = 0;
		n = 1;
		while (rs <= re&&cs <= ce) {
			if (dir == 0) {
				for (int i = cs; i <= ce; i++) {
					res[rs][i] = n;
					n++;
				}
				rs++;
			}
			else if (dir == 1) {
				for (int i = rs; i <= re; i++) {
					res[i][ce] = n;
					n++;
				}
				ce--;
			}
			else if (dir == 2) {
				for (int i = ce; i >= cs; i--) {
					res[re][i] = n;
					n++;
				}
				re--;
			}
			else {
				for (int i = re; i >= rs; i--) {
					res[i][cs] = n;
					n++;
				}
				cs++;
			}
			dir = (dir + 1) % 4;
		}
		return res;
	}
};
int main()
{
	Solution a;
	vector<vector<int>> res = a.generateMatrix(5);
	for each(vector<int> tmp in res) {
		cout << '[';
		for each (int i in tmp) {
			cout << i << "\t";
		}
		cout <<']'<< endl;
	}
    return 0;
}

