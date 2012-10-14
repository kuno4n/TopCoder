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
#include <utility>

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

const LL INF = (LL)1e100;

class BatchSystem {
	public:
	vector <int> schedule(vector <int> duration, vector <string> user) {
		map<string, LL> mp;
        REP(i, SZ(duration)) mp[user[i]] += duration[i];
//        FIT(it, mp) OUT((*it).first);
        vector < pair < LL, string > > vp;
        REP(i, SZ(user)) {
            if(mp[user[i]] != 0){
                vp.push_back(make_pair(mp[user[i]], user[i]));
                mp[user[i]] = 0;
            }
        }
//        REP(i, SZ(vp)) {OUT(vp[i].first); OUT(vp[i].second);}
        vector < pair < LL, string > > vp2;
        while(!vp.empty()){
            int minnum = 0;
            LL minval = INF;
            REP(i, SZ(vp)){
                if(vp[i].first < minval){
                    minnum = i;
                    minval = vp[i].first;
                }
            }
            vp2.push_back(vp[minnum]);
            vp.erase(vp.begin()+minnum);
        }
//        REP(i, SZ(vp2)) {OUT(vp2[i].first); OUT(vp2[i].second);}
        
        VI res;
        REP(i, SZ(vp2)) {
            REP(j, SZ(user)){
                if(vp2[i].second == user[j]) res.push_back(j);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int duration[]            = {400, 100, 100, 100};
			string user[]             = {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"};
			int expected__[]          = {3, 1, 2, 0 };

			clock_t start__           = clock();
			vector <int> received__   = BatchSystem().schedule(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <string>(user, user + (sizeof user / sizeof user[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int duration[]            = {200, 200, 200};
			string user[]             = {"Sarah", "Gil", "Warrick"};
			int expected__[]          = {0, 1, 2 };

			clock_t start__           = clock();
			vector <int> received__   = BatchSystem().schedule(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <string>(user, user + (sizeof user / sizeof user[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int duration[]            = {100, 200, 50};
			string user[]             = {"Horatio Caine", "horatio caine", "YEAAAAAAH"};
			int expected__[]          = {2, 0, 1 };

			clock_t start__           = clock();
			vector <int> received__   = BatchSystem().schedule(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <string>(user, user + (sizeof user / sizeof user[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int duration[]            = ;
			string user[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = BatchSystem().schedule(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <string>(user, user + (sizeof user / sizeof user[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int duration[]            = ;
			string user[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = BatchSystem().schedule(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <string>(user, user + (sizeof user / sizeof user[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int duration[]            = ;
			string user[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = BatchSystem().schedule(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <string>(user, user + (sizeof user / sizeof user[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// In the past, whole organizations depended on a single, big computer to do all the computational work. In a particular case, a computer has a list of pending jobs which is described by vector <int> duration and vector <string> user. There are n pending jobs and each job is described by these two arrays. For the i-th job, duration[i] is the total time in minutes required to complete the job and user[i] is a string that identifies the user that requested that job. A user may request multiple jobs. The computer may only process one job at a time. The waiting time for a user is defined as the time that this user has to wait before all of the jobs (s)he requested are finished. Your program must schedule the jobs in such a way that the average waiting time over all users is minimized.

Return a int[] containing the 0-based indices of the n jobs in the order in which they should be processed. If there are multiple possible results, return the one that comes first lexicographically.

DEFINITION
Class:BatchSystem
Method:schedule
Parameters:vector <int>, vector <string>
Returns:vector <int>
Method signature:vector <int> schedule(vector <int> duration, vector <string> user)


NOTES
-The lexicographically earlier of two vector <int>s of the same length is the one that has the smaller element in the first position at which they differ.
-User names are case sensitive. A user named "Bob"  is different from a user named "bob". See example 3 for clarification.


CONSTRAINTS
-duration will contain between 1 and 50 elements, inclusive.
-user will contain the same number of elements as duration.
-Each element of duration will be between 1 and 1000000000, inclusive.
-Each element of user will contain between 1 and 50 characters, inclusive.
-Each element of user will contain only letters ('a'-'z','A'-'Z') and at most one space character that will not be a leading or trailing space.


EXAMPLES

0)
{400, 100, 100, 100}
{"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"}

Returns: {3, 1, 2, 0 }

In total, Mac Taylor will have to wait 100 minutes, Stella Bonasera 300 minutes and Danny Messer 700 minutes. The best average time is approximately 366.66 minutes.

1)
{200, 200, 200}
{"Gil", "Sarah", "Warrick"}

Returns: {0, 1, 2 }



2)
{100, 200, 50}
{"Horatio Caine", "horatio caine", "YEAAAAAAH"}

Returns: {2, 0, 1 }



*/

// END CUT HERE
