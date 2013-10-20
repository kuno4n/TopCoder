
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


    const int MAX_V = 2510;
    
    int V;
    
    VI G[MAX_V];
    int match[MAX_V];
    bool used[MAX_V];
    
    void add_edge(int u, int v){
        G[u].PB(v);
        G[v].PB(u);
    }
    
    bool dfs(int v){
        used[v] = true;
        REP(i, SZ(G[v])){
            int u = G[v][i], w = match[u];
            if(w < 0 || (!used[w] && dfs(w))){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    
    int bipartite_matching(){
        int res = 0;
        MSET(match, -1);
        REP(v, V){
            if(match[v] < 0){
                MSET(used, 0);
                if(dfs(v)) res++;
            }
        }
        return res;
    }


class FoxAndGo3 {
public:
   int maxEmptyCells( vector <string> b ) {
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int n = SZ(b);
	V = 0;
	REP(i, MAX_V) G[i].clear();
	map<pair<int, int>, int> mp;
	
	REP(i, n) REP(j, n) if(b[i][j] == '.') mp[make_pair(i, j)] = V++;
	REP(i, n) REP(j, n) if(b[i][j] == 'o'){
		REP(k, 4) {
			int ii = i + dx[k];
			int jj = j + dy[k];
			if(ii >= 0 && ii < n && jj >= 0 && jj < n && b[ii][jj] == '.'){
				add_edge(mp[make_pair(ii, jj)], V);
			}
		}
		V++;
	}
	return V - bipartite_matching();
	
	
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
			string board[]            = {"o.o",
 ".o.",
 "o.o"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"...",
 ".o.",
 "..."}
;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"xxxxx",
 "xxoxx",
 "xo.ox",
 "xxoxx",
 "xxxxx"}
;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {".xox.",
 ".o.ox",
 "x.o.o",
 "ox.ox",
 ".ox.."}
 ;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"o.o.o",
 ".ox..",
 "oxxxo",
 "..x..",
 "o.o.o"}
;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"...",
 "...",
 "..."};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndGo3().maxEmptyCells(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Fox Ciel is playing Go with Jiro.
Ciel plays black and Jiro plays white.
You are given a vector <string> board that represents a square board on which they play.
Black pieces are denoted 'x', white pieces 'o' and empty cells '.' (period).



In the current position no two white pieces are adjacent.
Jiro has already given up and he will not be making any more moves.
Ciel is considering making some more moves.
Her goal now is to maximize the number of empty cells on the board.



In each move, Ciel can add a black piece onto an empty cell.
After each move, all dead white pieces are removed from the board.
A white piece is considered dead if its cell does not share a side with any empty cell.



Return the maximum number of empty cells on the board, after Ciel makes zero or more moves as described above.

DEFINITION
Class:FoxAndGo3
Method:maxEmptyCells
Parameters:vector <string>
Returns:int
Method signature:int maxEmptyCells(vector <string> board)


NOTES
-The rules described in the statement are not identical with the rules of Go. In particular, black pieces never die in this problem.


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly n characters.
-Each character in board will be one of 'o', 'x', and '.'.
-No two white pieces will be adjacent.
-Each white piece will be adjacent to at least one empty cell.


EXAMPLES

0)
{"o.o",
 ".o.",
 "o.o"}

Returns: 5

The best solution is to put black pieces on (1,2), (2,1), (2,3), and then on (3,2). After that the board will look as follows:

.x.
x.x
.x.

There are 5 empty cells.

1)
{"...",
 ".o.",
 "..."}


Returns: 8

This time the best solution is don't do any move.

2)
{"xxxxx",
 "xxoxx",
 "xo.ox",
 "xxoxx",
 "xxxxx"}


Returns: 4



3)
{".xox.",
 ".o.ox",
 "x.o.o",
 "ox.ox",
 ".ox.."}
 

Returns: 12



4)
{"o.o.o",
 ".ox..",
 "oxxxo",
 "..x..",
 "o.o.o"}


Returns: 12



5)
{"...",
 "...",
 "..."}

Returns: 9



*/

// END CUT HERE
