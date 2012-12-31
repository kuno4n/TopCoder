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

class BestApproximationDiv1 {
	public:
	string findFraction(int maxDen, string number) {
		int A = 0, B = 1, X = 1;
        
        for(int b = 1; b <= maxDen; b++){
            REP(a, b){
                int x = 1;
                FOR(i, 1, 7){
                    int tmp = (int)((double)a/b * pow(10.0, (double)i) + 1e-9) % 10;
                    if(tmp != number[i+1] - '0') break;
                    x++;
                }
                if(x > X){
                    X = x;
                    A = a;
                    B = b;
                }
                if(x == X && b < B){
                    A = a;
                    B = b;
                }
            }
        }
        
        stringstream ss;
        ss << A << "/" << B << " has " << X << " exact digits";
        return ss.str();
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int maxDen                = 42;
			string number             = "0.141592";
			string expected__         = "1/7 has 3 exact digits";

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int maxDen                = 3;
			string number             = "0.133700";
			string expected__         = "0/1 has 1 exact digits";

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int maxDen                = 1000;
			string number             = "0.123456";
			string expected__         = "10/81 has 7 exact digits";

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int maxDen                = 1000;
			string number             = "0.420000";
			string expected__         = "21/50 has 7 exact digits";

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int maxDen                = 100;
			string number             = "0.909999";
			string expected__         = "10/11 has 4 exact digits";

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int maxDen                = 115;
			string number             = "0.141592";
			string expected__         = "16/113 has 7 exact digits";

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int maxDen                = ;
			string number             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int maxDen                = ;
			string number             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int maxDen                = ;
			string number             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BestApproximationDiv1().findFraction(maxDen, number);
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
// Elly is not a big fan of mathematical constants.  Most of them are infinite, and therefore hard to memorize.  Fractions, on the other hand, are often easier to remember and can provide good approximations.  For example, 22/7 = 3.1428... is one way to approximate Pi.  Unfortunately, it's only accurate to 2 places after the decimal point, so it doesn't help at all.  A slightly better example is 355/113 = 3.14159292... which is correct up to 6 digits after the decimal point.

Elly understands that working with infinite decimal fractions is going to be very difficult, so she first wants to find a good way to approximate floating point numbers with decimal representations that are finite.  Your task is to help her in this mission.  You will be given a string number containing the decimal representation of a non-negative fraction strictly less than 1. There will be exactly 6 digits after the decimal point in number (trailing zeros are possible and significant).  More precisely, number will be formatted "0.dddddd" (quotes for clarity) where each d is a decimal digit ('0'-'9').

Given a fraction F = A/B, where 0 <= A < B, its quality of approximation with respect to number is calculated as follows:


Let S be the decimal fraction (infinite or finite) representation of F.
If S is infinite or the number of digits after the decimal point in S is greater than 6, only consider the first 6 decimals after the decimal point in S.  Truncate the rest of the digits without performing any kind of rounding.
If the number of digits after the decimal point in S is less than 6, append trailing zeroes to the right side until there are exactly 6 digits after the decimal point.
The quality of approximation is the number of digits in the longest common prefix of S and number.  The longest common prefix of two numbers is the longest string which is a prefix of the decimal representations of both numbers with no extra leading zeroes.  For example, "3.14" is the longest common prefix of 3.1428 and 3.1415.


Elly doesn't like long approximations either, so you are only allowed to use fractions where the denominator is less than or equal to maxDen.  Find an approximation F = A/B of number such that 1 <= B <= maxDen, 0 <= A < B, and the quality of approximation is maximized.  Return a string formatted "A/B has X exact digits" (quotes for clarity) where A/B is the approximation you have found and X is its quality.  If there are several such approximations, choose the one with the smallest denominator among all of them.  If there is still a tie, choose the one among those with the smallest numerator.


DEFINITION
Class:BestApproximationDiv1
Method:findFraction
Parameters:int, string
Returns:string
Method signature:string findFraction(int maxDen, string number)


CONSTRAINTS
-maxDen will be between 1 and 1000, inclusive.
-number will contain exactly 8 characters.
-number will consist of a digit '0', followed by a period ('.'), followed by exactly six digits ('0'-'9').


EXAMPLES

0)
42
"0.141592"

Returns: "1/7 has 3 exact digits"

3 plus the current approximation yields an approximation of Pi.

1)
3
"0.133700"

Returns: "0/1 has 1 exact digits"

Not a lot of options here.

2)
1000
"0.123456"

Returns: "10/81 has 7 exact digits"



3)
1000
"0.420000"

Returns: "21/50 has 7 exact digits"

This one can be represented in more than one way. Be sure to choose the one with the lowest denominator.

4)
100
"0.909999"

Returns: "10/11 has 4 exact digits"

Even though 91/100 is a much closer approximation, 10/11 matches up to 3 digits, and 91/100 only to one.

5)
115
"0.141592"

Returns: "16/113 has 7 exact digits"

A better approximation for the decimal part of Pi.

*/

// END CUT HERE
