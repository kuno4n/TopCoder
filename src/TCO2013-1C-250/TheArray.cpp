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

//int N, D, F, L;
//
//bool can(LL a){
////    OUT(a);
//    LL t1 = (abs(max(a, (LL)F) - min(a, (LL)F)) + D - 1) /D;
//    LL t2 = (abs(max(a, (LL)L) - min(a, (LL)L)) + D - 1) /D;
////    OUT(t1);
////    OUT(t2);
//    if(t1 + t2 >= N) return false;
//    return true;
//}

class TheArray {
	public:
	int find(int n, int d, int first, int last) {
//		N = n;
//        D = d;
//        F = first;
//        L = last;
//        
//        if(D == 0) return F;
//        LL hi = (1LL<<60)-1;
//        LL lo = max(F, L);
//        LL mid;
//        while(hi-lo > 1){
////            OUT(mid);
//            mid = (hi+lo) / 2;
//            if(can(mid)) lo = mid;
//            else hi = mid;
//        }
//        return lo;
        
        int res = -1000001;
        REP(i, n){
            res = max(res, min(first+i*d , last+(n-i-1)*d));
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
			int n                     = 3;
			int d                     = 5;
			int first                 = 2;
			int last                  = 4;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 10;
			int d                     = 100;
			int first                 = 999;
			int last                  = 100;
			int expected__            = 999;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 1000000;
			int d                     = 0;
			int first                 = 474;
			int last                  = 474;
			int expected__            = 474;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 97;
			int d                     = 53;
			int first                 = -92;
			int last                  = 441;
			int expected__            = 2717;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 99;
			int d                     = 3;
			int first                 = -743;
			int last                  = -619;
			int expected__            = -535;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int d                     = ;
			int first                 = ;
			int last                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheArray().find(n, d, first, last);
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
// John has an array of n integers.
Each pair of neighboring elements differs by at most d.
The first and the last elements of the array are equal to first and last, respectively.


Brus does not know John's array.
He only knows n, d, first and last.
He wants to compute the maximal possible element John might have in his array.


You are given ints n, d, first and last.
Return the maximal possible element the array might contain.


DEFINITION
Class:TheArray
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int n, int d, int first, int last)


NOTES
-The constraints given below guarantee that there will always be at least one array that matches the values Brus knows.
-For the constraints given below, the correct answer will always fit into an int.


CONSTRAINTS
-n will be between 2 and 1,000,000, inclusive.
-d will be between 0 and 1000, inclusive.
-first will be between -1000 and 1000, inclusive.
-last will be between -1000 and 1000, inclusive.
-|first - last| will be at most (n-1)*d.


EXAMPLES

0)
3
5
2
4

Returns: 7

Only the second element of the array is unknown.
Its maximal valid value is 7.


1)
10
100
999
100

Returns: 999

Due to the limitations, the first element is the largest element of the array.

2)
1000000
0
474
474

Returns: 474

All elements of the array are equal.

3)
97
53
-92
441

Returns: 2717



4)
99
3
-743
-619

Returns: -535



*/

// END CUT HERE
