#include <cstdio>
#include <utility>
#include <cstring>
#include <queue>
//poj 1753
using namespace std;

bool visit[65535];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int op[16] =
{
    51200,58368,29184,12544,
    35968,20032,10016,4880,
    2248,1252,626,305,
    140,78,39,19
};

typedef pair<int, int> PAIR;

int bfs(int state){
    if(state == 0 || state == 0xffff)
        return 0;
    memset(visit,0,sizeof(visit));
    queue<PAIR> que;
    PAIR cur, next;
    que.push(PAIR(state,0));
    visit[state] = true;
    while(!que.empty()){
        cur = que.front();
        que.pop();
        if(cur.first == 0 || cur.first == 65535)
            return cur.second;
        visit[cur.first] = true;
        for(int i = 0; i < 16; ++i){
            next.first = cur.first ^ op[i];
            if(visit[next.first]) continue;
            next.second = cur.second + 1;
            if(next.first == 0 || next.first == 0xffff)
            return next.second;
            visit[next.first] = true;
            que.push(next);
        }
    }
    return -1;
}

int main()
{
    int state = 0, ans;
    char ch[4][5];
    for(int i = 0; i < 4; ++i)
        scanf("%s",&ch[i]);
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
 //           printf("%c\t",ch[i][j]);
            if(ch[i][j] == 'b')
                state ^= (1<<((3 - i) * 4 + 3 - j));
        }
    }
    ans = bfs(state);
    if(ans == -1) puts("Impossible");
    else
        printf("%d\n", ans);
    return 0;
}

//void gene(){
//    int temp;
//    for(int i = 0; i < 4; ++i){
//        for(int j = 0; j < 4; ++j){
//            temp = 0 ^ (1 << ((3 - i) * 4 + 3 - j));
//            for(int t = 0; t < 4; ++t){
//                int x = i + dx[t], y = j + dy[t];
//                if(x < 0 || y < 0 || x > 3 || y > 3)
//                    continue;
//                temp ^= (1 << ((3 - x) * 4 + 3 - y));
//            }
//            cout << temp << "\t";
//        }
//        cout<<endl;
//    }
//}
