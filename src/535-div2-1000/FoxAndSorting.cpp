
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
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

LL dp[20][200];

class FoxAndSorting {
public:
   long long get( long long idx ) {
	MSET(dp, 0);
	dp[0][0] = 1;
	for(int i = 1; i <= 18; i++){
		dp[i][0]++;
		REP(j, 200){
			for(int k = (i==18 ? 1 : 0); k <= min(9, j); k++) dp[i][j] += dp[i-1][j-k];
		}
	} 
	
	int sum = 0;
	REP(d, 200){
		if(dp[18][d] >= idx) break;
		sum++;
		idx -= dp[18][d];
	}
	
	LL res = 0;
	for(int x = 18; x >= 1; x--){
		if(sum == 0){
			if(idx == 1) break;
			else{
				idx--;
				res *= 10;
				continue;
			}
		}
		for(int d = 0; d <= min(9, sum); d++){
			if(d == 0 && x == 18) continue;
			if(idx <= dp[x-1][sum-d]){
				res *= 10;
				res += d;
				sum -= d;
				break;
			}
			else idx -= dp[x-1][sum-d];
		}
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
			long long idx             = 10;
			long long expected__      = 100000000;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long idx             = 1000000000000000000LL;
			long long expected__      = 999999999999999999LL;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long idx             = 58;
			long long expected__      = 100000000100LL;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long idx             = 314159265358979LL;
			long long expected__      = 646003042230121105LL;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long idx             = 271828182845904523LL;
			long long expected__      = 132558071125756493LL;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long idx             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long idx             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long idx             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxAndSorting().get(idx);
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
// Fox Jiro and Eel Saburo are good friends. Saburo uses a strange way to compare integers. Please help Jiro understand it.

For a positive integer n, let d(n) be the sum of its digits in base 10. For example, d(407) = 4+0+7 = 11.

When comparing two different integers x and y, Saburo first compares their sums of digits, i.e., the values d(x) and d(y). If they differ, the one with the smaller sum is smaller.
For example, for Saburo 50 is smaller than 16, because d(50) < d(16).

If the numbers have the same sum of digits, Saburo compares them lexicographically (i.e., as strings).
For example, for Saburo the number 111 is smaller than the number 3, because d(111) = d(3) and "111" < "3".
Also, the number 470 is smaller than 4700, because "470" < "4700".

Let A be the sequence of integers {0, 1, ..., 999999999999999998, 999999999999999999 (10^18 - 1)}.
Let B be the sequence A, ordered according to Saburo's rules.
You are given a long long idx, representing a 1-based index into B.
Return the corresponding element of B.

DEFINITION
Class:FoxAndSorting
Method:get
Parameters:long long
Returns:long long
Method signature:long long get(long long idx)


NOTES
-Given two distinct strings A and B, we say that A is lexicographically smaller than B if either A is a prefix of B, or A has a smaller character than B on the first position on which they differ.


CONSTRAINTS
-idx will be between 1 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
10

Returns: 100000000

First 10 elements of B are: {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}.

1)
1000000000000000000

Returns: 999999999999999999

The last element.

2)
58

Returns: 100000000100



3)
314159265358979

Returns: 646003042230121105



4)
271828182845904523

Returns: 132558071125756493



*/

// END CUT HERE
