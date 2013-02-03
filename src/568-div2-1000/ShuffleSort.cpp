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

class ShuffleSort {
	public:
	double shuffle(vector <int> cards) {
		int n = SZ(cards);
        double res = 0.0;
        sort(ALL(cards));
        REP(i, n){
            int a = 0;
            FOR(j, i, n) if(cards[j] == cards[i]) a++;
            res += (double)(n-i)/a;
        }
        return res-(n-1);
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
			int cards[]               = {1};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int cards[]               = {1,2};
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int cards[]               = {2,3,1};
			double expected__         = 4.0;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int cards[]               = {15,16,4,8,42,23};
			double expected__         = 16.0;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int cards[]               = {1,1,1,1,1,1,1,1} ;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int cards[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int cards[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int cards[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ShuffleSort().shuffle(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
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
// Fox Ciel has a deck of N cards numbered from 0 to N-1, inclusive. For each i, the i-th card has an integer cards[i] written on it. It is possible that the integers written on some cards are the same. Such cards are indistinguishable.

Ciel wants to sort the cards. More exactly, she wants to place them in a line on the table so that the integers on the cards form a non-decreasing sequence. To achieve this goal, she takes the entire deck into her hand and applies the following process (starting from step 1).

She shuffles all cards in her hand. This is equivalent to permuting the order of cards uniformly at random.
Let X be the smallest of all integers written on cards she still holds in her hand. Ciel checks the topmost card of the deck she just shuffled. If the card contains an integer greater than X, she proceeds to step 1. Otherwise, she places the card onto the table. (If there are already some cards on the table, the new card is placed on their right to extend the line of sorted cards.) After she does that, if she has no more cards in her hand, she is done. Otherwise, she repeats step 2 (without shuffling the deck!).

Given the vector <int> cards, return the expected number of times that step 1 (a shuffle of the deck) will be executed during the sorting process described above.


DEFINITION
Class:ShuffleSort
Method:shuffle
Parameters:vector <int>
Returns:double
Method signature:double shuffle(vector <int> cards)


NOTES
-The return value must have a relative or an absolute error of less than 1e-9.
-Informally, the return value can be seen as the average number of card shuffles required to sort a given deck of cards (where the average is taken over very many rounds of the experiment). For a formal definition, you can check http://en.wikipedia.org/wiki/Expected_value.


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will be between 1 and 50, inclusive.


EXAMPLES

0)
{1}

Returns: 1.0

There is just 1 card, but Ciel will still shuffle the cards once anyway.

1)
{1,2}

Returns: 2.0

After a single shuffle of the cards, their order from top to bottom can be (1, 2) or (2, 1). If it is (1, 2), then both cards will be placed on the table and the process will stop. Otherwise, no cards will be placed on the table and shuffle will have to be repeated.

In average, the process will end after 2 card shuffles.

2)
{2,3,1}

Returns: 4.0

The elements of cards are not necessarily given in a sorted order.

3)
{15,16,4,8,42,23}

Returns: 16.0



4)
{1,1,1,1,1,1,1,1}


Returns: 1.0

All cards are the same, so just one shuffle is always enough.

*/

// END CUT HERE
