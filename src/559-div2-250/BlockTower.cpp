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

class BlockTower {
	public:
	int getTallest(vector <int> b) {
		int N = SZ(b);
        int res = 0;
        
        int res_mae = 0;
        REP(i, N){
            if(!(b[i]%2)) res_mae += b[i];
            else{
                int tmp = res_mae;
                for(int j=i; j<N; j++){
                    if(b[j]%2) tmp += b[j];
                }
                res = max(res, tmp);
            }
        }
        res = max(res, res_mae);
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
			int blockHeights[]        = {4,7};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int blockHeights[]        = {7,4};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int blockHeights[]        = {7};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int blockHeights[]        = {4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int blockHeights[]        = {48,1,50,1,50,1,48};
			int expected__            = 196;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int blockHeights[]        = {49,2,49,2,49};
			int expected__            = 147;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int blockHeights[]        = {44,3,44,3,44,47,2,47,2,47,2};
			int expected__            = 273;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int blockHeights[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int blockHeights[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int blockHeights[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlockTower().getTallest(vector <int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
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
// Josh loves playing with blocks. Currently, he has N blocks, labeled 0 through N-1. The heights of all blocks are positive integers. More precisely, for each i, the height of block i is blockHeights[i]. Josh is interested in making the tallest block tower possible. He likes all his towers to follow three simple rules:

The blocks must be stacked in a single column, one atop another. The height of the tower is simply the sum of heights of all its blocks.
The labels of blocks used in the tower must increase from the bottom to the top. In other words, whenever Josh places box x on top of box y, we have x > y.
Josh will never place a box of an even height on top of a box of an odd height.

You are given the vector <int> blockHeights. Return the height of the tallest possible block tower Josh can build.

DEFINITION
Class:BlockTower
Method:getTallest
Parameters:vector <int>
Returns:int
Method signature:int getTallest(vector <int> blockHeights)


CONSTRAINTS
-blockHeights will contain between 1 and 50 elements, inclusive.
-Each element of blockHeights will be between 1 and 50, inclusive.


EXAMPLES

0)
{4,7}

Returns: 11

The optimal tower contains both blocks. Block 0 is on the bottom of the tower.

1)
{7,4}

Returns: 7

This time the optimal tower contains just block 0. Josh cannot put block 1 on top of it, because 4 is even and 7 is odd.

2)
{7}

Returns: 7



3)
{4}

Returns: 4



4)
{48,1,50,1,50,1,48}

Returns: 196

Note that in a valid tower the labels of the blocks have to increase from bottom to top. Their heights do not have to. In this case the optimal tower consists of blocks 0, 2, 4, and 6, in this order. Its total height is 48 + 50 + 50 + 48 = 196.

5)
{49,2,49,2,49}

Returns: 147



6)
{44,3,44,3,44,47,2,47,2,47,2}

Returns: 273



*/

// END CUT HERE
