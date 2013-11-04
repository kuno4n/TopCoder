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

class FoxAndBusiness {
	public:
	double minimumCost(int K, int totalWork, vector <int> a, vector <int> p) {
        int n = SZ(a);
		double lo = 0;
        double hi = 1e20;
        REP(_, 1000){
            double md = (lo + hi) / 2;
            vector<double> tmp;
            REP(i, n) tmp.push_back(a[i]*md - (double)a[i]*p[i]);
            sort(ALL(tmp));
            reverse(ALL(tmp));
            double sum = 0;
            REP(i, K) sum += tmp[i];
            if(sum >= 3600*K) hi = md;
            else lo = md;
        }
        return hi * totalWork;
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
			int K                     = 1;
			int totalWork             = 10;
			int a[]                   = {10};
			int p[]                   = {20};
			double expected__         = 3800.0;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int K                     = 1;
			int totalWork             = 100;
			int a[]                   = {50, 60};
			int p[]                   = {1000, 2000};
			double expected__         = 107200.0;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int K                     = 2;
			int totalWork             = 300;
			int a[]                   = {10, 20, 47};
			int p[]                   = {15, 20, 98765};
			double expected__         = 77500.0;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int K                     = 4;
			int totalWork             = 1000;
			int a[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int p[]                   = {20, 30, 40, 58, 60, 70, 80, 90, 100, 150};
			double expected__         = 531764.705882353;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int K                     = ;
			int totalWork             = ;
			int a[]                   = ;
			int p[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int K                     = ;
			int totalWork             = ;
			int a[]                   = ;
			int p[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int K                     = ;
			int totalWork             = ;
			int a[]                   = ;
			int p[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxAndBusiness().minimumCost(K, totalWork, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])));
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
// Fox Jiro and Eel Saburo are good friends. They work in the same company as partners.
Currently, they have totalWork units of work that needs to be done.
The work can be divided arbitrarily, even into pieces containing a non-integer number of units.

Jiro and Saburo will not be doing the work themselves.
They have N employees, numbered 0 through N-1.
Each employee has two parameters:

The ability a[i]: the number of units of work he or she can do in one hour.
The pay p[i]: the amount (in yen) he or she has to be paid for each unit of work done.

Jiro and Saburo have to select exactly K of their employees to do the work.
Due to the local laws, they are not allowed to divide the work among the employees arbitrarily:
Each of the K employees must work for exactly the same time.
(Note that different employees may make different amounts of work in that time.)

Additionally, all the work has to be done on a single machine.
Jiro and Saburo do not own such a machine, but they can rent one.
The machine can be rented for an arbitrary (possibly also non-integer) number of seconds, and the rent is 1 yen per second.
(Note that the employees will have to use the machine sequentially, i.e., one after another.)

You are given the int K, the int totalWork, the vector <int> a, and the vector <int> p.
Find and return the smallest amount for which Jiro and Saburo can get all the work done. (Note that the total amount consists of two parts: the money paid to the selected employees, and the money paid for renting the machine.)

DEFINITION
Class:FoxAndBusiness
Method:minimumCost
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double minimumCost(int K, int totalWork, vector <int> a, vector <int> p)


NOTES
-The returned value must be accurate to within a relative or absolute error of 1e-9.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-a and p will each contain exactly N elements.
-Each element of a will be between 1 and 100,000, inclusive.
-Each element of p will be between 1 and 100,000, inclusive.
-K will be between 1 and N, inclusive.
-totalWork will be between 1 and 100,000, inclusive.


EXAMPLES

0)
1
10
{10}
{20}

Returns: 3800.0

We have to select the only employee.
For 10 units of work we have to pay him 10 * 20 = 200 yen.
The work will take him 10/10 = 1 hour.
We need to rent the machine for 1 hour = 3600 seconds, this will cost 3600 yen.
The total amount is 200 + 3600 = 3800 yen.

1)
1
100
{50, 60}
{1000, 2000}

Returns: 107200.0

Employee 0 is the better choice.

2)
2
300
{10, 20, 47}
{15, 20, 98765}

Returns: 77500.0

Employee 2 is the fastest worker, but she is way too expensive.
The optimal solution is to select employees 0 and 1.
Out of the 300 units of work, employee 0 will get 100 and employee 1 will get 200.
This way, each of them will work for exactly 10 hours.
The total we have to pay: 100*15 yen to employee 0, 200*20 yen to employee 1, and 72000 yen for renting the machine for 20 hours.

3)
4
1000
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
{20, 30, 40, 58, 60, 70, 80, 90, 100, 150}

Returns: 531764.705882353



*/

// END CUT HERE
