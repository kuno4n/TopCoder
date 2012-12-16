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

class CountingSeries {
	public:
	long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
		LL res=0;
        if(upperBound>=a)
            res = (upperBound-a)/b + 1;
        
        if(d==1){
            if(c<=upperBound && (c-a<0 || (c-a)%b)) return res+1;
            else return res;
        }
        
        while(c<=upperBound){
            if(c-a<0 || (c-a)%b) res++;
            c*=d;
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
			long long a               = 1;
			long long b               = 1;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 1000;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 3;
			long long b               = 3;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 343;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 40;
			long long b               = 77;
			long long c               = 40;
			long long d               = 100000;
			long long upperBound      = 40;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long a               = 452;
			long long b               = 24;
			long long c               = 4;
			long long d               = 5;
			long long upperBound      = 600;
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long a               = 234;
			long long b               = 24;
			long long c               = 377;
			long long d               = 1;
			long long upperBound      = 10000;
			long long expected__      = 408;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
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
// You are given long longs a, b, c and d. The numbers a and b define an arithmetic progression that consists of all numbers of the form a + b*x, where x is a nonnegative integer. Likewise, c and d define a geometric progression that consists of all the numbers that are equal to c * d^y, where y is a nonnegative integer. You are also given a long long upperBound. Return the total number of integers between 1 and upperBound, inclusive, that belong to the arithmetic progression, the geometric progression or both.

DEFINITION
Class:CountingSeries
Method:countThem
Parameters:long long, long long, long long, long long, long long
Returns:long long
Method signature:long long countThem(long long a, long long b, long long c, long long d, long long upperBound)


NOTES
-The ^ operator in this statement denotes the exponentiation operation. For example, 3^0 = 1 and 2^4 = 2*2*2*2 = 16.


CONSTRAINTS
-a, b, c and upperBound will each be between 1 and 1000000000000 (10^12), inclusive.
-d will be between 1 and 100000 (10^5), inclusive.


EXAMPLES

0)
1
1
1
2
1000

Returns: 1000

The arithmetic progression is: 1, 2, 3, 4, ... .
The geometric progression is: 1, 2, 4, 8, 16, ... . 
Each positive integer is contained in at least one of the progressions.

1)
3
3
1
2
1000

Returns: 343

This time, the arithmetic progression is: 3, 6, 9, 12, ... .
The geometric progression is still: 1, 2, 4, 8, 16, ....
There are 333 multiples of 3 between 1 and 1000, inclusive, and there are 10 powers of 2, 512 being the highest. As these two progressions do not have any common elements, the total result is 343.

2)
40
77
40
100000
40

Returns: 1



3)
452
24
4
5
600

Returns: 10

The 10 numbers are: 4, 20, 100, 452, 476, 500, 524, 548, 572 and 596.

4)
234
24
377
1
10000

Returns: 408



*/

// END CUT HERE
