
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

VI G[55], p, r;
int n;

double dfs(int node, int d){
	double res = 1.0;
	int dd = d;
	while(dd > 1){
		res /= dd;
		dd--;
	}
	REP(i, SZ(G[node])) res += dfs(G[node][i], d+1);
	return res;
}

class PrinceXToastbook {
public:
   double eat( vector <int> prerequisite ) {
	p = prerequisite;
	int n = SZ(p);
	REP(i, 55) G[i].clear();
	r.clear();
	REP(i, n){
		if(p[i] >= 0) G[p[i]].push_back(i);
		else r.push_back(i);
	}
	
	double res = 0.0;
	REP(i, SZ(r)) res += dfs(r[i], 1);
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
			int prerequisite[]        = {-1, 0};
			double expected__         = 1.5;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int prerequisite[]        = {-1, 0, 1};
			double expected__         = 1.6666666666666667;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int prerequisite[]        = {1, -1, 1};
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int prerequisite[]        = {1, 0};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int prerequisite[]        = {-1, -1};
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int prerequisite[]        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int prerequisite[]        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int prerequisite[]        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PrinceXToastbook().eat(vector <int>(prerequisite, prerequisite + (sizeof prerequisite / sizeof prerequisite[0])));
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
// Prince Gogo is the charming prince of the Kingdom of Ducks, where slimes and ducks live in peace and harmony.

Today, Prince Gogo purchased N toastbooks, numbered 0 through N-1. Each toastbook contains some knowledge and grants it to the person who eats it. It is known that no two toastbooks contain the same knowledge.

Initially, Gogo doesn't know any of the knowledge inside the toastbooks. He intends to eat them all and gain as many pieces of knowledge as possible. Furthermore, some of the books require a specific piece of knowledge in order to understand its knowledge. This will be given as a vector <int> prerequisite. If there is no required knowledge to understand the toastbook number i, prerequisite[i] will be -1.
Otherwise, prerequisite[i] will be the number of the toastbook that contains the knowledge necessary to understand book i. If Gogo eats some book x without having the required knowledge, he will not gain the knowledge inside the book, even if he later gains the knowledge from the book prerequisite[x].

Unfortunately, Gogo forgot to number the toastbooks when he purchased them. Hence, he is forced to eat all N toastbooks in a random order. Return the expected number of toastbooks that Gogo will understand.

DEFINITION
Class:PrinceXToastbook
Method:eat
Parameters:vector <int>
Returns:double
Method signature:double eat(vector <int> prerequisite)


NOTES
-The expected value of a random variable can be imagined as the average value of very many independent experiments.
-The returned value must have an absolute or relative error less than 10^-9.


CONSTRAINTS
-prerequisite will contain between 2 and 50 elements, inclusive.
-Each element of prerequisite will be between -1 and N-1, inclusive, where N is the number of elements in prerequisite.
-For all i, prerequisite[i] will not be i.


EXAMPLES

0)
{-1, 0}

Returns: 1.5

There are only two possible orders. If Gogo eats book 0 first, he
gains the knowledge in both books. If Gogo eats book 1 first, he
lacks the required knowledge to understand the book 1 when he read it. Hence, he will
only gain the knowledge in book 0. Therefore, the expected number
of books that Gogo will understand is the average of the two, which
is 1.5.

1)
{-1, 0, 1}

Returns: 1.6666666666666667

There are 6 possible orders. The number of books understood is as follows:
0, 1, 2: 3
0, 2, 1: 2
1, 0, 2: 1
1, 2, 0: 1
2, 0, 1: 2
2, 1, 0: 1

Hence, the expected number of books that Gogo will understand is their average, which is (3+2+1+1+2+1)/6 = 10/6.

2)
{1, -1, 1}

Returns: 2.0



3)
{1, 0}

Returns: 0.0

Each book has the other book as a prerequisite. Gogo will not be able to understand either one, regardless of the order in which he eats them.

4)
{-1, -1}

Returns: 2.0



*/

// END CUT HERE
