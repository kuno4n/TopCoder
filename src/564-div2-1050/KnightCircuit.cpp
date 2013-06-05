
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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

LL bfs(LL w, LL h, int a, int b){
	bool visited[h][w];
	REP(i, h) REP(j, w) visited[i][j] = false;
	int dx[8] = {a, a, b, b, -a, -a, -b, -b};
	int dy[8] = {b, -b, a, -a, b, -b, a, -a};
	LL res = 0;
	REP(i, h) REP(j, w) if(!visited[i][j]){
		LL cnt = 0;
		queue <pair<LL, LL> > que;
		que.push(make_pair(i, j));
		while(SZ(que)){
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			if(visited[x][y]) continue;
			visited[x][y] = true;
			cnt++;
			REP(k, 8){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny]) continue;
				que.push(make_pair(nx, ny));
			}
		}
		res = max(res, cnt);
	}
	return res;
}

class KnightCircuit {
public:
   long long maxSize( int _w, int _h, int a, int b ) {
	LL w = _w, h = _h;
	int g = gcd(a, b);
	if(g > 1) return maxSize((w-1)/g+1, (h-1)/g+1, a/g, b/g);
	if(w <= 21 || h <= 21) return bfs(w, h, a, b);
	else{
		if((a+b)&1) return w*h;
		else return ((w+1)/2)*((h+1)/2) + (w/2)*(h/2);
	}
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
			int w                     = 1;
			int h                     = 1;
			int a                     = 2;
			int b                     = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 3;
			int h                     = 20;
			int a                     = 1;
			int b                     = 3;
			long long expected__      = 11;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 100000;
			int h                     = 100000;
			int a                     = 1;
			int b                     = 2;
			long long expected__      = 10000000000LL;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 3;
			int h                     = 3;
			int a                     = 1;
			int b                     = 2;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int w                     = 30;
			int h                     = 30;
			int a                     = 8;
			int b                     = 4;
			long long expected__      = 64;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int w                     = 32;
			int h                     = 34;
			int a                     = 6;
			int b                     = 2;
			long long expected__      = 136;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int w                     = ;
			int h                     = ;
			int a                     = ;
			int b                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int w                     = ;
			int h                     = ;
			int a                     = ;
			int b                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int w                     = ;
			int h                     = ;
			int a                     = ;
			int b                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KnightCircuit().maxSize(w, h, a, b);
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
// The (a,b)-knight is a chess piece that moves by jumping, just as a regular knight, but the jump is a cells in one direction, b in the other. Formally, an (a,b)-knight standing on the cell (x,y) can move to any of the following eight cells:
(x+a,y+b), (x+a,y-b), (x-a,y+b), (x-a,y-b), (x+b,y+a), (x+b,y-a), (x-b,y+a), and (x-b,y-a).
Of course, if the (a,b)-knight is close to the edge of the board, some of these cells might not be on the board.
It is not allowed to jump to a cell that is not on the board.

A knight circuit is a sequence of cells on a chess board that starts and ends with the same cell.
Each consecutive pair of cells in the knight circuit must correspond to a single jump of the (a,b)-knight.
The knight circuit may visit each cell arbitrarily many times.
The size of a knight circuit is the number of different cells visited by the circuit.

You are given the ints w and h: the width (in columns) and the height (in rows) of a rectangular chessboard. You are also given the ints a and b: the parameters of your knight. Return the maximum knight circuit size that can be obtained on the given board. You are free to choose any cell as the start of your circuit.


DEFINITION
Class:KnightCircuit
Method:maxSize
Parameters:int, int, int, int
Returns:long long
Method signature:long long maxSize(int w, int h, int a, int b)


CONSTRAINTS
-w, h will each be between 1 and 100000, inclusive.
-a and b will each be between 1 and 10, inclusive.
-a and b will not be equal.


EXAMPLES

0)
1
1
2
1

Returns: 1

This is a 1x1 board. Note that a sequence that consists of a single cell is considered to be a valid knight circuit.

1)
3
20
1
3

Returns: 11



2)
100000
100000
1
2

Returns: 10000000000

It is possible to make a circuit that contains every cell on the board.

3)
3
3
1
2

Returns: 8



4)
30
30
8
4

Returns: 64



5)
32
34
6
2

Returns: 136



*/

// END CUT HERE
