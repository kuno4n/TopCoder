#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class MinCostPalindrome {
	public:
	int getMinimum(string s, int oCost, int xCost) {
        int res = 0;
        int mn = min(oCost, xCost);
		for(int i=0, j=SZ(s)-1; i<j; i++, j--){
            if(s[i] == s[j]){
                if(s[i] == '?') res += (mn*2);
            }
            else{
                if(s[i] == '?') res += (s[j] == 'o'? oCost : xCost);
                else if(s[j] == '?') res += (s[i] == 'o'? oCost : xCost);
                else return -1;
            }
        }
        if(SZ(s)&1){
            if(s[SZ(s)/2] == '?') res += mn;
        }
        return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string s                  = "oxo?xox?";
			int oCost                 = 3;
			int xCost                 = 5;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "x??x";
			int oCost                 = 9;
			int xCost                 = 4;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "ooooxxxx";
			int oCost                 = 12;
			int xCost                 = 34;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "oxoxooxxxxooxoxo";
			int oCost                 = 7;
			int xCost                 = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "?o";
			int oCost                 = 6;
			int xCost                 = 2;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "????????????????????";
			int oCost                 = 50;
			int xCost                 = 49;
			int expected__            = 980;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string s                  = "o??oxxo?xoox?ox??x??" ;
			int oCost                 = 3;
			int xCost                 = 10;
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string s                  = ;
			int oCost                 = ;
			int xCost                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinCostPalindrome().getMinimum(s, oCost, xCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}

/*
// PROBLEM STATEMENT
// A palindrome is a string that reads the same from left to right as it does from right to left.

You are given a string s. The length of s is even. Each character of s is either 'o', 'x', or '?'
Your task in this problem is to replace each occurrence of '?' in s with either 'o' or 'x' so that s becomes a palindrome.
You are also given ints oCost and xCost.
Replacing '?' with 'o' costs oCost, and replacing '?' with 'x' costs xCost.

Return the minimum cost of replacing '?'s by 'x's and 'o's that turns s into a palindrome. If it is impossible to obtain a palindrome, return -1 instead.

DEFINITION
Class:MinCostPalindrome
Method:getMinimum
Parameters:string, int, int
Returns:int
Method signature:int getMinimum(string s, int oCost, int xCost)


NOTES
-You are not allowed to change an 'x' into an 'o' or vice versa.


CONSTRAINTS
-s will contain between 2 and 20 characters, inclusive.
-The length of s will be even.
-Each character of s will be either 'o' or 'x' or '?'.
-oCost will be between 1 and 50, inclusive.
-xCost will be between 1 and 50, inclusive.


EXAMPLES

0)
"oxo?xox?"
3
5

Returns: 8

The only way to produce a palindrome is to replace s[3] with 'x' and s[7] with 'o'. The first replacement costs 5, the second costs 3, so the total cost is 3+5=8.

1)
"x??x"
9
4

Returns: 8

There are two ways to produce a palindrome here. The cheaper one is to change both '?'s to 'x's. This costs 4+4=8. Note that you are required to replace all '?'s.

2)
"ooooxxxx"
12
34

Returns: -1

There is no '?' character, and s is not a palindrome. We have no way to change it into a palindrome.

3)
"oxoxooxxxxooxoxo"
7
4

Returns: 0

There is no '?' character, and s is already a palindrome. Making no replacements does not cost anything.

4)
"?o"
6
2

Returns: 6



5)
"????????????????????"
50
49

Returns: 980



6)
"o??oxxo?xoox?ox??x??" 
3
10

Returns: 38



*/

// END CUT HERE
