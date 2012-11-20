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

class ICPCBalloons {
	public:
	int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
		VI M, L;
        M.clear();
        L.clear();
        int nM = 0;
        int nL = 0;
        REP(i, SZ(balloonCount)){
            if(balloonSize[i] == 'M') {
                M.push_back(balloonCount[i]);
                nM += balloonCount[i];
            }
            else {
                L.push_back(balloonCount[i]);
                nL += balloonCount[i];
            }
        }
        REP(i, 20) M.push_back(0);
        REP(i, 20) L.push_back(0);
        sort(ALL(M), greater<int>() );
        sort(ALL(L), greater<int>() );
        
        int res = 1000000;
        REP(mask, 1<<SZ(maxAccepted)){
            VI aM, aL;
            aM.clear();
            aL.clear();
            int naM = 0;
            int naL = 0;
            REP(i, SZ(maxAccepted)){
                if(mask & 1<<i){
                    aM.push_back(maxAccepted[i]);
                    naM += maxAccepted[i];
                }
                else{
                    aL.push_back(maxAccepted[i]);
                    naL += maxAccepted[i];
                }
            }
            if(naM > nM || naL > nL) continue;
            
            int tmp = 0;
            sort(ALL(aM), greater<int>());
            sort(ALL(aL), greater<int>());
            REP(i, SZ(aM)) if(aM[i] > M[i]) tmp += (aM[i] - M[i]);
            REP(i, SZ(aL)) if(aL[i] > L[i]) tmp += (aL[i] - L[i]);
            
            res = min(res, tmp);
        }
        
        if(res == 1000000) return -1;
        else return res;
        
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
			int balloonCount[]        = {100};
			string balloonSize        = "L";
			int maxAccepted[]         = {1,2,3,4,5};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int balloonCount[]        = {100};
			string balloonSize        = "M";
			int maxAccepted[]         = {10,20,30,40,50};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int balloonCount[]        = {5,6,1,5,6,1,5,6,1};
			string balloonSize        = "MLMMLMMLM";
			int maxAccepted[]         = {7,7,4,4,7,7};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int balloonCount[]        = {100,100};
			string balloonSize        = "ML";
			int maxAccepted[]         = {50,51,51};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int balloonCount[]        = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
			string balloonSize        = "MMMLLLMMLLMLMLM";
			int maxAccepted[]         = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int balloonCount[]        = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
			string balloonSize        = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
			int maxAccepted[]         = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
			int expected__            = 210;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int balloonCount[]        = ;
			string balloonSize        = ;
			int maxAccepted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int balloonCount[]        = ;
			string balloonSize        = ;
			int maxAccepted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int balloonCount[]        = ;
			string balloonSize        = ;
			int maxAccepted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
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
// You are organizing a subregional ACM ICPC contest. The problemset at the contest will consist of M problems. According to an ACM ICPC tradition, when a team solves a problem, it gets awarded a balloon. To account for this, you've bought balloons of N different colors (conveniently numbered from 0 to N-1). The number of balloons of color i that you've bought is given by balloonCount[i]. Balloons come in two sizes: medium and large. All balloons of the same color have the same size. If the i-th character of balloonSize is 'M', then all balloons of color i have medium size, and if this character is 'L', then all balloons of color i have large size.

Today you've been at the meeting with the scientific committee of the contest. There, you learned that there are additional restrictions of which you were not aware. Here are those restrictions:

All balloons that get awarded for a particular problem must have the same color and size.
For any two problems, the colors of balloons awarded for solving them must be different. In other words, the color of balloons awarded for each problem must be unique.

These are definitely bad news, since you ordered balloons pretty much arbitrarily and it's possible that you won't be able to satisfy the restrictions with the balloons you currently have. However, the good news is that scientific committee members were able to evaluate the difficulty of each problem. More exactly, they told you that the maximum number of teams that can potentially solve the i-th problem is maxAccepted[i]. The scientific committee members are very clever and experienced, so their prediction is guaranteed to come true.

Your budget is limited and balloons are expensive, so buying more of them is not an option. Fortunately, there is a very cheap balloon repaint service at your city, so you are going to use it. The service offers repainting a given balloon into any other color. This can be one of the N colors you have, as well as any color that you don't have yet. However, it is not possible to change the size of a balloon.

You are given the vector <int>s balloonCount, maxAccepted and the string balloonSize. Return the minimum number of balloons that have to be repainted in order to guarantee that you will be able to award balloons to the teams properly. If it is impossible to achieve the goal using any number of balloon repaintings, return -1.

DEFINITION
Class:ICPCBalloons
Method:minRepaintings
Parameters:vector <int>, string, vector <int>
Returns:int
Method signature:int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted)


CONSTRAINTS
-balloonCount will contain between 1 and 50 elements, inclusive.
-Each element of balloonCount will be between 1 and 100, inclusive.
-balloonSize will contain the same number of characters as the number of elements in balloonCount.
-Each character of balloonSize will be 'M' or 'L'.
-maxAccepted will contain between 1 and 15 elements, inclusive.
-Each element of maxAccepted will be between 1 and 100, inclusive.


EXAMPLES

0)
{100}
"L"
{1,2,3,4,5}

Returns: 10

You have 100 large balloons of the same color. 5 of them can be used for problem 4 and 1+2+3+4=10 balloons need to be repainted in order to be used for remaining problems.

1)
{100}
"M"
{10,20,30,40,50}

Returns: -1

We don't have enough balloons. Repainting is not going to help.

2)
{5,6,1,5,6,1,5,6,1}
"MLMMLMMLM"
{7,7,4,4,7,7}

Returns: 6

(Note that all of the indices in this annotation are 0-based.)

Repaint one balloon of color 7 into color 1. Repaint one balloon of color 7 into color 4. Now large balloons can be awarded for problems 0, 1, and 2.

Repaint two balloons of colors 2 and 5 into color 0. Repaint two balloons of colors 6 and 8 into color 3. Now medium balloons of colors 0, 3, and 6 can be awarded for problems 3, 4, and 5.

3)
{100,100}
"ML"
{50,51,51}

Returns: -1

Even though we have 200 balloons overall and only at most 152 accepted solutions, there is still no way of dividing and repainting the balloons that works.

4)
{8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}
"MMMLLLMMLLMLMLM"
{3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}

Returns: 5



5)
{1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}
"LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"
{44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}

Returns: 210



*/

// END CUT HERE
