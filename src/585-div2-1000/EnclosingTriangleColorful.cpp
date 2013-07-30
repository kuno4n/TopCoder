
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


    struct P{
        LL x, y;
        P() {}
        P(LL x, LL y) : x(x), y(y){
        }
        P operator + (P p){
            return P(x+p.x, y+p.y);
        }
        P operator - (P p){
            return P(x-p.x, y-p.y);
        }
        P operator * (LL d){
            return P(x*d, y*d);
        }
        LL dot(P p){ // “àÏ
            return x*p.x + y*p.y;
        }
        LL det(P p){ // ŠOÏ
            return x*p.y - y*p.x;
        }
    };
    
	LL ccw(P p1, P p2, P p3){
		return (p2-p1).det(p3-p1);
	}


int px[1205], py[1205], nxt[1205];
VI x, y;
bool valid[1205][1205];

bool chk(int a, int b){
	bool res = true;
	REP(i, SZ(x)) res &= (ccw(P(px[a], py[a]), P(px[b], py[b]), P(x[i], y[i])) >= 0);
	return res;
}

class EnclosingTriangleColorful {
public:
   int getNumber( int m, vector <int> _x, vector <int> _y ) {
	int t = 0;
	REP(s, 4) FOR(i, 1, m){
		int ox[4] = {i, m, m-i, 0};
		int oy[4] = {0, i, m, m-i};
		px[t] = ox[s];
		py[t] = oy[s];
		nxt[t++] = (s+1) * (m-1);
	}
	
	x = _x, y = _y;
	REP(i, t) REP(j, t) valid[i][j] = chk(i, j);
	
	int res = 0;
	REP(i, t) FOR(j, nxt[i], t) FOR(k, nxt[j], t){
		if(valid[i][j] && valid[j][k] && valid[k][i]) res++;
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
			int m                     = 4;
			int x[]                   = { 1, 2, 3 };
			int y[]                   = { 1, 3, 2 };
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int m                     = 7;
			int x[]                   = { 1, 1, 6, 6 };
			int y[]                   = { 1, 6, 1, 6 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int m                     = 4;
			int x[]                   = { 2 };
			int y[]                   = { 2 };
			int expected__            = 72;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int m                     = 10;
			int x[]                   = { 2, 6, 7, 6 };
			int y[]                   = { 7, 7, 9, 3 };
			int expected__            = 52;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int m                     = 15;
			int x[]                   = { 7, 6, 5, 4, 3 };
			int y[]                   = { 1, 4, 7, 10, 13 };
			int expected__            = 150;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int m                     = 300;
			int x[]                   = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 137, 177, 125, 123, 172, 125, 137, 143, 120, 178 } ;
			int y[]                   = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 118, 122, 179, 122, 180, 121, 182, 183, 128, 177 } ;
			int expected__            = 21690886;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int m                     = ;
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int m                     = ;
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int m                     = ;
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
// You are given an int m. 
Consider a square in the plane such that the corners of the square have coordinates (0, 0), (m, 0), (m, m), and (0, m). 
All the lattice points on the sides of this square are colored, as described below: 

The points with coordinates (1, 0), ..., (m-1, 0) are red. 
The points with coordinates (m, 1), ..., (m, m-1) are green. 
The points with coordinates (m-1, m), ..., (1, m) are blue. 
The points with coordinates (0, m-1), ..., (0, 1) are yellow. 

Some other lattice points are black. 
Each black point lies strictly inside the square. 
You are given two vector <int>s: x and y. 
These describe the black points: 
For each i, there is a black point at (x[i], y[i]). 



You want to draw a triangle such that: 

its vertices have three distinct colors out of the set { red, green, blue, yellow }, 
all black points lie inside or on the boundary of the triangle. 

Return the number of ways to draw such a triangle. 


DEFINITION
Class:EnclosingTriangleColorful
Method:getNumber
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int getNumber(int m, vector <int> x, vector <int> y)


CONSTRAINTS
-m will be between 2 and 300, inclusive. 
-x and y will each contain between 1 and 50 elements, inclusive. 
-x and y will contain the same number of elements. 
-Each element of x and y will be between 1 and m-1, inclusive. 
-All points described by x and y will be distinct. 


EXAMPLES

0)
4
{ 1, 2, 3 }
{ 1, 3, 2 }

Returns: 8

The picture shows the 8 ways to draw a triangle. 



1)
7
{ 1, 1, 6, 6 }
{ 1, 6, 1, 6 }

Returns: 0



2)
4
{ 2 }
{ 2 }

Returns: 72



3)
10
{ 2, 6, 7, 6 }
{ 7, 7, 9, 3 }

Returns: 52



4)
15
{ 7, 6, 5, 4, 3 }
{ 1, 4, 7, 10, 13 }

Returns: 150



5)
300
{ 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
  179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
  116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
  163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
  137, 177, 125, 123, 172, 125, 137, 143, 120, 178 }

{ 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
  125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
  150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
  182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
  118, 122, 179, 122, 180, 121, 182, 183, 128, 177 }


Returns: 21690886



*/

// END CUT HERE
