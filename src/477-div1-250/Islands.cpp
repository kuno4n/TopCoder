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

class Islands {
	public:
	int beachLength(vector <string> kingdom) {
		int res = 0;
        int h = SZ(kingdom);
        int w = SZ(kingdom[0]);
        REP(i, SZ(kingdom)){
            REP(j, SZ(kingdom[0])){
                if(kingdom[i][j] == '#'){
                    if(j>0 && kingdom[i][j-1]=='.') res++;
                    if(j<w-1 && kingdom[i][j+1]=='.') res++;
                    if(i%2 == 0){
                        if(i>0 && j>0 && kingdom[i-1][j-1]=='.') res++;
                        if(i>0 && kingdom[i-1][j] == '.') res++;
                        if(i<h-1 && j>0 && kingdom[i+1][j-1]=='.') res++;
                        if(i<h-1 && kingdom[i+1][j]=='.') res++;
                    }
                    else{
                        if(i>0 && kingdom[i-1][j]=='.') res++;
                        if(i>0 && j<w-1 && kingdom[i-1][j+1] == '.') res++;
                        if(i<h-1 && kingdom[i+1][j]=='.') res++;
                        if(i<h-1 && j<w-1 && kingdom[i+1][j+1]=='.') res++;
                    }
                }
            }
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
			string kingdom[]          = {".#...#.."};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string kingdom[]          = {"..#.##", 
 ".##.#.", 
 "#.#..."};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string kingdom[]          = {"#...#.....",
 "##..#...#."};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string kingdom[]          = {"....#.",
 ".#....",
 "..#..#",
 "####.."};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string kingdom[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string kingdom[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string kingdom[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Islands().beachLength(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])));
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
// The king is trying to find new ways to generate revenue, and he is currently exploring tourism as one potential avenue. The kingdom is a group of islands, and the amount of revenue that can be generated depends on the combined total length of beaches on all the islands.

You are given a vector <string> kingdom consisting of '.' or '#' characters. '#' represents a land mass, whereas '.' represents water. kingdom[i][j] represents a regular-hexagon shaped area with each side of unit length. Since the cells are hexagonal in shape, the odd-numbered rows (0-based) are 'shifted' towards the right. A beach is a segment which has water on one side, and land on the other.
An example vector <string> and the corresponding image are given below to illustrate. The beaches are marked in red.

{"..#.##",
 ".##.#.",
 "#.#..."}



Return the combined total length of beaches on all the islands.

DEFINITION
Class:Islands
Method:beachLength
Parameters:vector <string>
Returns:int
Method signature:int beachLength(vector <string> kingdom)


CONSTRAINTS
-kingdom will contain between 1 and 50 elements, inclusive.
-Each element of kingdom will contain between 1 and 50 characters, inclusive.
-Each element of kingdom will contain the same number of characters.
-Each character in kingdom will be either '.' or '#'.


EXAMPLES

0)
{".#...#.."}

Returns: 4

There are two small islands with water on two sides of each island. 

1)
{"..#.##", 
 ".##.#.", 
 "#.#..."}

Returns: 19

The example in the problem statement. 

2)
{"#...#.....",
 "##..#...#."}

Returns: 15



3)
{"....#.",
 ".#....",
 "..#..#",
 "####.."}

Returns: 24



*/

// END CUT HERE
