#define LOCAL
#define DEBUG

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
#include <stdlib.h>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <unistd.h>
#include <limits.h>

#ifdef LOCAL
#include "cout.h"
#endif

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

#define OUT(A) cerr << #A << " = " << A << endl
#define OUT2(A, B) cerr << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl

#ifdef _MSC_VER
#include <Windows.h>
LL getTime() {
    return GetTickCount();
}
#else
#include <sys/time.h>
LL getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    LL result =  tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
    //cerr << result << endl;
    return result;
}
#endif

LL starttime;

void settime(){
    starttime = getTime();
}

LL nowtime(){
    return getTime() - starttime;
}

void dmperr(int linenum){
    OUT(linenum);
    abort();
}

unsigned int randxor()
{
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dx2[8] = {-2, -1, -1, 0, 0, 1, 1, 2};
int dy2[8] = {0, -1, 1, -2, 2, -1, 1, 0};



const int MOD = 2147483647;
const int MUL = 48271;
const int INF_COST = 16*16*4 + 100;
#ifdef LOCAL
const LL LIMIT_TIME = 35000;
#else
const LL LIMIT_TIME = 29500;
#endif



//////////
// param

#ifdef DEBUG
int Param_1turn;
int Param_2turn;
int Param_douji;
int Param_after1turn;
#else
const int Param_1turn = 17;
const int Param_2turn = 0;
const int Param_douji = 19;
const int Param_after1turn = 9;
#endif

#ifdef DEBUG
int all_score;
#endif


class World{
    public:
    int n;
    int colors;
    int board[16][16];
    int pool[2][2];
    int score;
    
    // random generator
    int range, last;
    
    // one/two turn用 plan
    int ptr;
    vector<tuple<int, int, int> > pgm;
    
    // brute force用 plan
    int targetx[4], targety[4];
    int pBoard[16][16]; // target場所なら1 動かす4つの場所なら2,4,6,8。割る2 -1することでpx, pyのidが出る
    int px[4], py[4]; // 現在の場所
    int seed;
    
    int turncnt[10];
    int movecnt;
    
    
    /////
    
    World(int &colors, vector <string> &board, int &startSeed){
        this->colors = colors;
        this->n = SZ(board);
        REP(i, n) REP(j, n){
            this->board[i][j] = board[i][j] - '0';
        }
        last = startSeed;
        range = colors;
        pool[0][0] = last % colors;
        pool[0][1] = getNextColor();
        pool[1][0] = getNextColor();
        pool[1][1] = getNextColor();
        
        pcost = 0;
        nowcost = 0;
        REP(i, n) REP(j, n) Aboard[i][j] = 8;
        MSET(Bboard, 0);
        ptr = 0;
        pgm.clear();
        
        seed = startSeed;
        
        movecnt = 0;
        MSET(turncnt, 0);
    }
    
    int getNextColor() {
        last = (int)(((long long) last * MUL) % MOD);
        int ans = last % range;
        return ans;
    }
    
    
    void dmpBoard(){
        REP(i, n){
            REP(j, n) cerr << board[i][j];
            cerr << endl;
        }
        cerr << endl;
    }
    
    
    void clearPlan(){
        MSET(targetx, -1);
        MSET(targety, -1);
    }
    
    void removeSquares() {
        while (true) {
            bool find = false;
            for (int i=0; i + 1 < n && !find; i++) {
                for (int j=0; j + 1 < n && !find; j++) {
                    if (board[i][j] == board[i][j + 1] &&
                        board[i][j] == board[i + 1][j] &&
                        board[i][j] == board[i + 1][j + 1]) {
                        find = true;
                        score++;
                        REP(ii, 2) REP(jj, 2) board[i+ii][j+jj] = pool[ii][jj];
                        REP(ii, 2) REP(jj, 2) pool[ii][jj] = getNextColor();
                    }
                }
            }
            if(find){
                clearPlan();
            }
            else {
                break;
            }
        }
    }
    
    void applyMove(int r1, int c1, int dir){
        int r2 = r1 + dx[dir];
        int c2 = c1 + dy[dir];
        if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= n){
            dmperr(__LINE__);
        }
        int tmp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = tmp;
        
        if(targetx[0] == -1) return;
        
        if(getIdFromXY(r2, c2) != -1){
            dmperr(__LINE__);
        }
        int id = getIdFromXY(r1, c1);
        px[id] = r2;
        py[id] = c2;
        setId(id, r2, c2);
        pBoard[r1][c1] -= (id+1) * 2;
        nowcost++;
    }
    
    bool isValidSquare(int x, int y){
        if(x < 0 || x >= n-1 || y < 0 || y >= n-1) return false;
        return true;
    }
    
    bool inSquare(int x, int y, int tx, int ty){ // x, yからのSquareに tx, tyが 入っているか
        if(x <= tx && tx <= x+1 && y <= ty && ty <= y+1) return true;
        return false;
    }
    
    bool isValidCell(int x, int y){
        if(x < 0 || x > n-1 || y < 0 || y > n-1) return false;
        return true;
    }

    
    /////////
    // 1turn check
    
    int Aboard[16][16]; // 実際のコピー
    int Bboard[16][16]; // 動いた部分に1
    
    void dmpABoard(){
        REP(i, n){
            REP(j, n) cerr << Aboard[i][j];
            cerr << endl;
        }
        cerr << endl;
    }
    
    void dmpBBoard(){
        REP(i, n){
            REP(j, n) cerr << Bboard[i][j];
            cerr << endl;
        }
        cerr << endl;
    }

    
    // id, dir を返す ダメなら個数0
    // 最大でも個数2のはず
    vector< pair<int, int> > listOneturn(int x, int y, int board_id = 0){
        vector< pair<int, int> > res;
        if(!isValidSquare(x, y)) return res;
        
        int (*_board)[16];
        if(board_id == 0) _board = board;
        else if(board_id == 1) _board = Aboard;
        int cnt[colors]; MSET(cnt, 0);
        int target_col = -1;
        
        REP(i, 4) cnt[_board[x+i/2][y+i%2]]++;
        REP(i, colors) if(cnt[i] == 3) target_col = i;
        if(target_col == -1) return res;
        
        int id = -1;
        REP(i, 4) if(_board[x+i/2][y+i%2] != target_col) id = i;
        REP(d, 4){
            int nx = x + id/2 + dx[d];
            int ny = y + id%2 + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(inSquare(x, y, nx, ny)) continue;
            if(_board[nx][ny] != target_col) continue;
            res.push_back(make_pair(id, d));
        }
        return res;
    }
    
    void initBoard(int x, int y){
        for(int i = max(0, x-4); i < min(n, x+6); i++){
            for(int j = max(0, y-4); j < min(n, y+6); j++){
                Aboard[i][j] = board[i][j];
                Bboard[i][j] = 0;
            }
        }
    }
    
    void applyMoveA(int r1, int c1, int dir){
        int r2 = r1 + dx[dir];
        int c2 = c1 + dy[dir];
        if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= n){
            dmperr(__LINE__);
        }
        if(Aboard[r1][c1] == 8 || Aboard[r2][c2] == 8){
            dmperr(__LINE__);
        }
        int tmp = Aboard[r1][c1];
        Aboard[r1][c1] = Aboard[r2][c2];
        Aboard[r2][c2] = tmp;
    }
    
    bool canRemove(int x, int y){
        if(!isValidSquare(x, y)) return false;
        int c = Aboard[x][y];
        FOR(i, 1, 4) if(Aboard[x+i/2][y+i%2] != c) return false;
        return true;
    }
    
    int scoreOneturn(int x, int y, int id, int dir){
//        initBoard(x, y);
        int scr = 0;
        
        REP(i, 4) Bboard[x+i/2][y+i%2] = 1;
        Bboard[x+id/2+dx[dir]][y+id%2+dy[dir]] = 1;
        
        applyMoveA(x+id/2, y+id%2, dir);
        if(!canRemove(x, y)){
            dmpABoard();
            OUT2(x, y);
            dmperr(__LINE__);
        }
        REP(ii, 2) REP(jj, 2) Aboard[x+ii][y+jj] = pool[ii][jj];
        
        // 上/左で消えてたらNG
        for(int j = y-1; j <= y+1; j++) if(canRemove(x-2, j)) return 0;
        for(int j = y-2; j <= y+2; j++) if(canRemove(x-1, j)) return 0;
        for(int j = y-2; j <= y;   j++) if(canRemove(x,   j)) return 0;
        
        for(int i = max(0, x-4); i < min(n-1, x+5); i++){
            for(int j = max(0, y-4); j < min(n-1, y+5); j++){
                int chk = 0;
                REP(k, 4) chk |= Bboard[i+k/2][j+k%2];
                if(chk&2) continue;
                if(chk&1){
                    if(canRemove(i, j)){
                        scr += Param_douji;
                        REP(k, 4) Bboard[i+k/2][j+k%2] = 2;
                    }
                    else{
                        vector< pair<int, int> > a;
                        a = listOneturn(i, j, 1);
                        scr += Param_after1turn * SZ(a);
                    }
                }
                else{
                    REP(ii, 4) REP(jj, 4){
                        int idx = i + ii/2;
                        int idy = j + ii%2;
                        int nx = idx + dx[jj];
                        int ny = idy + dy[jj];
                        if(!isValidCell(nx, ny)) continue;
                        if(inSquare(i, j, nx, ny)) continue;
                        if(Bboard[nx][ny] == 0) continue;
                        if(Aboard[nx][ny] == 8) continue;
                        int c = Aboard[nx][ny];
                        bool ok = true;
                        REP(k, 4){
                            if(i + k/2 == idx && j + k%2 == idy) continue;
                            ok &= Aboard[i+k/2][j+k%2] == c;
                        }
                        if(ok) scr += Param_after1turn;
                    }
                }
            }
        }
        return scr;
    }
    
    /////////
    // 2turn check
    // <x, y, dir>, <id, dir>
    
    vector< pair<tuple<int, int, int>, pair<int, int> > > listTwoTurn(int x, int y, int board_id = 0){
        vector< pair<tuple<int, int, int>, pair<int, int> > > res;
        if(!isValidSquare(x, y)) return res;
        
        int (*_board)[16];
        if(board_id == 0) _board = board;
        else if(board_id == 1) _board = Aboard;
        int cnt[colors]; MSET(cnt, 0);
//        int target_col = -1;
        
        REP(i, 4) cnt[_board[x+i/2][y+i%2]]++;
        
        REP(c, colors){
            if(cnt[c] == 3){
                int id, tx, ty;
                id = tx = ty = -1;
                REP(i, 4) if(_board[x+i/2][y+i%2] != c) id = i, tx = x+i/2, ty = y+i%2;
                REP(i, 8){ // dx2, dy2
                    int fx = tx + dx2[i];
                    int fy = ty + dy2[i];
                    if(!isValidCell(fx, fy)) continue;
                    if(abs(tx-fx) + abs(ty-fy) != 2){
                        dmperr(__LINE__);
                    }
                    if(inSquare(x, y, fx, fy)) continue;
                    if(_board[fx][fy] != c) continue;
                    
                    // fx, fy を tx, ty に動かす
                    
                    if(id == 0){
                        switch(i){
                            case 0:
                                res.push_back(make_pair(make_tuple(fx, fy, 2), make_pair(id, 0)));
                                break;
                            case 1:
                                res.push_back(make_pair(make_tuple(fx, fy, 1), make_pair(id, 0)));
                                res.push_back(make_pair(make_tuple(fx, fy, 2), make_pair(id, 3)));
                                break;
                            case 2:
                                res.push_back(make_pair(make_tuple(fx, fy, 3), make_pair(id, 0)));
                                res.push_back(make_pair(make_tuple(fx+1, fy, 3), make_pair(1, 0)));
                                break;
                            case 3:
                                res.push_back(make_pair(make_tuple(fx, fy, 1), make_pair(id, 3)));
                                break;
                            case 4:
                                res.push_back(make_pair(make_tuple(fx, fy-1, 3), make_pair(1, 1)));
                                break;
                            case 5:
                                res.push_back(make_pair(make_tuple(fx, fy, 0), make_pair(id, 3)));
                                res.push_back(make_pair(make_tuple(fx, fy+1, 0), make_pair(2, 3)));
                                break;
                            case 6:
                                dmperr(__LINE__);
                                break;
                            case 7:
                                res.push_back(make_pair(make_tuple(fx-1, fy, 0), make_pair(2, 2)));
                                break;
                            default:
                                break;
                        }
                    }
                    if(id == 1){
                        switch(i){
                            case 0:
                                res.push_back(make_pair(make_tuple(fx, fy, 2), make_pair(id, 0)));
                                break;
                            case 1:
                                res.push_back(make_pair(make_tuple(fx, fy, 1), make_pair(id, 0)));
                                res.push_back(make_pair(make_tuple(fx+1, fy, 1), make_pair(0, 0)));
                                break;
                            case 2:
                                res.push_back(make_pair(make_tuple(fx, fy, 3), make_pair(id, 0)));
                                res.push_back(make_pair(make_tuple(fx, fy, 2), make_pair(id, 1)));
                                break;
                            case 3:
                                res.push_back(make_pair(make_tuple(fx, fy+1, 1), make_pair(0, 3)));
                                break;
                            case 4:
                                res.push_back(make_pair(make_tuple(fx, fy, 3), make_pair(id, 1)));
                                break;
                            case 5:
                                dmperr(__LINE__);
                                break;
                            case 6:
                                res.push_back(make_pair(make_tuple(fx, fy, 0), make_pair(id, 1)));
                                res.push_back(make_pair(make_tuple(fx, fy-1, 0), make_pair(3, 1)));
                                break;
                            case 7:
                                res.push_back(make_pair(make_tuple(fx-1, fy, 0), make_pair(3, 2)));
                                break;
                            default:
                                break;
                        }
                    }
                    if(id == 2){
                        switch(i){
                            case 0:
                                res.push_back(make_pair(make_tuple(fx+1, fy, 2), make_pair(0, 0)));
                                break;
                            case 1:
                                res.push_back(make_pair(make_tuple(fx, fy, 2), make_pair(id, 3)));
                                res.push_back(make_pair(make_tuple(fx, fy+1, 2), make_pair(0, 3)));
                                break;
                            case 2:
                                dmperr(__LINE__);
                                break;
                            case 3:
                                res.push_back(make_pair(make_tuple(fx, fy, 1), make_pair(id, 3)));
                                break;
                            case 4:
                                res.push_back(make_pair(make_tuple(fx, fy-1, 3), make_pair(3, 1)));
                                break;
                            case 5:
                                res.push_back(make_pair(make_tuple(fx, fy, 0), make_pair(id, 3)));
                                res.push_back(make_pair(make_tuple(fx, fy, 1), make_pair(id, 2)));
                                break;
                            case 6:
                                res.push_back(make_pair(make_tuple(fx, fy, 3), make_pair(id, 2)));
                                res.push_back(make_pair(make_tuple(fx-1, fy, 3), make_pair(3, 2)));
                                break;
                            case 7:
                                res.push_back(make_pair(make_tuple(fx, fy, 0), make_pair(id, 2)));
                                break;
                            default:
                                break;
                        }
                    }
                    if(id == 3){
                        switch(i){
                            case 0:
                                res.push_back(make_pair(make_tuple(fx+1, fy, 2), make_pair(1, 0)));
                                break;
                            case 1:
                                dmperr(__LINE__);
                                break;
                            case 2:
                                res.push_back(make_pair(make_tuple(fx, fy, 2), make_pair(id, 1)));
                                res.push_back(make_pair(make_tuple(fx, fy-1, 2), make_pair(1, 1)));
                                break;
                            case 3:
                                res.push_back(make_pair(make_tuple(fx, fy+1, 1), make_pair(2, 3)));
                                break;
                            case 4:
                                res.push_back(make_pair(make_tuple(fx, fy, 3), make_pair(id, 1)));
                                break;
                            case 5:
                                res.push_back(make_pair(make_tuple(fx, fy, 1), make_pair(id, 2)));
                                res.push_back(make_pair(make_tuple(fx-1, fy, 1), make_pair(2, 2)));
                                break;
                            case 6:
                                res.push_back(make_pair(make_tuple(fx, fy, 0), make_pair(id, 1)));
                                res.push_back(make_pair(make_tuple(fx, fy, 3), make_pair(id, 2)));
                                break;
                            case 7:
                                res.push_back(make_pair(make_tuple(fx, fy, 0), make_pair(id, 2)));
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
            else if(cnt[c] == 2){
                int id1 = -1;
                int id2 = -1;
                REP(i, 4) if(_board[x+i/2][y+i%2] != c){
                    if(id1 == -1) id1 = i;
                    else id2 = i;
                }
                if(id2 == -1){
                    dmperr(__LINE__);
                }
                vector< tuple<int, int, int> > res1;
                vector< pair<int, int> > res2;
                REP(i, 4){
                    int nx = x + id1/2 + dx[i];
                    int ny = y + id1%2 + dy[i];
                    if(!isValidCell(nx, ny)) continue;
                    if(inSquare(x, y, nx, ny)) continue;
                    if(_board[nx][ny] != c ) continue;
                    res1.push_back(make_tuple(x + id1/2, y + id1%2, i));
                }
                REP(i, 4){
                    int nx = x + id2/2 + dx[i];
                    int ny = y + id2%2 + dy[i];
                    if(!isValidCell(nx, ny)) continue;
                    if(inSquare(x, y, nx, ny)) continue;
                    if(_board[nx][ny] != c ) continue;
                    res2.push_back(make_pair(id2, i));
                }
                REP(i, SZ(res1)) REP(j, SZ(res2)) res.push_back(make_pair(res1[i], res2[j]));
            }
        }
        
        return res;
    }
    
    bool alreadyCanRemove(int x1, int y1, int x2, int y2){
        for(int i = min(x1-1, x2-1); i <= max(x1, x2); i++){
            for(int j = min(y1-1, y2-1); j <= max(y1, y2); j++){
                if(canRemove(i, j)) return true;
            }
        }
        return false;
    }
    
    // <x, y, dir>, <id, dir>
    int scoreTwoturn(int x, int y, tuple<int, int, int> turn1, pair<int, int> turn2){
        int scr = 0;
//        initBoard(x, y);
        
        int x1 = get<0>(turn1);
        int y1 = get<1>(turn1);
        int dir1 = get<2>(turn1);
        int x2 = x1 + dx[dir1];
        int y2 = y1 + dy[dir1];
        if(Aboard[x1][y1] == Aboard[x2][y2]) return 0;
        
        Bboard[x1][y1] = 1;
        Bboard[x2][y2] = 1;
        
        applyMoveA(x1, y1, dir1);
        
        // 既に消えてたらNG
        if(alreadyCanRemove(x1, y1, x2, y2)) return 0;
        
        scr = scoreOneturn(x, y, turn2.first, turn2.second);
        return scr;
        
    }
    
    
    /////////
    // Brute force
    
    int pcost, nowcost; // エラーチェック用
    
    
    void dmpPBoard(){
        REP(i, n){
            REP(j, n) cerr << pBoard[i][j];
            cerr << endl;
        }
        cerr << endl;
    }
    
    int getIdFromXY(int x, int y){
        return pBoard[x][y] / 2 - 1;
    }
    
    void setId(int id, int x, int y){
        pBoard[x][y] += (id+1) * 2;
    }
    
    bool isGoal(int id){
        return targetx[id] == px[id] && targety[id] == py[id];
    }
    
    void swapTarget(int id1, int id2){
        int tmpx = targetx[id1];
        int tmpy = targety[id1];
        targetx[id1] = targetx[id2];
        targety[id1] = targety[id2];
        targetx[id2] = tmpx;
        targety[id2] = tmpy;
    }
    
    tuple<int, int, int> makeMove(int id){
        if(isGoal(id)){
            dmperr(__LINE__);
        }
        if(id != getIdFromXY(px[id], py[id])){
            dmperr(__LINE__);
        }
        int dir = -1;
        if(targetx[id] < px[id]) dir = 0;
        else if(targety[id] > py[id]) dir = 1;
        else if(targetx[id] > px[id]) dir = 2;
        else if(targety[id] < py[id]) dir = 3;
        else {
            dmperr(__LINE__);
        }
        int nx = px[id] + dx[dir];
        int ny = py[id] + dy[dir];
        if(getIdFromXY(nx, ny) == -1){
            return make_tuple(px[id], py[id], dir);
        }
        else{
            int id2 = getIdFromXY(nx, ny);
            if(isGoal(id2)){
                swapTarget(id, id2);
            }
            return makeMove(id2);
        }
    }
    
    
    void bruteForce(){
        int mincost = INF_COST;
        nowcost = 0;
        int score = -1;
        
        int startr = randxor() % (n-1);
        int startc = randxor() % (n-1);
        
        for(int r = startr; ; r = (r+1) % (n-1)){
            for(int c = startc; ; c = (c+1) % (n-1)){
                //            if(nowtime() > 29000 && mincost != INF_COST) break;
                
                int tx[4], ty[4];
                REP(i, 4){
                    tx[i] = r + i/2;
                    ty[i] = c + i%2;
                }
                
                // 4マスそれぞれについて、bfs
                bool used[16][16]; MSET(used, false); // 先勝ちで抑えていく
                bool vis[4][16][16]; MSET(vis, false); // bfs用
                int fromx[4][6]; MSET(fromx, -1); // このセルにこのcolorならどこからもってくるか
                int fromy[4][6]; MSET(fromy, -1);
                
                queue<int> qx[4], qy[4];
                REP(i, 4) qx[i].push(tx[i]), qy[i].push(ty[i]);
                REP(i, 4) vis[i][tx[i]][ty[i]] = true;
                int turn = 0;
                while(SZ(qx[0]) || SZ(qx[1]) || SZ(qx[2]) || SZ(qx[3])){
                    //                if(turn >= (nowtime() < 25000 ? 3 : 2)) break;
                    if(turn >= 3) break;
                    REP(i, 4){
                        while(1){
                            if(SZ(qx[i]) == 0) break;
                            int x = qx[i].front();
                            int y = qy[i].front();
                            if(abs(tx[i]-x) + abs(ty[i]-y) != turn) break;
                            
                            qx[i].pop(); qy[i].pop();
                            int col = board[x][y];
                            if(!used[x][y] && fromx[i][col] == -1){
                                used[x][y] = true;
                                fromx[i][col] = x;
                                fromy[i][col] = y;
                            }
                            REP(j, 4){
                                int nx = x + dx[j];
                                int ny = y + dy[j];
                                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[i][nx][ny]){
                                    vis[i][nx][ny] = true;
                                    qx[i].push(nx);
                                    qy[i].push(ny);
                                }
                            }
                        }
                    }
                    turn++;
                }
                
                
                // すべての場所、すべてのcolors色中どれが最もコスト小で集められるか
                REP(col, colors){
                    int cost = 0;
                    REP(i, 4){
                        if(fromx[i][col] == -1){
                            cost = INF_COST;
                            break;
                        }
                        cost += abs(tx[i] - fromx[i][col]) + abs(ty[i] - fromy[i][col]);
                    }
                    if(cost < 3){
                        OUT(cost);
                        dmperr(__LINE__);
                    }
                    else if(cost == 3){
                        REP(id, 4){
                            int fx = fromx[id][col];
                            int fy = fromy[id][col];
                            int x1 = fx;
                            int x2 = fx;
                            int y1 = fy;
                            int y2 = fy;
                            int tox = tx[id];
                            int toy = ty[id];
                            if(fx < tox){
                                x2++;
                                if(board[x1][y1] == board[x2][y2]) continue;
                                initBoard(r, c);
                                Bboard[x1][y1] = 1;
                                Bboard[x2][y2] = 1;
                                applyMoveA(x1, y1, 2);
                                if(alreadyCanRemove(x1, y1, x2, y2)) continue;
                                
                                vector< pair<tuple<int, int, int>, pair<int, int> > > list2 = listTwoTurn(r, c, 1); // <x, y, dir>, <id, dir>
                                REP(k, SZ(list2)){
                                    tuple<int, int, int> turn1 = list2[k].first;
                                    pair<int ,int> turn2 = list2[k].second;
                                    initBoard(r, c);
                                    applyMoveA(x1, y1, 2);
                                    int tmp_score = scoreTwoturn(r, c, turn1, turn2) + Param_2turn;
                                    if(score < tmp_score){
                                        score = tmp_score;
                                        pgm.clear();
                                        pgm.push_back(make_tuple(x1, y1, 2));
                                        pgm.push_back(turn1);
                                        pgm.push_back(make_tuple(r+turn2.first/2, c+turn2.first%2, turn2.second));
                                    }
                                }
                            }
                            else if(fx > tox){
                                x2--;
                                if(board[x1][y1] == board[x2][y2]) continue;
                                initBoard(r, c);
                                Bboard[x1][y1] = 1;
                                Bboard[x2][y2] = 1;
                                applyMoveA(x1, y1, 0);
                                if(alreadyCanRemove(x1, y1, x2, y2)) continue;
                                
                                vector< pair<tuple<int, int, int>, pair<int, int> > > list2 = listTwoTurn(r, c, 1); // <x, y, dir>, <id, dir>
                                REP(k, SZ(list2)){
                                    tuple<int, int, int> turn1 = list2[k].first;
                                    pair<int ,int> turn2 = list2[k].second;
                                    initBoard(r, c);
                                    applyMoveA(x1, y1, 0);
                                    int tmp_score = scoreTwoturn(r, c, turn1, turn2) + Param_2turn;
                                    if(score < tmp_score){
                                        score = tmp_score;
                                        pgm.clear();
                                        pgm.push_back(make_tuple(x1, y1, 0));
                                        pgm.push_back(turn1);
                                        pgm.push_back(make_tuple(r+turn2.first/2, c+turn2.first%2, turn2.second));
                                    }
                                }
                            }
                            if(fy < toy){
                                y2++;
                                if(board[x1][y1] == board[x2][y2]) continue;
                                initBoard(r, c);
                                Bboard[x1][y1] = 1;
                                Bboard[x2][y2] = 1;
                                applyMoveA(x1, y1, 1);
                                if(alreadyCanRemove(x1, y1, x2, y2)) continue;
                                
                                vector< pair<tuple<int, int, int>, pair<int, int> > > list2 = listTwoTurn(r, c, 1); // <x, y, dir>, <id, dir>
                                REP(k, SZ(list2)){
                                    tuple<int, int, int> turn1 = list2[k].first;
                                    pair<int ,int> turn2 = list2[k].second;
                                    initBoard(r, c);
                                    applyMoveA(x1, y1, 1);
                                    int tmp_score = scoreTwoturn(r, c, turn1, turn2) + Param_2turn;
                                    if(score < tmp_score){
                                        score = tmp_score;
                                        pgm.clear();
                                        pgm.push_back(make_tuple(x1, y1, 1));
                                        pgm.push_back(turn1);
                                        pgm.push_back(make_tuple(r+turn2.first/2, c+turn2.first%2, turn2.second));
                                    }
                                }
                                
                            }
                            else if(fy > toy){
                                y2--;
                                if(board[x1][y1] == board[x2][y2]) continue;
                                initBoard(r, c);
                                Bboard[x1][y1] = 1;
                                Bboard[x2][y2] = 1;
                                applyMoveA(x1, y1, 3);
                                if(alreadyCanRemove(x1, y1, x2, y2)) continue;
                                
                                vector< pair<tuple<int, int, int>, pair<int, int> > > list2 = listTwoTurn(r, c, 1); // <x, y, dir>, <id, dir>
                                REP(k, SZ(list2)){
                                    tuple<int, int, int> turn1 = list2[k].first;
                                    pair<int ,int> turn2 = list2[k].second;
                                    initBoard(r, c);
                                    applyMoveA(x1, y1, 3);
                                    int tmp_score = scoreTwoturn(r, c, turn1, turn2) + Param_2turn;
                                    if(score < tmp_score){
                                        score = tmp_score;
                                        pgm.clear();
                                        pgm.push_back(make_tuple(x1, y1, 3));
                                        pgm.push_back(turn1);
                                        pgm.push_back(make_tuple(r+turn2.first/2, c+turn2.first%2, turn2.second));
                                    }
                                }
                                
                            }
                        }
                    }
                    else if(cost < mincost && SZ(pgm) == 0){
                        mincost = cost;
                        pcost = mincost;
                        MSET(pBoard, 0);
                        REP(i, 4){
                            px[i] = fromx[i][col];
                            py[i] = fromy[i][col];
                            targetx[i] = tx[i], targety[i] = ty[i];
                            pBoard[targetx[i]][targety[i]] = 1;
                            pBoard[px[i]][py[i]] += (i+1)*2;
                        }
                    }
                }
                if((c+1) % (n-1) == startc) break;
            }
            if((r+1) % (n-1) == startr) break;
        }
        
        if(SZ(pgm) > 0) targetx[0] = -1;
        
        if(SZ(pgm) == 0 && mincost == INF_COST){
            dmperr(__LINE__);
        }
    }
    
    
    /////////
    // init
    
    void initPlan(){
        ptr = 0;
        pgm.clear();
        
        REP(i, n) REP(j, n) Aboard[i][j] = 8;
        MSET(Bboard, 0);
        
        int score = -1;
        
        
        int starti = randxor() % (n-1);
        int startj = randxor() % (n-1);
        
        for(int i = starti; ; i = (i+1) % (n-1)){
            for(int j = startj; ; j = (j+1) % (n-1)){
                
                vector< pair<int, int> > list = listOneturn(i, j);
                REP(k, SZ(list)){
                    int id = list[k].first;
                    int dir = list[k].second;
                    initBoard(i, j);
                    int tmp_score = scoreOneturn(i, j, id, dir) + Param_1turn;
                    if(score < tmp_score){
                        score = tmp_score;
                        pgm.clear();
                        pgm.push_back(make_tuple(i+id/2, j+id%2, dir));
                    }
                }
                if((j+1) % (n-1) == startj) break;
            }
            if((i+1) % (n-1) == starti) break;
        }
        
        if(score < Param_1turn + Param_after1turn){
            for(int i = starti; ; i = (i+1) % (n-1)){
                for(int j = startj; ; j = (j+1) % (n-1)){
                    vector< pair<tuple<int, int, int>, pair<int, int> > > list2 = listTwoTurn(i, j); // <x, y, dir>, <id, dir>
                    REP(k, SZ(list2)){
                        tuple<int, int, int> turn1 = list2[k].first;
                        pair<int ,int> turn2 = list2[k].second;
                        initBoard(i, j);
                        int tmp_score = scoreTwoturn(i, j, turn1, turn2) + Param_2turn;
                        if(score < tmp_score){
                            score = tmp_score;
                            pgm.clear();
                            pgm.push_back(turn1);
                            pgm.push_back(make_tuple(i+turn2.first/2, j+turn2.first%2, turn2.second));
                        }
                    }
                    if((j+1) % (n-1) == startj) break;
                }
                if((i+1) % (n-1) == starti) break;
            }
        }
        
        
        if(SZ(pgm) == 0) bruteForce();

    }
    
    tuple<int, int, int> getNextMove(){
        if(targetx[0] == -1 && ptr >= SZ(pgm)){
            initPlan();
            turncnt[movecnt]++;
            movecnt = 0;
        }
        movecnt++;
        if(SZ(pgm) > 0){
            return pgm[ptr++];
        }
        else{
            REP(i, 4){
                if(isGoal(i)) continue;
                return makeMove(i);
            }
        }
        dmperr(__LINE__);
        return makeMove(0);
    }
    
};


class SquareRemover {
	public:
    int colors;
    int n;
    
    void solve_child(World &w, vector <int> &res, int &turn){
        if(w.pcost < w.nowcost){
            dmperr(__LINE__);
        }
        tuple<int, int, int> ans = w.getNextMove();
        int x = get<0>(ans);
        int y = get<1>(ans);
        int d = get<2>(ans);
        w.applyMove(x, y, d);
        w.removeSquares();
        res.push_back(x);
        res.push_back(y);
        res.push_back(d);
    }
    
    vector <int> solve(int &colors, vector <string> &board, int &startSeed){
        vector <int> res(30000);
        World w = World(colors, board, startSeed);
        w.score = 0;
        w.removeSquares();
        w.clearPlan();

        int kuri = 250;
        int matome = 10000 / kuri;
        
        LL _t1 = nowtime();
        
        REP(i, kuri){
            if(i == 0){
                
                vector<World> ww;
                REP(j, 5) ww.push_back(w);
                vector <int> tmp_res[5];
                
                REP(j, matome){
                    REP(k, 5) solve_child(ww[k], tmp_res[k], j);
                }
                
                int max_score = -1;
                int id = -1;
                REP(j, 5) if(max_score < ww[j].score) max_score = ww[j].score, id = j;
                
                REP(j, matome*3) res[matome*3*i + j] = tmp_res[id][j];
                w = ww[id];
                
            }
            else {
                World cand_w = w;
                vector <int> cand_res;
                int max_score = -1;
                
                do{
                    World ww = w;
                    vector <int> tmp_res;
                    REP(j, matome){
                        solve_child(ww, tmp_res, j);
                    }
                    if(max_score < ww.score) max_score = ww.score, cand_w = ww, cand_res = tmp_res;
                }while(nowtime() < LIMIT_TIME * (i+1) / kuri);
                
                REP(j, matome*3) res[matome*3*i + j] = cand_res[j];
                w = cand_w;
            }
        }
        OUT(w.score);

        
//        REP(i, 5) OUT2(i, w.turncnt[i]);
        
        
#ifdef DEBUG
        all_score += w.score;
#endif
        
        return res;
    }
                       
	vector <int> playIt(int colors, vector <string> board, int startSeed) {
        settime();
        this->colors = colors;
        n = SZ(board);
        OUT(colors);
        OUT(n);
        vector <int> res = solve(colors, board, startSeed);
        LL _t = nowtime();
        OUT(_t);
        return res;
	}
};

#ifdef LOCAL
int main(){
    
#ifdef DEBUG
    int colors[50], n[50], startSeed[50];
    vector<string> board[50];
    
    REP(i, 50){
        colors[i] = rand() % 3 + 4;
        n[i] = rand() % 9 + 8;
        REP(ii, n[i]){
            string s = "";
            REP(jj, n[i]) s += rand() % colors[i] + '0';
            board[i].push_back(s);
        }
        startSeed[i] = rand() % 2147483647;
    }
    
    int max_score = -1;
    int cand_Param_1turn = -1;
    int cand_Param_douji = -1;
    int cand_Param_after1turn = -1;
    
    Param_2turn = 0;
    Param_1turn = 17;
    Param_douji = 19;
    Param_after1turn = 9;

    
//    for(Param_1turn = 17; Param_1turn <= 18; Param_1turn++){
//        for(Param_douji = 19; Param_douji <= 20; Param_douji++){
//            for(Param_after1turn = 6; Param_after1turn <= 6; Param_after1turn++){
                all_score = 0;
                REP(i, 50){
//                    cerr << "test #" << i << endl;
                    vector<int> res = SquareRemover().playIt(colors[i], board[i], startSeed[i]);
//                    //                    cerr << endl;
                }
//                OUT(Param_1turn);
//                OUT(Param_douji);
//                OUT(Param_after1turn);
//                OUT(all_score);
//                if(all_score > max_score){
//                    max_score = all_score;
//                    cand_Param_1turn = Param_1turn;
//                    cand_Param_douji = Param_douji;
//                    cand_Param_after1turn = Param_after1turn;
//                }
//            }
//        }
//    }
    
//    OUT(max_score);
//    OUT(cand_Param_1turn);
//    OUT(cand_Param_douji);
//    OUT(cand_Param_after1turn);

#else
    int colors, n, startSeed;
    cin >> colors >> n;
    vector<string> board(n);
    REP(i, n){
        cin >> board[i];
    }
    cin >> startSeed;
    vector<int> res = SquareRemover().playIt(colors, board, startSeed);
    REP(i, 30000) cout << res[i] << endl;
//    flush(stdout);
#endif
    
    return 0;
}
#endif



