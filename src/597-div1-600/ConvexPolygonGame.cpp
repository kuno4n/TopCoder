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

int INF = (1<<29);
int ub[200010];
int lb[200010];

VI resx, resy;

class ConvexPolygonGame {
	public:
	string winner(vector <int> X, vector <int> Y) {
		int n = SZ(X);
        REP(i, n) X[i] += 100000, Y[i] += 100000;
        REP(i, 200010) ub[i] = -INF, lb[i] = INF;
        
        REP(i, n){
            LL bx = X[i], by = Y[i];
            LL nx = X[(i+1)%n], ny = Y[(i+1)%n];
            LL dx = nx - bx, dy = ny - by;
            if(bx < nx){
                lb[bx] = by+1;
                for(int x = bx+1; x < nx; x++){
                    lb[x] = (dx*by + dy*(x-bx) + dx - 1) / dx;
                }
            }
            else if(bx > nx){
                ub[bx] = by-1;
                for(int x = bx-1; x > nx; x--){
                    ub[x] = (-dx*by + dy*(bx-x)) / -dx;
                }
            }
            else if(by < ny) lb[bx] = by+1;
            else ub[bx] = by-1;
        }
        
        resx.clear();
        resy.clear();
        REP(x, 200010){
            for(int y = lb[x]; y <= ub[x]; y++){
                resx.push_back(x);
                resy.push_back(y);
                if(SZ(resx) > 200010) return "Masha";
            }
        }
        
        for(int i = 2; i < SZ(resx); i++){
            LL y1 = (LL)(resy[1]-resy[0]) * (resx[i]-resx[0]);
            LL y2 = (LL)(resy[i]-resy[0]) * (resx[1]-resx[0]);
            if(y1 != y2) return "Masha";
        }
        return "Petya";
        
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
			int X[]                   = {0, 1, 0};
			int Y[]                   = {0, 0, 1};
			string expected__         = "Petya";

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {0, 4, 2};
			int Y[]                   = {0, 0, 2};
			string expected__         = "Masha";

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {0, 100, 100, 0};
			int Y[]                   = {0, 0, 100, 100};
			string expected__         = "Masha";

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {0, 50, 100, 50};
			int Y[]                   = {0, -1, 0, 1};
			string expected__         = "Petya";

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X[]                   = {-100000, 100000, 100000, -100000};
			int Y[]                   = {-1, -1, 1, 1};
			string expected__         = "Masha";

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int X[]                   = {-1, 0, 0, -1};;
          int Y[]                   = {-500, -500, 500, 500};
			string expected__         = "Masha";

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int X[]                   = ;
			int Y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X[]                   = ;
			int Y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ConvexPolygonGame().winner(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
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
// Little Petya likes convex polygons a lot. Recently he has received a convex polygon as a gift from his mother. The only thing that Petya likes more than convex polygons is playing with little Masha. Petya invented the following game for two players that involves his polygon.
At the beginning of the game there is a convex polygon drawn on the plane. The coordinates of vertices of this polygon are given in vector <int> X and vector <int> Y. Petya and Masha take alternate turns, Masha plays first. On his or her turn the player draws a new convex polygon that has the following properties:

 All vertices of the new polygon have integer coordinates.

 Each new vertex is located either strictly inside the old polygon or on an edge of the old polygon.

 No vertex of the new polygon coincides with any vertex of the old polygon.

 No three vertices of the new polygon lie on the same line.

 The new polygon has non-zero area.


Note that the new polygon and the old polygon are not required to have the same number of vertices. 
After drawing a new polygon the player erases the old one. A player who can't make a move loses the game. Determine who will be the winner if both kids play optimally. If the winner is Masha, return the string "Masha" (without quotes), otherwise return "Petya".

DEFINITION
Class:ConvexPolygonGame
Method:winner
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string winner(vector <int> X, vector <int> Y)


CONSTRAINTS
-X will contain between 3 and 50 elements, inclusive.
-Y will contain between 3 and 50 elements, inclusive.
-X and Y will contain the same number of elements.
-Each element of X will be between -100 000 and 100 000, inclusive.
-Each element of Y will be between -100 000 and 100 000, inclusive.
-The polygon represented by X and Y will be convex, will have non-zero area and won't contain any 3 vertices that are located on the same line.
-Vertices of the polygon will be listed in counter-clockwise order.


EXAMPLES

0)
{0, 1, 0}
{0, 0, 1}

Returns: "Petya"

Masha has no valid moves, so she loses the game immediately.

1)
{0, 4, 2}
{0, 0, 2}

Returns: "Masha"

One of the possible Masha's moves is to select the triangle (1, 0), (3, 1), (1, 1). Regardless of her first move Petya will never be able to make the next move.

2)
{0, 100, 100, 0}
{0, 0, 100, 100}

Returns: "Masha"



3)
{0, 50, 100, 50}
{0, -1, 0, 1}

Returns: "Petya"



4)
{-100000, 100000, 100000, -100000}
{-1, -1, 1, 1}

Returns: "Masha"



*/

// END CUT HERE
