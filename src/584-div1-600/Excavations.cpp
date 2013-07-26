
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

    LL C[55][55];
    
    void makepas(){
		MSET(C, 0);
		C[0][0] = C[1][0] = C[1][1] = 1;
        for(int i=2; i<55; i++){
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j=1; j<i; j++){
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }




class Excavations {
public:
   long long count( vector <int> kind, vector <int> depth, vector <int> found, int K ) {

	// depthのconvert（圧縮）
	VI de = depth;
	sort(ALL(de));
	map<int, int> mp;
	for(int i = 0, j = 1; i < SZ(de); i++){
		if(mp.count(de[i]) == 0) mp[de[i]] = j++;
	}
	REP(i, SZ(depth)) depth[i] = mp[depth[i]];
	
	// found対象
	int n = SZ(found);
	VI good[n];
	REP(i, n){
		REP(j, SZ(kind)) if(kind[j] == found[i]) good[i].PB(depth[j]);
		sort(ALL(good[i]));
	}
	
	// found対象外
	VI bad;
	set<int> s; REP(i, SZ(found)) s.insert(found[i]);
	REP(i, SZ(kind)) if(s.count(kind[i]) == 0) bad.PB(depth[i]);
	sort(ALL(bad));	
	
	// found対象より１個以上ずつ抽出
	makepas();
	LL dp[55][55][55]; // 次に見るtype, 現在までの「それぞれのtypeの最小のdepth」の最大値, 現在までに選んだsiteの数
	MSET(dp, 0);
	dp[0][0][0] = 1;
	REP(i, n) REP(j, 55) REP(k, 55) if(dp[i][j][k] > 0){
		REP(at, SZ(good[i])){ // type-iから、最小のdepthをgood[i][at]として選ぶ
			for(int plus = 0; plus <= SZ(good[i])-at-1; plus++){ // at以降からplus個選ぶ
				dp[i+1][max(j, good[i][at])][k+plus+1] += dp[i][j][k] * C[SZ(good[i])-at-1][plus];
			}
		}
	}
	
	// found対象外より残りを抽出
	LL res = 0;
	REP(j, 55) REP(k, 55) if(dp[n][j][k] > 0 && k <= K){
		res += dp[n][j][k] * C[bad.end() - upper_bound(ALL(bad),j)][K-k];
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
			int kind[]                = {1, 1, 2, 2};
			int depth[]               = {10, 15, 10, 20};
			int found[]               = {1};
			int K                     = 2;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int kind[]                = {1, 1, 2, 2};
			int depth[]               = {10, 15, 10, 20};
			int found[]               = {1, 2};
			int K                     = 2;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int kind[]                = {1, 2, 3, 4};
			int depth[]               = {10, 10, 10, 10};
			int found[]               = {1, 2};
			int K                     = 3;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int kind[]                = {1, 2, 2, 3, 1, 3, 2, 1, 2};
			int depth[]               = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114};
			int found[]               = {1, 2, 3};
			int K                     = 7;
			long long expected__      = 35;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int kind[]                = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
			int depth[]               = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};
			int found[]               = {50};
			int K                     = 18;
			long long expected__      = 9075135300LL;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int kind[]                = ;
			int depth[]               = ;
			int found[]               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int kind[]                = ;
			int depth[]               = ;
			int found[]               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int kind[]                = ;
			int depth[]               = ;
			int found[]               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Excavations().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(depth, depth + (sizeof depth / sizeof depth[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
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
// Once upon a time, there was a civilization called Ruritania. It had n building sites numbered from 0 to n-1. There were various types of buildings such as libraries, markets, and palaces. Each building type was assigned an integer from 1 to 50. The building at site i (0-based index) was of type kind[i].

With the passing of millennia, Ruritania declined and its building sites were covered in sand, concealing all the buildings. Due to wind and terrain, the depth of the sand varied. The building at site i (0-based index) was buried depth[i] meters below the surface.

Recently, an intrepid archeologist excavated K building sites using a machine that could dig to a maximum depth of D meters. Thus, he only discovered buildings that had been buried at most D meters below the surface.

You are given vector <int>s kind, depth, and found as well as the int K. The types of buildings discovered by the excavation are given by the vector <int> found, which contains at most one value for each building type even if several buildings of a type were excavated.

Return the number of K-tuples of sites that could have been excavated to arrive at the given values. If the given information is not consistent with any configuration of building sites, return 0.


DEFINITION
Class:Excavations
Method:count
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:long long
Method signature:long long count(vector <int> kind, vector <int> depth, vector <int> found, int K)


CONSTRAINTS
-kind will contain N elements, where N is between 1 and 50, inclusive.
-Each element of kind will be between 1 and 50, inclusive.
-depth will contain N elements.
-Each element of depth will be between 1 and 100,000, inclusive.
-found will contain between 1 and 50 elements, inclusive.
-Each element of found will occur in kind at least once.
-The elements of found will be distinct.
-K will be between the number of elements in found and N, inclusive.


EXAMPLES

0)
{1, 1, 2, 2}
{10, 15, 10, 20}
{1}
2

Returns: 3

There are four building sites. Two have buildings of type 1 and two have buildings of type 2. The type 1 buildings are at depths 10 and 15. The type 2 buildings are at depths 10 and 20. The archeologist has excavated two sites and discovered only type 1 buildings. He must have excavated one of three possible pairs of sites:

Sites 0 and 1. The archeologist's machine excavates to a maximum depth D of at least 10.
Sites 0 and 3. The machine excavates to a maximum depth D that falls in the interval [10, 20).
Sites 1 and 3. The machine excavates to a maximum depth that falls in the interval [15, 20).

The other pairs of sites could not have been excavated. For example, the archeologist could not have excavated sites 0 and 2, because he would have found either none or both of the buildings.


1)
{1, 1, 2, 2}
{10, 15, 10, 20}
{1, 2}
2

Returns: 4

The archeologist could have chosen any pair of sites containing a type 1 and a type 2 building. With a large enough value of D, he could have excavated both.


2)
{1, 2, 3, 4}
{10, 10, 10, 10}
{1, 2}
3

Returns: 0

The archeologist cannot have excavated three sites, or else he would have found three types of buildings.

3)
{1, 2, 2, 3, 1, 3, 2, 1, 2}
{12512, 12859, 125, 1000, 99, 114, 125, 125, 114}
{1, 2, 3}
7

Returns: 35



4)
{50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}
{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}
{50}
18

Returns: 9075135300



*/

// END CUT HERE
