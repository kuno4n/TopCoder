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

class RabbitNumbering {
	public:
	int theCount(vector <int> maxNumber) {
		sort(ALL(maxNumber));
        LL res = 1;
        int mod = 1000000007;
        REP(i, SZ(maxNumber)) res = (res*(maxNumber[i]-i))%mod;
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
			int maxNumber[]           = {5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int maxNumber[]           = {4, 4, 4, 4};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int maxNumber[]           = {5, 8};
			int expected__            = 35;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int maxNumber[]           = {2, 1, 2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int maxNumber[]           = {25, 489, 76, 98, 704, 98, 768, 39, 697, 8, 56, 74, 36, 95, 87, 2, 968, 4, 920, 54, 873, 90};
			int expected__            = 676780400;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int maxNumber[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int maxNumber[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int maxNumber[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
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
// Taro and Hanako have rabbits, and they want to assign a distinct integer to each rabbit so they can easily identify them.


The rabbits have expressed their preferences to Taro and Hanako. The i-th rabbit wants an integer between 1 and maxNumber[i], inclusive. Taro and Hanako must obey the preferences of all their rabbits.


Return the number of ways they can assign numbers to their rabbits, modulo 1,000,000,007. If it's impossible to assign distinct integers to the rabbits, return 0.

DEFINITION
Class:RabbitNumbering
Method:theCount
Parameters:vector <int>
Returns:int
Method signature:int theCount(vector <int> maxNumber)


CONSTRAINTS
-maxNumber will contain between 1 and 50 elements, inclusive.
-Each element of maxNumber will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{5}

Returns: 5

They can assign any number between 1 and 5, inclusive, to the only rabbit.

1)
{4, 4, 4, 4}

Returns: 24

All permutations of {1, 2, 3, 4} are possible.

2)
{5, 8}

Returns: 35



3)
{2, 1, 2}

Returns: 0



4)
{25, 489, 76, 98, 704, 98, 768, 39, 697, 8, 56, 74, 36, 95, 87, 2, 968, 4, 920, 54, 873, 90}

Returns: 676780400



*/

// END CUT HERE
