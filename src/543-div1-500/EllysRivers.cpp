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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

double dp[52][100010];

double sq(double a){
    return a * a;
}

double sh(double a, double b){
    return sqrt(sq(a) + sq(b));
}

class EllysRivers {
	public:
	double getMin(int length, int walk, vector <int> width, vector <int> speed) {
        for(int i = 0; i <= length+1; i++) dp[0][i] = (double)i/walk;
        
        REP(i, SZ(width)){
            int ptr = 0;
            for(int j = 0; j <= length; j++){
                while(1){
                    double t1 = dp[i][ptr]   + sh(width[i], j-ptr  )/speed[i];
                    double t2 = ptr < j ? dp[i][ptr+1] + sh(width[i], j-ptr-1)/speed[i] : (1<<30);
                    if(t1 < t2){
                        dp[i+1][j] = t1;
                        break;
                    }
                    ptr++;
                }
            }
        }
        return dp[SZ(width)][length];
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int length                = 10;
			int walk                  = 3;
			int width[]               = {5, 2, 3};
			int speed[]               = {5, 2, 7};
			double expected__         = 3.231651964071508;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int length                = 10000;
			int walk                  = 211;
			int width[]               = {911};
			int speed[]               = {207};
			double expected__         = 48.24623664712219;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int length                = 1337;
			int walk                  = 2;
			int width[]               = {100, 200, 300, 400};
			int speed[]               = {11, 12, 13, 14};
			double expected__         = 128.57830549575695;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int length                = 77;
			int walk                  = 119;
			int width[]               = {11, 12, 13, 14};
			int speed[]               = {100, 200, 300, 400};
			double expected__         = 0.3842077071089629;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int length                = 7134;
			int walk                  = 1525;
			int width[]               = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
			int speed[]               = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
			double expected__         = 214.6509731258811;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int length                = 100000;
			int walk                  = 1000000;
          int width[]               = {1};
          int speed[]               = {1};
			double expected__         = 1.1;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int length                = ;
			int walk                  = ;
			int width[]               = ;
			int speed[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int length                = ;
			int walk                  = ;
			int width[]               = ;
			int speed[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(speed, speed + (sizeof speed / sizeof speed[0])));
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
// Shopping is by no means an easy task. Yes, sure, if you want to buy shoes or some clothes that's no problem at all. But what happens if you would like an extremely rare poison, found only in the mists of Amazonia? Now you see, Elly's life is not as easy as you would think. She has almost reached her final destination, but unfortunately she can only use boats and travel by foot for the final part.

There are N+1 really long, but narrow parallel islands, going from South to North, numbered from 0 to N, inclusive. There are also N rivers between the islands, numbered from 0 to N-1, inclusive. River i is width[i] kilometers wide and flows between islands i and i+1. The speed of the current in each river is negligible. For river i, the maximum speed at which Elly can sail is speed[i] kilometers per hour, regardless of the direction in which she sails.

All islands are length kilometers long. Starting from the southmost point, each one has boat docks one kilometer apart throughout its entire coastline. Thus, there are length + 1 docks on each island (at kilometer 0, 1, ?, length). The islands are so narrow, that you can assume the same dock serves the boats on both sides of the island, and that walking horizontally from one side of the island to the other takes no time.

For simplicity we can represent the islands as parallel vertical line segments, and the docks as points on the plane. Island 0 goes from point (0, 0) to (0, length), island 1 from (width[0], 0) to (width[0], length), island 2 from (width[0] + width[1], 0) to (width[0] + width[1], length), and so on, where width[i] gives the width of the i-th river. The docks on island 0 are with coordinates (0, 0), (0, 1), ? (0, length); the ones on island 1 are with coordinates (width[0], 0), (width[0], 1), ?, (width[0], length); these on island 2 are with coordinates (width[0] + width[1], 0), (width[0] + width[1], 1), ?, (width[0] + width[1], length) and so on.

Elly can only take boats from dock to dock (i.e. she can neither depart from nor arrive at non-integer coordinates). She can also walk (vertically) along any island with a constant speed of walk kilometers per hour. The girl is currently on the southmost point of the westmost island and wants to reach the northmost point of the eastmost island. Elly wonders what is the minimal time required to travel to her destination. Help her by writing a method that calculates this for her.

You are given the length of the islands in the int length and the walking speed in the int walk. The widths of the rivers will be given in the vector <int> width and the maximal sailing speeds in the vector <int> speed. Return a double giving the shortest time in which she can reach her destination.

DEFINITION
Class:EllysRivers
Method:getMin
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double getMin(int length, int walk, vector <int> width, vector <int> speed)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-length will be between 1 and 100,000, inclusive.
-walk will be between 1 and 1,000,000, inclusive.
-width will contain between 1 and 50 elements, inclusive.
-speed will contain between 1 and 50 elements, inclusive.
-width and speed will contain the same number of elements.
-Each element of width will be between 1 and 1,000,000, inclusive.
-Each element of speed will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
10
3
{5, 2, 3}
{5, 2, 7}

Returns: 3.231651964071508

Elly will not walk on any of the islands. She will sail four kilometers to the north in the first river,
reaching the second island at point (5, 4). Then she sails another one kilometer to the north in the second river,
going to (7, 5) on the third island. In the end she will sail to her destination at (10, 10).
The required times for her journey are as follows:

(0, 0) -> (5, 4) = 6.403124237433 / 5 = 1.280624847487 hours
(5, 4) -> (7, 5) = 2.236067977499 / 2 = 1.118033988749 hours
(7, 5) -> (10, 10) = 5.830951894845 / 7 = 0.832993127835 hours



1)
10000
211
{911}
{207}

Returns: 48.24623664712219

Don't forget that Elly can walk on the islands.

2)
1337
2
{100, 200, 300, 400}
{11, 12, 13, 14}

Returns: 128.57830549575695



3)
77
119
{11, 12, 13, 14}
{100, 200, 300, 400}

Returns: 0.3842077071089629



4)
7134
1525
{11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}
{1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}

Returns: 214.6509731258811

A large random example.

*/

// END CUT HERE
