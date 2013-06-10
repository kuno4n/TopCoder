
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

//    struct P{
//        LL x, y;
//        P() {}
//        P(LL x, LL y) : x(x), y(y){
//        }
//        P operator + (P p){
//            return P(x+p.x, y+p.y);
//        }
//        P operator - (P p){
//            return P(x-p.x, y-p.y);
//        }
//        P operator * (LL d){
//            return P(x*d, y*d);
//        }
//        LL dot(P p){ // 内積
//            return x*p.x + y*p.y;
//        }
//        LL det(P p){ // 外積
//            return x*p.y - y*p.x;
//        }
//    }; 
       struct P{
        double x, y;
        P() {}
        P(double x, double y) : x(x), y(y){
        }
        P operator + (P p){
            return P(x+p.x, y+p.y);
        }
        P operator - (P p){
            return P(x-p.x, y-p.y);
        }
        P operator * (LL d){
            return P(x*d, y*d);
        }
        double dot(P p){ // 内積
            return x*p.x + y*p.y;
        }
        double det(P p){ // 外積
            return x*p.y - y*p.x;
        }
    };
    
    //線分p1-p2と線分q1-q2が交差していたら、trueを返す。
    //線分が重なっている場合はfalseを返す。
    //端点で交わっている場合もfalseを返す。
    bool intersect(P p1, P p2, P q1, P q2){
        double t1 = (p1.x - p2.x) * (q1.y - p1.y) + (p1.y - p2.y) * (p1.x - q1.x);
        double t2 = (p1.x - p2.x) * (q2.y - p1.y) + (p1.y - p2.y) * (p1.x - q2.x);
        double t3 = (q1.x - q2.x) * (p1.y - q1.y) + (q1.y - q2.y) * (q1.x - p1.x);
        double t4 = (q1.x - q2.x) * (p2.y - q1.y) + (q1.y - q2.y) * (q1.x - p2.x);
        if(t1*t2 < 0 && t3*t4 < 0) return true;
        return false;
    }

	//辞書順で比較
	bool cmp_x(const P& p, const P& q){
		if(p.x != q.x) return p.x < q.x;
		return p.y < q.y;
	}
    
	//凸包を求める。
	//nは要素数。
	//psはpの配列で渡すこと。
	vector<P> convex_hull(P* ps, int n){
		sort(ps, ps+n, cmp_x);
		int k = 0;
		vector<P> qs(n*2);
		REP(i, n){
			while(k>1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
			qs[k++] = ps[i];
		}
		for(int i=n-2, t=k; i>=0; i--){
			while(k>t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
			qs[k++] = ps[i];
		}
		qs.resize(k-1);
		return qs;
	}
	

bool check(vector<P> convex, P* ps, int n){
	REP(i, SZ(convex)) REP(j, n-1) FOR(k, j+1, n){
		P p1 = convex[i], p2 = convex[(i+1)%SZ(convex)], q1 = ps[j], q2 = ps[k];
		if(intersect(p1, p2, q1, q2)) return true;
	}
	return false;
}

class CheckerFreeness {
public:

   string isFree( vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY ) {
	string swx="", swy="", sbx="", sby="";
	REP(i, SZ(whiteX)) swx += whiteX[i];
	REP(i, SZ(whiteY)) swy += whiteY[i];
	REP(i, SZ(blackX)) sbx += blackX[i];
	REP(i, SZ(blackY)) sby += blackY[i];
	stringstream sswx, sswy, ssbx, ssby;
	sswx << swx, sswy << swy, ssbx << sbx, ssby << sby;
	P w[250], b[250];
	int nw=0, nb=0;
	LL elemx, elemy;
	while(sswx >> elemx && sswy >> elemy) w[nw++] = P(elemx, elemy);
	while(ssbx >> elemx && ssby >> elemy) b[nb++] = P(elemx, elemy);
	vector<P> convex_w = convex_hull(w, nw);
	vector<P> convex_b = convex_hull(b, nb);
	if(check(convex_w, b, nb) || check(convex_b, w, nw)) return "NO";
	return "YES";
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
			string whiteX[]           = {"1 2"};
			string whiteY[]           = {"2 1"};
			string blackX[]           = {"1 2"};
			string blackY[]           = {"1 2"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string whiteX[]           = {"2", "5", "3", " ", "1", "7", "3"};
			string whiteY[]           = {"180 254"};
			string blackX[]           = {"32", "5 1", "42"};
			string blackY[]           = {"462 423"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string whiteX[]           = {"1 10000000 9999999"};
			string whiteY[]           = {"1 9999999 1"};
			string blackX[]           = {"2 5000000 9999998"};
			string blackY[]           = {"2 5000001 9999999"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string whiteX[]           = {"1"};
			string whiteY[]           = {"2"};
			string blackX[]           = {"3"};
			string blackY[]           = {"4"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string whiteX[]           = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
,"93 5922 714 2258 4369 9524 302 8417 6620 1143"};
			string whiteY[]           = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"};
			string blackX[]           = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"};
			string blackY[]           = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string whiteX[]           = {"219211 1996214 1706774 3634920 909831 1774128 8503"
,"52 2233050 2099138 3380396 1128982 3682525 1483700"
," 763080 487867 8203 1791027 463556 1103323 1406861"
," 6374234 760949 4340236 727393 2073832 1289052 103"
,"8147 4448130 151066 412440 1068735 377239 2677933 "
,"1299598 339843 289973 3707319 555280 230418 431719"};
			string whiteY[]           = {"1638083 5698739 3105504 9726902 9745795 5049444 15"
,"80592 3952120 6606668 7460527 7239299 8726128 4913"
,"547 6264100 5701660 8865937 4969114 8014845 327236"
,"1 6389154 9739755 2561669 9412417 5452337 3150506 "
,"5832197 1571976 8779325 3306446 948271 5133709 949"
,"394 6919798 7525636 3568024 6833196 9237472 733313"
,"1 9939064 9720014"};
			string blackX[]           = {"5860334 8007503 7455523 4864927 9573526 2718360 81"
,"12104 6684287 9921506 4840886 5415948 3451454 5320"
,"996 9268757 9261724 8254668 2292750 8035828 233352"
,"1 7676906 5234406 8533320 6562751 4884098 4971897 "
,"5569360 8519168 3100295 9351613 7733878 7579030 32"
,"46775 7297460 8370542 7099759 5782969 2978083 3390"
,"488 7482758 1332401 6094629 9717305 5503121 572842"
,"1 4903563 6331656 2867455 3410007 7751527 7228221 "
,"4111694 5171296 6847697 4601273 7599828 5515929 94"
,"60593 9332762 5389080 4512091 8668538 5711743 5838"
,"534 4825079 8145628 3810005 2964724 5594550 785748"
,"3 6283769"};
			string blackY[]           = {"5911694 8009943 212555 5838688 9896256 607434 5857"
,"663 4616750 1477573 7168026 3090917 4379806 326465"
,"7 4189076 2104028 3279691 94211 8503556 78457 4394"
,"360 3344176 3223317 2624498 4883494 1532240 732937"
,"1 1518674 1353567 892134 5536454 8527392 2603965 6"
,"623264 8830827 2030444 3002706 83058 4475866 20876"
,"25 1790695 4034441 5409379 3571098 4600050 736561 "
,"250475 3733256 3011439 2144994 4523046 3119883 607"
,"582 8361403 6525451 7518329 926803 4884524 8424659"
," 7088689 5762049 9532481 4914186 7314621 4339084 3"
,"741685 3837953 3177252 612550 9688871 5872931"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string whiteX[]           = ;
			string whiteY[]           = ;
			string blackX[]           = ;
			string blackY[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string whiteX[]           = ;
			string whiteY[]           = ;
			string blackX[]           = ;
			string blackY[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string whiteX[]           = ;
			string whiteY[]           = ;
			string blackX[]           = ;
			string blackY[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CheckerFreeness().isFree(vector <string>(whiteX, whiteX + (sizeof whiteX / sizeof whiteX[0])), vector <string>(whiteY, whiteY + (sizeof whiteY / sizeof whiteY[0])), vector <string>(blackX, blackX + (sizeof blackX / sizeof blackX[0])), vector <string>(blackY, blackY + (sizeof blackY / sizeof blackY[0])));
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
// Given is a finite set S of distinct points in the XY plane.
No three of the points lie on the same line.
Each of the points is colored either white or black.
A convex quadrilateral with vertices in four of the vertices of S is called a checker if no pair of adjacent vertices shares the same color.
In other words, in a checker two opposite vertices have to be white and the other two have to be black.
The set S is called checker-free if there is no checker with vertices in the set.





You are given four vector <string>s: whiteX, whiteY, blackX, and blackY.
These encode the X and Y coordinates of all white and all black points in S, respectively.
By concatenating all elements of whiteX you will obtain a list of positive integers separated by single spaces: the X-coordinates of all white points.
By concatenating all elements of whiteY you will obtain a list of positive integers separated by single spaces: the Y-coordinates of all white points, in the same order.
The vector <string>s blackX and blackY describe the black points in S in the same way.

Return "YES" if the given set is checker-free. Otherwise, return "NO".

DEFINITION
Class:CheckerFreeness
Method:isFree
Parameters:vector <string>, vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY)


CONSTRAINTS
-whiteX, whiteY, blackX and blackY will each contain between 1 and 50 elements, inclusive.
-Each element of whiteX, whiteY, blackX and blackY will contain between 1 and 50 characters, inclusive.
-After concatenating the elements of whiteX, the resulting string will be a single space separated list of integers. The same things will hold for whiteY, blackX and blackY.
-There will be between 1 and 222 integers in each of the lists.
-The number of integers in the lists of whiteX and whiteY will be the same.
-The number of integers in the lists of blackX and blackY will be the same.
-Each integer in the lists will be between 1 and 10,000,000, inclusive.
-No two points will be the same.
-No three points will be on the same line.
-Integers in the lists will have no leading zeros.


EXAMPLES

0)
{"1 2"}
{"2 1"}
{"1 2"}
{"1 2"}

Returns: "NO"




1)
{"2", "5", "3", " ", "1", "7", "3"}
{"180 254"}
{"32", "5 1", "42"}
{"462 423"}

Returns: "YES"

Concatenate all elements of each vector <string> correctly.




2)
{"1 10000000 9999999"}
{"1 9999999 1"}
{"2 5000000 9999998"}
{"2 5000001 9999999"}

Returns: "YES"

The values of coordinates can be large.
Watch out for overflow and precision errors.

3)
{"1"}
{"2"}
{"3"}
{"4"}

Returns: "YES"

There are only two points, so this input is obviously checker-free.

4)
{"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
,"93 5922 714 2258 4369 9524 302 8417 6620 1143"}
{"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"}
{"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"}
{"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"}

Returns: "NO"



5)
{"219211 1996214 1706774 3634920 909831 1774128 8503"
,"52 2233050 2099138 3380396 1128982 3682525 1483700"
," 763080 487867 8203 1791027 463556 1103323 1406861"
," 6374234 760949 4340236 727393 2073832 1289052 103"
,"8147 4448130 151066 412440 1068735 377239 2677933 "
,"1299598 339843 289973 3707319 555280 230418 431719"}
{"1638083 5698739 3105504 9726902 9745795 5049444 15"
,"80592 3952120 6606668 7460527 7239299 8726128 4913"
,"547 6264100 5701660 8865937 4969114 8014845 327236"
,"1 6389154 9739755 2561669 9412417 5452337 3150506 "
,"5832197 1571976 8779325 3306446 948271 5133709 949"
,"394 6919798 7525636 3568024 6833196 9237472 733313"
,"1 9939064 9720014"}
{"5860334 8007503 7455523 4864927 9573526 2718360 81"
,"12104 6684287 9921506 4840886 5415948 3451454 5320"
,"996 9268757 9261724 8254668 2292750 8035828 233352"
,"1 7676906 5234406 8533320 6562751 4884098 4971897 "
,"5569360 8519168 3100295 9351613 7733878 7579030 32"
,"46775 7297460 8370542 7099759 5782969 2978083 3390"
,"488 7482758 1332401 6094629 9717305 5503121 572842"
,"1 4903563 6331656 2867455 3410007 7751527 7228221 "
,"4111694 5171296 6847697 4601273 7599828 5515929 94"
,"60593 9332762 5389080 4512091 8668538 5711743 5838"
,"534 4825079 8145628 3810005 2964724 5594550 785748"
,"3 6283769"}
{"5911694 8009943 212555 5838688 9896256 607434 5857"
,"663 4616750 1477573 7168026 3090917 4379806 326465"
,"7 4189076 2104028 3279691 94211 8503556 78457 4394"
,"360 3344176 3223317 2624498 4883494 1532240 732937"
,"1 1518674 1353567 892134 5536454 8527392 2603965 6"
,"623264 8830827 2030444 3002706 83058 4475866 20876"
,"25 1790695 4034441 5409379 3571098 4600050 736561 "
,"250475 3733256 3011439 2144994 4523046 3119883 607"
,"582 8361403 6525451 7518329 926803 4884524 8424659"
," 7088689 5762049 9532481 4914186 7314621 4339084 3"
,"741685 3837953 3177252 612550 9688871 5872931"}

Returns: "YES"



*/

// END CUT HERE
