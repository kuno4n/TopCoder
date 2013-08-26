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

int G[55][55];
int h, w;
int col[2][55];


void dfs(int xy, int num, int color){
    if(col[xy][num] != -1) return;
    
    col[xy][num] = color;
    if(xy == 0){
        REP(i, w) if(G[num][i] != -1) dfs(1, i, color ^ G[num][i]);
    }
    else{
        REP(i, h) if(G[i][num] != -1) dfs(0, i, color ^ G[i][num]);
    }
}

bool check(){
    REP(i, h) dfs(0, i, 0);
    REP(i, h) REP(j, w) if(G[i][j] != -1 && (col[0][i] ^ col[1][j]) != G[i][j]) return false;
    return true;
}

class ThreeColorability {
	public:
	vector <string> lexSmallest(vector <string> cells) {
		MSET(G, -1);
        h = SZ(cells), w = SZ(cells[0]);
        REP(i, h) REP(j, w) if(cells[i][j] != '?') G[i][j] = (cells[i][j] == 'Z');
        
        MSET(col, -1);
        vector <string> res;
        if(!check()) return res;
        
        res = cells;
        REP(i, h) REP(j, w) if(G[i][j] == -1){
            G[i][j] = 0;
            MSET(col, -1);
            if(check()) res[i][j] = 'N';
            else G[i][j] = 1, res[i][j] = 'Z';
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string cells[]            = {"Z"};
			string expected__[]       = {"Z" };

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string cells[]            = {"??", "?N"};
			string expected__[]       = {"NN", "NN" };

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string cells[]            = {"ZZZ", "ZNZ"};
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string cells[]            = {"N?N??NN","??ZN??Z","NN???Z?","ZZZ?Z??","Z???NN?","N?????N","ZZ?N?NN"};
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string cells[]            = {"ZZZZ","ZZZZ","ZZZZ"};
			string expected__[]       = {"ZZZZ", "ZZZZ", "ZZZZ" };

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string cells[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string cells[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string cells[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ThreeColorability().lexSmallest(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
There is a H times W rectangle divided into unit cells.
The rows of cells are numbered 0 to H-1 from top to bottom, and the columns are numbered 0 to W-1 from left to right.
The corners of cells are called lattice points.
By definition, there are (H+1)*(W+1) lattice points in our rectangle.


Each of the four edges of each cell is painted white.
Additionally, in some cells exactly one of the two diagonals is painted white.
In the remaining cells no diagonal is painted white yet.
Later, you are going to paint exactly one of the diagonals white in each of these cells.


Once you are done painting the diagonals, your next goal will be to color each of the lattice points using one of three available colors: red, green, or blue.
There is only one constraint: adjacent lattice points are not allowed to share the same color.


Two lattice points are called adjacent if they are connected by a white line segment.
(In other words, consecutive corners of a cell are always adjacent, opposite corners of a cell are adjacent if and only if they are connected by a painted diagonal, and no other pairs of lattice points are adjacent.)


Obviously, you need to paint the missing diagonals in such a way that there will be a valid coloring of lattice points, if possible.


You are given a vector <string> cells with H elements, each consisting of W characters.
If cells[i][j] is 'N', there is a diagonal line from the top left to the bottom right corner in the cell in row i, column j.
If cells[i][j] is 'Z', there is a diagonal line from the top right to the bottom left corner in the cell in row i, column j.
If cells[i][j] is '?', there is no diagonal yet in the cell in row i, column j.


If it is impossible to fill in the missing diagonals in such a way that there will be a valid coloring of all lattice points, return an empty vector <string>.
Otherwise, return a vector <string> that represents the rectangle with all the missing diagonals filled in.
I.e., the return value must be obtained from cells by replacing each '?' by either 'N' or 'Z'.
The return value must represent a rectangle for which a valid coloring of its lattice points exists.
If there are multiple possibilities, return the lexicographically smallest one.




DEFINITION
Class:ThreeColorability
Method:lexSmallest
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> lexSmallest(vector <string> cells)


NOTES
-Given two different vector <string>s A and B with the same number of elements, find the smallest index i such that A[i] and B[i] differ. If A[i] < B[i] we say that A is lexicographically smaller than B and vice versa.


CONSTRAINTS
-cells will contain between 1 and 50 elements, inclusive.
-Each element of cells will contain between 1 and 50 characters, inclusive.
-All elements of cells will contain the same number of characters.
-Each character of cells will be either 'N' or 'Z' or '?'.


EXAMPLES

0)
{"Z"}

Returns: {"Z" }

The given rectangle and a possible coloring is as follows.






1)
{"??", "?N"}

Returns: {"NN", "NN" }





2)
{"ZZZ", "ZNZ"}

Returns: { }



3)
{"N?N??NN","??ZN??Z","NN???Z?","ZZZ?Z??","Z???NN?","N?????N","ZZ?N?NN"}

Returns: { }



4)
{"ZZZZ","ZZZZ","ZZZZ"}

Returns: {"ZZZZ", "ZZZZ", "ZZZZ" }



*/

// END CUT HERE
