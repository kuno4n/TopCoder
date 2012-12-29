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

bool suffix(string s1, string s2){
    if(SZ(s1) <= SZ(s2)) return false;
    REP(i, SZ(s2)){
        if(s1[SZ(s1)-SZ(s2)+i] != s2[i]) return false;
    }
    return true;
}

class TheLotteryBothDivs {
	public:
	double find(vector <string> goodSuffixes) {
        vector <string> s; s.clear();
        REP(i, SZ(goodSuffixes)){
            bool ok = true;
            REP(j, SZ(goodSuffixes)){
                if(i==j) continue;
                if(suffix(goodSuffixes[i], goodSuffixes[j])) ok = false;
            }
            if(ok) s.push_back(goodSuffixes[i]);
        }
        sort(ALL(s));
        s.erase(unique(ALL(s)), s.end());
        
        double res = 0.0;
        REP(i, SZ(s)){
            res += 1.0/(pow(10.0, (double)SZ(s[i])));
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
			string goodSuffixes[]     = {"4"};
			double expected__         = 0.1;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string goodSuffixes[]     = {"4", "7"};
			double expected__         = 0.2;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string goodSuffixes[]     = {"47", "47"};
			double expected__         = 0.01;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string goodSuffixes[]     = {"47", "58", "4747", "502"};
			double expected__         = 0.021;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string goodSuffixes[]     = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
			double expected__         = 0.201100101;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string goodSuffixes[]     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string goodSuffixes[]     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string goodSuffixes[]     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheLotteryBothDivs().find(vector <string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
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
// Farmer John wants to buy a lottery ticket. Before he buys a ticket, Fox Brus decided to calculate the probability that John will get a prize.


There are 1,000,000,000 types of lottery tickets. They are numbered "000000000" to "999999999" (they may have leading zeroes). Each type of ticket has an equal probability of being bought by John. You are given a vector <string> goodSuffixes. If the number written on John's ticket has at least one element of goodSuffixes as a suffix, he will get a prize.


Return the probability that John will get a prize.

DEFINITION
Class:TheLotteryBothDivs
Method:find
Parameters:vector <string>
Returns:double
Method signature:double find(vector <string> goodSuffixes)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.
-A suffix of a string is obtained by removing zero or more contiguous characters from the beginning of the string.


CONSTRAINTS
-goodSuffixes will contain between 1 and 50 elements, inclusive.
-Each element of goodSuffixes will contain between 1 and 9 characters, inclusive.
-Each character in goodSuffixes will be a digit ('0'-'9').


EXAMPLES

0)
{"4"}

Returns: 0.1

John will get a prize if the last digit is '4'. It happens with probability 0.1.

1)
{"4", "7"}

Returns: 0.2



2)
{"47", "47"}

Returns: 0.01

goodSuffixes may contain duplicate elements.

3)
{"47", "58", "4747", "502"}

Returns: 0.021



4)
{"8542861", "1954", "6", "523", "000000000", "5426", "8"}

Returns: 0.201100101



*/

// END CUT HERE
