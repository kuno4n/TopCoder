
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



long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}

map<LL, int> prime_factor(long long l){
    map<LL, int> res;
    for(long long i=2; i*i<=l; i++){
        while(l%i == 0){
            res[i]++;
            l /= i;
        }
    }
    if(l!=1) res[l] = 1;
    return res;
}





LL INF = (1LL<<58);
map<LL, int> pf;
LL h, w, s;
LL res;

bool check(LL p, LL q){
	LL ss = s/p/q;
	ss -= (p-1)*w + (q-1);
	if(ss < 0 || ss&1) return false;
	ss /= 2;
	LL x = ss/w, y = ss%w;
	if(p+x > h || q+y > w) return false;
	return true;
}

void rec(map<LL, int>::iterator it, LL p, LL q){
	if(it == pf.end()){
		if(check(p, q)) chmin(res, p*q);
		return;
	}
	
	LL base = it->first, ex = it->second;
	it++;
	for(int i = 0; i <= ex; i++) for(int j = 0; j <= ex-i; j++){
		rec(it, p*_Pow(base, i), q*_Pow(base, j));
	}
	return;
}


class RectangularSum {
public:
   long long minimalArea( int height, int width, long long S ) {
	h = height, w = width;
	s = S*2;
	pf = prime_factor(s);
	res = INF;
	rec(pf.begin(), 1, 1);
	
	if(res == INF) return -1;
	else return res;
	
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
			int height                = 2;
			int width                 = 3;
			long long S               = 8;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int height                = 3;
			int width                 = 3;
			long long S               = 10;
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int height                = 3;
			int width                 = 3;
			long long S               = 36;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int height                = 25;
			int width                 = 25;
			long long S               = 16000;
			long long expected__      = 32;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int height                = 1000000;
			int width                 = 1000000;
			long long S               = 1000000000000LL;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int height                = 6;
			int width                 = 6;
			long long S               = 236;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int height                = 1000000;
			int width                 = 1;
			long long S               = 499999500000;
			long long expected__      = 999999;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int height                = ;
			int width                 = ;
			long long S               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RectangularSum().minimalArea(height, width, S);
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
// Consider the following table:


The table has height rows and width columns.
Rows and columns are each numbered sequentially, starting from 0.
For each i, j: the cell in row i, column j contains the number (i*width+j).
For example, the table with height=2 and width=3 looks as follows:

0 1 2
3 4 5


A subtable of this table is any table that can be obtained from the original table by selecting a rectangle of cells and erasing everything outside the rectangle.

You are given the ints height and width, and a long long S.
If there is no subtable in which the elements sum to S, return -1.
Otherwise, return the smallest possible area of such a subtable.

DEFINITION
Class:RectangularSum
Method:minimalArea
Parameters:int, int, long long
Returns:long long
Method signature:long long minimalArea(int height, int width, long long S)


CONSTRAINTS
-height will be between 1 and 1,000,000 (10^6), inclusive.
-width will be between 1 and 1,000,000 (10^6), inclusive.
-S will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
3
8

Returns: 4

The following subtable (shown in bold italic) has a sum of 8:

0 1 2
3 4 5


1)
3
3
10

Returns: -1



2)
3
3
36

Returns: 9



3)
25
25
16000

Returns: 32



4)
1000000
1000000
1000000000000

Returns: 2



*/

// END CUT HERE
