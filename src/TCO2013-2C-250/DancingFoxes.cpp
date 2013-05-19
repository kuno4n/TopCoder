
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

int INF = (1<<29);

class DancingFoxes {
public:
   int minimalDays( vector <string> friendship ) {
    const int MAX_V = 60;
    int V = SZ(friendship);
    
    int G[MAX_V][MAX_V];
    REP(i, V) REP(j, V) G[i][j] = INF;
    REP(i, V){
		G[i][i] = 0;
		REP(j, V) if(friendship[i][j] == 'Y'){
			G[i][j] = 1;
			G[j][i] = 1;
		}
	}
    
    REP(k, V) REP(i, V) REP(j, V){
        if(G[i][j] > G[i][k] + G[k][j]){
            G[i][j] = G[i][k] + G[k][j];
        }
    }
    
    if(G[0][1] == INF) return -1;
    
    int dp[60]; REP(i, 60) dp[i] = 0;
    dp[1] = 0;
    for(int i = 2; i < 60; i++) dp[i] = dp[i-(i+1)/3] + 1;
    return dp[G[0][1]];
    

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
			string friendship[]       = {"NNY",
 "NNY",
 "YYN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string friendship[]       = {"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string friendship[]       = {"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string friendship[]       = {"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string friendship[]       = {"NY",
 "YN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string friendship[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string friendship[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string friendship[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays(vector <string>(friendship, friendship + (sizeof friendship / sizeof friendship[0])));
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
// Fox Ciel and Fox Jiro both went to spend an evening in the dancing room.
Together, there are N foxes in the room.
The foxes are numbered 0 through N-1.
In particular, Ciel is fox 0 and Jiro is fox 1.



You are given a vector <string> friendship that describes the initial friendship between the foxes in the room.
More precisely, friendship contains N elements with N characters each.
Character j of element i of friendship is 'Y' if foxes i and j are friends at the beginning of the evening, and 'N' otherwise.
Note that friendship is symmetric: whenever X is a friend of Y, Y is a friend of X.



During the evening, multiple songs will be played in succession.
During each song, some pairs of foxes will be dancing together.
Foxes are not allowed to change partners during the dance.
Thus in each dance each fox either dances with a single partner, or sits the dance out.



Foxes are not allowed to form the pairs for a dance arbitrarily.
It is only allowed for two foxes to dance together if they are friends, or if they have a common friend who can introduce them.
That is, if foxes A and B are not friends at the moment, they can only dance together if there is a fox C such that A and B are both friends with C.
After two foxes dance together, they become friends.



Fox Ciel wants to become friends with Fox Jiro.
Return the smallest number of dances in which this can be achieved (assuming that all other foxes cooperate and form pairs for the dances optimally).
If it's impossible to make Ciel and Jiro friends, return -1 instead.

DEFINITION
Class:DancingFoxes
Method:minimalDays
Parameters:vector <string>
Returns:int
Method signature:int minimalDays(vector <string> friendship)


NOTES
-Gender does not matter for the foxes when choosing their dance partners.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-friendship will contain exactly N elements.
-Each element of friendship will contain exactly N characters.
-Each character in friendship will be 'Y' or 'N'.
-For each i, friendship[i][i] = 'N'.
-For each i and j, friendship[i][j] = friendship[j][i].


EXAMPLES

0)
{"NNY",
 "NNY",
 "YYN"}

Returns: 1

There are 3 foxes. Ciel and Jiro are not friends, but they are both friends with fox 2. Thus, they may dance together in the first dance and become friends.

1)
{"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}

Returns: -1

Ciel does not know any other fox at the dance, so she cannot dance with anybody.

2)
{"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"}

Returns: 2



3)
{"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"}

Returns: 3



4)
{"NY",
 "YN"}

Returns: 0

Ciel and Jiro are already friends in the beginning, no dances are needed. In such a case, the correct return value is 0.

*/

// END CUT HERE
