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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}


class FoxAndGCDLCM {
	public:
	long long get(long long G, long long L) {
		if(L%G) return -1;
        LL tmp = L/G;
        for(LL a = (LL)sqrt(tmp); ; a--){
            if(!(tmp%a)) {
                LL b = tmp/a;
                if(gcd(a,b) == 1) return G*a+G*b;
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
			long long G               = 2;
			long long L               = 20;
			long long expected__      = 14;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long G               = 5;
			long long L               = 8;
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long G               = 1000;
			long long L               = 100;
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long G               = 100;
			long long L               = 1000;
			long long expected__      = 700;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long G               = 10;
			long long L               = 950863963000LL;
			long long expected__      = 6298430;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long G               = ;
			long long L               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long G               = ;
			long long L               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long G               = ;
			long long L               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxAndGCDLCM().get(G, L);
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
// Fox Jiro and Eel Saburo are good friends. One day Saburo found two interesting positive integers: A and B.

On the next day, Saburo met Jiro and wanted to tell him the two integers. However, he managed to forget their values. All Saburo could remember was their greatest common divisor G and their least common multiple L.

You are given two long longs: G and L. Find the original integers A and B, and return the value of A+B. If there are multiple pairs of A and B that correspond to G and L, pick the one that minimizes A+B. If it is impossible to find such A and B (i.e., Saburo made a mistake somewhere), return -1.

DEFINITION
Class:FoxAndGCDLCM
Method:get
Parameters:long long, long long
Returns:long long
Method signature:long long get(long long G, long long L)


NOTES
-The greatest common divisor of two integers a and b is the largest positive integer that divides both a and b without any remainder.
-The least common multiple of two integers a and b is the smallest positive integer that is a multiple of both a and b.


CONSTRAINTS
-G will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-L will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
20

Returns: 14

The possible pairs of A and B are {2, 20} and {4, 10}. We need to pick {4, 10} since 4+10 is the smallest sum of A and B.

1)
5
8

Returns: -1

There are no pairs of A and B such that their greatest common divisor is 5 and their least common multiple is 8.

2)
1000
100

Returns: -1



3)
100
1000

Returns: 700



4)
10
950863963000

Returns: 6298430



*/

// END CUT HERE
