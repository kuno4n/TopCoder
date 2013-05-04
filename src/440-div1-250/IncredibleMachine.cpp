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

class IncredibleMachine {
	public:
	double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
		double lo = 0.0, hi = 1000000000.0;
        
        REP(z, 200){
            double g = (lo + hi) / 2;
            double t = 0.0;
            double v = 0.0;
            for(int i = 1; i < SZ(x); i++){
                double xx = (double)x[i] - x[i-1];
                double yy = (double)y[i-1] - y[i];
                double d = sqrt(xx*xx + yy*yy);
                double sin = yy / d;
                double a = g * sin;
                double tt = (-v + sqrt(v*v + 2*a*d)) / a;
                t += tt;
                v += a * tt;
            }
            if(t < T) hi = g;
            else lo = g;
        }
        return lo;
        
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
			int x[]                   = {0,6};
			int y[]                   = {100,22};
			int T                     = 4;
			double expected__         = 9.807692307692307;

			clock_t start__           = clock();
			double received__         = IncredibleMachine().gravitationalAcceleration(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,26,100};
			int y[]                   = {50,26,24};
			int T                     = 4;
			double expected__         = 26.743031720603582;

			clock_t start__           = clock();
			double received__         = IncredibleMachine().gravitationalAcceleration(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0,7,8};
			int y[]                   = {10,6,0};
			int T                     = 7;
			double expected__         = 1.1076837407708007;

			clock_t start__           = clock();
			double received__         = IncredibleMachine().gravitationalAcceleration(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int x[]                   = ;
			int y[]                   = ;
			int T                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = IncredibleMachine().gravitationalAcceleration(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			int T                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = IncredibleMachine().gravitationalAcceleration(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int T                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = IncredibleMachine().gravitationalAcceleration(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), T);
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
// You may remember an old computer game called "The Incredible Machine".  It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.  Moreover, you were able to perform these observations with different values for gravitational acceleration.

We are observing a system with some unknown acceleration of gravity.  There is a slope which has the form of a polyline with N vertices.  Each vertex of the polyline is positioned lower and to the right of the previous one.  At time 0, a ball is placed at the first vertex.  The ball is small enough to be considered a single point.  Assume that there's no friction between the slope and the ball, the ball is absolutely nonelastic, and the direction of its velocity changes instantly at the polyline's vertices.  Under these conditions, the ball will follow the polyline without ever losing contact with it.  The ball reaches the final vertex at time T.

You are given vector <int>s x and y, where (x[i], y[i]) are the coordinates of the i-th vertex.  Return the gravitational acceleration in this system.  A body rolling down an inclined plane of angle alpha (measured between the plane and horizontal direction) under gravitational acceleration g has a constant acceleration of a = g * sin(alpha). The distance d travelled by an object during time t moving with initial velocity v0 and with constant acceleration a is equal to d = v0 * t + 0.5 * a * t^2. The velocity v1 of the object after time t has passed is equal to v1 = v0 + a * t.

DEFINITION
Class:IncredibleMachine
Method:gravitationalAcceleration
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double gravitationalAcceleration(vector <int> x, vector <int> y, int T)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-Elements of x will be strictly ascending.
-Elements of x will be between 0 and 100, inclusive.
-x and y will contain the same number of elements.
-Elements of y will be strictly descending.
-Elements of y will be between 0 and 100, inclusive.
-T will be between 1 and 100, inclusive.


EXAMPLES

0)
{0,6}
{100,22}
4

Returns: 9.807692307692307

That's an acceleration of gravity that might be somewhere on Earth's surface.


1)
{0,26,100}
{50,26,24}
4

Returns: 26.743031720603582

And this is likely on Jupiter.


2)
{0,7,8}
{10,6,0}
7

Returns: 1.1076837407708007

Note that in spite of the angle at vertex (7,6), the body won't fly off the slope and will follow the segment (7,6)-(8,0).



*/

// END CUT HERE
