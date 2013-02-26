
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl


int N;

bool G[40][40];
int childcnt[40];
int tree[40][40];

LL dp[40][2][40][40];
LL dp_tmp[2][40][40];

//LL dp_f[40][3][40][40];
//LL dp_g[40][2][40][40][40];
//
//LL f(int root, int parentcol, int sumnode, int sumcomponent);
//LL g(int root, int rootcol, int childnum, int sumnode, int sumcomponent);

void makeTree(int node, int parent){
	REP(i, 40) if(G[node][i] && i != parent){
		tree[node][childcnt[node]++] = i;
		makeTree(i, node);
	}
	return;
}

void dfs(int node){
	REP(child, childcnt[node]) dfs(tree[node][child]);
	dp[node][1][1][1] = 1;
	dp[node][0][0][0] = 1;
	REP(child, childcnt[node]){
		MSET(dp_tmp, 0);
		REP(col, 2) REP(n, N) REP(c, N){
			if(dp[node][col][n][c] == 0) continue;
			REP(col_child, 2) REP(n_child, N) REP(c_child, N){
				if(dp[tree[node][child]][col_child][n_child][c_child] == 0) continue;
				if(col == 1 && col_child == 1) 
					dp_tmp[col][n+n_child][c+c_child-1] += dp[node][col][n][c] * dp[tree[node][child]][col_child][n_child][c_child];
				else dp_tmp[col][n+n_child][c+c_child] += dp[node][col][n][c] * dp[tree[node][child]][col_child][n_child][c_child];
			}
		}
		REP(col, 2) REP(n, N) REP(c, N) dp[node][col][n][c] = dp_tmp[col][n][c];
	}
	return;
}

//LL g(int root, int rootcol, int childnum, int sumnode, int sumcomponent){
//	if(dp_g[root][rootcol][childnum][sumnode][sumcomponent] >= 0)
//		return dp_g[root][rootcol][childnum][sumnode][sumcomponent];
//	LL res = 0;
//
//	if(childnum >= childcnt[root]){
//		if(sumnode == 0 && sumcomponent == 0) res = 1;
//		else res = 0;
//	}
//	else{
//		for(int n = 0; n <= sumnode;  n++){
//			for(int c = 0; c <= sumcomponent; c++){
//				LL ff = f(tree[root][childnum], rootcol, n, c);
//				LL gg = g(root, rootcol, childnum+1, sumnode-n, sumcomponent-c);
//				res += ff*gg;
//			}
//		}
//		
//	}
//
//	return dp_g[root][rootcol][childnum][sumnode][sumcomponent] = res;
//}
//
//LL f(int root, int parentcol, int sumnode, int sumcomponent){
//	if(dp_f[root][parentcol][sumnode][sumcomponent] >= 0)
//		return dp_f[root][parentcol][sumnode][sumcomponent];
//	LL res = 0;
//
//	if(parentcol == 0) // root == 0
//		if(sumnode > 0 && sumcomponent > 0)
//			res += g(root, 1, 0, sumnode-1, sumcomponent-1);
//	if(parentcol == 1)
//		if(sumnode > 0) 
//			res += g(root, 1, 0, sumnode-1, sumcomponent);
//	if(parentcol == 2)
//		if(sumnode > 0 && sumcomponent > 0)
//			res += g(root, 1, 0, sumnode-1, sumcomponent-1);
//		
//	res += g(root, 2, 0, sumnode, sumcomponent);
//
//	return dp_f[root][parentcol][sumnode][sumcomponent] = res;
//}


class CentaurCompany {
public:
   double getvalue( vector <int> a, vector <int> b ) {
	   N = SZ(a) + 1;

	   MSET(G, false);
	   REP(i, SZ(a)){
		   G[a[i]-1][b[i]-1] = true;
		   G[b[i]-1][a[i]-1] = true;
	   }

	   MSET(tree, 0); MSET(childcnt, 0);
	   makeTree(0, -1);

	   MSET(dp, 0); MSET(dp_tmp, 0);
	   dfs(0);


	   //MSET(dp_g, -1); MSET(dp_f, -1);
	   //REP(sumnode, N) REP(sumcomponent, N) f(0, 0, sumnode, sumcomponent);
	   //
	   //LL sum = 0;
	   //REP(sumnode, N) REP(sumcomponent, N) if(dp_f[0][0][sumnode][sumcomponent] > 0)
		  // sum += 2 * (max(0, 2*sumcomponent - sumnode -2)) * dp_f[0][0][sumnode][sumcomponent];
	   //return (double)sum/(1LL<<N);

	   LL sum = 0;
	   REP(col, 2) REP(sumnode, N) REP(sumcomponent, N)
		   sum += 2 * (max(0, 2*sumcomponent - sumnode -2)) * dp[0][col][sumnode][sumcomponent];
	   return (double)sum/(1LL<<N);
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
			int a[]                   = {1};
			int b[]                   = {2};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {1,1,1};
			int b[]                   = {2,3,4};
			double expected__         = 0.125;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {1,2,3,2,2};
			int b[]                   = {2,3,4,5,6};
			double expected__         = 0.375;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {1,2,3,4,5,6,7,8,9};
			int b[]                   = {2,3,4,5,6,7,8,9,10};
			double expected__         = 0.41796875;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int b[]                   = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
			double expected__         = 15.500000001076842;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int a[]                   = {10, 7, 2, 5, 6, 2, 4, 9, 7};
			int b[]                   = {8, 10, 10, 4, 1, 6, 2, 2, 3};
			double expected__         = 0.646484375;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CentaurCompany().getvalue(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
// The Centaur company has N servers, numbered 1 through N.
These servers are currently connected into a network.
The topology of the network is a tree.
In other words, there are exactly N-1 bidirectional cables, each connecting some two servers in such a way that the entire network is connected.

The Centaur company is about to split into two new companies: the Human company and the Horse company.
When this happens, the companies will divide the servers randomly.
More precisely, for each of the N servers the two companies will flip a fair coin, and the winner of the coin flip gets the server.
Once they divide the servers, each company will configure their own servers not to use the cables that lead to the servers of the other company.

Of course, it may then happen that some pairs of servers that belong to the same company will not be able to communicate any more.
Therefore, each of the new companies will then use new, additional cables to connect all of its servers to the same network.
New cables can be added for free.
However, each of the servers currently only has one empty slot into which an end of a cable can be inserted.
Adding one additional empty slot to a server costs 1.
If desired, it is possible to add multiple slots to the same server.
Each of the companies will connect their servers using a way with the smallest possible cost.

You are given two vector <int>s a and b, each containing N-1 elements.
These two arrays describe the original cables:
for each i, there is a cable that connects the servers a[i] and b[i].

Compute and return the expected value of the total cost paid by the two companies to connect their networks.
(The expectation is taken over all possible ways in which they can divide the N servers.)

DEFINITION
Class:CentaurCompany
Method:getvalue
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double getvalue(vector <int> a, vector <int> b)


NOTES
-N can be determined as (1 + the length of a).
-The expected value of a variable can be seen as the average value of the variable, where the average is taken over many rounds of the experiment. See http://en.wikipedia.org/wiki/Expected_value for a formal definition.
-Your return value must have a relative or absolute error of at most 1e-9.


CONSTRAINTS
-N will be between 2 and 36, inclusive.
-a and b will contain exactly N-1 elements.
-Each element of a and b will be between 1 and N, inclusive.
-The network defined by a and b will be a tree (as explained in the problem statement).


EXAMPLES

0)
{1}
{2}

Returns: 0.0

Regardless of the result of the coin flips, the companies don't need additional cables to connect their own servers. Therefore, the expected cost is zero.

1)
{1,1,1}
{2,3,4}

Returns: 0.125

If the Horse company gets only the server 1 and the Human company gets the other servers, the Human company must add one empty slot. For example, the Human company can add one empty slot to the server 2 and add new cables to connect the server 2 with the servers 3 and 4. Similarly, if the Human company gets only the server 1 and the Horse company gets the other servers, the cost will also be 1. In all other cases the cost will be 0. The expected cost is 1/(2^4) + 1/(2^4) = 1/8.

2)
{1,2,3,2,2}
{2,3,4,5,6}

Returns: 0.375

For example, if the Horse company gets only the server 2 and the Human company gets the other servers, the Human company must add one empty slot. In the picture below, initially each server has one empty slot (blue). The Human company adds one extra slot (yellow) to the server 5. The Human company also adds cables that connect the servers 1 and 5, 3 and 5, and 4 and 6.




3)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}

Returns: 0.41796875



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}

Returns: 15.500000001076842



5)
{10, 7, 2, 5, 6, 2, 4, 9, 7}
{8, 10, 10, 4, 1, 6, 2, 2, 3}

Returns: 0.646484375



*/

// END CUT HERE
