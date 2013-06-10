
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

int n;
bool G[60][60];
set<int> table[60][60];
map<pair<int, int>, int> idx;
bool used[60];

void dfs(int start, int now, set<int> s){
	used[now] = true;
	REP(i, n) if(!used[i] && G[now][i]){
		set<int> tmp = s;
		tmp.insert(idx[make_pair(now, i)]);
		table[start][i] = tmp;
		dfs(start, i, tmp);
	}
}

class FoxAndTouristFamilies {
public:
   double expectedLength( vector <int> A, vector <int> B, vector <int> f ) {
	n = SZ(A)+1;
	
	REP(i, 60) REP(j, 60) G[i][j] = false;
	REP(i, n-1) G[A[i]][B[i]] = G[B[i]][A[i]] = true;
	
	idx.clear();
	REP(i, n-1){
		idx[make_pair(A[i], B[i])] = i;
		idx[make_pair(B[i], A[i])] = i;
	}
	
	REP(i, 60) REP(j, 60) table[i][j].clear();
	REP(i, n){
		REP(j, 60) used[j] = false;
		set<int> s;
		dfs(i, i, s);
	}
	
	double res = 0.0;
	REP(i, n-1){
		double tmp = 1.0;
		REP(j, SZ(f)){
			int cnt = 0;
			REP(k, n) if(table[f[j]][k].count(i)) cnt++;
			tmp *= (double)cnt/(n-1);
		}
		res += tmp;
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
			int A[]                   = {0, 1};
			int B[]                   = {1, 2};
			int f[]                   = {0};
			double expected__         = 1.5;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {0, 1};
			int B[]                   = {1, 2};
			int f[]                   = {0, 0};
			double expected__         = 1.25;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {0, 1};
			int B[]                   = {1, 2};
			int f[]                   = {0, 1};
			double expected__         = 0.75;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {0, 1};
			int B[]                   = {1, 2};
			int f[]                   = {0, 2};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {0,0,0};
			int B[]                   = {1,2,3};
			int f[]                   = {0};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {0,0,0};
			int B[]                   = {1,2,3};
			int f[]                   = {1,2};
			double expected__         = 0.7777777777777777;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int A[]                   = {0,1,1,3,5,6};
			int B[]                   = {1,2,3,4,4,4};
			int f[]                   = {5,6,1};
			double expected__         = 0.4537037037037037;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int A[]                   = {0,1,2,3,4,5,6,7,8,9};
			int B[]                   = {1,2,3,4,5,6,7,8,9,10};
			int f[]                   = {0,0,0,0,0,0,0,0,0,0};
			double expected__         = 1.4914341925000003;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			int f[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int A[]                   = ;
			int B[]                   = ;
			int f[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int A[]                   = ;
			int B[]                   = ;
			int f[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FoxAndTouristFamilies().expectedLength(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(f, f + (sizeof f / sizeof f[0])));
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
// Fox Ciel has recently visited the Tourist Kingdom.
The people of this kingdom love to travel.



The kingdom contains n cities, conveniently numbered 0 through n-1.
There are exactly n-1 roads in the kingdom.
Each road is bidirectional and connects exactly two cities.



Let a simple path be a sequence of two or more cities such that no city is repeated in the sequence and each pair of consecutive cities is connected by a road.
In our kingdom, for each pair of cities there is a simple path that starts with one of them and ends with the other.
It follows that the road network always has to be a tree.



You are given the roads as two vector <int>s A and B, each with n-1 elements.
For each valid i, there is a road connecting the cities A[i] and B[i].



There are m families in the kingdom.
The families are numbered 0 through m-1.
Each family lives in a single city.
Multiple families may live in the same city.
You are given a vector <int> f with m elements.
For each i, family i lives in the city f[i].



Before the next holidays, each family i will randomly choose a destination city x[i].
The choice will be made uniformly at random from the set of all cities other than their home city f[i].
The choices made by different families are mutually independent.
During the holidays, each family will travel from their home city f[i] to the chosen destination city x[i] using the simple path that connects them.
(Note that there is always exactly one such simple path.)



Depending on all the random choices, it may happen that some roads will be used by all the traveling families.
If a road is used by all families, we will call it full.
The king of Tourist Kingdom will have all the full roads decorated for the families to enjoy.
Given a particular set of choices made by the families, let L be the number of full roads (possibly zero).



You are given the vector <int>s A, B, and f.
Compute and return the expected value of L.

DEFINITION
Class:FoxAndTouristFamilies
Method:expectedLength
Parameters:vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double expectedLength(vector <int> A, vector <int> B, vector <int> f)


NOTES
-Informally, the expected value of L can be seen as the average over very many rounds of the experiment.
-In this case, the expected value of L is the same as the average value of L, where the average is taken over all possible sets of choices the families might make.


CONSTRAINTS
-n will be between 2 and 51, inclusive.
-A and B will each contain exactly n-1 elements.
-Each element of A and B will be between 0 and n-1, inclusive.
-The roads defined by A and B will form a tree.
-f will contain between 1 and 50 elements, inclusive.
-Each element of f will be between 0 and n-1, inclusive.


EXAMPLES

0)
{0, 1}
{1, 2}
{0}

Returns: 1.5

There is only one family.
Their home is in city 0.
With probability 50% they will pick x[0]=1.
In this case, L=1, as the only full road is 0-1.
And with probability 50% they will pick x[0]=2.
In this case, L=2, as there are two full roads (0-1 and 1-2).
The answer is the average of these two possibilities:
0.5*1 + 0.5*2 = 1.5

1)
{0, 1}
{1, 2}
{0, 0}

Returns: 1.25

With probability 25%, both families decide to visit city 2.
In that case L=2 and the full roads are 0-1 and 1-2.
In all other cases L=1 and the only full road is 0-1.
The answer is 0.25*2 + 0.75*1 = 1.25

2)
{0, 1}
{1, 2}
{0, 1}

Returns: 0.75



3)
{0, 1}
{1, 2}
{0, 2}

Returns: 1.0



4)
{0,0,0}
{1,2,3}
{0}

Returns: 1.0



5)
{0,0,0}
{1,2,3}
{1,2}

Returns: 0.7777777777777777



6)
{0,1,1,3,5,6}
{1,2,3,4,4,4}
{5,6,1}

Returns: 0.4537037037037037



7)
{0,1,2,3,4,5,6,7,8,9}
{1,2,3,4,5,6,7,8,9,10}
{0,0,0,0,0,0,0,0,0,0}

Returns: 1.4914341925000003



*/

// END CUT HERE
