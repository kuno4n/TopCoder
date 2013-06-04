
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

int n;
vector <string> t1, t2;
int d1[9][9], d2[9][9];

void maketree1(int from, int node, int d){
	d1[from][node] = d;
	REP(i, n) if(t1[node][i] == 'X' && d1[from][i] == -1) maketree1(from, i, d+1);
}
void maketree2(int from, int node, int d){
	d2[from][node] = d;
	REP(i, n) if(t2[node][i] == 'X' && d2[from][i] == -1) maketree2(from, i, d+1);
}


class TreeUnionDiv2 {
public:
   int maximumCycles( vector <string> tree1, vector <string> tree2, int K ) {
	n = SZ(tree1);
	t1 = tree1, t2 = tree2;
	MSET(d1, -1), MSET(d2, -1);
	REP(i, n) maketree1(i, i, 1);
	REP(i, n) maketree2(i, i, 1);
	
	VI v;
	int res = 0;
	REP(i, n) v.push_back(i);
	do{
		int tmp = 0;
		REP(i, n-1) for(int j = i+1; j < n; j++) if(d1[i][j] + d2[v[i]][v[j]] == K) tmp++;
		res = max(res, tmp);
	}while(next_permutation(ALL(v)));
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
			string tree1[]            = {"-X",
 "X-"}
;
			string tree2[]            = {"-X",
 "X-"}
;
			int K                     = 4;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string tree1[]            = {"-X-",
 "X-X",
 "-X-"}
;
			string tree2[]            = {"-X-",
 "X-X",
 "-X-"}
;
			int K                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string tree1[]            = {"-X-",
 "X-X",
 "-X-"};
			string tree2[]            = {"-X-",
 "X-X",
 "-X-"};
			int K                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string tree1[]            = {"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}
;
			string tree2[]            = {"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}
;
			int K                     = 6;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string tree1[]            = {"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}

;
			string tree2[]            = {"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}
;
			int K                     = 7;
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string tree1[]            = ;
			string tree2[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string tree1[]            = ;
			string tree2[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string tree1[]            = ;
			string tree2[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TreeUnionDiv2().maximumCycles(vector <string>(tree1, tree1 + (sizeof tree1 / sizeof tree1[0])), vector <string>(tree2, tree2 + (sizeof tree2 / sizeof tree2[0])), K);
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

Manao is interested in graphs formed by connecting two trees. The connection process is as follows. Manao takes two trees composed of N vertices each. The vertices in each tree are labeled from 0 to N - 1. Then, he generates some permutation P of numbers from 0 to N - 1. Finally, the graph is formed by connecting vertex i of the first tree to vertex P[i] of the second tree, for each i from 0 to N - 1. To remove ambiguity, the vertices of the first tree within the graph are referred to as A0, A1, ..., AN-1 and the vertices of the second graph are referred to as B0, B1, ..., BN-1. Manao wants to know the maximum number of simple cycles of length K which the resulting graph could contain if he chooses P optimally.

You are given two vector <string>s, tree1 and tree2. Both contain N elements, each of them N characters long. The j-th character in the i-th element of tree1 is 'X' if vertices i and j in the first tree are connected and '-' otherwise. tree2 describes the second tree in the same fashion.

Compute and return the maximum possible number of simple cycles of length K in the graph formed by connecting the two given trees as described above. Two simple cycles are equal if one of them can be cyclically shifted, or reversed and cyclically shifted, to coincide with the second. According to this definition, (1, 2, 3, 4), (2, 3, 4, 1) and (3, 2, 1, 4) are all equal.

DEFINITION
Class:TreeUnionDiv2
Method:maximumCycles
Parameters:vector <string>, vector <string>, int
Returns:int
Method signature:int maximumCycles(vector <string> tree1, vector <string> tree2, int K)


CONSTRAINTS
-tree1 and tree2 will each contain N elements, where N is between 1 and 9, inclusive.
-Each element of tree1 and tree2 will be N characters long.
-Each element of tree1 and tree2 will consist of 'X' and '-' characters only.
-tree1[i][i] and tree2[i][i] will be '-' for each i between 0 and N-1.
-tree1[i][j] will be equal to tree1[j][i] for each i, j between 0 and N-1.
-tree2[i][j] will be equal to tree2[j][i] for each i, j between 0 and N-1.
-Both tree1 and tree2 will describe a graph which is a tree.
-K will be between 3 and 7, inclusive.


EXAMPLES

0)
{"-X",
 "X-"}

{"-X",
 "X-"}

4

Returns: 1

Manao has two trees with two vertices each. He can connect them in two ways:



Either way, the resulting graph is a single cycle of length 4.

1)
{"-X-",
 "X-X",
 "-X-"}

{"-X-",
 "X-X",
 "-X-"}

5

Returns: 2

These are the possible six graphs which can be obtained by connecting the two given trees:



Except for the two topmost graphs, all the graphs contain two cycles of length 5.

2)
{"-X-",
 "X-X",
 "-X-"}
{"-X-",
 "X-X",
 "-X-"}
3

Returns: 0

These are the same trees as in the previous example. You can see at the pictures that none of the obtained graphs contains a cycle of length 3.

3)
{"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}

{"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}

6

Returns: 5

When the permutation P is {0, 3, 2, 1, 4}, the resulting graph contains the following five simple cycles of length 6:

A0, A1, A4, B4, B1, B0
A0, A1, A2, B2, B1, B0
A1, A2, B2, B1, B0, B3
A1, A2, B2, B1, B4, A4
A1, A4, B4, B1, B0, B3

The corresponding graph is the following:



4)
{"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}


{"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}

7

Returns: 17



*/

// END CUT HERE
