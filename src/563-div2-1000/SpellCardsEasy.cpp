
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




class SpellCardsEasy {
public:
   int maxDamage( vector <int> level, vector <int> damage ) {
	int n = SZ(level);
	int dp[n+1][n+1]; MSET(dp, -1);
	dp[n][0] = 0;
	for(int i = n-1; i >= 0; i--) REP(j, n+1) if(dp[i+1][j] != -1) {
		dp[i][j+1] = max(dp[i][j+1], dp[i+1][j]);
		if(j >= level[i]-1) dp[i][j-level[i]+1] = max(dp[i][j-level[i]+1], dp[i+1][j] + damage[i]);
	}
	int res = -1;
	REP(i, n+1) res = max(res, dp[0][i]);
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
			int level[]               = {1,1,1};
			int damage[]              = {10,20,30};
			int expected__            = 60;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int level[]               = {3,3,3};
			int damage[]              = {10,20,30};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int level[]               = {4,4,4};
			int damage[]              = {10,20,30};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int level[]               = {50,1,50,1,50};
			int damage[]              = {10,20,30,40,50};
			int expected__            = 60;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int level[]               = {2,1,1};
			int damage[]              = {40,40,10};
			int expected__            = 80;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int level[]               = {1,2,1,1,3,2,1};
			int damage[]              = {10,40,10,10,90,40,10};
			int expected__            = 150;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int level[]               = {1,2,2,3,1,4,2};
			int damage[]              = {113,253,523,941,250,534,454};
			int expected__            = 1577;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int level[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int level[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int level[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpellCardsEasy().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
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
// You are playing a card game.
In the card game, each card holds a magic spell with two properties: its level and its damage.
During the game, you will play some of the cards (possibly none or all of them) to attack your enemy.



Initially, there are n cards.
The cards are placed in a row and they are labeled from 0 to n-1, in order.
You are given two vector <int>s: level and damage.
For each i, the level of card i is level[i], and its damage is damage[i].



In each turn of the game, you can pick a card to play.
You can only pick card i if there are at least another (level[i]-1) cards to the right of it.
Picking a card with level L and damage D has the following effects:

Your opponent receives D damage.
Starting with this card, L cards are discarded. 
That is, if the chosen card was card i, then the discarded cards are cards i to (i+L-1), inclusive.




Return the maximal total damage you can deal to your opponent.

DEFINITION
Class:SpellCardsEasy
Method:maxDamage
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxDamage(vector <int> level, vector <int> damage)


CONSTRAINTS
-level will contain between 1 and 50 elements, inclusive.
-level and damage will contain the same number of elements.
-Each element in level will be between 1 and 50, inclusive.
-Each element in damage will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,1,1}
{10,20,30}

Returns: 60

You can use all three spell cards (in any order), so the total damage is: 10 + 20 + 30 = 60.

1)
{3,3,3}
{10,20,30}

Returns: 10

You are only allowed to use card 0. Using it deals 10 damage and discards all three cards.

2)
{4,4,4}
{10,20,30}

Returns: 0

This time you can't use any spell cards.

3)
{50,1,50,1,50}
{10,20,30,40,50}

Returns: 60

You can use the spell cards with damage 20 and 40.

4)
{2,1,1}
{40,40,10}

Returns: 80



5)
{1,2,1,1,3,2,1}
{10,40,10,10,90,40,10}

Returns: 150



6)
{1,2,2,3,1,4,2}
{113,253,523,941,250,534,454}

Returns: 1577



*/

// END CUT HERE
