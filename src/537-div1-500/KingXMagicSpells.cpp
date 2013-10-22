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

class KingXMagicSpells {
	public:
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
        int n = SZ(ducks);
        double res = 0.0;
        
        REP(i, 40){
            double dp[K+1][n]; MSET(dp, 0);
            REP(j, n) if(ducks[j] & (1LL<<i)) dp[0][j] = 1.0;
            int so[n]; MSET(so, 0);
            REP(j, n) if(spellOne[j] & (1LL<<i)) so[j] = 1;
            
            REP(k, K) REP(j, n){
                dp[k+1][j] += (so[j] ? 1-dp[k][j] : dp[k][j]) * 0.5;
                dp[k+1][spellTwo[j]] += dp[k][j] * 0.5;
            }
            res += dp[K][0] * (1LL<<i);
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
			int ducks[]               = {5, 3, 7};
			int spellOne[]            = {1, 7, 4};
			int spellTwo[]            = {1, 0, 2};
			int K                     = 1;
			double expected__         = 3.5;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int ducks[]               = {5, 8};
			int spellOne[]            = {53, 7};
			int spellTwo[]            = {1, 0};
			int K                     = 2;
			double expected__         = 21.5;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int ducks[]               = {123, 456, 789, 1234, 56789};
			int spellOne[]            = {0, 0, 0, 0, 0};
			int spellTwo[]            = {0, 1, 2, 3, 4};
			int K                     = 50;
			double expected__         = 123.0;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int ducks[]               = {83291232, 3124231, 192412, 3813249, 629231, 9998989};
			int spellOne[]            = {58, 37, 44, 66, 72, 19};
			int spellTwo[]            = {2, 0, 1, 5, 4, 3};
			int K                     = 11;
			double expected__         = 2.888186784716797E7;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int ducks[]               = ;
			int spellOne[]            = ;
			int spellTwo[]            = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int ducks[]               = ;
			int spellOne[]            = ;
			int spellTwo[]            = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int ducks[]               = ;
			int spellOne[]            = ;
			int spellTwo[]            = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = KingXMagicSpells().expectedNumber(vector <int>(ducks, ducks + (sizeof ducks / sizeof ducks[0])), vector <int>(spellOne, spellOne + (sizeof spellOne / sizeof spellOne[0])), vector <int>(spellTwo, spellTwo + (sizeof spellTwo / sizeof spellTwo[0])), K);
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
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

The palace has N rooms, conveniently numbered 0 through N-1. The rooms are occupied by the ducks King Dengklek loves the most. There are ducks[i] ducks in room i.

Today, King Dengklek realized that two magic spells are affecting the palace. Being a perfect king, he quickly learned that on each day, exactly one of the two magic spells will take place with the same probability (i.e., 50%). The effects of the two magic spells are as follows:

Spell 1: For each i, let D be the number of ducks in room i right before the spell's effect takes place. The number of ducks in room i will become D XOR spellOne[i] (see the Notes section for the definition of XOR).
Spell 2: For each i, all ducks in room i will move to room spellTwo[i]. All these movements will happen simultaneously. This will permute the ducks (i.e., no two elements of spellTwo will be equal).


King Dengklek is worried about these odd magic spells. He is especially worried about room 0, because he has promised that he will grant all ducks in this room to his successor. You are given the vector <int>s ducks, spellOne, spellTwo, and the int K. Return the expected number of ducks in room 0 after the magic spells have affected the palace for K days.

DEFINITION
Class:KingXMagicSpells
Method:expectedNumber
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-If a and b are single bits then a XOR b is defined as (a + b) modulo 2. For two integers, A and B, in order to calculate A XOR B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A XOR B = C = (cn...c1)2, where ci = ai XOR bi. For example, 10 XOR 3 = (1010)2 XOR (0011)2 = (1001)2 = 9.


CONSTRAINTS
-ducks, spellOne, and spellTwo will contain the same number of elements, between 1 and 50, inclusive.
-Each element of ducks will be between 0 and 1,000,000,000, inclusive.
-Each element of spellOne will be between 0 and 1,000,000,000, inclusive.
-Each element of spellTwo will be between 0 and N-1, inclusive, where N is the number of elements in ducks.
-All elements of spellTwo will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
{5, 3, 7}
{1, 7, 4}
{1, 0, 2}
1

Returns: 3.5

We want to know the expected number of ducks in room 0 after K=1 day. Exactly one spell will take place. Depending on which spell takes place, there are two possible outcomes:

Spell 1: The numbers of ducks in the rooms become {5 XOR 1, 3 XOR 7, 7 XOR 4} = {4, 4, 3}.
Spell 2: The numbers of ducks in the rooms become {3, 5, 7}.

Therefore, the expected number of ducks in room 0 is (4 + 3)/2 = 3.5.

1)
{5, 8}
{53, 7}
{1, 0}
2

Returns: 21.5

There are four possible outcomes, depending on which two spells take place:

Spell 1 and then spell 1: {48, 15} and then {5, 8}.
Spell 1 and then spell 2: {48, 15} and then {15, 48}.
Spell 2 and then spell 1: {8, 5} and then {61, 2}.
Spell 2 and then spell 2: {8, 5} and then {5, 8}.

Therefore, the expected number of ducks in room 0 is (5 + 15 + 61 + 5)/4 = 21.5.

2)
{123, 456, 789, 1234, 56789}
{0, 0, 0, 0, 0}
{0, 1, 2, 3, 4}
50

Returns: 123.0

In this case, the number of ducks in each room will never change.

3)
{83291232, 3124231, 192412, 3813249, 629231, 9998989}
{58, 37, 44, 66, 72, 19}
{2, 0, 1, 5, 4, 3}
11

Returns: 2.888186784716797E7



*/

// END CUT HERE
