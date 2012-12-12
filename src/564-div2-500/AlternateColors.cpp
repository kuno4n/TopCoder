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

class AlternateColors {
	public:
	string getColor(long long r, long long g, long long b, long long k) {
		LL mn3 = min(r, min(g, b));
        LL K = k;
        k -= mn3*3;
        r -= mn3;
        g -= mn3;
        b -= mn3;
        if(k <= 0){
            int tmp = K%3;
            if(tmp == 0) return "BLUE";
            if(tmp == 1) return "RED";
            if(tmp == 2) return "GREEN";
        }
        
        bool R2 = r>0 ? true: false;
        bool G2 = g>0 ? true: false;
        bool B2 = b>0 ? true: false;
        K = k;
        LL L1=0;
        LL L2=0;
        if(R2) L1 = r;
        if(G2 && !R2) L1 = g;
        if(G2 && R2) L2 = g;
        if(B2) L2 = b;
        
        LL mn2 = min(L1, L2);
        k -= mn2*2;
        L1 -= mn2;
        L2 -= mn2;
        
        if(k <= 0){
            int tmp = K%2;
            if(tmp == 0){
                return B2? "BLUE" : "GREEN";
            }
            else{
                return R2? "RED" : "GREEN";
            }
        }
        if(L1 > 0){
            return R2? "RED" : "GREEN";
        }
        return B2? "BLUE" : "GREEN";
        
        
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			long long r               = 1;
			long long g               = 1;
			long long b               = 1;
			long long k               = 3;
			string expected__         = "BLUE";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long r               = 3;
			long long g               = 4;
			long long b               = 5;
			long long k               = 4;
			string expected__         = "RED";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long r               = 7;
			long long g               = 7;
			long long b               = 1;
			long long k               = 7;
			string expected__         = "GREEN";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long r               = 1000000000000LL;
			long long g               = 1;
			long long b               = 1;
			long long k               = 1000000000002LL;
			string expected__         = "RED";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long r               = 653;
			long long g               = 32;
			long long b               = 1230;
			long long k               = 556;
			string expected__         = "BLUE";

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
            case 5: {
                long long r               = 9;
                long long g               = 8;
                long long b               = 7;
                long long k               = 21;
                string expected__         = "BLUE";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 6: {
                long long r               = 9;
                long long g               = 8;
                long long b               = 7;
                long long k               = 22;
                string expected__         = "RED";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 7: {
                long long r               = 9;
                long long g               = 8;
                long long b               = 7;
                long long k               = 23;
                string expected__         = "GREEN";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 8: {
                long long r               = 9;
                long long g               = 7;
                long long b               = 8;
                long long k               = 22;
                string expected__         = "RED";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 9: {
                long long r               = 9;
                long long g               = 7;
                long long b               = 8;
                long long k               = 23;
                string expected__         = "BLUE";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 10: {
                long long r               = 7;
                long long g               = 9;
                long long b               = 8;
                long long k               = 22;
                string expected__         = "GREEN";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 11: {
                long long r               = 7;
                long long g               = 9;
                long long b               = 8;
                long long k               = 23;
                string expected__         = "BLUE";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 12: {
                long long r               = 9;
                long long g               = 8;
                long long b               = 7;
                long long k               = 24;
                string expected__         = "RED";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 13: {
                long long r               = 8;
                long long g               = 7;
                long long b               = 9;
                long long k               = 24;
                string expected__         = "BLUE";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 14: {
                long long r               = 7;
                long long g               = 9;
                long long b               = 8;
                long long k               = 24;
                string expected__         = "GREEN";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 15: {
                long long r               = 7;
                long long g               = 7;
                long long b               = 9;
                long long k               = 22;
                string expected__         = "BLUE";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 16: {
                long long r               = 7;
                long long g               = 9;
                long long b               = 7;
                long long k               = 22;
                string expected__         = "GREEN";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 17: {
                long long r               = 9;
                long long g               = 7;
                long long b               = 7;
                long long k               = 22;
                string expected__         = "RED";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 18: {
                long long r               = 9;
                long long g               = 0;
                long long b               = 0;
                long long k               = 6;
                string expected__         = "RED";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 19: {
                long long r               = 0;
                long long g               = 9;
                long long b               = 0;
                long long k               = 6;
                string expected__         = "GREEN";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 20: {
                long long r               = 0;
                long long g               = 0;
                long long b               = 9;
                long long k               = 6;
                string expected__         = "BLUE";
                
                clock_t start__           = clock();
                string received__         = AlternateColors().getColor(r, g, b, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }

		// custom cases

/*      case 5: {
			long long r               = ;
			long long g               = ;
			long long b               = ;
			long long k               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long r               = ;
			long long g               = ;
			long long b               = ;
			long long k               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long r               = ;
			long long g               = ;
			long long b               = ;
			long long k               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlternateColors().getColor(r, g, b, k);
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
// Bob is playing with his ball destroyer robot. Initially, Bob has r red balls, g green balls and b blue balls. The robot will repeat the following 3-step program until there are no balls left:

If there is at least one red ball available, destroy one red ball.
If there is at least one green ball available, destroy one green ball.
If there is at least one blue ball available, destroy one blue ball.

You are given the long longs r, g and b. You are also given a long long k. Find the color of the k-th ball (1-index based) that will be destroyed.
If the color of the k-th ball to be destroyed is red, return "RED" (quotes for clarity, returned values are case-sensitive).
If the color is green, return "GREEN".
If the color is blue, return "BLUE".


DEFINITION
Class:AlternateColors
Method:getColor
Parameters:long long, long long, long long, long long
Returns:string
Method signature:string getColor(long long r, long long g, long long b, long long k)


CONSTRAINTS
-r, g and b  will each be between 1 and 1000000000000 (10^12), inclusive.
-k will be between 1 and r+g+b, inclusive.


EXAMPLES

0)
1
1
1
3

Returns: "BLUE"

The order in which the balls are destroyed is: Red, green and blue. The third ball was blue.

1)
3
4
5
4

Returns: "RED"

The order in which the balls are destroyed is:  Red, green, blue, red, green, blue, red, green, blue, green, blue and blue.

2)
7
7
1
7

Returns: "GREEN"



3)
1000000000000
1
1
1000000000002

Returns: "RED"

Once the only green and blue balls are destroyed, all of the remaining balls will be red.

4)
653
32
1230
556

Returns: "BLUE"



*/

// END CUT HERE
