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

class RobotHerb {
	public:
	long long getdist(int T, vector <int> a) {
		LL dx = 0;
        LL dy = 0;
        int dir = 0;
        VI aa = a;
        REP(i, 3){
            REP(j, SZ(aa)){
                a.push_back(aa[j]);
            }
        }
        REP(i, SZ(a)){
            if(dir%4 == 0) dy += a[i];
            if(dir%4 == 1) dx += a[i];
            if(dir%4 == 2) dy -= a[i];
            if(dir%4 == 3) dx -= a[i];
            dir = (dir + a[i]) % 4;
        }
        LL dxx = dx * (T/4);
        LL dyy = dy * (T/4);
//        OUT(dxx);
//        OUT(dyy);
        int remain = T%4;
//        OUT(remain);
        REP(i, remain*SZ(aa)){
            if(dir%4 == 0) dyy += a[i];
            if(dir%4 == 1) dxx += a[i];
            if(dir%4 == 2) dyy -= a[i];
            if(dir%4 == 3) dxx -= a[i];
            dir = (dir + a[i]) % 4;
        }
//        OUT(dxx);
//        OUT(dyy);
        return abs(dxx) + abs(dyy);
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
			int T                     = 1;
			int a[]                   = {1,2,3};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int T                     = 100;
			int a[]                   = {1};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int T                     = 5;
			int a[]                   = {1,1,2};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int T                     = 1000000000;
			int a[]                   = {100};
			long long expected__      = 100000000000LL;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int T                     = 570;
			int a[]                   = {2013,2,13,314,271,1414,1732};
			long long expected__      = 4112;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int T                     = ;
			int a[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int T                     = ;
			int a[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int T                     = ;
			int a[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RobotHerb().getdist(T, vector <int>(a, a + (sizeof a / sizeof a[0])));
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
// Robot Herb is playing on an infinite square grid.
At any moment, Herb stands on one of the squares and he faces one of the four cardinal directions.
In his memory, Herb has a program.
The program is a sequence of commands.
For each i, the i-th of these commands has the following form:

First move forward a[i] tiles.
Then turn 90 degrees to the right, a[i] times in a row.

Herb has decided to run the program T times.
You are given the int T and the vector <int> a that describes Herb's program.
Let A be the initial position of Herb and B be his position after the program was executed T times. Return the Manhattan distance between tiles A and B.

DEFINITION
Class:RobotHerb
Method:getdist
Parameters:int, vector <int>
Returns:long long
Method signature:long long getdist(int T, vector <int> a)


NOTES
-Let's introduce a Cartesian coordinate system on the grid so that each cardinal direction is parallel to one of the axes. The Manhattan distance between two tiles with centers at points (x1, y1) and (x2, y2) is defined as |x1-x2| + |y1-y2|.


CONSTRAINTS
-T will be between 1 and 1,000,000,000, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
1
{1,2,3}

Returns: 2

Suppose that initially Herb stands on the tile with center at (0, 0) and faces the positive y direction. The program will get executed as follows:

                       tile         direction
After 1st command:     (0, 1)       positive x
After 2nd command:     (2, 1)       negative x
After 3rd command:     (-1, 1)      negative y

The manhattan distance between the initial and the final positions is |-1| + |1| = 2.

1)
100
{1}

Returns: 0



2)
5
{1,1,2}

Returns: 10



3)
1000000000
{100}

Returns: 100000000000

The answer doesn't fit into a 32-bit integer data type.

4)
570
{2013,2,13,314,271,1414,1732}

Returns: 4112



*/

// END CUT HERE
