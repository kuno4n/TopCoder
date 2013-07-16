
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

int n, zcnt;
LL table[60];

LL dp[3000];

class KingdomAndDice {
public:
   double newFairness( vector <int> firstDie, vector <int> secondDie, int X ) {
	sort(ALL(firstDie)), sort(ALL(secondDie));
	n = SZ(secondDie);
	zcnt = count(ALL(firstDie), 0);
	
	firstDie.PB(X+10);
	secondDie.PB(X+1);
	MSET(table, 0);
	int ptr = 0;
	REP(i, SZ(secondDie)){
		int cnt = 0;
		while(firstDie[ptr] < secondDie[i]) cnt++, ptr++;
		if(i == 0) continue;
		table[i] = secondDie[i] - secondDie[i-1] - 1 - cnt;
	}
	MSET(dp, -1);
	int ptr2 = 0, cnt = 0;
	REP(i, n){
		while(firstDie[i] > secondDie[ptr2]) ptr2++;
		cnt += ptr2;
	}
	dp[cnt] = 0;
	
	for(int i = 1; i <= n; i++) for(int j = 2900; j >= 0; j--) for(int k = 1; k <= min((LL)zcnt, table[i]); k++){
		int pt = j - i*k;
		if(pt < 0 || dp[pt] < 0 || dp[pt] + k > zcnt) continue;
		if(dp[j] == -1) dp[j] = dp[pt] + k;
		else chmin(dp[j], dp[pt]+k);
	}
	
	int best = (1<<29);
	int res = -1;
	REP(i, 2900) if(dp[i] >= 0) if(abs(i*2 - n*n) < best) best = abs(i*2 - n*n), res = i;
	return res/((double)n*n);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int firstDie[]            = {0, 2, 7, 0};
			int secondDie[]           = {6, 3, 8, 10};
			int X                     = 12;
			double expected__         = 0.4375;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int firstDie[]            = {0, 2, 7, 0};
			int secondDie[]           = {6, 3, 8, 10};
			int X                     = 10;
			double expected__         = 0.375;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int firstDie[]            = {0, 0};
			int secondDie[]           = {5, 8};
			int X                     = 47;
			double expected__         = 0.5;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int firstDie[]            = {19, 50, 4};
			int secondDie[]           = {26, 100, 37};
			int X                     = 1000;
			double expected__         = 0.2222222222222222;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int firstDie[]            = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012};
			int secondDie[]           = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561};
			int X                     = 10000;
			double expected__         = 0.49;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases
      case 5: {
			int firstDie[]            = {1000000000, 999999999, 999999998, 999999997, 999999996, 999999995, 999999994, 999999993, 999999992, 999999991, 999999990, 999999989, 999999988, 999999987, 999999986, 999999985, 999999984, 999999983, 999999982, 999999981, 999999980, 999999979, 999999978, 999999977, 999999976, 999999975, 999999974, 999999973, 999999972, 999999971, 999999970, 999999969, 999999968, 999999967, 999999966, 999999965, 999999964, 999999963, 999999962, 999999961, 999999960, 999999959, 999999958, 999999957, 999999956, 999999955, 999999954, 999999953, 999999952, 999999951};
			int secondDie[]           = {999999950, 999999949, 999999948, 999999947, 999999946, 999999945, 999999944, 999999943, 999999942, 999999941, 999999940, 999999939, 999999938, 999999937, 999999936, 999999935, 999999934, 999999933, 999999932, 999999931, 999999930, 999999929, 999999928, 999999927, 999999926, 999999925, 999999924, 999999923, 999999922, 999999921, 999999920, 999999919, 999999918, 999999917, 999999916, 999999915, 999999914, 999999913, 999999912, 999999911, 999999910, 999999909, 999999908, 999999907, 999999906, 999999905, 999999904, 999999903, 999999902, 999999901};
			int X                     = 1000000000;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int firstDie[]            = ;
			int secondDie[]           = ;
			int X                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int firstDie[]            = ;
			int secondDie[]           = ;
			int X                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = KingdomAndDice().newFairness(vector <int>(firstDie, firstDie + (sizeof firstDie / sizeof firstDie[0])), vector <int>(secondDie, secondDie + (sizeof secondDie / sizeof secondDie[0])), X);
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
// King Dengklek has two N-sided dice. The dice are not necessarily equal. Each of the dice is fair: when rolled, each side will come up with probability 1/N. Some time ago, each side of each die was labeled by a positive integer between 1 and X, inclusive. The labels were all unique. In other words, exactly 2*N distinct integers were used to label the sides of the two dice.

King Dengklek has been playing with the first die for a long time. Therefore, some of its labels were scratched off. The corresponding sides of the die are now empty. The second die still has all of its labels.

The current labels on the first die are given in the vector <int> firstDie: if the i-th side has no label, firstDie[i] is 0, otherwise firstDie[i] is the label. The current labels on the second die are given in secondDie: the i-th side of the second die has the label secondDie[i].

In King Dengklek's favorite game, he takes one of the dice, his opponent takes the other, and they each roll the die they have. The one who throws a larger number is the winner. King Dengklek wants to fill in the missing labels on the first die. His goal is to fill them in such a way that his favorite game becomes as fair as possible.

When filling in the missing labels, King Dengklek wants to preserve the two properties mentioned above: first, each integer between 1 and X, inclusive, may only occur at most once on the two dice. Second, no other labels may be used. However, there is an exception to the second rule: King Dengklek is also allowed to use the label 0. Moreover, he may even use this label multiple times.

You are given the vector <int>s firstDie and secondDie, and the int X. For a particular way to fill in the missing labels, let P be the probability that the player with the first die wins in the king's game. Find the labeling that minimizes the value |P - 0.5| and return the corresponding value of P. If there are two possible solutions, return the smaller one.

DEFINITION
Class:KingdomAndDice
Method:newFairness
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double newFairness(vector <int> firstDie, vector <int> secondDie, int X)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-|x| denotes the the absolute value of x. For example, |3| = |-3| = 3.


CONSTRAINTS
-firstDie and secondDie will contain the same number of elements, between 2 and 50, inclusive.
-X will be between 2*N and 1,000,000,000, inclusive, where N is the number of elements in firstDie.
-Each element of firstDie will be between 0 and X, inclusive.
-Each element of secondDie will be between 1 and X, inclusive.
-Each integer between 1 and X, inclusive, will occur at most once in firstDie and secondDie together.


EXAMPLES

0)
{0, 2, 7, 0}
{6, 3, 8, 10}
12

Returns: 0.4375

One possible solution is to relabel the first die into {4, 2, 7, 11}. The probability of winning against the second die will be 7/16.

1)
{0, 2, 7, 0}
{6, 3, 8, 10}
10

Returns: 0.375

One possible solution is to relabel the first die into {9, 2, 7, 5}. The probability of winning against the second die will be 3/8.

2)
{0, 0}
{5, 8}
47

Returns: 0.5

One possible solution is to relabel the first die into {10, 0}.

3)
{19, 50, 4}
{26, 100, 37}
1000

Returns: 0.2222222222222222

The first die does not have any missing labels.

4)
{6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012}
{1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561}
10000

Returns: 0.49



*/

// END CUT HERE
