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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

LL cnt(LL num, LL b){
    return num / b;
}

class FractionInDifferentBases {
	public:
	long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
		P -= (P/Q) * Q;
        LL tmpQ = Q;
        vector <LL> pri_Q;
        for(LL i = 2; i*i <= tmpQ; i++){
            while(tmpQ % i == 0){
                pri_Q.push_back(i);
                tmpQ /= i;
            }
        }
        if(tmpQ != 1) pri_Q.push_back(tmpQ);
        
        set <LL> setb;
        LL b = 1;
        REP(i, SZ(pri_Q)){
            if(P%pri_Q[i] == 0) P/=pri_Q[i];
            else setb.insert(pri_Q[i]);
        }
        for(set<LL>::iterator it = (setb).begin(); it != (setb).end(); it++) b *= *it;
        
        return (B-A+1) - (cnt(B, b) - cnt(A-1, b));
        
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
			long long P               = 1;
			long long Q               = 2;
			long long A               = 10;
			long long B               = 10;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long P               = 1;
			long long Q               = 9;
			long long A               = 9;
			long long B               = 10;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long P               = 5;
			long long Q               = 6;
			long long A               = 2;
			long long B               = 10;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long P               = 2662;
			long long Q               = 540;
			long long A               = 2;
			long long B               = 662;
			long long expected__      = 639;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long P               = 650720;
			long long Q               = 7032600;
			long long A               = 2012;
			long long B               = 2012540;
			long long expected__      = 2010495;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long P               = ;
			long long Q               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long P               = ;
			long long Q               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long P               = ;
			long long Q               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
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
This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

It is well-known that when writing a fraction as a rational number, we will either get a finite expansion or an infinite (but periodic) expansion.
For example, 1/8 written in base 10 is 0.125, and 1/9 written in base 10 is 0.1111...

The same fraction can have a finite expansion in some bases and an infinite one in other bases.
For example, 1/9 had an infinite expansion in base 10, but 1/9 written in base 3 is 0.01 and 1/9 in base 9 is 0.1.

Little Arthur loves numbers and especially the ones that are infinitely long. For a given fraction P/Q he would like to find all integer bases between A and B, inclusive, such that the fraction has an infinite expansion.

Given ints P, Q, A, and B return the number of such bases.

DEFINITION
Class:FractionInDifferentBases
Method:getNumberOfGoodBases
Parameters:long long, long long, long long, long long
Returns:long long
Method signature:long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B)


NOTES
-Number X written in an integer base b is a sequence of digits (containing a single separator point, if the number is not an integer) dndn-1..d1d0.d-1..d-m where each di has an integer value between 0 and b-1, inclusive.
-The notation effectively means that X = dn*bn + dn-1*bn-1 + .. + d1*b1 + d0*b0 + d-1*b-1 + .. + d-m*b-m.
-Note that X having an infinite expansion in base b means that number X cannot be expressed as a sum with finitely many powers of b.


CONSTRAINTS
-P will be between 0 and 1000000000000 (1012), inclusive.
-Q will be between 1 and 1000000000000 (1012), inclusive.
-A and B will each be between 2 and 1000000000000000000 (1018), inclusive.
-A will be less than or equal to B.


EXAMPLES

0)
1
2
10
10

Returns: 0

1/2 in base 10 is 0.5, thus, there is no base in the interval where 1/2 has an infinite expansion.

1)
1
9
9
10

Returns: 1

From the problem statement we see that 1/9 has an infinite expansion in base 10, but not in base 9.

2)
5
6
2
10

Returns: 8

3)
2662
540
2
662

Returns: 639

4)
650720
7032600
2012
2012540

Returns: 2010495

*/

// END CUT HERE
