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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }


double EPS = 1e-10;

double add(double a, double b){
    if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y){
    }
    P operator + (P p){
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p){
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d){
        return P(x*d, y*d);
    }
    double dot(P p){ 
        return add(x*p.x, y*p.y);
    }
    double det(P p){ 
        return add(x*p.y, -y*p.x);
    }
};

P intersection(P p1, P p2, P q1, P q2){
    return p1 + (p2-p1) * ((q2-q1).det(q1-p1) / (q2-q1).det(p2-p1));
}


P pt[70010];

class TriangleXor {
	public:
	int theArea(int W) {
		for(int i = 0; i <= W; i++) pt[i] = intersection(P(0, 0), P(W, 1), P(0, 1), P(i, 0));
//        for(int i = 0; i <= W; i++) OUT2(pt[i].x, pt[i].y);
        
        double res = 0.0;
        if(W%2 == 0) res += W/4.0;
        
        for(int i = (W%2 == 0 ? W-1 : W); i >= 0; i--) res += pt[i].x * (i%2 == 0 ? -1 : 1);
        
        for(int i = 1; i < W; i++){
            P pt_tmp = intersection(P(1, 0), P(W, 1), P(i, 0), P(0, 1));
            double d = pt_tmp.x - pt[i-1].x;
            double lo = W - pt[i-1].x*2 - d;
            double up = W - pt[i].x*2;
            res += (lo+up)*(pt[i].y-pt[i-1].y)/4;
            if(i % 2 == 0) res += d * (pt[i].y-pt[i-1].y) / 2;
        }
        
        if(W % 2 == 0) res += (W - pt[W-1].x*2) * (0.5 - pt[W-1].y) / 2;
        
        
        return floor((res + EPS));
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
			int W                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int W                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int W                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int W                     = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int W                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int W                     = 12345;
			int expected__            = 4629;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int W                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int W                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int W                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TriangleXor().theArea(W);
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
// 
You are given an int W.
There is a rectangle in the XY-plane with corners at (0, 0), (0, 1), (W, 0), and (W, 1).
Let T[x] be the triangle with vertices at (0, 1), (W, 1) and (x, 0).
(All points that lie inside the triangle are a part of T[x] as well.)


The objective in this problem is to calculate the area of the region (T[0] xor T[1] xor ... xor T[W]).
(See Notes for a formal definition.)
The figures below show the region (T[0] xor T[1] xor ... xor T[W]) for W=1,2,3,4,5,6.












Return the integer part of the area of the region.



DEFINITION
Class:TriangleXor
Method:theArea
Parameters:int
Returns:int
Method signature:int theArea(int W)


NOTES
-For sets of points A and B in the XY-plane, the set (A xor B) is defined as the set of all points that lie in exactly one of the sets A and B (i.e., points that belong to the union of A and B but don't belong to their intersection).
-If the exact area is A, the correct return value is floor(A), not round(A). In words: you should return the largest integer that is less than or equal to the exact area.
-The format of the return value was chosen to help you in case of small precision errors. The constraints guarantee that computing the correct area with absolute error less than 0.01 is sufficient to determine the correct return value. The author's solution is significantly more precise than that.


CONSTRAINTS
-W will be between 1 and 70,000, inclusive.
-The difference between the exact area of the region and the nearest integer will be greater than 0.01.


EXAMPLES

0)
1

Returns: 0

The exact area is 0.5.

1)
2

Returns: 1

The area is approximately 1.33333.

2)
3

Returns: 1

The exact area is 1.35.

3)
4

Returns: 2

The area is approximately 2.62857. Note that the correct answer is 2, not 3.

4)
5

Returns: 2

The area is approximately 2.13294.

5)
12345

Returns: 4629



*/

// END CUT HERE
