
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int T;
int ax[2510];
int ay[2510];
int h, w;
vector <string> f;

int dp[2510][52][52];

int rec(int t, int bx, int by){
	if(dp[t][bx][by] >= 0) return dp[t][bx][by];
	if(t == T+1) return dp[t][bx][by] = 1;
	if(bx == ax[t] && by == ay[t]) return dp[t][bx][by] = 0;
	
	int res = 0;
	REP(i, 4){
		int nx = bx + dx[i];
		int ny = by + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && f[nx][ny] != '#' &&
		   (nx != ax[t] || ny != ay[t])){
			res |= rec(t+1, nx, ny);
		}
	}
	return dp[t][bx][by] = res;
}

class GameInDarknessDiv2 {
public:
   string check( vector <string> field, vector <string> moves ) {
	string M = "";
	REP(i, SZ(moves)) M += moves[i];
	T = SZ(M);
	f = field;
	h = SZ(f), w = SZ(f[0]);
	REP(i, h) REP(j, w) if(f[i][j] == 'A') ax[0] = i, ay[0] = j;
	REP(i, T){
		char c = M[i];
		ax[i+1] = ax[i], ay[i+1] = ay[i];
		if(c == 'U') ax[i+1]--;
		if(c == 'D') ax[i+1]++;
		if(c == 'L') ay[i+1]--;
		if(c == 'R') ay[i+1]++;
	}
	int bx=-1, by=-1;
	REP(i, h) REP(j, w) if(f[i][j] == 'B') bx = i, by = j;
	MSET(dp, -1);
	string res;
	if(rec(1, bx, by) == 1) res = "Bob wins";
	else res = "Alice wins";
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
			string field[]            = {"A.B..",
 "##.##",
 "##.##"};
			string moves[]            = {"RRDUR"};
			string expected__         = "Alice wins";

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {"A.B..",
 "##.##",
 "##..."};
			string moves[]            = {"RRRLD"};
			string expected__         = "Bob wins";

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"};
			string moves[]            = {"RR", "R", "UDD"};
			string expected__         = "Alice wins";

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"A.###",
 ".B..."};
			string moves[]            = {"RDRRRLLLLUDUDRLURDLUD"};
			string expected__         = "Bob wins";

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string field[]            = {".....",
 ".#.#.",
 "##.#.",
 "A###.",
 "B...."};
			string moves[]            = {"D"};
			string expected__         = "Alice wins";

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string field[]            = {".#...#....#.......#....#......",
 "...###.#.#..#.#.#..###...#.#.#",
 ".#.#...#...#..#..#.....##.#...",
 "#..#.##..##..#.#..###.#....#.#",
 "..#..#..#...#...#....#..##.#..",
 "#..##..#..##.#.#.####..#.#...#",
 ".#....##.#.....#......##.#.#..",
 ".###.#...#.#.#..#.#.##...##.#.",
 ".....#.#.##..#.#..##...##...#.",
 "#.#.#...#...#.#.#...#.#.#.##.#",
 ".#..##.#..##..#.###...........",
 "..##.....####.......##.#.#.##.",
 "#....##.#.#...####.#...#.#.#..",
 "#.#.#......##.#...#..#.#..#..#",
 "..#..#.#.##...#.#..#..#..#..#.",
 ".#..#...#...#..#..#.#..#..#A#.",
 "..#..#.#.B##.##..#...#.#.##...",
 "#.#.##..#......#.#.#.#.#...#.#",
 "#.#...#.######...#.#.#.#.#.#..",
 "..#.##.#.....#.##..#...#.#.#.#",
 ".#..#..#.#.#.#.#..#.#####..#.#",
 "..#.#.##.#.#.##.#......#..#...",
 "#..#.....#.#.....#.#.##..##.#.",
 "##..###.#..#.#.#.#..##..#...##",
 "##.#...#..##.#.#..#.#..#.#.#..",
 "#..#.#.####..#..#..#..#......#",
 "..#..#.....####..#.##.#.###.#.",
 ".#..#.####.#.#..#.....#...#...",
 "..##.......#...#..####.##.#.#.",
 "#....#.#.#..#.###....#....#..#"};
			string moves[]            = {"UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU","RRUUURUULLD"};
			string expected__         = "Alice wins";

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string field[]            = ;
			string moves[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string field[]            = ;
			string moves[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string field[]            = ;
			string moves[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GameInDarknessDiv2().check(vector <string>(field, field + (sizeof field / sizeof field[0])), vector <string>(moves, moves + (sizeof moves / sizeof moves[0])));
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
// Alice and Bob are playing a game on a rectangular board.
Rows and columns are both numbered starting from 0.
We will use (i, j) to denote the cell in row i, column j.
The cell (0, 0) is in the top left corner of the board.
Some cells contain walls, others are empty.
The game is played on empty cells only. 

The game is played as follows:
Each player has one piece on the board.
Initially, each piece occupies a different cell.
The players take alternating turns, Alice starts.
In each turn, the player moves his/her piece onto one of the adjacent empty cells.
(Note that moving the piece is mandatory, it is not allowed to keep it in its current cell.) 

If at any moment the two tokens occupy the same cell, Alice wins.
If Alice gives up (described below), Bob wins. 

You are given a vector <string> field that describes the game board.
Character j of element i of field describes the initial content of the cell (i, j).
The character '.' represents an empty cell, '#' represents a wall, 'A' is an empty cell where Alice's piece starts, and 'B' is an empty cell where Bob's piece starts. 

Here is the twist:
The game board is completely in the dark.
Alice and Bob each know the initial location of both pieces.
During the game, Alice has no idea how Bob moves his piece.
However, Bob knows exactly how Alice will play the game.
(Note that this is actually possible: as Alice does not gain any information during the game, she may as well determine her entire strategy in advance.) 

You are given a vector <string> moves that represents Alice's strategy.
Concatenate all elements of moves to obtain a string M.
For each i, in her i-th turn, Alice will move her piece according to the character M[i-1].
Assume that before Alice's i-th turn her piece was at (y, x).
In the i-th turn she moves as follows:

If M[i-1] is 'U' (quotes for clarity): she moves to (y-1, x). 
If M[i-1] is 'R' (quotes for clarity): she moves to (y, x+1). 
If M[i-1] is 'L' (quotes for clarity): she moves to (y, x-1). 
If M[i-1] is 'D' (quotes for clarity): she moves to (y+1, x). 

It is guaranteed that M will represent a valid sequence of moves that only uses empty cells and never leaves the board.
If Alice gets to the situation where she has to make a move but has no more letters in M, she gives up and Bob wins the game. 

Bob can use his knowledge of M and his knowledge of the game board when planning his own moves.
If it is possible for Bob to win the game, return "Bob wins" (quotes for clarity).
Otherwise, return "Alice wins".


DEFINITION
Class:GameInDarknessDiv2
Method:check
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string check(vector <string> field, vector <string> moves)


NOTES
-Note that the return value is case sensitive.


CONSTRAINTS
-field and moves will contain between 1 and 50 elements, inclusive.
-Each element of field and moves will contain between 1 and 50 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character of each element of field will be either '.', '#', 'A' or 'B' (quotes for clarity).
-field will contain exactly one 'A' and 'B' each.
-Each character of moves will be either 'U', 'D', 'L' or 'R' (quotes for clarity).
-The sequence of moves represented by moves will be a valid sequence of moves for Alice's piece.
-In the starting position each player will have at least one possible move.


EXAMPLES

0)
{"A.B..",
 "##.##",
 "##.##"}
{"RRDUR"}

Returns: "Alice wins"

In this game, M="RRDUR".
In this case Alice can always win regardless of how Bob moves.
One possible game is as follows:

Alice moves her piece to (0, 1).
Bob moves his piece to (0, 3).
Alice moves to (0, 2).
Bob moves to (0, 4).
Alice moves to (1, 2).
Bob moves to (0, 3).
Alice moves to (0, 2).
Bob moves to (0, 4).
Alice moves to (0, 3).
Bob moves to (0, 3). Alice and Bob are on the same cell, so Alice wins.

Note that Alice has used up all characters of M. Even so, Alice doesn't give up unless she needs to make her 6-th move.


1)
{"A.B..",
 "##.##",
 "##..."}
{"RRRLD"}

Returns: "Bob wins"



2)
{"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"}
{"RR", "R", "UDD"}

Returns: "Alice wins"

Make sure to concatenate the elements of moves.

3)
{"A.###",
 ".B..."}
{"RDRRRLLLLUDUDRLURDLUD"}

Returns: "Bob wins"



4)
{".....",
 ".#.#.",
 "##.#.",
 "A###.",
 "B...."}
{"D"}

Returns: "Alice wins"



5)
{".#...#....#.......#....#......",
 "...###.#.#..#.#.#..###...#.#.#",
 ".#.#...#...#..#..#.....##.#...",
 "#..#.##..##..#.#..###.#....#.#",
 "..#..#..#...#...#....#..##.#..",
 "#..##..#..##.#.#.####..#.#...#",
 ".#....##.#.....#......##.#.#..",
 ".###.#...#.#.#..#.#.##...##.#.",
 ".....#.#.##..#.#..##...##...#.",
 "#.#.#...#...#.#.#...#.#.#.##.#",
 ".#..##.#..##..#.###...........",
 "..##.....####.......##.#.#.##.",
 "#....##.#.#...####.#...#.#.#..",
 "#.#.#......##.#...#..#.#..#..#",
 "..#..#.#.##...#.#..#..#..#..#.",
 ".#..#...#...#..#..#.#..#..#A#.",
 "..#..#.#.B##.##..#...#.#.##...",
 "#.#.##..#......#.#.#.#.#...#.#",
 "#.#...#.######...#.#.#.#.#.#..",
 "..#.##.#.....#.##..#...#.#.#.#",
 ".#..#..#.#.#.#.#..#.#####..#.#",
 "..#.#.##.#.#.##.#......#..#...",
 "#..#.....#.#.....#.#.##..##.#.",
 "##..###.#..#.#.#.#..##..#...##",
 "##.#...#..##.#.#..#.#..#.#.#..",
 "#..#.#.####..#..#..#..#......#",
 "..#..#.....####..#.##.#.###.#.",
 ".#..#.####.#.#..#.....#...#...",
 "..##.......#...#..####.##.#.#.",
 "#....#.#.#..#.###....#....#..#"}
{"UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU","RRUUURUULLD"}

Returns: "Alice wins"



*/

// END CUT HERE
