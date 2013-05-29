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

int INF = (1<<29);

typedef pair<int, int> P;
struct edge {int to, cap, cost, rev;};
const int MAX_V = 1000;

int V; // Vは別途忘れずに設定すること。「最後のノード番号＋１」であることに注意。sinkと同じ数ではない。sink+1。
vector <edge> G[MAX_V]; // 使い回す場合は、Gも忘れず初期化すること
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h+V, 0);
    while(f > 0){
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while(SZ(que)){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            REP(i, SZ(G[v])){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF) return -1;
        REP(v, V) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

class DirectionBoard {
	public:
	int getMinimum(vector <string> board) {
		int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        string s = "DURL";
        int h = SZ(board), w = SZ(board[0]);
        V = h*w*2 + 2;
        REP(i, MAX_V) G[i].clear();
        REP(x, h) REP(y, w) REP(i, 4){
            add_edge(x*w+y, h*w + ((x+dx[i]+h)%h)*w + (y+dy[i]+w)%w, 1, s[i] == board[x][y] ? 0 : 1);
        }
        REP(i, h*w) add_edge(h*w*2, i, 1, 0);
        FOR(i, h*w, h*w*2) add_edge(i, h*w*2+1, 1, 0);
        return min_cost_flow(h*w*2, h*w*2+1, h*w);
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
			string board[]            = {"RRRD",
 "URDD",
 "UULD",
 "ULLL"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"RRRD",
 "URLL",
 "LRRR"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"RRD",
 "URD",
 "ULL"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"ULRLRD",
 "UDDLRR"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"UDLRLDLD",
 "DLDLLDLR",
 "LLLLLDLD",
 "UUURRRDD"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUUDDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "RRRDLDURDURUDDR"}
;
			int expected__            = 73;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DirectionBoard().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// A direction board is a matrix filled with arrows. Each arrow occupies one cell and points in one of the four directions: left, right, down, up. Each cell has two coordinates (row, column), starting with (0, 0) in the top left corner. Given a starting cell (r, c), you can move through the board in the following way. First, check the arrow in cell (r, c). If it points left, move left of the current cell, i.e. into cell(r, c - 1). For the right arrow, move to (r, c + 1). Up goes to (r - 1, c) and down to (r + 1, c). Each row and column of the board is cyclic, so whenever the new cell is outside the board, you appear on the other side. For example, moving left from (3, 0) on a board of size 5 by 5 results in appearing in cell (3, 4).

You need a board such that for every starting cell you always return to it during the movement process. If the given board does not satisfy this condition, you can change the direction of the arrow in any cell. For example, look at the following boards. In the left one, one only returns to the initial cell when he begins in cells (1, 1), (1, 2), (2, 0), (2, 3). After redirecting two arrows, you obtain a board with the given property.



Find the minimum number of arrow redirections which transforms the given board into a valid one.

DEFINITION
Class:DirectionBoard
Method:getMinimum
Parameters:vector <string>
Returns:int
Method signature:int getMinimum(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will be of the same length.
-Each element of board will consist of characters from the set {'L', 'R', 'U', 'D'} only.


EXAMPLES

0)
{"RRRD",
 "URDD",
 "UULD",
 "ULLL"}

Returns: 0

This board is already good. No matter which cell you start in, you always you return to it.

1)
{"RRRD",
 "URLL",
 "LRRR"}

Returns: 2

The example from the problem statement.

2)
{"RRD",
 "URD",
 "ULL"}

Returns: 2

This board is not valid, because if one starts from (1, 1), he never returns to this cell. A possible solution with only two changes:



3)
{"ULRLRD",
 "UDDLRR"}

Returns: 4



4)
{"UDLRLDLD",
 "DLDLLDLR",
 "LLLLLDLD",
 "UUURRRDD"}

Returns: 9



5)
{"UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUUDDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "RRRDLDURDURUDDR"}


Returns: 73



*/

// END CUT HERE
