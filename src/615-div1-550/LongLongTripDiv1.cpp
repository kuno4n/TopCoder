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

class LongLongTripDiv1 {
public:
   string isAble( int N, vector <int> A, vector <int> B, vector <int> D, long long T ) {
       vector<pair<int, int> > G[55];
       REP(i, 55) G[i].clear();
       REP(i, SZ(A)){
           G[A[i]].push_back(make_pair(B[i], D[i]));
           G[B[i]].push_back(make_pair(A[i], D[i]));
       }
       if(SZ(G[0]) == 0) return "Impossible";
       int mod = G[0][0].second * 2;
       queue<tuple<int, LL, int> > q;
       q.push(make_tuple(0, 0, 0));
       bool vis[55][20010];
       MSET(vis, false);
       while(SZ(q)){
           tuple<int, LL, int> t = q.front();
           q.pop();
           int a = get<0>(t);
           LL  d = get<1>(t);
           int m = get<2>(t);
           if(d > T) continue;
           if(vis[a][m]) continue;
           vis[a][m] = true;
           if(a == N-1 && m == T % mod) return "Possible";
           REP(i, SZ(G[a])){
               q.push(make_tuple(G[a][i].first, d+G[a][i].second, (m+G[a][i].second)%mod));
           }
       }
       return "Impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 3;
			int A[]                   = {0,0,1};
			int B[]                   = {2,1,2};
			int D[]                   = {7,6,5};
			long long T               = 11;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int A[]                   = {0,0,1};
			int B[]                   = {2,1,2};
			int D[]                   = {7,6,5};
			long long T               = 25;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int A[]                   = {0};
			int B[]                   = {1};
			int D[]                   = {1};
			long long T               = 9;
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 2;
			int A[]                   = {1};
			int B[]                   = {0};
			int D[]                   = {1};
			long long T               = 1000000000000000000LL;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 4;
			int A[]                   = {0,0,1};
			int B[]                   = {2,1,2};
			int D[]                   = {10,10,10};
			long long T               = 1000;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 9;
			int A[]                   = {4,8,5,8,3,6,2,6,7,6,6};
			int B[]                   = {2,7,1,5,1,3,1,1,5,4,2};
			int D[]                   = {6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195};
			long long T               = 937186357646035002LL;
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int D[]                   = ;
			long long T               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int D[]                   = ;
			long long T               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int D[]                   = ;
			long long T               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LongLongTripDiv1().isAble(N, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), vector <int>(D, D + (sizeof D / sizeof D[0])), T);
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
// There is a country with N cities. The cities are numbered 0 through N-1. There are some bidirectional roads in the country. Each road connects a pair of cities. More precisely, for each i, road i connects the cities A[i] and B[i].

Limit is a deer that likes to travel along the roads. Traveling along road i (in either direction) takes him exactly D[i] minutes. Limit does not like cities, so he never waits in a city.

Limit is currently in the city 0, starting his travels. In exactly T minutes, he wants to be in the city N-1.

You are given the int N; the vector <int>s A, B, and D; and the long long T.
Return "Possible" (quotes for clarity) if Deer Limit can reach city N-1 in exactly T minutes.
Otherwise, return "Impossible".

DEFINITION
Class:LongLongTripDiv1
Method:isAble
Parameters:int, vector <int>, vector <int>, vector <int>, long long
Returns:string
Method signature:string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-A, B and D will each contain the same number of elements.
-Each element in A and B will be between 0 and N-1, inclusive.
-Each element in D will be between 1 and 10,000, inclusive.
-For each valid i, A[i] and B[i] will be different.
-No two roads will connect the same pair of cities.
-T will be between 1 and 10^18, inclusive.


EXAMPLES

0)
3
{0,0,1}
{2,1,2}
{7,6,5}
11

Returns: "Possible"

city 0 -> city 1 -> city 2 is a valid way.

1)
3
{0,0,1}
{2,1,2}
{7,6,5}
25

Returns: "Possible"

city 0 -> city 2 -> city 1 -> city 0 -> city 2 is a valid way.

2)
2
{0}
{1}
{1}
9

Returns: "Possible"

Here, Limit just travels back and forth between cities 0 and 1 along the only road in the country.

3)
2
{1}
{0}
{1}
1000000000000000000

Returns: "Impossible"



4)
4
{0,0,1}
{2,1,2}
{10,10,10}
1000

Returns: "Impossible"

In this test case, there is absolutely no way how to reach city N-1 from city 0.

5)
9
{4,8,5,8,3,6,2,6,7,6,6}
{2,7,1,5,1,3,1,1,5,4,2}
{6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195}
937186357646035002

Returns: "Impossible"



*/

// END CUT HERE
