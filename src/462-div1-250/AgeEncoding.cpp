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

#define EPS 1e-10

class AgeEncoding {
	public:
	double getRadix(int age, string candlesLine) {
        int n= SZ(candlesLine);
		bool one = true;
        if(candlesLine[n-1] == '0') one = false;
        REP(i, n-1) if(candlesLine[i] == '1') one = false;
        if(one){
            if(age == 1) return -2.0;
            return -1.0;
        }
        
        if(age == 1 && candlesLine[n-1] == '1') return -1.0;
        
        bool zero = true;
        REP(i, n-1) if(candlesLine[i] == '1') zero = false;
        if(zero) return -1.0;
        
        double hi = 101.0;
        double lo = EPS;
        while(abs(hi-lo) > EPS){
            double mid = (hi+lo)/2;
            double a = candlesLine[n-1]=='1' ? 1.0 : 0.0;
            FOR(i, 1, n){
                if(candlesLine[n-i-1] == '1'){
                    a += pow(mid, (double)i);
                }
            }
            if(a<age) lo = mid;
            else hi = mid;
        }
        return hi;
        
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int age                   = 10;
			string candlesLine        = "00010";
			double expected__         = 10.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int age                   = 21;
			string candlesLine        = "10101";
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int age                   = 6;
			string candlesLine        = "10100";
			double expected__         = 1.414213562373095;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int age                   = 21;
			string candlesLine        = "10111111110111101111111100111111110111111111111100";
			double expected__         = 0.9685012944510603;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int age                   = 16;
			string candlesLine        = "1";
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int age                   = 1;
			string candlesLine        = "1";
			double expected__         = -2.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int age                   = 1;
			string candlesLine        = "001000";
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int age                   = 1;
			string candlesLine        = "00100001";
			double expected__         = -2.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int age                   = ;
			string candlesLine        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int age                   = ;
			string candlesLine        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
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
// NOTE: This problem statement contains superscripts that may not display properly if viewed outside of the applet.


Your friend's birthday is approaching, and he wants his age to be written in candles on his cake.  In fact, he has already placed several candles on the cake.  The candles are arranged in a single row, and there are two different colors of candles.  One color represents the digit '0' and the other color represents the digit '1'.  You don't want to relayout the candles from scratch, so you have to determine if there's a base for which the existing candles spell out your friend's age.  To simplify the task, you can choose any strictly positive base, not necessarily an integer one.


For example, if the candles are "00010" and your friend's age is 10, then the candles spell out 10 in base 10 (decimal). If the candles are "10101" and your friend's age is 21, then you can say that "10101" is 21 in base 2 (binary). If the candles are "10100" and your friend's age is 6, then the candles spell out 6 in base sqrt(2)=1.41421356237.... Note that you are not allowed to rotate the cake, so "10" cannot be read as "01".


You are given a string candlesLine, where the i-th character is the digit ('0' or '1') represented by the i-th candle in the row of candles on the cake.  You are also given an int age, which is your friend's age.  Return the positive base for which the candles represent your friend's age.  If there is no such base, return -1, and if there are multiple such bases, return -2.

DEFINITION
Class:AgeEncoding
Method:getRadix
Parameters:int, string
Returns:double
Method signature:double getRadix(int age, string candlesLine)


NOTES
-The number anan-1...a1a0 in base B is equal to an*Bn + an-1*Bn-1 + ... + a1*B + a0.
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-age will be between 1 and 100, inclusive.
-candlesLine will contain between 1 and 50 characters, inclusive.
-Each character in candlesLine will be '0' (zero) or '1' (one).


EXAMPLES

0)
10
"00010"

Returns: 10.0

This is the first example from the statement: simply a decimal notation of the given age. Note that notation can have leading zeroes.

1)
21
"10101"

Returns: 2.0

This is the second example from the statement: "10101" is a binary notation of the given age.

2)
6
"10100"

Returns: 1.414213562373095

This is the third example from the statement.

3)
21
"10111111110111101111111100111111110111111111111100"

Returns: 0.9685012944510603



4)
16
"1"

Returns: -1.0

In any base, "1" represents the age of 1, so it's impossible to get the age of 16.

5)
1
"1"

Returns: -2.0

In any base, "1" represents the age of 1.

6)
1
"001000"

Returns: 1.0



*/

// END CUT HERE
