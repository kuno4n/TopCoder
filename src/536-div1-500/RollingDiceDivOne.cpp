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

class RollingDiceDivOne {
	public:
	long long mostLikely(vector <int> dice) {
        int n = SZ(dice);
        REP(i, n) dice[i]--;
        LL len = dice[0];
        LL sum = dice[0];
        for(int i = 1; i < n; i++){
            if(dice[i] <= len) len -= dice[i];
            else if(dice[i] <= sum) len = ((sum - dice[i]) & 1);
            else len = dice[i] - sum;
            sum += dice[i];
        }
        return sum/2 - len/2 + n;
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
			int dice[]                = {6, 6, 8};
			long long expected__      = 11;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int dice[]                = {10};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int dice[]                = {2, 3, 4, 5};
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int dice[]                = {1, 10, 1};
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int dice[]                = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402, 700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240};
			long long expected__      = 4366828428LL;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int dice[]                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int dice[]                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int dice[]                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RollingDiceDivOne().mostLikely(vector <int>(dice, dice + (sizeof dice / sizeof dice[0])));
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
// Byteasar is playing a tabletop role-playing game with his friends. To determine the effectiveness of their heroes' actions the players use a rather unique set of dice. The i-th (0-based) die has dice[i] faces. They are numbered from 1 to dice[i] and the face number k shows k pips. When a die is cast, every face has equal probability to come out on top.


Byteasar's hero is now trying to unlock a safe containing treasure.
In order to see if he succeeds, Byteasar has to guess a number M and then to roll all the dice.
The safe will open if and only if M is precisely equal to the total number of pips on the topmost faces of all the dice.
Obviously, the best strategy for Byteasar is to set M equal to the most probable outcome of the dice roll.


You are given the vector <int> dice. Return the value M such that the probability of the total number of pips being M is the highest possible. If there are multiple such values of M, return the smallest one.

DEFINITION
Class:RollingDiceDivOne
Method:mostLikely
Parameters:vector <int>
Returns:long long
Method signature:long long mostLikely(vector <int> dice)


NOTES
-Please note that a die can have as few as one or two faces.


CONSTRAINTS
-dice will contain between 1 and 50 elements, inclusive.
-Each element of dice will be between 1 and 109, inclusive.


EXAMPLES

0)
{6, 6, 8}

Returns: 11

The probability that the total number of pips on topmost faces of the three dice will be 11 is equal to 1/9.

1)
{10}

Returns: 1

You should return the minimum possible answer.

2)
{2, 3, 4, 5}

Returns: 9



3)
{1, 10, 1}

Returns: 3



4)
{382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240}

Returns: 4366828428



*/

// END CUT HERE
