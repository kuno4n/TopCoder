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

class P8XGraphBuilder {
    int     dp[60][60];
    int n;
	public:
	int solve(vector <int> scores) {
		MSET(dp, 0);
        dp[2][2] = scores[0]*2;
        n = SZ(scores);
        for(int i=1; 2+i<=n+1; i++){
            dp[2+i][2+i-1] = dp[2][2] + scores[0]*i + scores[i] - scores[0];
        }
//        OUT(dp[2][2]);
//        OUT(dp[3][2]);
        for(int leaf=2; leaf<n; leaf++){
            for(int node=leaf+1; node<n+1; node++){
                for(int i=1; node+i<=n+1; i++){
                    dp[node+i][leaf+i-1] = max(dp[node+i][leaf+i-1], dp[node][leaf] + scores[0]*i + scores[i] - scores[0]);
                }
            }
        }
        
        int res = 0;
        REP(i, n+2) {
//            OUT(dp[n+1][i]);
            res = max(res, dp[n+1][i]);
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
			int scores[]              = {1, 3, 0};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int scores[]              = {0, 0, 0, 10};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int scores[]              = {1, 2, 3, 4, 5, 6};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int scores[]              = {5, 0, 0};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int scores[]              = {1, 3, 2, 5, 3, 7, 5};
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int scores[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int scores[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int scores[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

You want to build a graph consisting of N nodes and N-1 edges. The graph must be connected. That is, for each pair of nodes there must be some sequence of edges that connects them. For example, the following picture shows a connected graph with N=5 nodes (dots) and N-1=4 edges (lines connecting pairs of dots):



An edge is adjacent to the two nodes that it connects. The degree of a node in the graph is equal to the number of edges adjacent to the node. For example, the degree of node A in the picture above is 3, while the degree of node B is 1. Note that in your graph the degree of each node will be between 1 and N-1, inclusive.

You are given a vector <int> scores with N-1 elements. The score of a node with degree d is scores[d-1]. The score of a graph is the sum of the scores of its nodes.

Your method should compute and return the maximum possible score for a graph you can construct.


DEFINITION
Class:P8XGraphBuilder
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> scores)


NOTES
-In your solution, the number of nodes N in your graph can be determined as one plus the length of scores.
-In your graph, there must be at most one edge connecting any pair of nodes, and an edge cannot connect a node with itself.


CONSTRAINTS
-scores will contain between 1 and 50 elements, inclusive.
-Each element in scores will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{1, 3, 0}

Returns: 8

As scores contains 3 elements, we are building a graph with N=4 nodes. Nodes of degree 1 have score 1, nodes of degree 2 have score 3, and nodes of degree 3 have score 0.
One possible graph with the highest score looks as follows:



In this graph the degrees of the nodes are 1, 2, 2, 1, respectively. The sum of their scores is 1+3+3+1 = 8.

1)
{0, 0, 0, 10}

Returns: 10

One possible solution for this test case is:


2)
{1, 2, 3, 4, 5, 6}

Returns: 12



3)
{5, 0, 0}

Returns: 15



4)
{1, 3, 2, 5, 3, 7, 5}

Returns: 20



*/

// END CUT HERE
