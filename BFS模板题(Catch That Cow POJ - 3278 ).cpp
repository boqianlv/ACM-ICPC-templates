/*Catch That Cow POJ - 3278 
Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input
Line 1: Two space-separated integers: N and K
Output
Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
Sample Input
5 17
Sample Output
4
Hint
The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10000000+10;
bool vis[maxn];
int u,v,sum=0;

struct state
{
    int x;
    int step;
};

bool check(state s)
{
    if(!vis[s.x]&&s.x>=0&&s.x<=100000)
        return 1;
    else
        return 0;
}

void bfs(state st)
{
    queue <state> q;

    state now,next;
    st.step=0;
    q.push(st);
    vis[st.x]=1;
    while(!q.empty())
    {
        now=q.front();
        if(now.x+1==v||now.x-1==v||now.x*2==v)
        {
            sum=now.step;
            return;
        }
        next.x=now.x+1;
        next.step=now.step+1;
        if(check(next))
        {
            q.push(next);
            vis[next.x]=1;
        }
        next.x=now.x-1;
        next.step=now.step+1;
        if(check(next))
        {
            q.push(next);
            vis[next.x]=1;
        }
        next.x=now.x*2;
        next.step=now.step+1;
        if(check(next))
        {
            q.push(next);
            vis[next.x]=1;
        }
        q.pop();
    }
    return ;
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&u,&v);
    if(u==v)
    {
        printf("0\n");
        return 0;
    }
    state A;
    A.x=u;
    A.step=0;
    bfs(A);
    printf("%d\n",sum+1);
    return 0;
}
