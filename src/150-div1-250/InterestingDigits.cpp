#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
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
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class InterestingDigits {
	public:
	vector <int> digits(int base) {
        VI res;

        int tmp = base - 1;
        res.push_back(tmp);
        
        for(int i=2; i<tmp; i++){
            if(!(tmp%i)) res.push_back(i);
        }
        sort(ALL(res));
        
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int base                  = 10;
			int expected__[]          = { 3, 9 };

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int base                  = 3;
			int expected__[]          = { 2 };

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int base                  = 9;
			int expected__[]          = { 2, 4, 8 };

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int base                  = 26;
			int expected__[]          = { 5, 25 };

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int base                  = 30;
			int expected__[]          = { 29 };

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int base                  = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int base                  = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int base                  = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = InterestingDigits().digits(base);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
The digits 3 and 9 share an interesting property.  If you take any multiple of 3 and sum its digits, you get another multiple of 3.
For example, 118*3 = 354 and 3+5+4 = 12, which is a multiple of 3.  Similarly, if you take any multiple of 9 and sum its digits, 
you get another multiple of 9.  For example, 75*9 = 675 and 6+7+5 = 18, which is a multiple of 9.  Call any digit for which this 
property holds interesting, except for 0 and 1, for which the property holds trivially.



A digit that is interesting in one base is not necessarily interesting in another base.  For example, 3 is interesting in base 10
but uninteresting in base 5.  Given an int base, your task is to return all the interesting digits for that base
in increasing order.  To determine whether a particular digit is interesting or not, you need not consider all multiples of the digit.  You can be certain that, if
the property holds for all multiples of the digit with fewer than four digits, then it also holds for multiples with more digits.
For example, in base 10, you would not need to consider any multiples greater than 999.



DEFINITION
Class:InterestingDigits
Method:digits
Parameters:int
Returns:vector <int>
Method signature:vector <int> digits(int base)


NOTES
-When base is greater than 10, digits may have a numeric value greater than 9.  Because integers are displayed in base 10 by default, do not be alarmed when such digits appear on your screen as more than one decimal digit.  For example, one of the interesting digits in base 16 is 15.


CONSTRAINTS
-base is between 3 and 30, inclusive.


EXAMPLES

0)
10

Returns: { 3,  9 }

All other candidate digits fail for base=10.  For example, 2 and 5 both fail on 100, for which 1+0+0=1.  Similarly, 4 and 8 both fail on 216, for which 2+1+6=9, and 
6 and 7 both fail for 126, for which 1+2+6=9.

1)
3

Returns: { 2 }

2)
9

Returns: { 2,  4,  8 }

3)
26

Returns: { 5,  25 }

4)
30

Returns: { 29 }

*/

// END CUT HERE
