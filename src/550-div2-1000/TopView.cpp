#include <cstdio>
#include <cstdlib>
//#include <cmath>
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
//#include <cmath>
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

int h, w, n;

vector <char> vc;

int x1[100];
int y1[100];
int x2[100], y2[100];
bool g[100][100];



int cnv1(char c){
    if('0' <= c && c <= '9') return c - '0';
    if('A' <= c && c <= 'Z') return c - 'A' + 10;
    if('a' <= c && c <= 'z') return c - 'a' + 10 + 26;
    return -1;
}

char cnv2(int a){
    if(0 <= a && a <= 9) return '0' + a;
    if(10 <= a && a <= 35) return 'A' + (a-10);
    if(36 <= a && a <= 61) return 'a' + (a-36);
    return ' ';
}

class TopView {
	public:
	string findOrder(vector <string> grid) {
        h = SZ(grid), w = SZ(grid[0]);
        
        REP(i, 100) x1[i] = INF;
        REP(i, 100) y1[i] = INF;
        MSET(x2, -1), MSET(y2, -1);
        n = 0;
        vc.clear();
        REP(a, 62){
            char ch = cnv2(a);
            REP(i, h) REP(j, w){
                if(grid[i][j] != ch) continue;
                chmin(x1[n], i);
                chmin(y1[n], j);
                chmax(x2[n], i);
                chmax(y2[n], j);
            }
            if(x2[n] == -1) continue;
            vc.push_back(ch);
            n++;
        }
        
        REP(i, n) FOR(x, x1[i], x2[i]+1) FOR(y, y1[i], y2[i]+1) if(grid[x][y] == '.') return "ERROR!";
        
        MSET(g, false);
        REP(i, n) REP(j, n) if(i != j){
            FOR(x, x1[i], x2[i]+1) FOR(y, y1[i], y2[i]+1){
                if(grid[x][y] == vc[j]) g[i][j] = true;
            }
        }
        
        string res = "";
        bool used[n]; MSET(used, false);
        REP(cnt, n){
            pair<char, int> ci;
            ci = make_pair('z'+1, -1);
            REP(i, n) if(!used[i]){
                bool can = true;
                REP(j, n) if(g[j][i] && !used[j]) can = false;
                if(can) chmin(ci, make_pair(vc[i], i));
            }
            if(ci.second == -1) return "ERROR!";
            res.push_back(ci.first);
            used[ci.second] = true;
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
			string grid[]             = {"..AA..",
 ".CAAC.",
 ".CAAC."};
			string expected__         = "CA";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"..47..",
 "..74.."}
;
			string expected__         = "ERROR!";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"};
			string expected__         = "65AXab";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"};
			string expected__         = "ERROR!";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string grid[]             = {"z9999999999999999999999999999999999999999999999991", "2A888888888888888888888888888888888888888888888888", "5ABEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEC8", "5ADEFGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG8", "5ADEJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJHHG8", "5ADEJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJHHG8", "5ADEJKMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNIIG8", "5ADEJLPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPONIIG8", "5ADEJLPQSTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTNIIG8", "5ADEJLPRUVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVTNIIG8", "7ADEJLPRXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXWVTNIIG8", "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8", "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8", "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8", "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8", "7ADEJLPRXaffffffffffffffffffffffffffffffeZZVTNIIG8", "7ADEJLPRXbfimnnnnnnnnnnnnnrrrrrrrrrrrrrrqZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "5ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8", "5ADEJLPRXbfj0000000000000mqwwwwwwwwwwwwwwZZVTNIIG8", "5ADEJLPRXbejjjjjjjjjjjjjjjjjjjjjjjjjjjjjiZZVTNIIG8", "5ADEJLPRXbcddddddddddddddddddddddddddddddZZVTNIIG8", "5ADEJLPRXbgklllllllllllllllllllllllllllldZZVTNIIG8", "5ADEJLPRXbhovvvvvvvvvvvvvvvuttttttttttsldZZVTNIIG8", "5ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "5ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpuyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8", "6ADEJLPRXbhpppppppppppppppposxxxxxxxxxxkdZZVTNIIG8", "6ADEJLPRXbhhhhhhhhhhhhhhhhhhhhhhhhhhhhhgcYYVTNIIG8", "5ADEJLPRWbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaYYUSNIIG8", "5ADEJLORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRQMIIG8", "5ADEJLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLKIIG8", "5ADCHIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIF8", "51DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDB8", "2333333333333333334444444444444444443333333333333z"};
			string expected__         = "z123456789ABDCEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn0opqrstuvwxy";

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string grid[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TopView().findOrder(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
// Ralph was once playing with a set of cards and a grid of cells.
Each card was a rectangle of a unique color.
Different cards may have had different dimensions.
Ralph took his cards one at a time, and placed each of them onto the grid.
When placing a card, Ralph aligned its sides with grid lines, so each card covered some rectangular block of cells.
Some cards may have overlapped other, previously placed cards partially or even completely.
Once all the cards were placed, on each cell only the topmost card was visible.

You are given a vector <string> grid that describes what Ralph could see after placing the cards. The j-th character of element i of grid is '.' if the cell at position (i,j) is empty (does not contain any card) or is an alphanumeric character that represents the only color Ralph could see when looking at the cell.

Ralph does not remember the order he used to place the cards. Write a program that finds the order in which the cards of each visible color were placed.  The return value should be a string, containing exactly once each of the alphanumeric characters that occur in grid.
The i-th character of the return value should be the color of the i-th card (0-based index) that Ralph placed.
In case there are multiple valid orders, return the lexicographically smallest one.
In case there is no valid order of colors, return "ERROR!" (quotes for clarity).

DEFINITION
Class:TopView
Method:findOrder
Parameters:vector <string>
Returns:string
Method signature:string findOrder(vector <string> grid)


NOTES
-The letters in grid are case-sensitive: 'a' and 'A' are distinct colors.
-The lexicographically smaller of two strings of equal length is the one that has the earlier character (using ASCII ordering) at the first position at which they differ.


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-All elements of grid will contain the same number of characters.
-Each character in each element of grid will be a period ('.'), an uppercase letter ('A'-'Z'), a lowercase letter ('a'-'z'), or a digit ('0'-'9').
-At least one character in grid will be different from '.'.


EXAMPLES

0)
{"..AA..",
 ".CAAC.",
 ".CAAC."}

Returns: "CA"

The card with color C is a rectangle of 2 rows and 4 columns. The card with color A, a rectangle of 3 rows and 2 columns, was placed on top of it.

1)
{"..47..",
 "..74.."}


Returns: "ERROR!"

Each card has a unique color, this top perspective view tells us about 2 cards. This setting is not possible without using multiple cards of color 4 or 7.

2)
{"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"}

Returns: "65AXab"



3)
{"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"}

Returns: "ERROR!"



*/

// END CUT HERE
