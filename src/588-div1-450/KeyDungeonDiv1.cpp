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


int r[1<<12][140], g[1<<12][140], w[1<<12][140];


class KeyDungeonDiv1 {
	public:
	int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys) {
        MSET(r, -1); MSET(g, -1); MSET(w, -1);
        int n = SZ(doorR);
        r[0][keys[0]] = keys[0], g[0][keys[0]] = keys[1], w[0][keys[0]] = keys[2];
        
        int res = 0;
        REP(i, (1<<n)) REP(j, 140) if(r[i][j] >= 0){
            chmax(res, r[i][j]+g[i][j]+w[i][j]);
            REP(k, n) if(!(i&(1<<k))){
                int nr = r[i][j], ng = g[i][j], nw = w[i][j];
                nr -= doorR[k];
                if(nr < 0){
                    nw += nr;
                    if(nw < 0) continue;
                    nr = 0;
                }
                ng -= doorG[k];
                if(ng < 0){
                    nw += ng;
                    if(nw < 0) continue;
                    ng = 0;
                }
                nr += roomR[k], ng += roomG[k], nw += roomW[k];
                if(w[i|(1<<k)][nr] < nw){
                    r[i|(1<<k)][nr] = nr;
                    g[i|(1<<k)][nr] = ng;
                    w[i|(1<<k)][nr] = nw;
                }
            }
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
			int doorR[]               = {1, 2, 3};
			int doorG[]               = {0, 4, 9};
			int roomR[]               = {0, 0, 10};
			int roomG[]               = {0, 8, 9};
			int roomW[]               = {1, 0, 8};
			int keys[]                = {3, 1, 2};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int doorR[]               = {1, 1, 1, 2};
			int doorG[]               = {0, 2, 3, 1};
			int roomR[]               = {2, 1, 0, 4};
			int roomG[]               = {1, 3, 3, 1};
			int roomW[]               = {1, 0, 2, 1};
			int keys[]                = {0, 4, 0};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int doorR[]               = {2, 0, 4};
			int doorG[]               = {3, 0, 4};
			int roomR[]               = {0, 0, 9};
			int roomG[]               = {0, 0, 9};
			int roomW[]               = {8, 5, 9};
			int keys[]                = {0, 0, 0};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int doorR[]               = {5, 3, 0, 0};
			int doorG[]               = {0, 1, 2, 1};
			int roomR[]               = {0, 9, 2, 4};
			int roomG[]               = {2, 9, 2, 0};
			int roomW[]               = {0, 9, 1, 1};
			int keys[]                = {1, 1, 0};
			int expected__            = 32;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int doorR[]               = {9,5,10,8,4,3,0,8,4,1,3,9};
			int doorG[]               = {9,10,0,8,9,4,3,8,1,8,10,4};
			int roomR[]               = {1,2,0,2,3,3,5,3,1,3,0,5};
			int roomG[]               = {5,2,5,0,5,2,3,4,0,0,5,2};
			int roomW[]               = {1,5,1,2,0,4,4,0,3,3,1,3};
			int keys[]                = {5,0,1};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int doorR[]               = {0, 1, 4};
			int doorG[]               = {1, 0, 3};
			int roomR[]               = {2, 2, 9};
			int roomG[]               = {2, 2, 9};
			int roomW[]               = {0, 0, 0};
			int keys[]                = {0, 0, 1};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int doorR[]               = ;
			int doorG[]               = ;
			int roomR[]               = ;
			int roomG[]               = ;
			int roomW[]               = ;
			int keys[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int doorR[]               = ;
			int doorG[]               = ;
			int roomR[]               = ;
			int roomG[]               = ;
			int roomW[]               = ;
			int keys[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
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
// You are exploring a dungeon.
In the dungeon you found some locked doors.
Each locked door has some red and some green keyholes (zero or more of each kind).
In order to open a door, you must insert fitting keys into all its keyholes simultaneously.
All the keys used to open a door break in the process of opening it and you have to throw them away.
However, each door hides a small chamber that contains some new keys for you.
Once you open the door, you may take all of those keys and possibly use them to open new doors.
(Of course, it only makes sense to open each door at most once. If you open the same door again, there will be no new keys for you.) 

There are three kinds of keys: red, green, and white ones.
Each red key fits into any red keyhole.
Each green key fits into any green keyhole.
Each white key fits into any keyhole (both red and green ones). 

You are given vector <int>s doorR, doorG, roomR, roomG, and roomW.
These five vector <int>s all have the same length.
For each valid i, the values at index i describe one of the doors you found:
the door has doorR[i] red and doorG[i] green keyholes, and upon opening it you gain new keys: roomR[i] red ones, roomG[i] green ones, and roomW[i] white ones. 

You are also given the vector <int> keys with three elements:
keys[0] is the number of red keys, keys[1] the number of green keys, and keys[2] the number of white keys you have at the beginning. 

Your goal is to have as many keys as possible at the moment when you decide to stop opening doors.
(The colors of the keys do not matter.)
You are allowed to open the doors in any order you like, and to choose the keys used to open each of the doors.
You are also allowed to stop opening doors whenever you are satisfied with your current number of keys.
Compute and return the maximal total number of keys you can have at the end.

DEFINITION
Class:KeyDungeonDiv1
Method:maxKeys
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys)


CONSTRAINTS
-doorR, doorG, roomR, roomG and roomW will each contain between 1 and 12 elements, inclusive.
-doorR, doorG, roomR, roomG and roomW will contain the same number of elements.
-Each element of doorR, doorG, roomR, roomG and roomW will be between 0 and 10, inclusive.
-keys will contain exactly 3 elements.
-Each element of keys will be between 0 and 10, inclusive.


EXAMPLES

0)
{1, 2, 3}
{0, 4, 9}
{0, 0, 10}
{0, 8, 9}
{1, 0, 8}
{3, 1, 2}

Returns: 8

First you have 3 red keys, 1 green key, 2 white keys. You can end with 8 keys as follows:


First, you open door 0 using 1 red key. From the opened chamber you gain 1 white key, so currently you have 2 red keys, 1 green key, and 3 white keys.


Second, you open door 1 using 2 red keys, 1 green key, and 3 white keys (all of them into green locks). Immediately after opening the door you have no keys: all the ones you had were just used and thus they broke. However, the chamber you just opened contains 8 green keys.


You can't end with more than 8 keys, so you should return 8.

1)
{1, 1, 1, 2}
{0, 2, 3, 1}
{2, 1, 0, 4}
{1, 3, 3, 1}
{1, 0, 2, 1}
{0, 4, 0}

Returns: 4

You have only green keys, while each door has at least 1 red keyhole. So you cannot open any of the doors.

2)
{2, 0, 4}
{3, 0, 4}
{0, 0, 9}
{0, 0, 9}
{8, 5, 9}
{0, 0, 0}

Returns: 27

Initially you have no key at all, but door 1 also has no key hole. Therefore, you can start by opening door 1.

3)
{5, 3, 0, 0}
{0, 1, 2, 1}
{0, 9, 2, 4}
{2, 9, 2, 0}
{0, 9, 1, 1}
{1, 1, 0}

Returns: 32



4)
{9,5,10,8,4,3,0,8,4,1,3,9}
{9,10,0,8,9,4,3,8,1,8,10,4}
{1,2,0,2,3,3,5,3,1,3,0,5}
{5,2,5,0,5,2,3,4,0,0,5,2}
{1,5,1,2,0,4,4,0,3,3,1,3}
{5,0,1}

Returns: 16



*/

// END CUT HERE
