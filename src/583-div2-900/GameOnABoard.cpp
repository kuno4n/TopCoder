
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

int INF = (1<<29);
int mem[42][42][42][42];
int h, w;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef pair<int, int> P;


class GameOnABoard {
public:
   int optimalChoice( vector <string> cost ) {
	REP(i, 42) REP(j, 42) REP(k, 42) REP(l, 42) mem[i][j][k][l] = INF;
	h = SZ(cost), w = SZ(cost[0]);
	
	REP(i, h) REP(j, w){
		queue<P> q, q_nxt, emp;
		int co = cost[i][j] - '0';
		q_nxt.push(P(i, j));
		mem[i][j][i][j] = co;
		
		while(SZ(q_nxt)){
			q = q_nxt; q_nxt = emp;
			
			while(SZ(q)){
				int x = q.front().first, y = q.front().second;
				q.pop();
				REP(k, 4){
					int nx = x+dx[k], ny = y+dy[k];
					if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
					if(mem[i][j][nx][ny] != INF) continue;
					if(cost[nx][ny] == '0'){
						q.push(P(nx, ny));
						mem[i][j][nx][ny] = co;
					}
					else{
						q_nxt.push(P(nx, ny));
						mem[i][j][nx][ny] = co+1;
					}
				}
			}
			co++;
		}
		
	}
	
	int res = INF;
	REP(i, h) REP(j, w){
		int mx = 0;
		REP(ii, h) REP(jj, w) chmax(mx, mem[i][j][ii][jj]);
		chmin(res, mx);
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
			string cost[]             = {"11",
 "10"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cost[]             = {"01",
 "10"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cost[]             = {"111001",
 "001000",
 "111111",
 "001111",
 "001100",
 "001011",
 "111001",
 "010011"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cost[]             = {"001001101011",
 "110011001101",
 "111111000001",
 "111101010001",
 "011100101111",
 "110010111000",
 "111111110101",
 "111011110111",
 "111100100011",
 "000000000110",
 "101011011110",
 "011111000111",
 "101111001011"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cost[]             = {"110010100101010110100010001100111011",
 "001000000110100011010100000001001000",
 "011000110111101001011101110111000100",
 "111001011000100101111010100110110011",
 "111000011101001010000100001010000010",
 "111001110010100101000001001100011011",
 "111110100111010101100000100111000111",
 "011111111100100111111110000001110111",
 "110000010101001111100011110000001000",
 "010010110111111100011101100000011010",
 "110001100001111001101000101110110001",
 "110010000111011110000010110111010101",
 "100100110101001001101000001101101101",
 "001011101101001100111110101111001110",
 "111010111111111100110100000011111100",
 "110101101000001001000100101011100000",
 "011011001011010001001000100000110101",
 "011111111100000011010111010011010100",
 "111001111110001110001110010100111010",
 "000001111000001100101010000001101110",
 "010000110000010010111110111000010101",
 "100010010100110011000111101001101011",
 "111010110001101011010001111101111100",
 "000111110000110000000101100101000110",
 "110000010111001001110001101010111100",
 "011111101101001011011010011111100010",
 "110101111101010100110010000011001101",
 "101101111001010100101111100001110001",
 "000110010100101111011011110010010010",
 "110101010011101000111011100000010011",
 "110001010001110011010100110000010001",
 "111010101100111100100011001101010100",
 "011000000000100001011010000100010001",
 "100000110110000001010001001111010000",
 "100011111110010011011011001110011111",
 "101100001111100101001101100000100001",
 "010000111011010110011001110011111000",
 "100010100111110111001010100101111010",
 "000110011110111011111000101000001000"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string cost[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cost[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cost[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GameOnABoard().optimalChoice(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])));
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
// This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.

Alice and Bob are playing a game on a rectangular board. We use (i, j) to denote the j-th cell in the i-th row (0-based index). Each cell has a cost of either 0 or 1 and they are given by the vector <string> cost. The j-th character of i-th element in cost (0-based index) denotes the cost of cell (i, j). A path between two distinct cells (x1, y1) and (x2, y2) is a sequence of cells (c0, c1, ..., ck) such that c0=(x1, y1), ck=(x2, y2) and for each i from 0 to k-1, cells ci and ci+1 have a common side. Cost of a path is the total cost of cells on this path.

The game is played as follows: First Alice chooses a cell (x1,y1), then Bob chooses a cell (x2,y2) which is different from (x1, y1). Finally, they compute the value L: the minimum cost of a path between (x1,y1) and (x2,y2). Alice's goal is to minimize L, and Bob's goal is to maximize L. Compute and return the value L that will be achieved if both players play optimally.

DEFINITION
Class:GameOnABoard
Method:optimalChoice
Parameters:vector <string>
Returns:int
Method signature:int optimalChoice(vector <string> cost)


NOTES
-Two cells (x1, y1) and (x2, y2) have a common side if |x1-x2|+|y1-y2|=1.


CONSTRAINTS
-cost will contain between 2 and 40 elements, inclusive.
-Each element of cost will be between 2 and 40 characters long, inclusive.
-Each element of cost will be of the same length.
-Each element of cost will consist of '0's and '1's only.


EXAMPLES

0)
{"11",
 "10"}

Returns: 2

Regardless of Alice's choice, Bob can always achieve L=2 by choosing the opposite corner.
Sometimes he also has other optimal moves. For example, if Alice chooses (0,0), Bob can choose any of the other three cells to get L=2.

1)
{"01",
 "10"}

Returns: 1

Alice will not choose the cell (0,1), nor the cell (1,0). If she chooses one of those, Bob will choose the other one and L will be 2.
Alice prefers the other option. If she chooses one of the cells (0,0) or (1,1), Bob can only achieve L=1.

2)
{"111001",
 "001000",
 "111111",
 "001111",
 "001100",
 "001011",
 "111001",
 "010011"}

Returns: 3



3)
{"001001101011",
 "110011001101",
 "111111000001",
 "111101010001",
 "011100101111",
 "110010111000",
 "111111110101",
 "111011110111",
 "111100100011",
 "000000000110",
 "101011011110",
 "011111000111",
 "101111001011"}

Returns: 5



4)
{"110010100101010110100010001100111011",
 "001000000110100011010100000001001000",
 "011000110111101001011101110111000100",
 "111001011000100101111010100110110011",
 "111000011101001010000100001010000010",
 "111001110010100101000001001100011011",
 "111110100111010101100000100111000111",
 "011111111100100111111110000001110111",
 "110000010101001111100011110000001000",
 "010010110111111100011101100000011010",
 "110001100001111001101000101110110001",
 "110010000111011110000010110111010101",
 "100100110101001001101000001101101101",
 "001011101101001100111110101111001110",
 "111010111111111100110100000011111100",
 "110101101000001001000100101011100000",
 "011011001011010001001000100000110101",
 "011111111100000011010111010011010100",
 "111001111110001110001110010100111010",
 "000001111000001100101010000001101110",
 "010000110000010010111110111000010101",
 "100010010100110011000111101001101011",
 "111010110001101011010001111101111100",
 "000111110000110000000101100101000110",
 "110000010111001001110001101010111100",
 "011111101101001011011010011111100010",
 "110101111101010100110010000011001101",
 "101101111001010100101111100001110001",
 "000110010100101111011011110010010010",
 "110101010011101000111011100000010011",
 "110001010001110011010100110000010001",
 "111010101100111100100011001101010100",
 "011000000000100001011010000100010001",
 "100000110110000001010001001111010000",
 "100011111110010011011011001110011111",
 "101100001111100101001101100000100001",
 "010000111011010110011001110011111000",
 "100010100111110111001010100101111010",
 "000110011110111011111000101000001000"}

Returns: 7



*/

// END CUT HERE
