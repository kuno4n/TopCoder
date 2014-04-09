#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
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

const int mod = 1000000007;
LL dp[1000010][2];
LL dp2[55][2];
LL dp3[55][2];

class CycleColoring {
public:
   int countColorings( vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K ) {
       MSET(dp, 0);
       dp[0][0] = 1;
       FOR(i, 1, 1000010){
           dp[i][0] = (dp[i-1][1] * (K-1)) % mod;
           dp[i][1] = (dp[i-1][0] + dp[i-1][1] * (K-2)) % mod;
       }
       
       int n = SZ(vertexCount);
       MSET(dp2, 0);
       REP(i, n){
           int m = vertexCount[i];
           int a = toVertex[(i-1+n)%n];
           int b = fromVertex[i];
           if(a == b) dp2[i][0] = dp[m][0];
           else{
               dp2[i][0] = dp[(b-a+m)%m][0] * dp[(a-b+m)%m][0] % mod;
               dp2[i][1] = dp[(b-a+m)%m][1] * dp[(a-b+m)%m][1] % mod;
           }
       }
       MSET(dp3, 0);
       dp3[0][0] = dp2[0][0];
       dp3[0][1] = dp2[0][1];
       FOR(i, 1, n){
           dp3[i][0] = (dp3[i-1][0] * dp2[i][0] % mod + dp3[i-1][1] * (K-1) % mod * dp2[i][1] % mod) % mod;
           dp3[i][1] = (dp3[i-1][0] * dp2[i][1] % mod + dp3[i-1][1] * (K-2) % mod * dp2[i][1] % mod + dp3[i-1][1] * dp2[i][0] % mod) % mod;
       }
       
       return (dp3[n-1][0] * K) % mod;
                                                                          
                                                                          
       
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
			int vertexCount[]         = {3, 3};
			int fromVertex[]          = {0, 0};
			int toVertex[]            = {0, 0};
			int K                     = 3;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int vertexCount[]         = {6};
			int fromVertex[]          = {4};
			int toVertex[]            = {1};
			int K                     = 3;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int vertexCount[]         = {3, 3};
			int fromVertex[]          = {0, 1};
			int toVertex[]            = {1, 2};
			int K                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int vertexCount[]         = {9, 5};
			int fromVertex[]          = {8, 3};
			int toVertex[]            = {0, 2};
			int K                     = 8;
			int expected__            = 589124602;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int vertexCount[]         = {14, 15, 16, 17};
			int fromVertex[]          = {5, 10, 4, 6};
			int toVertex[]            = {10, 3, 14, 10};
			int K                     = 614;
			int expected__            = 818050159;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int vertexCount[]         = {482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590};
			int fromVertex[]          = {59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461};
			int toVertex[]            = {150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331};
			int K                     = 479360784;
			int expected__            = 763634309;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int vertexCount[]         = ;
			int fromVertex[]          = ;
			int toVertex[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int vertexCount[]         = ;
			int fromVertex[]          = ;
			int toVertex[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int vertexCount[]         = ;
			int fromVertex[]          = ;
			int toVertex[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CycleColoring().countColorings(vector <int>(vertexCount, vertexCount + (sizeof vertexCount / sizeof vertexCount[0])), vector <int>(fromVertex, fromVertex + (sizeof fromVertex / sizeof fromVertex[0])), vector <int>(toVertex, toVertex + (sizeof toVertex / sizeof toVertex[0])), K);
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
// This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

Today, Bob is trying to count the colorings of a strange graph. It looks like a cycle of cycles.

The graph has two types of edges -- solid edges and dashed edges.

The edges between the vertices of the original cycles are all solid edges.
The edges that connect cycles together are all dashed edges.

More precisely, the graph consists of N cycles. The cycles are labelled, in order, as C0, C1, ..., CN-1. You are given a vector <int> vertexCount with N elements. Cycle Ci has vertexCount[i] vertices.  The vertices of cycle Ci are labelled, in order, as vi, 0, vi, 1, ..., vi, vertexCount[i]-1. Note that the last vertex in this order is also connected to the first one. All of the edges that form these cycles are solid edges.

You are also given two vector <int>s fromVertex and toVertex, with N elements each. These vector <int>s describe the connection between cycle Ci and Ci+1 as follows:  The vertex in cycle Ci with label vi, fromVertex[i] and the vertex in cycle Ci+1 with label vi+1, toVertex[i] will be connected with a dashed edge.

Bob has K distinct colors.  He wants to know how many different ways there are to color the vertices of the graph under the following two rules:

  Vertices connected with a solid edge must be colored using a different color.
  Vertices connected with a dashed edge must be colored using the same color.


Two colorings are considered different if there is a vertex vi, j which has a different color in each coloring. Let C be the number of colorings that correspond to the given rules. As C can be extremely large, you should compute and return the value (C modulo 1,000,000,007).

DEFINITION
Class:CycleColoring
Method:countColorings
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K)


NOTES
-i+1 is considered modulo N - hence, references to cycle CN are referring to cycle C0.


CONSTRAINTS
-vertexCount will contain between 1 and 50 elements, inclusive.
-vertexCount, fromVertex, and toVertex will all contain the same number of elements.
-Each element of vertexCount will be between 3 and 1,000,000, inclusive.
-Element fromVertex[i] will be between 0 and vertexCount[i] - 1, inclusive.
-Element toVertex[i] will be between 0 and vertexCount[i+1] - 1, inclusive.
-K will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3, 3}
{0, 0}
{0, 0}
3

Returns: 12

This graph consists of two cycles of length 3. There are two dashed edges, each connecting vertex 0 of one cycle to vertex 0 of the other cycle. These two vertices must share the same color. We have 3 possibilities for that color. Once we fix it, we have 2 possibilities how to color the rest of each cycle. Hence, the answer is 3*2*2 = 12.

1)
{6}
{4}
{1}
3

Returns: 12

This graph only has one cycle. Note that for N=1 there is still one dashed edge and it connects two vertices on the same cycle. The 12 valid colorings of the resulting graph correspond to the 12 valid colorings of the graph from Example 0.

2)
{3, 3}
{0, 1}
{1, 2}
3

Returns: 0

Vertices 0 and 2 on cycle 0 must both have the same color as vertex 1 on cycle 1. However, vertices 0 and 2 on cycle 0 are adjacent and therefore must have different colors. This is a contradiction. Therefore, there are no valid colorings of this graph.

3)
{9, 5}
{8, 3}
{0, 2}
8

Returns: 589124602



4)
{14, 15, 16, 17}
{5, 10, 4, 6}
{10, 3, 14, 10}
614

Returns: 818050159



5)
{482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590}
{59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461}
{150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331}
479360784

Returns: 763634309



*/

// END CUT HERE
