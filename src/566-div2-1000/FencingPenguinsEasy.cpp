
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


    double EPS = 1e-10;
    
    double add(double a, double b){
        if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
        return a + b;
    }
    
    struct P{
        double x, y;
        P() {}
        P(double x, double y) : x(x), y(y){
        }
        P operator + (P p){
            return P(add(x, p.x), add(y, p.y));
        }
        P operator - (P p){
            return P(add(x, -p.x), add(y, -p.y));
        }
        P operator * (double d){
            return P(x*d, y*d);
        }
        double dot(P p){ // 内積
            return add(x*p.x, y*p.y);
        }
        double det(P p){ // 外積
            return add(x*p.y, -y*p.x);
        }
    };
	
	// CCW : ConterClockWise
	// ３頂点を回った時、反時計回りなら正
	double ccw(P p1, P p2, P p3){
		return (p2-p1).det(p3-p1);
	}
	
	// 三角形の面積。反時計回りなら正
	double triangleArea(P p1, P p2, P p3){
		return ((p2-p1).det(p3-p1))/2;
	}
    

class FencingPenguinsEasy {
public:
   double calculateMinArea( int numPosts, int radius, vector <int> x, vector <int> y ) {
	int pnum = SZ(x);
	bool valid[250][250];
	REP(i, 250) REP(j, 250) valid[i][j] = false;
	
	P pt[250];
	double PI = acos(-1);
	double thi = 0.0;
	REP(i, numPosts){
		pt[i] = P(radius*cos(thi), radius*sin(thi));
		thi += PI*2/numPosts;
	}
	REP(i, numPosts) REP(j, numPosts){
		valid[i][j] = true;
		if(i == j) continue;
		REP(k, pnum) if(ccw(pt[i], pt[j], P(x[k], y[k])) < EPS) valid[i][j] = false;
	} 
	double dp[250][250];
	double INF = (1e50);
	REP(i, 250) REP(j, 250) dp[i][j] = INF;
	REP(i, 250) REP(j, 250) if(valid[i][j]) dp[i][j] = 0;
	for(int dif = 2; dif < numPosts; dif++){
		REP(l, numPosts){
			int r = l + dif; if(r >= numPosts) continue;
			for(int nl = l + 1; nl < r; nl++){
				if(!valid[l][nl]) continue;
				dp[l][r] = min(dp[l][r], dp[nl][r] + triangleArea(pt[l], pt[nl], pt[r]));
			}
		}
	}
	double res = INF;
	REP(l, numPosts) for(int r = l+2; r < numPosts; r++) if(valid[r][l]) res = min(res, dp[l][r]);
	return (res == INF ? -1 : res);
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
			int numPosts              = 3;
			int radius                = 5;
			int x[]                   = {-1};
			int y[]                   = {0};
			double expected__         = 32.47595264191645;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numPosts              = 30;
			int radius                = 5;
			int x[]                   = {6};
			int y[]                   = {0};
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numPosts              = 4;
			int radius                = 5;
			int x[]                   = {2};
			int y[]                   = {1};
			double expected__         = 25.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numPosts              = 4;
			int radius                = 5;
			int x[]                   = {2,-2};
			int y[]                   = {1,-1};
			double expected__         = 50.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numPosts              = 8;
			int radius                = 5;
			int x[]                   = {8};
			int y[]                   = {8};
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int numPosts              = 7;
			int radius                = 10;
			int x[]                   = {9};
			int y[]                   = {1};
			double expected__         = 29.436752637711805;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int numPosts              = 30;
			int radius                = 800;
			int x[]                   = {8,2,100,120,52,67,19,-36};
			int y[]                   = {-19,12,88,-22,53,66,-140,99} ;
			double expected__         = 384778.74757953023;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int numPosts              = ;
			int radius                = ;
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int numPosts              = ;
			int radius                = ;
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int numPosts              = ;
			int radius                = ;
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FencingPenguinsEasy().calculateMinArea(numPosts, radius, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
Paco collects penguins. His penguins like to play and run around on the ice where he lives. In order to keep his penguins safe he decided to construct a single fence enclosure to keep danger out.



Paco's penguins have fallen asleep. Acting quickly Paco placed numPosts posts in a circular configuration on the ice. Each post is placed radius meters from location (0,0). The posts are equally spaced with the first post being placed at location (radius, 0). 



To construct the fencing, Paco will connect some pairs of fence posts using straight fences.
No two segments of the fence are allowed to cross.
In the resulting fencing, each fence post will either be unused, or it will be connected to exactly two other fence posts. In order to minimize the damage his penguins cause to the ice, he would like to minimize the area enclosed by the fence.



In order to keep all his penguins happy Paco would like to have all his penguins in the one single enclosure. Two penguins are in the same enclosure if it is possible to walk from one penguin to the other without crossing a fence. 







You are given two ints numPosts and radius. You are also given two vector <int>s x and y representing the (x,y) location of each of the sleeping penguins. Each penguin is small enough to be considered a point. Compute an return the smallest area of an enclosure that can contain all the penguins. If it is not possible to enclose all the penguins return -1.


DEFINITION
Class:FencingPenguinsEasy
Method:calculateMinArea
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double calculateMinArea(int numPosts, int radius, vector <int> x, vector <int> y)


CONSTRAINTS
-numPosts will be between 3 and 222, inclusive.
-radius will be between 5 and 100,000, inclusive.
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element in x will be between -100,000 and 100,000, inclusive.
-Each element in y will be between -100,000 and 100,000, inclusive.
-No penguin will come within 10^-6 of any potential fencing.
-No two penguins will occupy the same location.


EXAMPLES

0)
3
5
{-1}
{0}

Returns: 32.47595264191645

There is only one possible enclosure that uses all three fence posts.

1)
30
5
{6}
{0}

Returns: -1.0



2)
4
5
{2}
{1}

Returns: 25.0

If the posts are numbered starting from 0 at (radius, 0) and increasing in the counter-clockwise direction. The resulting possible answers would be:

(0,1,2)
(0,1,3)

Both enclosures cover the same area.


3)
4
5
{2,-2}
{1,-1}

Returns: 50.0



4)
8
5
{8}
{8}

Returns: -1.0

It is not possible to enclose this penguin.

Please note that while a penguin can't be located close to a potential fencing (see constraints), it can be located close to or exactly on a straight line passing through any pair of fence posts.

5)
7
10
{9}
{1}

Returns: 29.436752637711805



6)
30
800
{8,2,100,120,52,67,19,-36}
{-19,12,88,-22,53,66,-140,99}


Returns: 384778.74757953023



*/

// END CUT HERE
