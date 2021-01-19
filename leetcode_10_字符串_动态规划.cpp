#include<string>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length();
		int n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
		// dp[i][j]��ʾs��ǰi���ַ���p��ǰj���ַ��Ƿ�ƥ��
		dp[0][0] = true;
		// p>0ƥ��s==0,�ж�ż��*��β
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) {
				dp[0][i] = dp[0][i - 2] && p[i - 1] == '*';
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				// ��ǰj-1��Ϊ*
				if (p[j - 1] != '*' || j == 1) {
					dp[i][j] = dp[i - 1][j - 1] && isMatch(s[i - 1], p[j - 1]);
				}
				else {
					// *��ǰһ���ַ���Ϊ���� s���ڵ�Ҳ��p��ǰ��ƥ��
					dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && isMatch(s[i - 1], p[j - 2]));
				}
			}
		}
		return dp[m][n];
	}

	bool isMatch(char& a, char& b) {
		return a == b || b == '.';
	}
};