
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

int L, W;
VI wi, sw;

double hyp(int a, double b){
	return sqrt(a*a + b*b);
}

double ternary(double l, int num){
	if(num == 3) return (double)l/W;
	double val1, val2;
	double left = 0, right = l;
	REP(_, 100){
		double p1 = (left*2 + right) / 3;
		double p2 = (left + right*2) / 3;
		val1 = hyp(wi[num], p1) / sw[num] + ternary(l-p1, num+1);
		val2 = hyp(wi[num], p2) / sw[num] + ternary(l-p2, num+1);
		if(val1 > val2) left = p1;
		else right = p2;
	}
	return val1;
}

class EllysThreeRivers {
public:
   double getMin( int length, int walk, vector <int> width, vector <int> swim ) {
	L = length, W = walk;
	wi = width, sw = swim;
	return ternary(L, 0);
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
			int walk                  = 8;
			int width[]               = {5, 2, 3};
			int swim[]                = {5, 2, 7};
			double expected__         = 3.2063518370413364;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int length                = 1000;
			int walk                  = 100;
			int width[]               = {91, 911, 85};
			int swim[]                = {28, 97, 19};
			double expected__         = 21.549321613601297;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int length                = 666;
			int walk                  = 4;
			int width[]               = {777, 888, 999};
			int swim[]                = {11, 12, 13};
			double expected__         = 228.26633673141083;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int length                = 6;
			int walk                  = 100;
			int width[]               = {2, 3, 4};
			int swim[]                = {77, 88, 99};
			double expected__         = 0.12049782476139667;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int length                = 873;
			int walk                  = 54;
			int width[]               = {444, 588, 263};
			int swim[]                = {67, 97, 26};
			double expected__         = 26.365540023205206;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int length                = ;
			int walk                  = ;
			int width[]               = ;
			int swim[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int length                = ;
			int walk                  = ;
			int width[]               = ;
			int swim[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int length                = ;
			int walk                  = ;
			int width[]               = ;
			int swim[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = EllysThreeRivers().getMin(length, walk, vector <int>(width, width + (sizeof width / sizeof width[0])), vector <int>(swim, swim + (sizeof swim / sizeof swim[0])));
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
// Shopping is by no means an easy task. Yes, sure, if you want to buy shoes or some clothes that's no problem at all. But what happens if you would like an extremely rare poison, found only in the mists of Amazonia? Now you see, Elly's life is not as easy as you would think. She has almost reached her final destination, but unfortunately she can only walk and swim in the final part.

There are 4 really long, but narrow parallel islands, going from South to North, numbered from 0 to 3, inclusive. All islands have the same length length. There are also 3 rivers between the islands, numbered from 0 to 2, inclusive. Each river has certain width, given in width. River i flows between islands i and i+1.
For simplicity we can represent the islands as vertical line segments in the plane. The first island goes from point (0, 0) to (0, length), the second one from (width[0], 0) to (width[0], length), the third one from (width[0] + width[1], 0) to (width[0] + width[1], length), and so on, where width[i] is the width of the i-th river.

Elly can walk along any island with a constant speed walk. At any point on the current island, Elly may decide to swim to some point on the next island. (Both points may have non-integer coordinates.) The speed of the water in the rivers is negligible, so Elly's speed while swimming is the same in all directions. However, different rivers may contain different amounts of plants and animals that influence Elly's speed. More precisely, while swimming between islands i and i+1, Elly's speed is swim[i]. Elly is currently on the southmost point of island 0 and wants to reach the northmost point of island 3. She wonders what is the minimal time required to travel to her destination.



You are given the length of the islands (in kilometers) in the int length and Elly's walking speed (in kilometers per hour) in the int walk. You are also given the vector <int>s width and swim, that give the width (in kilometers) and Elly's swimming speed (in kilometers per hour) for each river, respectively. Return a double denoting the minimal required time (in hours) for Elly to reach her destination.

DEFINITION
Class:EllysThreeRivers
Method:getMin
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double getMin(int length, int walk, vector <int> width, vector <int> swim)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-During her trip, Elly must swim exactly three times.


CONSTRAINTS
-length will be between 1 and 1000, inclusive.
-walk will be between 1 and 100, inclusive.
-width will contain exactly 3 elements.
-swim will contain exactly 3 elements.
-Each element of width will be between 1 and 1000, inclusive.
-Each element of swim will be between 1 and 100, inclusive.


EXAMPLES

0)
10
8
{5, 2, 3}
{5, 2, 7}

Returns: 3.2063518370413364

One optimal way to reach the end point is by swimming from (0, 0) to (5, 4.003203734135),
then walking to (5, 4.050839751462) on island 1, then swimming to (7, 4.567237538143) on island 2,
then swimming to (10, 9.989414218372) on island 2 and walking the rest to (10, 10) on island 3.
The required times are as follows:

(0, 0) -> (5, 4.003203734135) = 6.405126082833 / 5 = 1.281025216567
(5, 4.003203734135) -> (5, 4.050839751462) = 0.047636017327 / 8 = 0.005954502166
(5, 4.050839751462) -> (7, 4.567237538143) = 2.065591119774 / 2 = 1.032795559887
(7, 4.567237538143) -> (10, 9.989414218372) = 6.196773350028 / 7 = 0.885253335718
(10, 9.989414218372) -> (10, 10.000000000000) = 0.010585781628 / 8 = 0.001323222703



1)
1000
100
{91, 911, 85}
{28, 97, 19}

Returns: 21.549321613601297

Even though the walking speed is greater than the swimming speed in all rivers, there is a way to achieve the optimal answer without walking.

2)
666
4
{777, 888, 999}
{11, 12, 13}

Returns: 228.26633673141083



3)
6
100
{2, 3, 4}
{77, 88, 99}

Returns: 0.12049782476139667



4)
873
54
{444, 588, 263}
{67, 97, 26}

Returns: 26.365540023205206

A large random example.

*/

// END CUT HERE
