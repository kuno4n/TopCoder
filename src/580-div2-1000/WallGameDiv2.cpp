
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

vector <string> c;
int h, w;
int mem[55][55];
int INF = (1<<29);

int rec(int x, int y){
	if(mem[x][y] != -1) return mem[x][y];
	if(c[x][y] == 'x') return mem[x][y] = -INF;
	int co[55]; MSET(co, -1); co[y] = c[x][y]-'0';
	for(int i = y-1; i >= 0 && c[x][i] != 'x'; i--) co[i] = co[i+1]+c[x][i]-'0';
	for(int i = y+1; i < w && c[x][i] != 'x'; i++) co[i] = co[i-1]+c[x][i]-'0';
	int res = -INF;
	if(x==0){
		if(co[0] == -1) return mem[x][y] = -INF;
		return mem[x][y] = co[0];
	}
	if(x==h-1){
		return mem[x][y] = rec(x-1, y) + co[y];
	}
	REP(i, w) if(co[i] != -1) res = max(res, rec(x-1, i) + co[i]);
	return mem[x][y] = res;
}

class WallGameDiv2 {
public:
   int play( vector <string> costs ) {
	c = costs;
	h = SZ(c), w = SZ(c[0]);
	REP(i, 55) REP(j, 55) mem[i][j] = -1;
	int res = -INF;
	REP(i, w) res = max(res, rec(h-1, i));
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
			string costs[]            = {"042"
,"391"};
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string costs[]            = {"0xxxx"
,"1x111"
,"1x1x1"
,"11191"
,"xxxx1"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string costs[]            = {"0"
,"5"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string costs[]            = {"0698023477896606x2235481563x59345762591987823x663"
,"1x88x8338355814562x2096x7x68546x18x54xx1077xx5131"
,"64343565721335639575x18059738478x156x781476124780"
,"2139850139989209547489708x3466104x5x3979260330074"
,"15316x57171x182167994729710304x24339370252x2x8846"
,"459x479948xx26916349194540891252317x99x4329x34x91"
,"96x3631804253899x69460666282614302698504342364742"
,"4x41693527443x7987953128673046855x793298x8747219x"
,"7735427289436x56129435153x83x37703808694432026643"
,"340x973216747311x970578x9324423865921864682853036"
,"x1442314831447x860181542569525471281x762734425650"
,"x756258910x0529918564126476x481206117984425792x97"
,"467692076x43x91258xx3xx079x34x29xx916574022682343"
,"9307x08x451x2882604411x67995x333x045x0x5xx4644590"
,"4x9x088309856x342242x12x79x2935566358156323631235"
,"04596921625156134477422x2691011895x8564609x837773"
,"223x353086929x27222x48467846970564701987061975216"
,"x4x5887805x89746997xx1419x758406034689902x6152567"
,"20573059x699979871151x444449x5170122650576586x898"
,"683344308229681464514453186x51040742xx138x5170x93"
,"1219892x9407xx63107x24x4914598xx4x478x31485x69139"
,"856756530006196x8722179365838x9037411399x41126560"
,"73012x9290145x1764125785844477355xx827269976x4x56"
,"37x95684445661771730x80xx2x459547x780556228951360"
,"54532923632041379753304212490929413x377x204659874"
,"30801x8716360708478705081091961915925276739027360"
,"5x74x4x39091353819x10x433010250089676063173896656"
,"03x07174x648272618831383631629x020633861270224x38"
,"855475149124358107x635160129488205151x45274x18854"
,"091902044504xx868401923845074542x50x143161647934x"
,"71215871802698346x390x2570413992678429588x5866973"
,"87x4538137828472265480468315701832x24590429832627"
,"9479550007750x658x618193862x80317248236583631x846"
,"49802902x511965239855908151316389x972x253946284x6"
,"053078091010241324x8166428x1x93x83809001454563464"
,"2176345x693826342x093950x12x7290x1186505760xx978x"
,"x9244898104910492948x2500050208763770568x92514431"
,"6855xx7x145213846746325656963x0419064369747824511"
,"88x15690xxx31x20312255171137133511507008114887695"
,"x391503034x01776xx30264908792724712819642x291x750"
,"17x1921464904885298x58x58xx174x7x673958x9615x9230"
,"x9217049564455797269x484428813681307xx85205112873"
,"19360179004x70496337008802296x7758386170452xx359x"
,"5057547822326798x0x0569420173277288269x486x582463"
,"2287970x0x474635353111x85933x33443884726179587xx9"
,"0x697597684843071327073893661811597376x4767247755"
,"668920978869307x17435748153x4233659379063530x646x"
,"0019868300350499779516950730410231x9x18749463x537"
,"00508xx083203827x42144x147181308668x3192478607467"};
			int expected__            = 3512;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string costs[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string costs[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string costs[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WallGameDiv2().play(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])));
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
// 
Rabbit and Eel are playing a board game.
The game is played with a single token on a rectangular board that is divided into a grid of unit cells.
Some cells contain a digit that represents the cost of placing the token onto that cell.
Other cells contain the letter 'x' that represents a blocked cell.
It is not allowed to place the token onto a blocked cell.


Initially, the token is placed on the leftmost cell of the topmost row.
(The constraints guarantee that this cell will never be blocked and its cost will always be 0.)
Eel starts the game by putting up some walls.
Eel may place as many walls as he wants, including none.
Each wall must be placed between two adjacent cells in the same column.


Once Eel has placed the walls, Rabbit gets to move the token.
In each step, Rabbit may move the token one cell left, one cell right, or one cell down.
(Note that Rabbit is not allowed to move the token upwards.)
Rabbit may only move the token into cells that are not blocked.
Each time Rabbit moves the token into a cell, he has to pay the cost associated with that cell.


The game ends when Rabbit first moves the token into the bottommost row.
The constraints guarantee that this can be achieved if Eel does not place any walls.
The game must always be allowed to end.
That is, Eel must not place a set of walls that blocks all possible paths to the bottommost row.


Rabbit's goal is to minimize and Eel's goal is to maximize the total cost paid by Rabbit during the game.
You are given the vector <string> costs representing the costs of cells:
character j of element i of cost is either a digit that represents the cost written in the cell in row i, column j; or it is the letter 'x' that represents a blocked cell.
Return the total cost of the game assuming that both Rabbit and Eel play optimally.


DEFINITION
Class:WallGameDiv2
Method:play
Parameters:vector <string>
Returns:int
Method signature:int play(vector <string> costs)


CONSTRAINTS
-costs will contain between 2 and 50 elements, inclusive.
-Each element of costs will contain between 1 and 50 characters, inclusive.
-Each element of costs will contain the same number of characters.
-Each character of each element of costs will be a letter 'x' or a decimal digit ('0'-'9').
-There will be at least one valid path from the leftmost cell of topmost row to a cell in the bottommost row.
-costs[0][0] will always be '0'.


EXAMPLES

0)
{"042"
,"391"}

Returns: 13

Eel's optimal stategy is to put two walls: between '0'-'3' and between '2'-'1'. Then Rabbit's optimal strategy is to move the token along the path '0'->'4'->'9'. The total cost will be 13.

1)
{"0xxxx"
,"1x111"
,"1x1x1"
,"11191"
,"xxxx1"}

Returns: 16

There's only one path from the starting cell to the bottom row and Eel isn't allowed to block it. Rabbit will move the token along this path and will get to pay a cost of 16. Note that it is not allowed to move the token upwards.


2)
{"0"
,"5"}

Returns: 5



3)
{"0698023477896606x2235481563x59345762591987823x663"
,"1x88x8338355814562x2096x7x68546x18x54xx1077xx5131"
,"64343565721335639575x18059738478x156x781476124780"
,"2139850139989209547489708x3466104x5x3979260330074"
,"15316x57171x182167994729710304x24339370252x2x8846"
,"459x479948xx26916349194540891252317x99x4329x34x91"
,"96x3631804253899x69460666282614302698504342364742"
,"4x41693527443x7987953128673046855x793298x8747219x"
,"7735427289436x56129435153x83x37703808694432026643"
,"340x973216747311x970578x9324423865921864682853036"
,"x1442314831447x860181542569525471281x762734425650"
,"x756258910x0529918564126476x481206117984425792x97"
,"467692076x43x91258xx3xx079x34x29xx916574022682343"
,"9307x08x451x2882604411x67995x333x045x0x5xx4644590"
,"4x9x088309856x342242x12x79x2935566358156323631235"
,"04596921625156134477422x2691011895x8564609x837773"
,"223x353086929x27222x48467846970564701987061975216"
,"x4x5887805x89746997xx1419x758406034689902x6152567"
,"20573059x699979871151x444449x5170122650576586x898"
,"683344308229681464514453186x51040742xx138x5170x93"
,"1219892x9407xx63107x24x4914598xx4x478x31485x69139"
,"856756530006196x8722179365838x9037411399x41126560"
,"73012x9290145x1764125785844477355xx827269976x4x56"
,"37x95684445661771730x80xx2x459547x780556228951360"
,"54532923632041379753304212490929413x377x204659874"
,"30801x8716360708478705081091961915925276739027360"
,"5x74x4x39091353819x10x433010250089676063173896656"
,"03x07174x648272618831383631629x020633861270224x38"
,"855475149124358107x635160129488205151x45274x18854"
,"091902044504xx868401923845074542x50x143161647934x"
,"71215871802698346x390x2570413992678429588x5866973"
,"87x4538137828472265480468315701832x24590429832627"
,"9479550007750x658x618193862x80317248236583631x846"
,"49802902x511965239855908151316389x972x253946284x6"
,"053078091010241324x8166428x1x93x83809001454563464"
,"2176345x693826342x093950x12x7290x1186505760xx978x"
,"x9244898104910492948x2500050208763770568x92514431"
,"6855xx7x145213846746325656963x0419064369747824511"
,"88x15690xxx31x20312255171137133511507008114887695"
,"x391503034x01776xx30264908792724712819642x291x750"
,"17x1921464904885298x58x58xx174x7x673958x9615x9230"
,"x9217049564455797269x484428813681307xx85205112873"
,"19360179004x70496337008802296x7758386170452xx359x"
,"5057547822326798x0x0569420173277288269x486x582463"
,"2287970x0x474635353111x85933x33443884726179587xx9"
,"0x697597684843071327073893661811597376x4767247755"
,"668920978869307x17435748153x4233659379063530x646x"
,"0019868300350499779516950730410231x9x18749463x537"
,"00508xx083203827x42144x147181308668x3192478607467"}

Returns: 3512



*/

// END CUT HERE
