
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

class PiecewiseLinearFunction {
public:
   int maximumSolutions( vector <int> Y ) {
	int n = SZ(Y);
	REP(i, n-1) if(Y[i] == Y[i+1]) return -1;
	vector <LL> y;
	REP(i, n) y.push_back((LL)Y[i]*2);
	
	int mn = 0;
	REP(i, n) for(int j = -1; j <= 1; j++){
		LL tar = y[i] + j;
		int cnt = 0;
		REP(k, n-1){
			if(y[k] <= tar && tar < y[k+1]) cnt++;
			else if(tar <= y[k] && y[k+1] < tar) cnt++;
		}
		if(y[n-1] == tar) cnt++;
		chmax(mn, cnt);
	}
	return mn;
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
			int Y[]                   = {3, 2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int Y[]                   = {4, 4};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int Y[]                   = {1, 4, -1, 2};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int Y[]                   = {2, 1, 2, 1, 3, 2, 3, 2};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int Y[]                   = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int Y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int Y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int Y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PiecewiseLinearFunction().maximumSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
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
// F is a function that is defined on all real numbers from the closed interval [1,N].
You are given a vector <int> Y with N elements.
For each i (1 <= i <= N) we have F(i) = Y[i-1].
Additionally, you know that F is piecewise linear: for each i, on the interval [i,i+1] F is a linear function.
The function F is uniquely determined by this information.
For example, if F(4)=1 and F(5)=6 then we must have F(4.7)=4.5.

As another example, this is the plot of the function F for Y = {1, 4, -1, 2}.



Given a real number y, we can count the number of solutions to the equation F(x)=y.
For example, for the function plotted above there are 0 solutions for y=7, there is 1 solution for y=4, and there are 3 solutions for y=1.1.
We are looking for the largest number of solutions such an equation can have.
For the function plotted above the answer would be 3: there is no y such that F(x)=y has more than 3 solutions.

If there is an y such that the equation F(x)=y has infinitely many solutions, return -1.
Otherwise, return the maximum possible number of solutions such an equation may have.


DEFINITION
Class:PiecewiseLinearFunction
Method:maximumSolutions
Parameters:vector <int>
Returns:int
Method signature:int maximumSolutions(vector <int> Y)


CONSTRAINTS
-Y will contain between 2 and 50 elements, inclusive.
-Each element of Y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3, 2}

Returns: 1

The graph of this function is a line segment between (1, 3) and (2, 2). For any y such that 2 ? y ? 3 the equation F(x)=y has 1 solution, and for any other y it has 0 solutions.

1)
{4, 4}

Returns: -1

The function's plot is a horizontal line segment between points (1, 4) and (2, 4). For y=4, F(x)=y has infinitely many solutions.

2)
{1, 4, -1, 2}

Returns: 3

This is the example from the problem statement. Three solutions are obtained for any value of y between 1 and 2, inclusive:



3)
{2, 1, 2, 1, 3, 2, 3, 2}

Returns: 5



4)
{125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000}

Returns: 6



*/

// END CUT HERE
