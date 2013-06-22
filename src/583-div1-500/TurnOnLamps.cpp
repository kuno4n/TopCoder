
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

VI r;
string st, isI;
bool G[55][55];
VI table[55][55];
int n;

//void turn(int edge){
//	if(st[edge] == '1') return;
//	st[edge] = '1';
//	
//	int n1 = r[edge];
//	int n2 = edge+1;
//	
//	if(n1 != 0 && n1-1 != edge) turn(n1-1);
//	if(n2 != 0 && n2-1 != edge) turn(n2-1);
//	REP(i, n){
//		if(i == edge) continue;
//		if(r[i] == n1) turn(i);
//		if(r[i] == n2) turn(i);
//	}
//	return;
//}


map<pair<int, int> , int> n_e;

int cnt(int n1, int n2){
	VI vi = table[n1][n2];
	int res = 0;
	REP(i, SZ(vi)){
		if(isI[vi[i]] == '1' && st[vi[i]] == '0') res++;
		if(isI[vi[i]] == '1' && st[vi[i]] == '1') res--;
	}	
	return res;
}

void turn(int n1, int n2){
	VI vi = table[n1][n2];
	REP(i, SZ(vi)) if(isI[vi[i]] == '1') st[vi[i]] = (st[vi[i]] == '0' ? '1' : '0');
}

class TurnOnLamps {
public:
   int minimize( vector <int> roads, string initState, string isImportant ) {
	r = roads;
	st = initState, isI = isImportant;
	n = SZ(r) + 1;
	
	n_e.clear();
	REP(i, n) REP(j, n) G[i][j] = false, table[i][j].clear();
	REP(i, n-1){
		int n1 = r[i], n2 = i+1;
		G[n1][n2] = true;
		G[n2][n1] = true;
		pair<int, int> a = make_pair(n1, n2);
		pair<int, int> b = make_pair(n2, n1);
		n_e[a] = i;
		n_e[b] = i;
	}
	REP(start, n){
		queue<int> q_node;
		queue< VI > q_edge;
		bool vis[n]; REP(i, n) vis[i] = false;
		
		q_node.push(start);
		q_edge.push(vector<int>(0));
		
		while(SZ(q_node)){
			int node = q_node.front(); q_node.pop();
			VI vi = q_edge.front(); q_edge.pop();
			if(vis[node]) continue;
			vis[node] = true;
			table[start][node] = vi;
			REP(nxt, n){
				if(!G[node][nxt]) continue;
				VI tmp = vi; tmp.push_back(n_e[make_pair(node, nxt)]);
				q_node.push(nxt);
				q_edge.push(tmp);
			}
		}
	}
	
	
	
	int res = 0;
	while(1){
		int mx = 0;
		int i, j;
		REP(ii, n) REP(jj, n) {
			int tmp = cnt(ii, jj);
			if(tmp > mx) i = ii, j = jj, mx = tmp;
		}
		if(mx == 0) break;
		res++;
		turn(i, j);
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
			int roads[]               = {0,0,1,1};
			string initState          = "0001";
			string isImportant        = "0111";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int roads[]               = {0,0,1,1};
			string initState          = "0000";
			string isImportant        = "0111";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int roads[]               = {0,0,1,1,4,4};
			string initState          = "000100";
			string isImportant        = "111111";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int roads[]               = {0,0,1,1,4,4};
			string initState          = "100100";
			string isImportant        = "011101";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int roads[]               = {0,0,2,2,3,1,6,3,1};
			string initState          = "010001110";
			string isImportant        = "000110100";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int roads[]               = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
			string initState          = "0000000000010000000000000010000010100000000000000";
			string isImportant        = "1010111111111011011111000110111111111111111110111";
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int roads[]               = ;
			string initState          = ;
			string isImportant        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int roads[]               = ;
			string initState          = ;
			string isImportant        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int roads[]               = ;
			string initState          = ;
			string isImportant        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TurnOnLamps().minimize(vector <int>(roads, roads + (sizeof roads / sizeof roads[0])), initState, isImportant);
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

Gobble City has a tree topology: There are N intersections, numbered 0 through N-1. The intersections are connected by N-1 bidirectional roads in such a way that it is possible to travel between any two intersections. More precisely, for each pair of intersections there is a unique path (a sequence of roads; see Notes for a formal definition) that connects them. You are given a vector <int> roads that describes the roads: for each i (0 <= i <= N-2), we have 0 <= roads[i] <= i and there is a road between intersections numbered roads[i] and i+1.

On each road there is a single lamp. The lamps are numbered 0 through N-2. For each i, lamp i is on the road that connects roads[i] and i+1. You are given a string initState that describes the initial states of all lamps: initState[i]='1' means that lamp i is initially on, and initState[i]='0' means that it is off.

Now you are at the Control Center for these lamps. The only way in which you can operate the lamps looks as follows: You enter the numbers of two intersections (X and Y) into the Control Center computer, and the computer toggles the state of all lamps on the path between X and Y. (Toggling the state of a lamp means that if the lamp was off it is now on, and vice versa.) You can perform arbitrarily many such operations, one after another.

Some of the lamps are important to you. You are given this information in the string isImportant: isImportant[i]='1' means that lamp i is important, and isImportant[i]='0' means that it is not.

Your goal is to turn on all important lamps at the same time. (We do not care about the state of the remaining lamps.) Return the minimum number of operations needed to achieve the goal.

DEFINITION
Class:TurnOnLamps
Method:minimize
Parameters:vector <int>, string, string
Returns:int
Method signature:int minimize(vector <int> roads, string initState, string isImportant)


NOTES
-In your solution some lamps may be toggled multiple times.
-A path between two intersection a and b is a sequence of intersections (v0=a, v1, v2, ..., vk=b) such that all v0, v1, ..., vk are pairwise distinct and for each i=0..k-1, there exists a road between vi and vi+1.


CONSTRAINTS
-roads will contain N-1 elements, where N is between 2 and 50, inclusive.
-For each i, the i-th (0-based index) element of roads will be between 0 and i, inclusive.
-initState will be N-1 characters long.
-initState will only contain the characters '0' and '1'.
-isImportant will be N-1 characters long.
-isImportant will only contain the characters '0' and '1'.


EXAMPLES

0)
{0,0,1,1}
"0001"
"0111"

Returns: 1

The figure below illustrates this test case and its optimal solution.

Red roads are the important ones. The optimal solution chooses the intersections 2 and 3. The path that corresponds to this choice is enclosed by the dashed line. All lamps on this path are toggled from 0 to 1.

1)
{0,0,1,1}
"0000"
"0111"

Returns: 2

This is almost the same test case as Example 0, but now the initial state of the lamp 3 (i.e., the lamp on the road that connects intersections 1 and 4) is now 0. As this is an important lamp, we now need two operations in order to turn all important lamps to 1.


2)
{0,0,1,1,4,4}
"000100"
"111111"

Returns: 2


Note that lamp on the road between intersections 1 and 4 was toggled twice: first from 1 to 0, and then from 0 back to 1.

3)
{0,0,1,1,4,4}
"100100"
"011101"

Returns: 2



4)
{0,0,2,2,3,1,6,3,1}
"010001110"
"000110100"

Returns: 1



5)
{0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}
"0000000000010000000000000010000010100000000000000"
"1010111111111011011111000110111111111111111110111"

Returns: 14



*/

// END CUT HERE
