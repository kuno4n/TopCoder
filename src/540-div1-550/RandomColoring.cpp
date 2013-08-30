
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

double dp[42][52][52][52]; 
double imos[3][52][52][52];

int cal_pt(int from, int d, int op, int mx){
	if(d == 0) return from;
	int res = from + d*op + (op == -1 ? 1 : 0);
	chmax(res, 0);
	chmin(res, mx);
	return res;
}

int cal_len(int from, int d, int mx){
	int a = max(0, from - d);
	int b = min(mx, from + d);
	return max(0, b - a + 1);
}

class RandomColoring {
public:
   double getProbability( int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2 ) {
	MSET(dp, 0);
	dp[0][startR][startG][startB] = 1.0;
	for(int i = 0; i < N-1; i++){
		MSET(imos, 0);
		
		REP(r, maxR) REP(g, maxG) REP(b, maxB){
//			OUT(i);
//			OUT(r);
//			OUT(g);
//			OUT(b);
//			OUT(dp[i][r][g][b]);
//			cout << endl;
			
			//sum
			int d1r = cal_len(r, d1-1, maxR-1);
			int d1g = cal_len(g, d1-1, maxG-1);
			int d1b = cal_len(b, d1-1, maxB-1);
			int d2r = cal_len(r, d2, maxR-1);
			int d2g = cal_len(g, d2, maxG-1);
			int d2b = cal_len(b, d2, maxB-1);
			int sum = d2r*d2g*d2b - d1r*d1g*d1b;
			if(sum == 0) continue;
			
			//d1
			for(int x = -1; x <= 1; x += 2) for(int y = -1; y <= 1; y += 2) for(int z = -1; z <= 1; z += 2){
				int nr = cal_pt(r, d1, x, maxR);
				int ng = cal_pt(g, d1, y, maxG);
				int nb = cal_pt(b, d1, z, maxB);
				imos[0][nr][ng][nb] += x*y*z*dp[i][r][g][b]/sum;
			}
			
			//d2
			for(int x = -1; x <= 1; x += 2) for(int y = -1; y <= 1; y += 2) for(int z = -1; z <= 1; z += 2){
				int nr = cal_pt(r, d2+1, x, maxR);
				int ng = cal_pt(g, d2+1, y, maxG);
				int nb = cal_pt(b, d2+1, z, maxB);
				imos[0][nr][ng][nb] -= x*y*z*dp[i][r][g][b]/sum;
//				OUT(nr);
//				OUT(ng);
//				OUT(nb);
//				cout << endl;
			}
		}
		
		
		REP(g, maxG) REP(b, maxB){
			double buf = 0;
			REP(r, maxR) buf += imos[0][r][g][b], imos[1][r][g][b] += buf;
		}
		REP(r, maxR) REP(b, maxB){
			double buf = 0;
			REP(g, maxG) buf += imos[1][r][g][b], imos[2][r][g][b] += buf;
		}
		REP(r, maxR) REP(g, maxG){
			double buf = 0;
			REP(b, maxB) buf += imos[2][r][g][b], dp[i+1][r][g][b] += buf;
		}
	}
	
	
	double res = 0.0;
	REP(i, maxR) REP(j, maxG) REP(k, maxB){
		if( abs(i - startR) > d2 || abs(j - startG) > d2 || abs(k - startB) > d2 ||
		   (abs(i - startR) < d1 && abs(j - startG) < d1 && abs(k - startB) < d1))
		   res += dp[N-1][i][j][k];
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
			int N                     = 2;
			int maxR                  = 5;
			int maxG                  = 1;
			int maxB                  = 1;
			int startR                = 2;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 0;
			int d2                    = 1;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int maxR                  = 5;
			int maxG                  = 1;
			int maxB                  = 1;
			int startR                = 2;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 0;
			int d2                    = 1;
			double expected__         = 0.22222222222222227;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 7;
			int maxR                  = 4;
			int maxG                  = 2;
			int maxB                  = 2;
			int startR                = 0;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 3;
			int d2                    = 3;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int maxR                  = 7;
			int maxG                  = 8;
			int maxB                  = 9;
			int startR                = 1;
			int startG                = 2;
			int startB                = 3;
			int d1                    = 0;
			int d2                    = 10;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 10;
			int maxR                  = 7;
			int maxG                  = 8;
			int maxB                  = 9;
			int startR                = 1;
			int startG                = 2;
			int startB                = 3;
			int d1                    = 4;
			int d2                    = 10;
			double expected__         = 0.37826245943967396;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 3;
			int maxR                  = 3;
			int maxG                  = 2;
			int maxB                  = 2;
			int startR                = 1;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 1;
			int d2                    = 2;
			double expected__         = 0.09090909090909148;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
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
// Little Arthur has built a new fence around his house and now it is time to color it.

The fence consists of N planks numbered 0 to N-1 such that i-th plank is adjacent to planks i-1 and i+1 (modulo N) for all i between 0 and N-1, inclusive.

Each of the planks in the fence has to be colored using a single color. Different planks may have different colors. Each color is defined by three integer components: R, G, and B (meaning red, green, and blue, respectively), where 0 <= R < maxR, 0 <= G < maxG, and 0 <= B < maxB. Arthur can use any of the maxR*maxG*maxB possible colors.

Arthur likes random patterns. Therefore he has devised the following randomized method of coloring the fence:

In the first step he colors plank 0 using the color with components startR, startG, startB.
Next, for each i from 1 to N-1, in this order, he does the following: He looks at the (already determined) color C of the plank (i-1). The color for plank i is chosen uniformly at random among all colors that make a good transition from the color C. (Good transitions are defined below.)


A transition from color (R, G, B) to color (R', G', B') is called good if all components differ by at most d2 units (formally, |R - R'| <= d2, |G - G'| <= d2, |B - B'| <= d2) and at least one component differs by at least d1 units (formally, at least one of the conditions |R - R'| >= d1, |G - G'| >= d1, |B - B'| >= d1 holds). Intuitively, a transition between two colors is called good if they are neither too similar, nor too different.

Unfortunately, Arthur hasn't realized that after coloring all planks the transition from plank (N-1) to plank 0 does not have to be good. (Note that the fence is cyclic and thus these two planks are adjacent.) If that happens, the fence will look ugly.

Given ints N, maxR, maxG, maxB, startR, startG, startB, d1, and d2, return the probability that the fence will be ugly. (I.e., the probability that the transition from the color of plank (N-1) to the color of plank 0 is not good.)

DEFINITION
Class:RandomColoring
Method:getProbability
Parameters:int, int, int, int, int, int, int, int, int
Returns:double
Method signature:double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.
-It is given that there exists at least one color that makes a good transition from the color (startR, startG, startB). Using this fact it can be proven that during the coloring process it is impossible to reach a state where there is no color that makes a good transition from the current plank's color. I.e. the coloring process cannot stop before coloring all the planks.


CONSTRAINTS
-N will be between 2 and 40, inclusive.
-maxR, maxG, maxB, will be between 1 and 50, inclusive.
-startR will be between 0 and maxR-1, inclusive.
-startG will be between 0 and maxG-1, inclusive.
-startB will be between 0 and maxB-1, inclusive.
-d1 and d2 will be between 0 and 50, inclusive.
-d1 will be less than or equal to d2.
-It is guaranteed that there will exist at least one valid color that makes a good transition from color (startR, startG, startB).


EXAMPLES

0)
2
5
1
1
2
0
0
0
1

Returns: 0.0

In this test case there are only two planks. Plank 1 will surely be colored using a color that makes a good transition from the color of plank 0. By symmetry, the transition from plank 1 color to plank 0 color has to be good as well. The fence will never be ugly.

1)
3
5
1
1
2
0
0
0
1

Returns: 0.22222222222222227

Only the R component can change here. There are nine ways how to color the planks 0, 1, and 2: 
(2, 0, 0) - (1, 0, 0) - (0, 0, 0)
(2, 0, 0) - (1, 0, 0) - (1, 0, 0)
(2, 0, 0) - (1, 0, 0) - (2, 0, 0)
(2, 0, 0) - (2, 0, 0) - (1, 0, 0)
(2, 0, 0) - (2, 0, 0) - (2, 0, 0)
(2, 0, 0) - (2, 0, 0) - (3, 0, 0)
(2, 0, 0) - (3, 0, 0) - (2, 0, 0)
(2, 0, 0) - (3, 0, 0) - (3, 0, 0)
(2, 0, 0) - (3, 0, 0) - (4, 0, 0)

All of these ways are equally likely. In two of them the transition from the color of plank 2 to the color of plank 0 is not good. Thus the probability of having an ugly fence is 2/9.

2)
7
4
2
2
0
0
0
3
3

Returns: 1.0

As the number of planks is odd, Arthur will certainly have an ugly fence.

3)
10
7
8
9
1
2
3
0
10

Returns: 0.0

For any pair of colors the transition between them is good. The fence cannot be ugly.

4)
10
7
8
9
1
2
3
4
10

Returns: 0.37826245943967396

5)
3
3
2
2
1
0
0
1
2

Returns: 0.09090909090909148



*/

// END CUT HERE
