
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

int INF = (1<<29);
int n;
int t1[310][310], t2[310][310];

class TreeUnion {
public:
   double expectedCycles( vector <string> tree1, vector <string> tree2, int K ) {
	stringstream ss1, ss2;
	REP(i, SZ(tree1)) ss1 << tree1[i];
	REP(i, SZ(tree2)) ss2 << tree2[i];
	REP(i, 310) REP(j, 310) t1[i][j] = t2[i][j] = INF;
	n = 1; int node1, node2;
	while(ss1 >> node1 && ss2 >> node2){
		t1[node1][n] = 1;
		t1[n][node1] = 1;
		t2[node2][n] = 1;
		t2[n][node2] = 1;
		n++;
	}
	REP(i, n) t1[i][i] = t2[i][i] = 0;
	REP(k, n) REP(i, n) REP(j, n) t1[i][j] = min(t1[i][j], t1[i][k]+t1[k][j]), t2[i][j] = min(t2[i][j], t2[i][k]+t2[k][j]);
	
	double res = 0.0;
	map<int, int> m;
	REP(i, n) for(int j = i+1; j < n; j++) m[t2[i][j]]++;
	REP(i, n) for(int j = i+1; j < n; j++) res += m[K-t1[i][j]-2]/(n*(n-1.0)/2);
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
			string tree1[]            = {"0"};
			string tree2[]            = {"0"};
			int K                     = 4;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string tree1[]            = {"0 1"};
			string tree2[]            = {"0 1"};
			int K                     = 4;
			double expected__         = 1.3333333333333333;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string tree1[]            = {"0 1"};
			string tree2[]            = {"0 1"};
			int K                     = 6;
			double expected__         = 0.3333333333333333;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string tree1[]            = {"0 ", "1 1 1"};
			string tree2[]            = {"0 1 0 ", "1"};
			int K                     = 5;
			double expected__         = 4.0;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string tree1[]            = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"};
			string tree2[]            = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"};
			int K                     = 7;
			double expected__         = 13.314285714285713;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string tree1[]            = ;
			string tree2[]            = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string tree1[]            = ;
			string tree2[]            = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string tree1[]            = ;
			string tree2[]            = ;
			int K                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TreeUnion().expectedCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
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
// This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.

Manao is studying graph theory and simple cycles in particular. A simple cycle of length L ? 3 in graph G is a sequence of vertices (v0, v1, ..., vL-1) such that all v0, v1, ..., vL-1 are pairwise distinct and for each i=0..L-1, an edge between vi and v(i+1) mod L exists in G.

Manao is interested in graphs formed by connecting two trees. The connection process is as follows. Manao takes two trees composed of N vertices each. The vertices in each tree are labeled from 0 to N - 1. Then, he generates a permutation P of numbers from 0 to N - 1 uniformly at random. Finally, the graph is formed by connecting vertex i of the first tree to vertex P[i] of the second tree, for each i from 0 to N - 1. To remove ambiguity, the vertices of the first tree within the graph are referred to as A0, A1, ..., AN-1 and the vertices of the second graph are referred to as B0, B1, ..., BN-1. Manao wants to know the expected number of simple cycles of length K in the resulting graph.

You are given two vector <string>s, tree1 and tree2. Merge the elements of tree1 to obtain a single string formatted as a space-separated list of N - 1 integers describing the first tree. Let x[i] denote the i-th integer (0-based index) in the list. Then, for each i, we have 0 ? x[i] ? i and in our tree the vertices x[i] and i+1 are connected by an edge. tree2 describes the second tree in the same fashion.
Compute and return the expected number of simple cycles of length K in the graph formed by connecting the two given trees as described above. Two simple cycles are equal if one of them can be cyclically shifted, or reversed and cyclically shifted, to coincide with the second. According to this definition, (1, 2, 3, 4), (2, 3, 4, 1) and (3, 2, 1, 4) are all equal.

DEFINITION
Class:TreeUnion
Method:expectedCycles
Parameters:vector <string>, vector <string>, int
Returns:double
Method signature:double expectedCycles(vector <string> tree1, vector <string> tree2, int K)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-The concatenation of elements of tree1 will be formatted as a space-separated list of N - 1 integers, where N is between 2 and 300, inclusive.
-tree1 will contain between 1 and 50 elements, inclusive.
-Each element of tree1 will be between 1 and 50 characters long, inclusive.
-For each i, the i-th integer (0-based index) in the concatenation of elements of tree1 will be between 0 and i, inclusive, and will have no extra leading zeros.
-The concatenation of elements of tree2 will be formatted as a space-separated list of N - 1 integers, where N is between 2 and 300, inclusive.
-tree2 will contain between 1 and 50 elements, inclusive.
-Each element of tree2 will be between 1 and 50 characters long, inclusive.
-For each i, the i-th integer (0-based index) in the concatenation of elements of tree2 will be between 0 and i, inclusive, and will have no extra leading zeros.
-K will be between 3 and 7, inclusive.


EXAMPLES

0)
{"0"}
{"0"}
4

Returns: 1.0

Manao has two trees with two vertices each. He can connect them in two ways:



Either way, the resulting graph is a single cycle of length 4.

1)
{"0 1"}
{"0 1"}
4

Returns: 1.3333333333333333

Manao has two chains composed of three vertices each. There are 6 possible permutations which result in the following graphs:



Each of the two graphs shown in the topmost row contains two cycles of length 4.
(Note that in each case the two cycles share the edge A1B1.)
Each of the other four graphs only contains one cycle of length 4.
Thus the expected number of cycles of length 4 is (2+2+1+1+1+1)/6 = 8/6 = 1.3333333333.

2)
{"0 1"}
{"0 1"}
6

Returns: 0.3333333333333333

These are the same trees as in the previous example, but this time Manao is looking for simple cycles with 6 vertices. Only the topmost two graphs contain a cycle of length 6, thus the expected number of such cycles for a random permutation P is 1/3.

3)
{"0 ", "1 1 1"}
{"0 1 0 ", "1"}
5

Returns: 4.0

The corresponding trees are these:




4)
{"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"}
{"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"}
7

Returns: 13.314285714285713

Do not forget to concatenate the elements of the lists first.

*/

// END CUT HERE
