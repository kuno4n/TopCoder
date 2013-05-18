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

int bitcnt(LL a){
    int res = 0;
    while(a != 0){
        if(a&1) res++;
        a >>= 1;
    }
    return res;
}

int INF = (1<<29);
int G[60][60];
int dp[1<<16][60];
int opn[60], cls[60], dur[60];

class TravellingPurchasingMan {
	public:
	int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
        REP(i, 60) REP(j, 60) G[i][j] = INF;
        REP(i, 60) G[i][i] = 0;
        REP(i, SZ(roads)){
            int a, b, d;
            stringstream ss; ss << roads[i];
            ss >> a >> b >> d;
            G[a][b] = d;
            G[b][a] = d;
        }
        REP(k, N) REP(i, N) REP(j, N){
            if(G[i][j] > G[i][k] + G[k][j]){
                G[i][j] = G[i][k] + G[k][j];
            }
        }
        
        int n = SZ(interestingStores);
        REP(i, n){
            int o, c, d;
            stringstream ss; ss << interestingStores[i];
            ss >> o >> c >> d;
            opn[i] = o;
            cls[i] = c;
            dur[i] = d;
        }
        
        REP(i, (1<<n)) REP(j, n) dp[i][j] = INF;
        REP(i, n) if(max(G[N-1][i], opn[i]) <= cls[i]) dp[1<<i][i] = max(G[N-1][i], opn[i]) + dur[i];
        REP(i, (1<<n)) REP(j, n) if(i & (1<<j)){
            REP(k, n) if(max(dp[i][j] + G[j][k], opn[k]) <= cls[k]){
                dp[i | (1<<k)][k] = min(dp[i | (1<<k)][k], max(dp[i][j] + G[j][k], opn[k]) + dur[k]);
            }
        }
        
        int res = 0;
        REP(i, (1<<n)) REP(j, n) if(dp[i][j] < INF){
            res = max(res, bitcnt(i));
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
			int N                     = 3;
			string interestingStores[] = {"1 10 10" , "1 55 31", "10 50 100" };
			string roads[]            = {"1 2 10"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TravellingPurchasingMan().maxStores(N, vector <string>(interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			string interestingStores[] = {"1 10 10" , "1 55 30", "10 50 100" };
			string roads[]            = {"1 2 10"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TravellingPurchasingMan().maxStores(N, vector <string>(interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 5;
			string interestingStores[] = {"0 1000 17"};
			string roads[]            = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TravellingPurchasingMan().maxStores(N, vector <string>(interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int N                     = ;
			string interestingStores[] = ;
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravellingPurchasingMan().maxStores(N, vector <string>(interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int N                     = ;
			string interestingStores[] = ;
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravellingPurchasingMan().maxStores(N, vector <string>(interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			string interestingStores[] = ;
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravellingPurchasingMan().maxStores(N, vector <string>(interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
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
// You are interested in purchasing items from a number of stores in a local market. The market is composed of N stores numbered from 0 to N-1. The stores with numbers from 0 to M-1 are interesting to you and all the other stores are not interesting. Some pairs of stores are connected by roads.

You are given a vector <string> interestingStores which contains M elements and describes the interesting stores. The i-th element corresponds to store i and is formatted "OPEN CLOSE DURATION" (quotes for clarity), where OPEN is the opening time (in seconds), CLOSE is the closing time (in seconds) and DURATION is the time (in seconds) required to make a purchase in this store. You can initiate a purchase from a store at any time T between OPEN and CLOSE, inclusive. In order to do so, you need to arrive to the store at time T (or earlier). The purchase will be finalized at time T + DURATION and you need to stay at the store for the entire duration of your purchase. Note that it is possible for a purchase to end when the store is already closed. You cannot make multiple purchases in the same store.

The roads are given by the vector <string> roads. Each element of roads describes a single bidirectional road and is formatted "A B LENGTH" (quotes for clarity). Here A and B are the numbers of stores connected by the road and LENGTH is the time (in seconds) required to move from A to B (or from B to A) using this road.

Your start at time 0 at the location of store N-1. Return the maximum number of purchases in interesting stores that you can make.

DEFINITION
Class:TravellingPurchasingMan
Method:maxStores
Parameters:int, vector <string>, vector <string>
Returns:int
Method signature:int maxStores(int N, vector <string> interestingStores, vector <string> roads)


NOTES
-You are allowed to wait for any amount of time at any location.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-roads will contain between 1 and 50 elements, inclusive.
-Each element of roads will be formatted "A B LENGTH" (quotes for clarity), where A, B and LENGTH are integers with no unnecessary leading zeros.
-In each road, A and B will each be between 0 and N-1, inclusive.
-In each road, A and B will be distinct.
-In each road, LENGTH will be between 1 and 604,800, inclusive.
-There will exist at most one road between each pair of stores.
-interestingStores will contain between 1 and min{16, N} elements, inclusive,
-Each element of interestingStores will be formatted "OPEN CLOSE DURATION" (quotes for clarity), where OPEN, CLOSE and DURATION are integers with no unnecessary leading zeros.
-In each store, OPEN will be between 0 and 604,800, inclusive.
-In each store, CLOSE will be between OPEN+1 and 604,800, inclusive.
-In each store, DURATION will be between 1 and 604,800, inclusive.


EXAMPLES

0)
3
{"1 10 10" , "1 55 31", "10 50 100" }
{"1 2 10"}

Returns: 1

It is not possible to make more than one purchase:
If you decide to make the purchase at store 2: You need to wait 10 seconds until it opens. Then wait until time = 110 seconds for the purchase to finish. At 110 seconds, all the other stores will be closed.
If you instead decide to make the purchase at store 1: You first need travel through the road and arrive store 1 at time = 10. The purchase finishes at time = 41. After you travel back to store 2, the time will be 51 seconds and store 2 will be closed.
There is no way to reach store 0 when store 2 is the starting point.


1)
3
{"1 10 10" , "1 55 30", "10 50 100" }
{"1 2 10"}

Returns: 2

This time we can travel to store 1, make the purchase and return to store 2 exactly at time = 50 to make two purchases in total.


2)
5
{"0 1000 17"}
{"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}

Returns: 0

It is not possible to reach store 0 before it closes.


*/

// END CUT HERE
