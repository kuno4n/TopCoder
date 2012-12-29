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

class TheNumbersWithLuckyLastDigit {
	public:
	int find(int n) {
		switch(n%10){
            case 0 : {
                if(n >= 20) return 5;
                else return -1;
            }
            case 1 : {
                if(n >= 11) return 2;
                else return -1;
            }
            case 2 : {
                if(n >= 12) return 3;
                else return -1;
            }
            case 3 : {
                if(n >= 23) return 5;
                else return -1;
            }
            case 4 : {
                return 1;
            }
            case 5 : {
                if(n >= 15) return 3;
                else return -1;
            }
            case 6 : {
                if(n >= 16) return 4;
                else return -1;
            }
            case 7 : {
                return 1;
            }
            case 8 : {
                return 2;
            }
            case 9 : {
                if(n >= 19) return 4;
                else return -1;
            }
        }
        return -1;
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
			int n                     = 99;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 11;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 13;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 1234567;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheNumbersWithLuckyLastDigit().find(n);
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
// 
John believes that the digits 4 and 7 are lucky, and all other digits are unlucky.
A positive integer is called a lucky number if its last digit is lucky.
For example, 4, 14 and 207 are lucky numbers, while 40, 741 and 3 are not lucky numbers.
John would like to represent the int n as a sum of only lucky numbers, and he would like to do this using the minimal possible number of summands.
Return the number of summands in the representation, or -1 if it is impossible to achieve the goal.



DEFINITION
Class:TheNumbersWithLuckyLastDigit
Method:find
Parameters:int
Returns:int
Method signature:int find(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
99

Returns: 4

One?of?the?possible?representations?is?99=14+24+27+34.

1)
11

Returns: 2

11=4+7.

2)
13

Returns: -1

It is impossible to achieve the goal.

3)
1234567

Returns: 1

*/

// END CUT HERE
