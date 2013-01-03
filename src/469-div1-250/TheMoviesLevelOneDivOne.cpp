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
//#include "cout.h"

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

class TheMoviesLevelOneDivOne {
	public:
	long long find(int n, int m, vector <int> row, vector <int> seat) {
        vector<pair<int, int> > v;
        REP(i, SZ(row)) v.push_back(make_pair(row[i], seat[i]));
        row.clear(); seat.clear();
        sort(ALL(v));
        REP(i, SZ(v)){
            row.push_back(v[i].first);
            seat.push_back(v[i].second);
        }
		LL res = (LL)n*(m-1);
        REP(i, SZ(row)){
            VI s;
            s.push_back(seat[i]-1);
            while(i+1 != SZ(row) && row[i]==row[i+1]) s.push_back(seat[++i]-1);
            REP(j, SZ(s)){
                res -= 2;
                if(s[j]==0 || (j>0 && s[j]-1==s[j-1])) res++;
                if(s[j]==m-1) res++;
            }
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int n                     = 2;
			int m                     = 3;
			int row[]                 = {1, 2};
			int seat[]                = {2, 3};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int m                     = 3;
			int row[]                 = {1, 1, 1, 2, 2, 2};
			int seat[]                = {1, 2, 3, 1, 2, 3};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 4;
			int m                     = 7;
			int row[]                 = {1};
			int seat[]                = {1};
			long long expected__      = 23;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 10;
			int m                     = 8;
			int row[]                 = {1, 9, 6, 10, 6, 7, 9, 3, 9, 2};
			int seat[]                = {7, 7, 3, 3, 7, 1, 5, 1, 6, 2};
			long long expected__      = 54;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int m                     = ;
			int row[]                 = ;
			int seat[]                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int m                     = ;
			int row[]                 = ;
			int seat[]                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int row[]                 = ;
			int seat[]                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheMoviesLevelOneDivOne().find(n, m, vector <int>(row, row + (sizeof row / sizeof row[0])), vector <int>(seat, seat + (sizeof seat / sizeof seat[0])));
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
// John and Brus are going to a theater to see a very interesting movie.  They would like to have seats next to each other in the same row.  The theater contains n rows, with m seats in each row.  Rows are numbered 1 to n from front to back, and seats are numbered 1 to m from left to right.  Some of the seats are already reserved, but John and Brus can book any of the available seats.

You are given vector <int>s row and seat.  The i-th elements of row and seat are the row number and seat number of the i-th reserved seat.  All remaining seats are available.  Return the number of ways for John and Brus to book two available seats next to each other in the same row.


DEFINITION
Class:TheMoviesLevelOneDivOne
Method:find
Parameters:int, int, vector <int>, vector <int>
Returns:long long
Method signature:long long find(int n, int m, vector <int> row, vector <int> seat)


NOTES
-Two bookings are considered different only if one contains a seat that the other does not contain.  In other words, they don't need to decide which seat John sits in and which seat Brus sits in.


CONSTRAINTS
-n and m will each be between 1 and 1,000,000,000, inclusive.
-row will contain between 1 and 47 elements, inclusive.
-row and seat will contain the same number of elements.
-Each element of row will be between 1 and n, inclusive.
-Each element of seat will be between 1 and m, inclusive.
-All pairs (row[i], seat[i]) will be distinct.


EXAMPLES

0)
2
3
{1, 2}
{2, 3}

Returns: 1

The first and the second seat in the second row are the only two free seats next to each other in the same row.

1)
2
3
{1, 1, 1, 2, 2, 2}
{1, 2, 3, 1, 2, 3}

Returns: 0

There are no free seats in the theater.

2)
4
7
{1}
{1}

Returns: 23

3)
10
8
{1, 9, 6, 10, 6, 7, 9, 3, 9, 2}
{7, 7, 3, 3, 7, 1, 5, 1, 6, 2}

Returns: 54

*/

// END CUT HERE
