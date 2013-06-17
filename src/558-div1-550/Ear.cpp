
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

int rx[310], bx[310], by[310];
int rcnt, bcnt;

// vector <string> vs = {"34 22 1", "00, 54"} みたいに入っている数値を、
// int a[300] みたいな配列に入れて、要素数をnに入れる。
// parse(vs, a, n); みたいに呼ぶ
void parse(vector<string> &s, int *a, int &n){
	n = 0;
	string t;
	REP(i, s.size()) t += s[i];
	stringstream ss(t);
	while(ss >> a[n]) n++;
}

class Ear {
public:
   long long getCount( vector <string> redX, vector <string> blueX, vector <string> blueY ) {
	parse(redX, rx, rcnt);
	parse(blueX, bx, bcnt);
	parse(blueY, by, bcnt);
//	string srx, sbx, sby;
//	REP(i, SZ(redX)) srx += redX[i];
//	REP(i, SZ(blueX)) sbx += blueX[i];
//	REP(i, SZ(blueY)) sby += blueY[i];
//	MSET(rx, 0), MSET(bx, 0), MSET(by, 0);
//	rcnt = 0;
//	stringstream ssrx;
//	ssrx << srx;
//	while(ssrx >> rx[rcnt++]); rcnt--;
//	stringstream ssbx;
//	bcnt = 0;
//	ssbx << sbx;
//	while(ssbx >> bx[bcnt++]); bcnt--;
//	stringstream ssby;
//	bcnt = 0;
//	ssby << sby;
//	while(ssby >> by[bcnt++]); bcnt--;
	
	sort(rx, rx+rcnt);
	LL res = 0;
	REP(i, bcnt) REP(j, bcnt){
		if(by[i] <= by[j]) continue;
		int l1 = lower_bound(rx, rx+rcnt, bx[j]) - rx - 1;
		int r1 = lower_bound(rx, rx+rcnt, bx[j]+1) - rx;
		int l2, r2;
		if(bx[i] < bx[j]){
			l2 = min(l1-1, lower_bound(rx, rx+rcnt, bx[i]) - rx - 1);
			int dx = bx[j]-bx[i], dy = by[i]-by[j];
			r2 = max(r1+1, lower_bound(rx, rx+rcnt, bx[i]+dx*by[i]/dy+1) - rx);
		}
		if(bx[i] == bx[j]){
			l2 = l1 - 1;
			r2 = r1 + 1;
		}
		if(bx[i] > bx[j]){
			int dx = bx[j]-bx[i], dy = by[i]-by[j];
			l2 = min(l1-1, lower_bound(rx, rx+rcnt, bx[i]+dx*by[i]/dy) - rx - 1);
			r2 = max(r1+1, lower_bound(rx, rx+rcnt, bx[i]+1) - rx);
		}
		if(l2 < 0 || r2 >= rcnt) continue;
		res += (l2+1)*(2*(LL)l1-l2) * (rcnt-r2)*(2*(LL)(r2-r1) + (rcnt-r2-1)) / 4;
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
			string redX[]             = {"3 2 8 7"};
			string blueX[]            = {"5 4"};
			string blueY[]            = {"2 4"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string redX[]             = {"3 2 8 7"};
			string blueX[]            = {"2 8"};
			string blueY[]            = {"3 4"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string redX[]             = {"1 2 6 9"};
			string blueX[]            = {"3 6 8 5"};
			string blueY[]            = {"1 5 4 3"};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string redX[]             = {"10000"};
			string blueX[]            = {"10000 9999"};
			string blueY[]            = {"10000 9999"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string redX[]             = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
			string blueX[]            = {"15", "0 250 ", "349"};
			string blueY[]            = {"2 3 1"};
			long long expected__      = 12;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string redX[]             = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
			string blueX[]            = {"4", " ", "5", " ", "6", " 7 ", "8"};
			string blueY[]            = {"1", " 2 ", "3 4", " 5"};
			long long expected__      = 204;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			string redX[]             = {"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20"};
			string blueX[]            = {"12 9 6 3"};
			string blueY[]            = {"1 2 3 4"};
			long long expected__      = 4680;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
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
// There are some red points and blue points on the Cartesian plane.
All red points are on the x-axis and all blue points are in the upper half-plane. That is, the y-coordinate of each red point is 0, and the y-coordinate of each blue point is strictly positive.

Fox Ciel wants to form an ear-shaped figure using these points.
She defines that the pair of four different red points A, B, C, D and two blue points P, Q is called an ear if and only if all the following conditions are satisfied.


Both points B and C lie strictly inside the segment AD.
The angles PAD, PDA, QBC and QCB are strictly less than 90 degrees.
Point Q is strictly inside of the triangle PAD.


In the following image, points in the left figure form an ear while points in the right figure do not.



You are given three vector <string>s redX, blueX and blueY.
Concatenate all elements of redX to get a space-separate list of integers.
The i-th integer of this list represents the x-coordinate of i-th red point.
In the same way, blueX and blueY encode lists of x-coordinates and y-coordinates of blue points.

Your method must return the number of ways in which we can choose the four red and two blue points that form an ear.


DEFINITION
Class:Ear
Method:getCount
Parameters:vector <string>, vector <string>, vector <string>
Returns:long long
Method signature:long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY)


NOTES
-The order of points in an ear does not matter. I.e., if two ears have the same four red and two blue points, they are considered the same.


CONSTRAINTS
-redX, blueX and blueY will each contain between 1 and 50 elements, inclusive.
-Each element of redX, blueX and blueY will contain between 1 and 50 characters, inclusive.
-After concatenating the elements of redX, the resulting string will be a single space separated list of integers.
-After concatenating the elements of blueX, the resulting string will be a single space separated list of integers.
-After concatenating the elements of blueY, the resulting string will be a single space separated list of integers.
-There will be between 1 and 300 integers in each of the lists.
-The number of integers in the lists of blueX and blueY will be the same.
-Each integer in the lists will be between 1 and 10,000, inclusive.
-All the integers in each list will be distinct.
-Integers in the lists will have no leading zeros.


EXAMPLES

0)
{"3 2 8 7"}
{"5 4"}
{"2 4"}

Returns: 1

This case corresponds to the left figure in the statement.

1)
{"3 2 8 7"}
{"2 8"}
{"3 4"}

Returns: 0

This case corresponds to the right figure in the statement.

2)
{"1 2 6 9"}
{"3 6 8 5"}
{"1 5 4 3"}

Returns: 4

There exists only one possible combinations of A, B, C and D since there are only four red points. Possible combinations of P and Q are as follows.

{(5, 3), (3, 1)}
{(6, 5), (3, 1)}
{(8, 4), (3, 1)}
{(6, 5), (5, 3)}




3)
{"10000"}
{"10000 9999"}
{"10000 9999"}

Returns: 0

It is impossible to choose four red points from only one red point.

4)
{"100 2", "00", " 39", "9", " 800 900 9", "99"}
{"15", "0 250 ", "349"}
{"2 3 1"}

Returns: 12

Concatenate each element of the vector <string>s correctly.

5)
{"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}
{"4", " ", "5", " ", "6", " 7 ", "8"}
{"1", " 2 ", "3 4", " 5"}

Returns: 204



*/

// END CUT HERE
