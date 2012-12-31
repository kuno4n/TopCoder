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

class Painting {
	public:
	int largestBrush(vector <string> picture) {
        int h = SZ(picture), w = SZ(picture[0]);
        for(int s = min(h, w); s>=2; s--){
            vector <string> p = picture;
            REP(i, h-s+1){
                REP(j, w-s+1){
                    bool ok = true;
                    FOR(ii, i, i+s) FOR(jj, j, j+s) if(picture[ii][jj] == 'W') ok = false;
                    if(ok) FOR(ii, i, i+s) FOR(jj, j, j+s) p[ii][jj] = '.';
                }
            }
            bool ok = true;
            REP(i, h) REP(j, w) if(p[i][j] == 'B') ok = false;
            if(ok) return s;
        }
        return 1;
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
			string picture[]          = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string picture[]          = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string picture[]          = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string picture[]          = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string picture[]          = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Painting().largestBrush(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
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
// Normally Mr. Grey is not a painter, but he recently had an absolutely brilliant idea for a picture. He thinks that once drawn, it will bring him world-wide fame.

The picture will be painted on an NxM sheet of white paper consisting of 1x1 squares. Its rows are numbered from 0 to N-1 and the columns are numbered from 0 to M-1. The cell in row i, column j is denoted as (i, j).

Of course, Mr. Grey already has a picture plan in his mind. It is given in a vector <string> picture, which contains exactly N elements, where each element contains exactly M characters. ?haracter j in element i of picture will be 'B' if the cell (i, j) must be painted black, and it will be 'W' if this cell must be left white.

Mr. Grey has a lot of black paint, but unfortunately he doesn't have a brush, so he went to a local shop to buy one. The shop offers square brushes of different sizes. More exactly, for each positive integer S, one can buy an SxS brush in the shop. Using an SxS brush, Mr. Grey will be able to paint entirely black SxS squares on the sheet of paper. In other words, he can choose row R and column C such that 0 <= R <= N - S, 0 <= C <= M - S, and then paint all cells (r, c) such that R <= r < R + S and C <= c < C + S in black paint. He can repeat this operation infinitely many times. If a cell must be black according to picture, it may be painted black several times. However, if a cell must be white, then it must never be painted black.

It's easy to see that every picture can be drawn using a 1x1 brush, but it will be impossible to draw some pictures using larger brushes. Buying a 1x1 brush seems to be the most practical choice. However, Mr. Grey is sure that big masters must use big brushes. Therefore, he would like to buy the largest possible brush that will still allow him to draw the picture that he has in mind.

Return the maximum value of S such that it's possible to draw picture using a brush of size SxS.

DEFINITION
Class:Painting
Method:largestBrush
Parameters:vector <string>
Returns:int
Method signature:int largestBrush(vector <string> picture)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will contain between 1 and 50 characters, inclusive.
-All elements of picture will contain the same number of characters.
-Each character in picture will be 'B' or 'W'.
-There will be at least one 'B' character in picture.


EXAMPLES

0)
{"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}

Returns: 4

It's easy to see that a solid 4x4 black square can be drawn using a 4x4 brush.

1)
{"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}

Returns: 1

This time we have only a border of a 4x4 square and it's necessary to have a 1x1 brush in order to draw it.

2)
{"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}


Returns: 3

A completely black 4x6 rectangle can be drawn using a 4x4 brush. However, if we want just one cell within it to remain white, the size of the brush will have to be reduced. In this example, a 3x3 brush would work.

3)
{"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}


Returns: 2

This is very similar to the previous example, but the white cell is in a different location. Mr. Grey will have to buy a 2x2 brush in this case.

4)
{"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}


Returns: 5



*/

// END CUT HERE
