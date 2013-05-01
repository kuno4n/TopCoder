#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl


int dbx(int a, int b){
    int res = 0;
    for(int i = 1; i <= a || i <= b; i *= 10){
        int aa = (a/i)%10;
        int bb = (b/i)%10;
        int tmp = (aa^bb) % 10;
        res += tmp * i;
    }
    return res;
}

class DoubleXor {
	public:
	int calculate(int N) {
        int res = N;
        for(int i = N-1; i >= 1; i--){
            res = dbx(res, i);
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
			int N                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 7;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 102;
			int expected__            = 103;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DoubleXor().calculate(N);
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
// Let us introduce a new operation called double xor, and use the operator ^^ to denote it.  For two integers A and B, A ^^ B is calculated as follows.  Take the decimal representations of A and B.  If they have different lengths, prepend the shorter one with leading zeros until they both have the same length.  Then, label the digits of A as a1, a2, ?, an (from left to right) and the digits of B as b1, b2, ... , bn (from left to right).  C = A ^^ B will consist of the digits c1, c2, ... , cn (from left to right), where ci = (ai ^ bi) % 10, where ^ is the usual bitwise XOR operator (see notes for exact definition) and x % y is the remainder of x divided by y.  If C happens to have any extra leading zeroes, they are ignored.

For example, 8765 ^^ 2309 = 462 (c1 = (8 ^ 2) % 10 = 10 % 10 = 0, c2 = (7 ^ 3) % 10 = 4 % 10 = 4, c3 = (6 ^ 0) % 10 = 6 % 10 = 6, c4 = (5 ^ 9) % 10 = 12 % 10 = 2), and 5 ^^ 123 = 126 ("5" is prepended with two leading zeros to become "005").

When multiple ^^ operations occur in an expression, they must be evaluated from left to right.  For example, A ^^ B ^^ C means (A ^^ B) ^^ C.

You are given an int N.  Return the value of N ^^ (N - 1) ^^ (N - 2) ^^ ? ^^ 1.

DEFINITION
Class:DoubleXor
Method:calculate
Parameters:int
Returns:int
Method signature:int calculate(int N)


NOTES
-If a and b are single bits then a ^ b is defined as (a + b) % 2. For two integers, A and B, in order to calculate A ^ B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A ^ B = C = (cn...c1)2, where ci = ai ^ bi. For example, 10 ^ 3 = (1010)2 ^ (0011)2 = (1001)2 = 9.


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 1

This is simply 1.

1)
2

Returns: 3

2^^1=3

2)
7

Returns: 0

7^^6^^5^^4^^3^^2^^1=0

3)
10

Returns: 11

4)
102

Returns: 103



*/

// END CUT HERE
