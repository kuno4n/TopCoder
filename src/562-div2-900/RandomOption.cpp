
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

long long fact(int n){
    long long res = 1;
    while(n!=1){
        res *= n;
        n--;
    }
    return res;
}


class RandomOption {
public:
   double getProbability( int keyCount, vector <int> badLane1, vector <int> badLane2 ) {
	int n = keyCount;
	map<int, set<int> > m;
	REP(i, SZ(badLane1)) m[badLane1[i]].insert(badLane2[i]), m[badLane2[i]].insert(badLane1[i]);
	LL dp[1<<n][n+1]; MSET(dp, 0);
	REP(i, n) dp[1<<i][i] = 1;
	REP(i, (1<<n)) REP(j, n) if(i&(1<<j)) REP(k, n) if(!(i&(1<<k)) && m[j].count(k) == 0){
		dp[i|(1<<k)][k] += dp[i][j];
	}
	LL res = 0; REP(i, n) res += dp[(1<<n)-1][i];
	return res/(double)fact(n);
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
			int keyCount              = 5;
			int badLane1[]            = {0};
			int badLane2[]            = {3};
			double expected__         = 0.6;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int keyCount              = 5;
			int badLane1[]            = {0, 1, 2};
			int badLane2[]            = {1, 2, 0};
			double expected__         = 0.1;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int keyCount              = 5;
			int badLane1[]            = {2, 2, 2, 2};
			int badLane2[]            = {0, 1, 3, 4};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int keyCount              = 7;
			int badLane1[]            = {0, 1, 2};
			int badLane2[]            = {6, 5, 4};
			double expected__         = 0.3904761904761904;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int keyCount              = 7;
			int badLane1[]            = {3, 5, 1, 0, 2, 6, 4};
			int badLane2[]            = {0, 2, 4, 6, 1, 5, 3};
			double expected__         = 0.09166666666666667;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int keyCount              = ;
			int badLane1[]            = ;
			int badLane2[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int keyCount              = ;
			int badLane1[]            = ;
			int badLane2[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int keyCount              = ;
			int badLane1[]            = ;
			int badLane2[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomOption().getProbability(keyCount, vector <int>(badLane1, badLane1 + (sizeof badLane1 / sizeof badLane1[0])), vector <int>(badLane2, badLane2 + (sizeof badLane2 / sizeof badLane2[0])));
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
// DJ Jeipouju likes a single-player music game called BM Mania.
In this game, the player has a controller with keyCount keys, arranged in a row and conveniently numbered 0 through keyCount-1, in order.
When starting a game, the player selects a song.
The game takes the musical score of the song and assigns each note to one of the keys of the controller.
The goal of the game is to "play" the song by hitting the corresponding keys of the controller at appropriate times.

The player also has a computer screen that shows him the keys he will have to hit in the future.
During the game, the keys that the player has to hit are shown to the player as lanes:
For each key of the controller, there is a column on the screen with downwards moving markers, each representing a keystroke.
Whenever a marker reaches the bottom of the screen, the player must press the corresponding key.

A simple scheme of the game screen with 5 keys is shown below.
Dashes ('-') represent the markers, equals signs ('=') are the bottom of the screen.
For convenience, we show the corresponding key numbers below.


   | | | | | |
   | |-| | | |
   | |-| | |-|
   |-| |-|-| |
   |-| | |-|-|
   | | |-|-| |
   |-| | | |-|
   ===========
   |0|1|2|3|4|


Jeipouju is a pretty good player.
Recently, he tried to play a difficult song, but he always failed at the same place in the song.
The reason of his failure was the fact that he was unable to play a combination of keystrokes that appeared in two adjacent lanes.
However, he can easily play the same combination on any pair of non-adjacent keys.

Luckily for Jeipouju, the game has an option to randomly permute the lanes of a song.
The figure below shows one possible outcome of activating the random option.
In the figure, the original lane 0 is now on the key 4, lane 1 moved to key 0, lanes 2 and 3 stayed
on their respective keys, and lane 4 moved to the key 1.


     original                        permuted
      song                             lanes
    | | | | | |                     | | | | | |
    |-| |-| | |                     | | |-| |-|
    | |-| | | |                     |-| | | | |
    |-| | |-| |   random activated  | | | |-|-|
    | |-| | | |  =================> |-| | | | |
    |-|-| | | |                     |-| | | |-|
    |-| | | | |                     | | | | |-|
    | |-| |-|-|                     |-|-| |-| |
    ===========                     ===========
    |0|1|2|3|4|                     |0|1|2|3|4|


Jeipouju thinks that there are several pairs of lanes that will cause him to fail if they are assigned to adjacent keys.
For each i, one such pair is badLane1[i] and badLane2[i].
More precisely, Jeipouju will win the game if and only if for all i the lanes badLane1[i] and badLane2[i] are assigned to non-adjacent keys.

You are given the int keyCount and two vector <int>s: badLane1 and badLane2. 
Return the probability that Jeipouju will win the game after the lanes have been randomly permuted.

DEFINITION
Class:RandomOption
Method:getProbability
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double getProbability(int keyCount, vector <int> badLane1, vector <int> badLane2)


NOTES
-The permutation of lanes is chosen uniformly at random from the set of all possible permutations.
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-keyCount will be between 5 and 14, inclusive.
-badLane1 will contain between 1 and 50 elements, inclusive.
-badLane2 will contain the same number of elements as badLane1.
-Each element of badLane1 and badLane2 will be between 0 and keyCount - 1, inclusive.
-For all i, badLane1[i] and badLane2[i] will be distinct.
-All the pairs of bad lanes will be distinct.


EXAMPLES

0)
5
{0}
{3}

Returns: 0.6

There are 5 keys and only one bad pair.
The probability that these lanes are assigned to adjacent keys is 4 / (5 choose 2) = 0.4, so the probability that we have a good arrangement is 1 - 0.4 = 0.6.

1)
5
{0, 1, 2}
{1, 2, 0}

Returns: 0.1

In a good arrangement, no two of the lanes 0, 1, and 2 may be adjacent.
Hence they have to be assigned to keys 0, 2, and 4, in some order.
The probability of this event is (3! * 2!) / 5! = 0.1.

2)
5
{2, 2, 2, 2}
{0, 1, 3, 4}

Returns: 0.0

All the pairs of lane 2 and other lanes are bad, so it is impossible to obtain a good arrangement.

3)
7
{0, 1, 2}
{6, 5, 4}

Returns: 0.3904761904761904



4)
7
{3, 5, 1, 0, 2, 6, 4}
{0, 2, 4, 6, 1, 5, 3}

Returns: 0.09166666666666667



*/

// END CUT HERE
