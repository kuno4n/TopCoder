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

int MOD = 1000000007;
void add(LL &a, LL b){
    a = (a+b) % MOD;
}


VI A, B, C, D;
LL memo[51][51][51][51];

LL rec(int a, int b, int c, int d){
    LL &res = memo[a][b][c][d];
    if(res >= 0) return res;
    if(a == 0 && b == 0) return res = 1;
    
    res = 0;
    if(a != 0 && c != 0 && A[a-1] == C[c-1]) add(res, rec(a-1, b, c-1, d));
    if(a != 0 && d != 0 && A[a-1] == D[d-1]) add(res, rec(a-1, b, c, d-1));
    if(b != 0 && c != 0 && B[b-1] == C[c-1]) add(res, rec(a, b-1, c-1, d));
    if(b != 0 && d != 0 && B[b-1] == D[d-1]) add(res, rec(a, b-1, c, d-1));
    return res;
}

class AliceBobShuffle {
	public:
	int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd) {
		A = AliceStart, B = BobStart, C = AliceEnd, D = BobEnd;
        int a = SZ(A), b = SZ(B), c = SZ(C), d = SZ(D);
        if(a+b != c+d) return 0;
        
        MSET(memo, -1);
        return rec(a,b,c,d);
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
			int AliceStart[]          = {1, 3};
			int BobStart[]            = {2, 4};
			int AliceEnd[]            = {2, 3};
			int BobEnd[]              = {1, 4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int AliceStart[]          = {1, 2, 1};
			int BobStart[]            = {1, 2};
			int AliceEnd[]            = {1, 2, 1};
			int BobEnd[]              = {2, 1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int AliceStart[]          = {1};
			int BobStart[]            = {2};
			int AliceEnd[]            = {3};
			int BobEnd[]              = {4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int AliceStart[]          = {1, 2};
			int BobStart[]            = {3};
			int AliceEnd[]            = {3};
			int BobEnd[]              = {2, 1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int AliceStart[]          = {3, 3, 2, 4, 1, 3, 1, 2, 1, 1, 5, 5, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2};
			int BobStart[]            = {4, 1, 4, 3, 4, 4, 4, 3, 2, 1, 6, 2, 2, 3, 2, 2, 1, 3, 2, 3};
			int AliceEnd[]            = {4, 1, 4, 3, 4, 4, 4, 1, 3, 1, 2, 2, 2, 3, 2, 1, 2, 1, 2, 2, 2};
			int BobEnd[]              = {3, 3, 2, 3, 4, 2, 1, 2, 1, 1, 5, 6, 5, 1, 3, 1, 2, 3, 1, 1, 1, 3};
			int expected__            = 314159265;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int AliceStart[]          = ;
			int BobStart[]            = ;
			int AliceEnd[]            = ;
			int BobEnd[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int AliceStart[]          = ;
			int BobStart[]            = ;
			int AliceEnd[]            = ;
			int BobEnd[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int AliceStart[]          = ;
			int BobStart[]            = ;
			int AliceEnd[]            = ;
			int BobEnd[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AliceBobShuffle().countWays(vector <int>(AliceStart, AliceStart + (sizeof AliceStart / sizeof AliceStart[0])), vector <int>(BobStart, BobStart + (sizeof BobStart / sizeof BobStart[0])), vector <int>(AliceEnd, AliceEnd + (sizeof AliceEnd / sizeof AliceEnd[0])), vector <int>(BobEnd, BobEnd + (sizeof BobEnd / sizeof BobEnd[0])));
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
// Alice and Bob decide to play a game with a deck of cards.  Each card has a single positive integer written on it.  Multiple cards may have the same number.  Cards with the same number are indistinguishable.  Alice and Bob begin by splitting the deck into two piles.  They each take one pile.  Then each of them writes down the sequence of numbers on the cards in his/her pile, in order from bottom to top.

Then comes the first phase of the game.
In this phase Alice and Bob build a third pile of cards, designated the "community" pile.
Initially, the community pile is empty.
The phase consists of multiple turns.
In each turn, either Alice or Bob takes the top card from his/her pile and places it on top of the community pile.
This continues until all the cards are in the community pile.
(Note that Alice and Bob are not required to alternate. They may take the turns in any order they like.)

Afterwards there is the second phase of the game.
In this phase Alice and Bob take the cards from the community pile to their personal piles.
Again, this happens in turns.
In each turn, either Alice or Bob takes the top card from the community pile and places it on top of his/her personal pile.
This continues until there are no more cards in the community pile.
(Again, Alice and Bob are not required to alternate. They may take the turns in any order they like.
They are each allowed to take any cards to their pile, not just those they had at the beginning.
They are also each allowed to take any number of cards, regardless of how many they had at the beginning.)
Finally, they again write down the sequence of numbers on the cards in each pile, from bottom to top.

Later, Alice and Bob decide to double-check what they wrote down.  Given the starting and ending lists of cards, they wonder how many ways the game could have progressed.  You will be given 4 vector <int>s: AliceStart, BobStart, AliceEnd, and BobEnd.  AliceStart and BobStart are the card stacks belonging to Alice and Bob at the start, and AliceEnd and BobEnd are the card stacks belonging to Alice and Bob at the end.  Return the number of different possible ways the game could have progressed, modulo 1,000,000,007 (10^9+7).

DEFINITION
Class:AliceBobShuffle
Method:countWays
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd)


NOTES
-Each card movement can be described by the source pile, the destination pile, and the number on the card.
-Two games are considered different if their sequences of card movements differ.


CONSTRAINTS
-AliceStart, BobStart, AliceEnd, and BobEnd will each contain between 1 and 50 elements, inclusive.
-Each element of AliceStart, BobStart, AliceEnd, and BobEnd will be between 1 and 100, inclusive.


EXAMPLES

0)
{1, 3}
{2, 4}
{2, 3}
{1, 4}

Returns: 4

There are 4 possible orders for the community pile at the end of the first phase: {4, 3, 2, 1}, {3, 4, 2, 1}, {4, 3, 1, 2}, {3, 4, 1, 2}.  (All of these are listed from bottom to top.)  Each of these uniquely determines one possible game.

1)
{1, 2, 1}
{1, 2}
{1, 2, 1}
{2, 1}

Returns: 4

The only possibility for the order of the community pile at the end of the first phase is {1, 2, 1, 2, 1}.  Still, there are 4 ways this game could have been played.  (For instance, the bottommost 1 must have come from Alice's deck, but the 2 above it could have been placed by either player.)

2)
{1}
{2}
{3}
{4}

Returns: 0

This is impossible.

3)
{1, 2}
{3}
{3}
{2, 1}

Returns: 0

Also impossible.

4)
{3, 3, 2, 4, 1, 3, 1, 2, 1, 1, 5, 5, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2}
{4, 1, 4, 3, 4, 4, 4, 3, 2, 1, 6, 2, 2, 3, 2, 2, 1, 3, 2, 3}
{4, 1, 4, 3, 4, 4, 4, 1, 3, 1, 2, 2, 2, 3, 2, 1, 2, 1, 2, 2, 2}
{3, 3, 2, 3, 4, 2, 1, 2, 1, 1, 5, 6, 5, 1, 3, 1, 2, 3, 1, 1, 1, 3}

Returns: 314159265



*/

// END CUT HERE
