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

class TheAlmostLuckyNumbersDivOne {
    LL count, _a, _b;
    void backtrack(LL l, bool used){
        if(l >= _a) count++;
        REP(i, 10){
            if(l==0 && i==0) continue;
            LL tmp = l*10 + i;
            if(tmp > _b) continue;
            if(i==4 || i==7) backtrack(tmp, used);
            else if(!used) backtrack(tmp, true);
        }
        return;
    }
    
	public:
	long long find(long long a, long long b) {
        _a = a; _b = b;
		count = 0;
        backtrack(0, false);
        return count;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long a               = 4;
			long long b               = 7;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 8;
			long long b               = 19;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 28;
			long long b               = 33;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long a               = 12345678900LL;
			long long b               = 98765432100LL;
			long long expected__      = 91136;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long a               = ;
			long long b               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long a               = ;
			long long b               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long a               = ;
			long long b               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
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
John and Brus believe that the digits 4 and 7 are lucky and all others are not.
According to them, an almost lucky number is a number that contains at most one non-lucky digit in its decimal representation.
Return the total number of almost lucky numbers between a and b, inclusive.



DEFINITION
Class:TheAlmostLuckyNumbersDivOne
Method:find
Parameters:long long, long long
Returns:long long
Method signature:long long find(long long a, long long b)


CONSTRAINTS
-a will be between 1 and 10^16, inclusive.
-b will be between a and 10^16, inclusive.


EXAMPLES

0)
4
7

Returns: 4

All numbers between 4 and 7 are almost lucky.

1)
8
19

Returns: 4

Numbers 8, 9, 14 and 17 are almost lucky.

2)
28
33

Returns: 0

No almost lucky numbers here.

3)
12345678900
98765432100

Returns: 91136



*/

// END CUT HERE
