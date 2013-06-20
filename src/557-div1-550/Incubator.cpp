
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



    const int MAX_V = 110;
    
    int V; // 左の頂点数。忘れずに設定すること。
    // ちなみに、Vは左右合わせた全部の頂点数でも問題ない。（左が終わった後に右からのをチェックしても、マッチ数は絶対増えない）
    
    
    VI G[MAX_V]; // ちゃんとGもケースごとに全部clear。
    int match[MAX_V];
    bool used[MAX_V];
    
    void add_edge(int u, int v){
        G[u].PB(v);
        G[v].PB(u);
    }
    
    bool dfs(int v){
        used[v] = true;
        REP(i, SZ(G[v])){
            int u = G[v][i], w = match[u];
            if(w < 0 || (!used[w] && dfs(w))){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    
    int bipartite_matching(){
        int res = 0;
        MSET(match, -1);
        REP(v, V){
            if(match[v] < 0){
                MSET(used, 0);
                if(dfs(v)) res++;
            }
        }
        return res;
    }


class Incubator {
public:
   int maxMagicalGirls( vector <string> love ) {
	
	int n = SZ(love);
	bool g[n][n]; MSET(g, false);
	REP(i, n) REP(j, n) if(love[i][j] == 'Y') g[i][j] = true;
	
	REP(k, n) REP(i, n) REP(j, n) g[i][j] |= g[i][k] & g[k][j];	
	int loop = 0;
	REP(i, n) if(g[i][i]){
		loop++;
		REP(j, n) g[i][j] = false, g[j][i] = false;
	}
	
	V = n;
	REP(i, MAX_V) G[i].clear();
	REP(i, n) REP(j, n) if(g[i][j]) add_edge(i, j+n);
	return n - loop - bipartite_matching();
	
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
			string love[]             = {"NY","NN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string love[]             = {"NYN", "NNY", "NNN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string love[]             = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string love[]             = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string love[]             = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string love[]             = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string love[]             = {"Y"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			string love[]             = {"NYYNN", "NNNNN", "NNNNN", "NNNNY", "NNNNY"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 8: {
			string love[]             = {"NYYNN", "NNNYN", "NNNNY", "NNNYN", "NNNNY"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 9: {
			string love[]             = {"NNNYYYNNNN", "YNYNNNYNNN", "NNNNNNNYYN", "NNNNNNNNNN", "NNNNNNNNNN", "NNNNNYNNNN", "NNNNNNYNNN", "NNNNNNNYNN", "NNNNNNNNYY", "NNNNNNNNNY"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 10: {
			string love[]             = {"NYN", "NNY", "YNN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 11: {
			string love[]             = {
				"NNNNNNYYNNNNNNNNNNNNNNNNN", 
				"NNNNNNNYNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNYN", 
				"NNNNNNNNNNNNNNNNNNNNNNNYN", 
				"NNNNNNNNNNNNNNNNNNNNNNNYN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NYYNNNNNNNYNNNNNNNNNNNNNN", 
				"YNNNNNNNNNNNNNNNNNNNNNNNN", 
				"YNNNNNNNNNNNNNYNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNY", 
				"NNNNNNNNNNYNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNYNNNYNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNNNYNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNYNNNNNNNNNNNNYNNNN", 
				"NNNNNNNYNNNNNNNNNNNNYNNNN", 
				"NNNNNNNNNYNNNNNNNNNNNNNNN", 
				"NNNNNNNNNNNNNNNNNNNNNNNNN", 
				"NNNNNNNYNNNNNNNYNNNNNNNNN"};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 12: {
			string love[]             = {"NNY", "NNY", "NNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Incubator().maxMagicalGirls(vector <string>(love, love + (sizeof love / sizeof love[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
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
// You are the Incubator.
You have the ability to turn normal girls into magical girls.



There are n girls in the city.
The girls are conveniently numbered 0 through n-1.
Some girls love some other girls.
Love is not necessarily symmetric.
It is also possible for a girl to love herself.



You are given a vector <string> love.
Character j of element i of love is 'Y' if girl i loves girl j.
Otherwise, that character is 'N'.
In the rest of the problem statement, we will use love[i][j] to denote the truth value of the statement "girl i loves girl j".



Each girl has two boolean properties: isMagical (is she a magical girl?) and isProtected (is she protected by some girl?).
Initially, for each girl i we have isMagical[i] = False and isProtected[i] = False.



At any moment, you can choose an ordinary girl and turn her into a magical girl.
That is, you can take a girl i such that isMagical[i] = False, and change isMagical[i] to True.



Each such change will trigger a series of events:

Each magical girl will protect all girls she loves: if isMagical[i] and love[i][j], then isProtected[j] is set to True.
Each protected girl will also protect all girls she loves: if isProtected[i] and love[i][j], then isProtected[j] is set to True.

Note that some of these changes may in turn trigger other changes, as more and more girls become protected.



Once there are no more changes, you can again change another ordinary girl into a magical one, and so on.
Your goal is to reach a situation with many girls that are magical, but not protected.
That is, you are interested in girls such that isMagical[i] = True and isProtected[i] = False.
Return the maximum number of such girls in a situation that can be reached using the above process.

DEFINITION
Class:Incubator
Method:maxMagicalGirls
Parameters:vector <string>
Returns:int
Method signature:int maxMagicalGirls(vector <string> love)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-love will contain exactly n elements.
-Each element of love will contain exactly n characters.
-Each character in each element of love will be either 'Y' or 'N'.


EXAMPLES

0)
{"NY","NN"}

Returns: 1

One optimal solution is to change girl 0 to a magical girl.
Girl 0 will be magical and she will not be protected.
It is not possible to have two girls that are both magical and not protected:
if you change both girls to magical girls (in any order), you will get a situation in which girl 1 is protected.

1)
{"NYN", "NNY", "NNN"}

Returns: 1

Again, there is no way to create more than one unprotected magical girl.
For example, if we start by making girl 2 magical, and then make girl 0 magical, magical girl 0 will protect girl 1, and protected girl 1 will protect girl 2.
Thus, in this case girl 0 will be magical and unprotected, girl 1 will be ordinary and protected, and girl 2 will be magical and protected.

2)
{"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}

Returns: 2



3)
{"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}

Returns: 2



4)
{"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}

Returns: 5



5)
{"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"}

Returns: 2



6)
{"Y"}

Returns: 0

Note that a girl may love herself.

*/

// END CUT HERE
