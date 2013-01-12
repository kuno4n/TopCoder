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




class PenguinSledding {
	public:
	long long countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2) {
        bool mat[numCheckpoints+1][numCheckpoints+1];
        MSET(mat, false);
        REP(i,SZ(checkpoint1)){
            mat[checkpoint1[i]][checkpoint2[i]] = true;
            mat[checkpoint2[i]][checkpoint1[i]] = true;
        }
        LL res = SZ(checkpoint1) + 1;
        REP(i, numCheckpoints+1){
            int cnt = 0;
            REP(j, numCheckpoints+1) if(mat[i][j]) cnt++;
            if(cnt >= 2) res += (1LL<<cnt) - cnt - 1;
        }
        int cnt = 0;
        REP(i, numCheckpoints+1) REP(j, i) REP(k, j) if(mat[i][j] && mat[j][k] && mat [k][i]) res++;
        
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
			int numCheckpoints        = 2;
			int checkpoint1[]         = {1};
			int checkpoint2[]         = {2};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numCheckpoints        = 4;
			int checkpoint1[]         = {1,2,3};
			int checkpoint2[]         = {2,3,4};
			long long expected__      = 6;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numCheckpoints        = 6;
			int checkpoint1[]         = {1,3,6};
			int checkpoint2[]         = {2,4,4};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numCheckpoints        = 50;
			int checkpoint1[]         = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 50, 40, 40, 40, 23, 4, 24, 40, 22, 40, 8, 40, 40, 40, 34, 21, 40, 40, 38, 40, 40, 40, 40, 40, 28, 40, 40, 40, 40, 46, 13, 40, 40, 40, 47, 40, 40};
			int checkpoint2[]         = {45, 42, 20, 48, 12, 32, 25, 10, 26, 39, 16, 2, 19, 43, 37, 17, 19, 19, 19, 18, 19, 27, 19, 29, 11, 36, 19, 19, 1, 41, 19, 35, 14, 33, 49, 3, 19, 7, 5, 19, 31, 19, 19, 6, 9, 15, 19, 44, 30};
			long long expected__      = 68719493118LL;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numCheckpoints        = 36;
			int checkpoint1[]         = {13, 24, 24, 20, 31, 16, 10, 36, 34, 32, 28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19, 21, 8, 1, 26, 27, 25, 15, 22, 30, 30, 6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18, 13, 14, 17, 35, 3};
			int checkpoint2[]         = {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9, 2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22, 4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15, 21, 22, 8, 26, 20, 14, 32, 25, 17, 35, 8, 36, 26, 23};
			long long expected__      = 162;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int numCheckpoints        = ;
			int checkpoint1[]         = ;
			int checkpoint2[]         = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numCheckpoints        = ;
			int checkpoint1[]         = ;
			int checkpoint2[]         = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int numCheckpoints        = ;
			int checkpoint1[]         = ;
			int checkpoint2[]         = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PenguinSledding().countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1 + (sizeof checkpoint1 / sizeof checkpoint1[0])), vector <int>(checkpoint2, checkpoint2 + (sizeof checkpoint2 / sizeof checkpoint2[0])));
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
// 
Percy is a penguin in charge of the greatest penguin pastime, penguin sledding. It is Percy's job to help design the sledding course. Percy is a very careful penguin and would like to set up the course in a way that no two sledding paths cross. 



The sledding course contains some significant locations called checkpoints, and some sledding paths.
The checkpoints are numbered 1 through numCheckpoints, inclusive.
Each sledding path is a straight line segment that connects two distinct checkpoints.
The checkpoints are distinct, and no three of them lie on the same line.
(Therefore, no checkpoint will ever lie on a sledding path.)



When designing the course, Percy specifies some pairs of checkpoints that will be connected by sledding paths.
Accidents happen when two sledding paths cross, so such designs should be avoided.
Unfortunately, Percy does not know the precise locations of all checkpoints.
Therefore, Percy's design must not allow two sledding paths to cross, regardless of the locations of the checkpoints.
Percy calls a design safe if he is sure that no two sledding paths will cross.







Percy just found an old design that may be unsafe.
He would like to change it to a safe design by removing zero or more sledding paths from the original design.
Count all different safe designs he may obtain from the old design in this way.
Two designs are considered different if there is a pair of checkpoints that is connected by a sledding path in one design and disconnected in the other.



You are given the int numCheckpoints representing the number of checkpoints in the old design.
You are also given two vector <int>s checkpoint1 and checkpoint2 that describe the sledding paths in the old design:
For each i, there is a sledding path connecting the checkpoints checkpoint1[i] and checkpoint2[i].
Return the number of safe designs that can be made from the old design.


DEFINITION
Class:PenguinSledding
Method:countDesigns
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2)


CONSTRAINTS
-numCheckpoints will be between 2 and 50, inclusive.
-checkpoint1 will contain between 1 and 50 elements, inclusive.
-checkpoint1 and checkpoint2 will contain the same number of elements.
-Each element of checkpoint1 will be between 1 and numCheckpoints, inclusive.
-Each element of checkpoint2 will be between 1 and numCheckpoints, inclusive.
-Each pair of checkpoints will be connected by at most one sledding path.
-For each i, element i of checkpoint1 will not be equal to element i of checkpoint2.


EXAMPLES

0)
2
{1}
{2}

Returns: 2

There is only one sledding path. Both including it and removing it are safe designs.

1)
4
{1,2,3}
{2,3,4}

Returns: 6

Either sledding path (1,2) or (3,4) needs to be removed to form a safe design. If neither of these is removed the design is unsafe.

2)
6
{1,3,6}
{2,4,4}

Returns: 5

Note that some of the checkpoints may be isolated.

3)
50
{40, 40, 40, 40, 40, 40, 40, 40, 
 40, 40, 40, 40, 50, 40, 40, 40, 
 23, 4, 24, 40, 22, 40, 8, 40, 40,
 40, 34, 21, 40, 40, 38, 40, 40, 
 40, 40, 40, 28, 40, 40, 40, 40, 
 46, 13, 40, 40, 40, 47, 40, 40}
{45, 42, 20, 48, 12, 32, 25, 10, 
 26, 39, 16, 2, 19, 43, 37, 17, 
 19, 19, 19, 18, 19, 27, 19, 29, 
 11, 36, 19, 19, 1, 41, 19, 35, 
 14, 33, 49, 3, 19, 7, 5, 19, 31, 
 19, 19, 6, 9, 15, 19, 44, 30}

Returns: 68719493118



4)
36
{13, 24, 24, 20, 31, 16, 10, 36, 34, 32, 
 28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19,
 21, 8, 1, 26, 27, 25, 15, 22, 30, 30, 
 6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18, 
 13, 14, 17, 35, 3}
{10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
 2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
 4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
 21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
 8, 36, 26, 23}

Returns: 162



*/

// END CUT HERE
