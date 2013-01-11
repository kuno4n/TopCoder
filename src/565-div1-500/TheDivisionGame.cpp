
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
#include <queue>	

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
#define OUT(A) cout << #A << " = "<< A << endl

int current[1000001], nimber[1000001];

class TheDivisionGame {
public:
   long long countWinningIntervals( int L, int R ) {
	   MSET(current, 0); MSET(nimber, 0);
	   LL n = R-L+1;
	   REP(i, n) current[i] = L+i;
	   for(LL p=2; p*p<=R; p++){
		   LL s = L;
		   if(s%p != 0) s += p-s%p;
		   while(s<=R){
			   while(current[s-L]%p == 0){
				   current[s-L] /= p;
				   nimber[s-L]++;
			   }
			   s += p;
		   }
	   }
	   REP(i, n) if(current[i] != 1) nimber[i]++;

	   LL res = n*(n+1)/2;
	   LL prev[32];
	   MSET(prev, 0);
	   REP(i, n){
		   LL now[32];
		   MSET(now, 0);
		   REP(j, 32){
			   now[j^nimber[i]] += prev[j];
		   }
		   now[nimber[i]]++;
		   res -= now[0];
		   REP(i, 32) swap(prev[i], now[i]);
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
			int L                     = 9;
			int R                     = 10;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int L                     = 2;
			int R                     = 5;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int L                     = 2;
			int R                     = 6;
			long long expected__      = 13;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int L                     = 2;
			int R                     = 100;
			long long expected__      = 4345;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int L                     = 12566125;
			int R                     = 12567777;
			long long expected__      = 1313432;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int L                     = ;
			int R                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int L                     = ;
			int R                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int L                     = ;
			int R                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheDivisionGame().countWinningIntervals(L, R);
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
// Manao likes to play the Division Game with his friends. This two-player game is played with some collection of natural numbers S. Manao plays first and the players alternate in making a move. A move is choosing some number X from S and a natural number Y &gt 1 such that Y divides X. Then, X is replaced by X / Y in the collection. Note that at any moment the collection may contain multiple copies of the same number. The game proceeds until no more moves can be made. The player who managed to make the last move is declared the winner.

Since hot debates arise on what numbers should be in S, the friends decided to regularize their choice. They always choose a contiguous interval of numbers [A, B] to be the initial collection S. That is, at the beginning of the game, the collection S contains each of the integers A through B, inclusive, exactly once. Manao knows that A and B will satisfy the condition L &le A &le B &le R. You are given the ints L and R. Count the number of such intervals for which Manao will win the Division Game given that both players play optimally.

DEFINITION
Class:TheDivisionGame
Method:countWinningIntervals
Parameters:int, int
Returns:long long
Method signature:long long countWinningIntervals(int L, int R)


NOTES
-Only one number from the collection changes in each move. For example, if the collection contains three copies of the number 8, and the player chooses X=8 and Y=4, only one of the 8s in the collection will change to a 2.


CONSTRAINTS
-L will be between 2 and 1,000,000,000, inclusive.
-R will be between L and L + 1,000,000, inclusive.


EXAMPLES

0)
9
10

Returns: 2

If the chosen interval is [9,9] or [10,10], the collection S contains only one number. In these two situations Manao can win the game in a single move. On the other hand, if the chosen interval is [9,10], Manao will lose to an optimally playing opponent.


1)
2
5

Returns: 9

The only case where Manao loses is if the game starts with the interval [2,3]. Note that if the starting interval is [2,5], Manao can choose X=4 and Y=2 in his first move. After that move, the collection will contain the values 2, 2, 3, and 5.

2)
2
6

Returns: 13

Manao will also lose the game if the starting interval is [3,6].

3)
2
100

Returns: 4345



4)
12566125
12567777

Returns: 1313432



*/

// END CUT HERE
