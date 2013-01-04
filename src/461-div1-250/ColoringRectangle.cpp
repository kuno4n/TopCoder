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

int res, w, h;


void calc(VI v1, VI v2){
    int i = 0;
    double covered = 0.0;
//    double v1prev = 0.0, v2prev = 0.0;
    while(1){
        if(i == SZ(v1)) return;
        if(v1[i] < h) return;
        double cover = sqrt(v1[i]*v1[i] - h*h);
        double pt = covered + cover/2;
//        if(v1prev != 0.0 && pt - (double)v1[i]/2 < v1prev) return;
        covered += cover;
        if(covered >= w){
            res = min(res, i*2+1);
            return;
        }
//        v1prev = pt + (double)v1[i]/2;
        
        
        if(i == SZ(v2)) return;
        if(v2[i] < h) return;
         cover = sqrt(v2[i]*v2[i] - h*h);
         pt = covered + cover/2;
//        if(v2prev != 0.0 && pt - (double)v2[i]/2 < v2prev) return;
        covered += cover;
        if(covered >= w){
            res = min(res, i*2+2);
            return;
        }
//        v2prev = pt + (double)v2[i]/2;
        
        i++;
    }
    return;
}


class ColoringRectangle {
	public:
	int chooseDisks(int width, int height, vector <int> red, vector <int> blue) {
		sort(ALL(red), greater<int>());
        sort(ALL(blue), greater<int>());
        
        w = width, h= height;
        res = (1<<31)-1;

        calc(red, blue);
        calc(blue, red);
        
        
        if(res == (1<<31)-1) return -1;
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
			int width                 = 11;
			int height                = 3;
			int red[]                 = {5,5};
			int blue[]                = {2,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 30;
			int height                = 5;
			int red[]                 = {4,10,7,8,10};
			int blue[]                = {5,6,11,7,5};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 16;
			int height                = 4;
			int red[]                 = {6,5,7};
			int blue[]                = {5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int width                 = 4;
			int height                = 4;
			int red[]                 = {5};
			int blue[]                = {6};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int width                 = 6;
			int height                = 2;
			int red[]                 = {6,6};
			int blue[]                = {2};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are given a white rectangle of size width by height. A green horizontal line (parallel to the width of the rectangle) is drawn through the middle of the rectangle so that it divides the rectangle into two congruent rectangles. This line extends infinitely out of the rectangle. You are asked to place red and blue disks (a disk is a circle and its interior) on the rectangle so that the entire rectangle is covered. The center of every disk must be placed on the green line, not necessarily within the rectangle bounds. Disks are placed sequentially from left to right, i.e., the center of each next placed disk must lie strictly to the right of the center of the last previously placed disk. Each disk is placed on top of all previously placed disks, i.e., when a disk is placed it covers any parts of previously placed disks that overlap. To challenge yourself, you have decided to only allow disk placements that satisfy the following additional constraint.


Every point covered by a newly placed disk must either

 not be covered by any previous disk or
 if covered by some previous disk then the topmost previous disk covering this point must be a different color than the newly placed disk.

You are given vector <int> red and vector <int> blue. The number of elements in red and blue corresponds to the number of red and blue disks you have, respectively. Each element of red or blue is the diameter of a red or blue disk, respectively. Note that each disk can only be used at most once. Find the smallest number of disks that can be placed as described above such that every point in the rectangle is covered by at least one disk. Return -1 if this is not possible.

DEFINITION
Class:ColoringRectangle
Method:chooseDisks
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int chooseDisks(int width, int height, vector <int> red, vector <int> blue)


CONSTRAINTS
-width and height will be between 1 and 10000, inclusive.
-red will contain between 1 and 50 elements, inclusive.
-blue will contain between 1 and 50 elements, inclusive.
-Every element of red will be between 1 and 10000, inclusive.
-Every element of blue will be between 1 and 10000, inclusive.
-To avoid precision problems, if the answer for an input is X >= 1, then it will be possible to cover a rectangle with height of height and width of width + 1e-5 with X disks (given the same set of disks). Furthermore, for any input with answer X, it will not be possible to cover a rectangle with height of height and width of width - 1e-5 using fewer than X disks from the same set (or using any amount of disks if X is -1).


EXAMPLES

0)
11
3
{5,5}
{2,5}

Returns: 3

A possible placement is as follows:


1)
30
5
{4,10,7,8,10}
{5,6,11,7,5}

Returns: 4



2)
16
4
{6,5,7}
{5}

Returns: -1

There are not enough blue disks.

3)
4
4
{5}
{6}

Returns: 1

The blue disk alone is enough to cover the rectangle.

4)
6
2
{6,6}
{2}

Returns: 3



*/

// END CUT HERE
