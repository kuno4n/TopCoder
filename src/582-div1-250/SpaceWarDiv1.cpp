
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class SpaceWarDiv1 {
public:
   long long minimalFatigue( vector <int> ms, vector <int> es, vector<long long> ec ) {
	sort(ALL(ms));
	int n = SZ(ms), m = SZ(es);
	int mxm = 0, mxe = 0;
	REP(i, n) chmax(mxm, ms[i]);
	REP(i, m) chmax(mxe, es[i]);
	if(mxm < mxe) return -1;
	
	LL table[55]; MSET(table, 0);
	LL all = 0;
	REP(i, m){
		REP(j, n) if(es[i] <= ms[j]) table[j] += ec[i];
		all += ec[i];
	}
	LL lo = 0, hi = 10000000000000000LL;
	while(hi-lo > 1){
		LL md = (lo + hi) / 2;
		LL end = 0;
		REP(i, n) end += min(md, table[i]-end);
		if(end == all) hi = md;
		else lo = md;
	}
 	return hi;

   }
};

//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5
//2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
//100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000
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
			int magicalGirlStrength[] = {2, 3, 5};
			int enemyStrength[]       = {1, 3, 4};
			long long enemyCount[]    = {2, 9, 4};
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int magicalGirlStrength[] = {2, 3, 5};
			int enemyStrength[]       = {1, 1, 2};
			long long enemyCount[]    = {2, 9, 4};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int magicalGirlStrength[] = {14, 6, 22};
			int enemyStrength[]       = {8, 33};
			long long enemyCount[]    = {9, 1};
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int magicalGirlStrength[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
			int enemyStrength[]       = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
			long long enemyCount[]    = {20626770196420LL, 45538527263992LL, 52807114957507LL, 17931716090785LL, 65032910980630LL, 88711853198687LL, 26353250637092LL, 61272534748707LL, 89294362230771LL, 52058590967576LL, 60568594469453LL, 23772707032338LL, 43019142889727LL, 39566072849912LL, 78870845257173LL, 68135668032761LL, 36844201017584LL, 10133804676521LL, 6275847412927LL, 37492167783296LL};
			long long expected__      = 75030497287405LL;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int magicalGirlStrength[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5};
			int enemyStrength[]       = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
			long long enemyCount[]    = {100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000,100000000000000};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int magicalGirlStrength[] = ;
			int enemyStrength[]       = ;
			long long enemyCount[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int magicalGirlStrength[] = ;
			int enemyStrength[]       = ;
			long long enemyCount[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
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
// Magical Girls are girls who have magical powers.
They fight against evil to protect the Earth.
Cosmic enemies have just attacked the Earth, and the Magical Girls are going to fight them.

You are given a vector <int> magicalGirlStrength that describes the Magical Girls:
for each i, magicalGirlStrength[i] is the strength of one of the girls.
You are also given a vector <int> enemyStrength and a vector<long long> enemyCount that describe their enemies:
for each i, there are enemyCount[i] enemies that each have strength enemyStrength[i].

Each Magical Girl will always fight one enemy at a time.
A Magical Girl will defeat her enemy if her strength is greater than or equal to the strength of that enemy.

At the beginning of the fight the fatigue of each Magical Girl is 0.
Each time a Magical Girl defeats an enemy, her fatigue increases by 1.

The Magical Girls want to defeat all the enemies.
That is, each of the enemies must be defeated by one of the Magical Girls.
Additionally, the Magical Girls want to minimize the maximum fatigue among them.

If it is impossible to defeat all of the enemies, return -1.
Otherwise, return the smallest F with the following property:
the Magical Girls can defeat all enemies in such a way that at the end the fatigue of each girl is at most F.

DEFINITION
Class:SpaceWarDiv1
Method:minimalFatigue
Parameters:vector <int>, vector <int>, vector<long long>
Returns:long long
Method signature:long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount)


NOTES
-The elements of enemyStrength are not necessarily pairwise distinct.


CONSTRAINTS
-magicalGirlStrength will contain between 1 and 50 elements, inclusive.
-Each element of magicalGirlStrength will be between 1 and 10,000, inclusive.
-enemyStrength and enemyCount will each contain between 1 and 50 elements, inclusive.
-enemyStrength and enemyCount will contain the same number of elements.
-Each element of enemyStrength will be between 1 and 10,000, inclusive.
-Each element of enemyCount will be between 1 and 100,000,000,000,000 (10^14), inclusive.


EXAMPLES

0)
{2, 3, 5}
{1, 3, 4}
{2, 9, 4}

Returns: 7

There are 3 Magical Girls, their strength are 2, 3, and 5.
There are 3 kinds of enemies: 2 enemies with strength 1 each, 9 enemies with strength 3 each, and 4 enemies with strength 4 each.
This is one of the ways how to minimize the maximal fatigue:

Magical girl 0 defeats 2 enemies with strength 1.
Magical girl 1 defeats 7 enemies with strength 3.
Magical girl 2 defeats 2 enemies with strength 3 and 4 enemies with strength 4.


1)
{2, 3, 5}
{1, 1, 2}
{2, 9, 4}

Returns: 5

Each of the Magical Girls can defeat any of the enemies. The optimal strategy is that each girl should defeat 5 of the enemies.

2)
{14, 6, 22}
{8, 33}
{9, 1}

Returns: -1

None of the magical girls can defeat the enemy with strength 33.

3)
{869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}
{789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}
{20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}

Returns: 75030497287405



*/

// END CUT HERE
