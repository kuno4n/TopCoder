
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

class RainyRoad {
public:
   string isReachable( vector <string> road ) {
	   int n = SZ(road[0]);
	   REP(i, n){
		   if(road[0][i] == 'W' && road[1][i] == 'W') return "NO";
	   }
	   return "YES";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string road[]             = {".W.."
,"...."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string road[]             = {".W.."
,"..W."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string road[]             = {".W..W.."
,"...WWW."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string road[]             = {".."
,"WW"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string road[]             = {".WWWW."
,"WWWWWW"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string road[]             = {".W.W.W."
,"W.W.W.W"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string road[]             = {".............................................W."
,".............................................W."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string road[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string road[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string road[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
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
// Fox Ciel is going to take a path to meet her friends. The path is tiled with 1x1 square tiles. It is N tiles long and 2 tiles wide. If we imagine that the path is going from the left to the right, we can view it as a rectangle with 2 rows and N columns of tiles.
The rows of the path are numbered 0 to 1 from top to bottom, and the columns of the path are numbered 0 to N-1 from left to right. Ciel starts at the tile in row 0, column 0. She has to reach the tile in row 0, column N-1.

In each step, Ciel can move to an adjacent tile. Two tiles are adjacent if they share at least one point (a side or a corner).

Because it rained yesterday, some tiles are covered by puddles of water. Ciel will not step on these tiles. You are given a vector <string> road. The j-th character of i-th element is 'W' if a tile at i-th row of j-th column is covered by  water, and '.' otherwise.

Return the string "YES" if she can move to her destination without entering a tile which is filled with water. Otherwise, return "NO".

DEFINITION
Class:RainyRoad
Method:isReachable
Parameters:vector <string>
Returns:string
Method signature:string isReachable(vector <string> road)


NOTES
-The constraints guarantee that the starting tile and the destination tile are never covered by water.


CONSTRAINTS
-road will contain exactly 2 elements.
-Each elements of road will contain between 2 and 50 characters, inclusive.
-All elements of road will contain the same number of characters.
-Each character of road will be either '.' or 'W'.
-The first character and the last character of 0-th element of road will be '.'.


EXAMPLES

0)
{".W.."
,"...."}

Returns: "YES"

One of the possible ways is as follows. Here, 'F' is the tile occupied by Fox Ciel.

"FW.."
"...." 

".W.."
"F..." 

".W.."
".F.."

".W.."
"..F."

".W.F"
"...."


1)
{".W.."
,"..W."}

Returns: "YES"



2)
{".W..W.."
,"...WWW."}

Returns: "NO"



3)
{".."
,"WW"}

Returns: "YES"



4)
{".WWWW."
,"WWWWWW"}

Returns: "NO"



5)
{".W.W.W."
,"W.W.W.W"}

Returns: "YES"



6)
{".............................................W."
,".............................................W."}

Returns: "NO"



*/

// END CUT HERE
