
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

int d, res;
VI p;

void dfs(int n){OUT(n);
	if(n == d) return;
	if(p[n] == -1){
		res++;
		return;
	}
	dfs(p[n]);
	return;
}

class CellRemoval {
public:
   int cellsLeft( vector <int> parent, int deletedCell ) {
	d = deletedCell;
	p = parent;
	VI l;
	REP(i, SZ(p)){
		bool le = true;
		REP(j, SZ(p)) if(p[j] == i) le = false;
		if(le) l.PB(i);
	}
	res = 0;
	REP(i, SZ(l)) dfs(l[i]);
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
			int parent[]              = {-1,0,0,1,1};
			int deletedCell           = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {-1,0,0,1,1};
			int deletedCell           = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {-1,0,0,1,1};
			int deletedCell           = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {-1,0,0,2,2,4,4,6,6};
			int deletedCell           = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43, 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
			int deletedCell           = 24;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int parent[]              = ;
			int deletedCell           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int parent[]              = ;
			int deletedCell           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int parent[]              = ;
			int deletedCell           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
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
// In biology, organisms have the following property: Starting from the first cell (the zygote), each cell during an organism's development process either divides into 2 other cells or does not divide at all.  An organism is mature when all of its cells will not divide any further.

Let's assign a unique number to each cell in an organism's development process.  For example, consider a species in which each organism starts with cell 0, which divides into cells 1 and 2.  Cell 1 divides into cells 3 and 4.  Cells 2, 3 and 4 do not divide.  Every mature organism of this species will consist of exactly 3 cells - 2, 3 and 4.


During the development process, if we kill a cell, it will be absent in the mature form of the organism.  If that cell happens to be a cell that divides, then the mature organism will be missing all of the cell's descendants as well because the cell is killed before it has a chance to divide.  For example, in the organism described above, if we kill cell 1 during the development process, the mature organism will contain only cell 2.



You are given a vector <int> parentCell describing the development process of an organism.  The i-th element of parentCell is the parent cell of cell i (where i is a 0-based index).  The zygote's parent is -1.  Return the number of cells the mature form of this organism would have if you killed cell deletedCell during the development process.

DEFINITION
Class:CellRemoval
Method:cellsLeft
Parameters:vector <int>, int
Returns:int
Method signature:int cellsLeft(vector <int> parent, int deletedCell)


CONSTRAINTS
-parentCell will contain exactly N elements, where N is an odd integer between 1 and 50, inclusive.
-There will be exactly one "-1" element in parentCell.
-Every element of parentCell will be between -1 and N-1, inclusive.
-parentCell will form a binary tree.
-deletedCell will be between 0 and N-1, inclusive.


EXAMPLES

0)
{-1,0,0,1,1}
2

Returns: 2

This is the example organism from the problem statement.  If we kill cell 2, there will still be two cells left (3 and 4).

1)
{-1,0,0,1,1}
1

Returns: 1

This is the example organism from the problem statement.  If we kill cell 1, the only cell left will be cell 2.  Cells 3 and 4 will not exist because cell 1 is their ancestor.

2)
{-1,0,0,1,1}
0

Returns: 0

If we kill the zygote, there is nothing left.

3)
{-1,0,0,2,2,4,4,6,6}
4

Returns: 2



4)
{26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14}
24

Returns: 14



*/

// END CUT HERE
