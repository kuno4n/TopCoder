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

class DoorsGame {
	public:
	int determineOutcome(string doors, int trophy) {
		set<char> j, g, s;
        REP(i, trophy) j.insert(doors[i]);
        FOR(i, trophy, SZ(doors)) g.insert(doors[i]);
        FIT(it, j) if(g.count(*it)){
            char c = *it;
            s.insert(c);
        }
        FIT(it, s){
            j.erase(*it);
            g.erase(*it);
        }
        if(SZ(j) < SZ(g)){
            if(SZ(j)+SZ(s) > SZ(g)) return 0;
            else return (SZ(j)+SZ(s))*2 -1;
        }
        else if(SZ(j) > SZ(g)){
            if(SZ(g)+SZ(s) >= SZ(j)) return 0;
            else return (SZ(g)+SZ(s))*-2;
        }
        else if(SZ(s)==0) return SZ(j)+SZ(g) - 1;
        
        return 0;
        
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
			string doors              = "ABCD";
			int trophy                = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string doors              = "ABCC";
			int trophy                = 2;
			int expected__            = -2;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string doors              = "ABABAB";
			int trophy                = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string doors              = "ABAPDCAA";
			int trophy                = 5;
			int expected__            = -4;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string doors              = "MOCFDCE";
			int trophy                = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string doors              = "ABCCDE";
			int trophy                = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string doors              = "ABCCD";
			int trophy                = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string doors              = ;
			int trophy                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string doors              = ;
			int trophy                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string doors              = ;
			int trophy                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DoorsGame().determineOutcome(doors, trophy);
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
// John and Gogo are playing Doors Game. This game is played in a building containing a single row of N+1 rooms, numbered 0 through N from left to right. One of the rooms is called the trophy room. There's a door between each pair of adjacent rooms. Each door has a color, and there are 16 possible colors (represented by uppercase letters 'A' through 'P'). All doors are initially closed.


Initially, John is in room 0 and Gogo is in room N. The two players alternate turns, and John gets the first turn. On each turn, the current player chooses a color which hasn't yet been chosen from among the 16 possible colors. All doors, if any, with the chosen color are then opened. At this point, if one of the players can reach the trophy room by walking through only open doors, that player wins and the game ends. If both players can reach the trophy room, the game ends in a draw. If neither player can reach the trophy room, the game continues.


Each player will play according to the following strategy:
Each time a player needs to choose a color, he will make make his choice as follows:

If it's possible for him to choose a color in such a way that he will be able to win no matter what his opponent does, he will choose such a color. If there are several such colors, he will choose the one among them for which the game will end with the fewest total number of colors chosen, assuming that the opponent aims to maximize the number of colors chosen in the game.
Otherwise, if it's possible for him to choose a color in such a way that he will be able to end the game in a draw no matter what his opponent does, he will choose any such color.
Otherwise, he will choose a color for which the game will end with the largest total number of colors chosen, assuming that his opponent aims to win while minimizing the total number of colors chosen.


You are given the colors of the doors in the string doors. The i-th character in doors is the color of the door connecting rooms i and i+1. You are also given an int trophy, which denotes the number of the trophy room. If the game ends in a draw, return 0. Otherwise, let X be the number of colors chosen in the game. If John wins, return X. If Gogo wins, return -X.

DEFINITION
Class:DoorsGame
Method:determineOutcome
Parameters:string, int
Returns:int
Method signature:int determineOutcome(string doors, int trophy)


CONSTRAINTS
-doors will contain between 2 and 50 characters, inclusive.
-Each character in doors will be an uppercase letter 'A'-'P'.
-trophy will be between 1 and N-1, inclusive, where N is the number of characters in doors.


EXAMPLES

0)
"ABCD"
2

Returns: 3

There are five rooms, with the trophy room in the middle. John will win after he chooses color A and B.

1)
"ABCC"
2

Returns: -2

In this case, Gogo will win by just choosing color C.

2)
"ABABAB"
3

Returns: 0

When colors A and B have been chosen, both players will be able to reach the trophy room.

3)
"ABAPDCAA"
5

Returns: -4



4)
"MOCFDCE"
3

Returns: 5



5)
"ABCCDE"
3

Returns: 0



6)
"ABCCD"
3

Returns: 0



*/

// END CUT HERE
