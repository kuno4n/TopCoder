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

class MagicDiamonds {
    bool isPrime(long long l){
        if(l < 2) return false;
        for(LL i=2; i*i<=l; i++)
            if(l%i == 0 )
                return false;
        return true;
    }
	public:
	long long minimalTransfer(long long n) {
        if(n==3) return 3;
		if(isPrime(n)) return 2;
        return 1;
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
			long long n               = 2;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 4294967297LL;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 2147483647;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long n               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long n               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicDiamonds().minimalTransfer(n);
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
// You found n Magic Diamonds in the mountain. You are now thinking about transfering them to your home.
The only way you can transfer Magic Diamonds is to use Transfer Magic one or more times.


The Magic Diamonds are very strange.
For any positive integer x you can use Transfer Magic to transfer x Magic Diamonds at once. However, if x is a prime number, the Magic Diamonds will disappear instead of getting transferred. You are not allowed to lose any of the Magic Diamonds, therefore you may never use Transfer Magic on a prime number of Magic Diamonds. Your task is to transfer all Magic Diamonds using Transfer Magic as few times as possible.



You are given a long long n. Return the minimal number of Transfer Magic usages you need to transfer n Magic Diamonds.

DEFINITION
Class:MagicDiamonds
Method:minimalTransfer
Parameters:long long
Returns:long long
Method signature:long long minimalTransfer(long long n)


NOTES
-A positive integer x is a prime number if and only if it has exactly 2 divisors: 1 and x. Note that 1 is not a prime number.
-Your task can always be accomplished. For example, you can use Transfer Magic n times and transfer 1 Magic Diamond each time.


CONSTRAINTS
-n will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2

Returns: 2

We have to use Transfer Magic twice, each time we transfer 1 Magic Diamond.

1)
4294967297

Returns: 1

We just need to use Transfer Magic once, because 4294967297 is not a prime. We have 4294967297 = 641 * 6700417.

2)
2147483647

Returns: 2

This time n is a prime, so we have to use Transfer Magic at least twice. We have 2147483647 = 2147400000 + 83647 (83647 = 233 * 359, which is not a prime), thus the answer is 2.

3)
1

Returns: 1



*/

// END CUT HERE
