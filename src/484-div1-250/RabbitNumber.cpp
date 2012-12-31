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

int l, h;

int S(LL x){
    int cnt = 0;
    while(x){
        cnt += x%10;
        x /= 10;
    }
    return cnt;
}

int dfs(LL a){
    int res = 0;
    for(int i=0; i<=3; i++){
        LL tmp = a*10 + i;
        if(tmp!=0 &&  tmp<=1000000000){
            if(tmp>=l && tmp <=h && S(tmp*tmp)==S(tmp)*S(tmp)) res++;
            res += dfs(tmp);
        }
    }
    return res;
}

class RabbitNumber {
	public:
	int theCount(int low, int high) {
		l = low, h = high;
        return dfs(0);
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
			int low                   = 22;
			int high                  = 22;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int low                   = 484;
			int high                  = 484;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int low                   = 1;
			int high                  = 58;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int low                   = 58;
			int high                  = 484;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int low                   = 1000000000;
			int high                  = 1000000000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumber().theCount(low, high);
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
// When cat Taro and rabbit Hanako were practicing hard for SRM 484, they noticed an interesting property of 484. They called it Rabbit Number.


Let S(n) be the sum of the digits of n. For example, S(484) = 4+8+4 = 16 and S(22) = 2+2 = 4.
A positive integer x is called a Rabbit Number if S(x*x) = S(x)*S(x). For example, 22 is a Rabbit Number because S(484) = S(22)*S(22).


Return the number of Rabbit Numbers between low and high, inclusive.

DEFINITION
Class:RabbitNumber
Method:theCount
Parameters:int, int
Returns:int
Method signature:int theCount(int low, int high)


CONSTRAINTS
-low will be between 1 and 1,000,000,000, inclusive.
-high will be between low and 1,000,000,000, inclusive.


EXAMPLES

0)
22
22

Returns: 1

22 is a Rabbit Number because

S(22*22) = S(484) = 16

S(22) * S(22) = 4 * 4 = 16

1)
484
484

Returns: 0

484 is not a Rabbit Number because

S(484*484) = S(234256) = 22

S(484) * S(484) = 16 * 16 = 256

2)
1
58

Returns: 12



3)
58
484

Returns: 24



4)
1000000000
1000000000

Returns: 1



*/

// END CUT HERE
