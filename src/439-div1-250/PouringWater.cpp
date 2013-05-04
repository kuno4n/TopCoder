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

string _10to2(long long l){
    if (l == 0) return "0";
    string res = "";
    while(l != 1){
        if ( l & 1 ) res = '1' + res;
        else res = '0' + res;
        l >>= 1;
    }
    return '1' + res;
}

long long _2to10(string s){
    long long res = 0;
    REP (i, SZ(s)) {
        res <<= 1;
        if (s[i] == '1') res++;
    }
    return res;
}

class PouringWater {
	public:
	int getMinBottles(int N, int K) {
		string s = _10to2(N);OUT(s);
        int cnt = 0;
        int pos = 0;
        for(; pos < SZ(s); pos++){
            if(s[pos] == '1'){
                cnt++;
                if(cnt >= K) break;
            }
        }
        if(pos < SZ(s)-1){
            string s2 = s.substr(pos+1, SZ(s)-pos-1);
            int tmp = _2to10(s2);
            if(tmp == 0) return 0;
            else return (1<<(SZ(s)-pos-1)) - tmp;
        }
        else return 0;
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
			int N                     = 3;
			int K                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PouringWater().getMinBottles(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 13;
			int K                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PouringWater().getMinBottles(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 1000000;
			int K                     = 5;
			int expected__            = 15808;

			clock_t start__           = clock();
			int received__            = PouringWater().getMinBottles(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PouringWater().getMinBottles(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PouringWater().getMinBottles(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PouringWater().getMinBottles(N, K);
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
// You have N bottles, each with unlimited capacity.  Initially, each bottle contains exactly 1 liter of water.  You want to carry these bottles to another location, but you can only carry K bottles at a time.  You don't want to waste any water and you don't want to make more than one trip, so you decide to redistribute the contents of the bottles until you end up with no more than K non-empty bottles.

You are only allowed to redistribute your water using the following method.  First, pick two bottles that contain an equal amount of water.  Then, pour the entire content of one of those bottles into the other.  Repeat this process as many times as necessary.

Because of this restriction, it may be impossible to end up with no more than K non-empty bottles using only the N bottles that you have initially.  Fortunately, you can also buy more bottles.  Each bottle that you buy will contain exactly 1 liter of water and have unlimited capacity.  For example, consider the case where N is 3 and K is 1.  It's impossible to get from 3 bottles to 1.  If you pour one bottle into another, you end up with one 2 liter bottle and one 1 liter bottle.  At that point, you're stuck.  However, if you then buy another bottle, you can pour that bottle into the 1 liter bottle, and pour the resulting 2 liter bottle into the other 2 liter bottle to end up with just one 4 liter bottle. 

Return the minimum number of additional bottles you must buy in order to achieve your goal.  If it's impossible, return -1 instead.

DEFINITION
Class:PouringWater
Method:getMinBottles
Parameters:int, int
Returns:int
Method signature:int getMinBottles(int N, int K)


CONSTRAINTS
-N will be between 1 and 10^7, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
3
1

Returns: 1

The example from the problem statement.

1)
13
2

Returns: 3

If you have 13, 14, or 15 bottles, you can't end up with one or two bottles. With 16 bottles, you can end up with one bottle.

2)
1000000
5

Returns: 15808



*/

// END CUT HERE
