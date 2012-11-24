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

class AntsMeet {
    struct ant{
        int x;
        int y;
        char dir;
        void move(){
            if(dir=='N') y++;
            if(dir=='W') x--;
            if(dir=='S') y--;
            if(dir=='E') x++;
        }
        bool erase;
    };
    
    struct ant_less{
        bool operator()(const ant& left, const ant& right){
            return left.x < right.x;
        }
    };
    struct ant_y{
        bool operator()(const ant& left, const ant& right){
            return left.y < right.y;
        }
    };
    
	public:
	int countAnts(vector <int> x, vector <int> y, string direction) {
        vector <ant> ants;
        ants.clear();
		REP(i, SZ(x)){
            ant a;
            a.x = x[i]*2;
            a.y = y[i]*2;
            a.dir = direction[i];
            a.erase = false;
            ants.push_back(a);
        }
        
        REP(k, 5000){
            REP(i, SZ(ants)){
                ants[i].move();
            }
            sort(ALL(ants), ant_y());
            stable_sort(ALL(ants), ant_less());
            FOR(i,1,SZ(ants)){
                if(ants[i].x==ants[i-1].x && ants[i].y==ants[i-1].y){
                    ants[i].erase = true;
                    ants[i-1].erase = true;
                }
            }
//            REP(i, SZ(ants)) if(ants[i].erase) {
//                OUT(k);
//                OUT(ants[i].x);
//                OUT(ants[i].y);
//                ants.erase(i);
//            }
            for(typeof((ants).begin()) it = (ants).begin(); it != (ants).end();){
                if((*it).erase){
                    it = ants.erase(it);
                    continue;
                }
                it++;
            }
        }
        
        return SZ(ants);
        
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
			int x[]                   = {0,10,20,30};
			int y[]                   = {0,10,20,30};
			string direction          = "NWNE";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-10,0,0,10};
			int y[]                   = {0,-10,10,0};
			string direction          = "NEWS";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-1,-1,-1,0,0,0,1,1,1};
			int y[]                   = {-1,0,1,-1,0,1,-1,0,1};
			string direction          = "ESEWNNEWW";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
			int y[]                   = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
			string direction          = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
			int expected__            = 25;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423 ,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
			int y[]                   = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216 ,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
			string direction          = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
			int expected__            = 44;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          int x[]                   = {0,1};
          int y[]                   = {0,0};
          string direction          = "EW";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			string direction          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			string direction          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AntsMeet().countAnts(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), direction);
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
// Magical Girl Lein is observing ants. 
There are N ants. At first, they have integer coordinates in the Cartesian plane. More precisely, ant i starts at the point (x[i], y[i]). 
All ants move at the same speed. Each ant moves in one of the four basic directions. (I.e., either parallel to the x axis or parallel to the y axis.) 
When 2 or more ants meet at the same time, these ants disappear. 
You are given two vector <int>s x and y, containing N elements each, 
and a string direction, containing N characters. 
Character i of direction encodes the direction in which ant i is going: 

 'N' means north (y coordinate increases), 
 'E' means east (x coordinate increases), 
 'S' means south (y coordinate decreases), 
 and 'W' means west (x coordinate decreases). 

Return the number of ants that still exist after the last meeting occurs.

DEFINITION
Class:AntsMeet
Method:countAnts
Parameters:vector <int>, vector <int>, string
Returns:int
Method signature:int countAnts(vector <int> x, vector <int> y, string direction)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-The number of characters in direction will be the same as the number of elements in x.
-Each element of x and y will be between -1000 and 1000, inclusive.
-No pair of points in the input will be equal.
-Each character of direction will be one of 'N', 'E', 'W' and 'S'.


EXAMPLES

0)
{0,10,20,30}
{0,10,20,30}
"NWNE"

Returns: 2

The ants that start at (0,0) and (10,10) will meet at (0, 10) at time 10.
The remaining two ants will never meet.

1)
{-10,0,0,10}
{0,-10,10,0}
"NEWS"

Returns: 0

More than two ants can meet at the same time.

2)
{-1,-1,-1,0,0,0,1,1,1}
{-1,0,1,-1,0,1,-1,0,1}
"ESEWNNEWW"

Returns: 4

The ants that start at (-1,-1) and (0,-1) will meet at (-0.5,-1). 
The ants that start at (-1,1), (0,0) and (1,1) will meet at (0,1). 
Thus, 4 ants will remain after all meetings. 
Note that ants that start at (-1,0) and (0,-1) won't meet at (-1,1) because one of them will disappear before reaching the meeting point.

3)
{4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3}
{2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3}
"SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" 

Returns: 25



4)
{478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493}
{-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337}
"WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE"

Returns: 44



*/

// END CUT HERE
