#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
class po

public:

    int x , y , pos;
    
    point(){};
    point(int a , int b , int c){x = a , y = b , pos = c;}
    double distance(point &a){
        int dx = a.x - x;
        int dy = a.y - y;
        return sqrt(dx*dx + dy*dy); }
    bool operator != (point &a){
        if(a.x != x || a.y != y)
            return true;

        return false;  }
};
bool cmp(const point &a , const point &b){
    return a.y == b.y ? (a.x == b.x ? a.pos < b.pos : a.x < b.x ): a.y < b.y;
}
int orientation( point P , point Q , point R ){
    return  ( Q.x - P.x ) * ( R.y - P.y ) - ( R.x - P.x ) * ( Q.y - P.y );
}
void convex_hull(vector<point> &p , vector<point> &upper , vector<point> &lower){
    sort(p.begin() , p.end() , cmp);
    int k = 1;
    for(int i = 1 ; i < p.size() ; i++)
        if(p[i-1] != p[i])
            p[k++] = p[i];
    p.resize(k);
    int sz = 2*k;
    upper.resize(sz);
    lower.resize(sz);
    int j = 0 ;
    k = 0;
    for(int i = 0 ; i < p.size() ; i++){
        while(j >= 2 && orientation(lower[j-2] , lower[j-1] , p[i]) <= 0)
            j--;
        while(k >=2 && orientation(upper[k-2] , upper[k-1] , p[i]) >= 0)
            k--;
        lower[j++] = p[i];
        upper[k++] = p[i];
    }
    lower.resize(j);
    upper.resize(k);
}
int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<point> v;
        int x , y;
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d",&x , &y);
            v.pb(point(x , y , i+1));
        }
        vector<point> lower , upper;
        convex_hull(v , upper , lower);
        for(int i = upper.size() - 2 ; i > 0 ; i--)
            lower.pb(upper[i]);
        double dist = 0.0;
        for(int i = 1 ; i < lower.size() ; i++)
            dist += lower[i-1].distance(lower[i]);
        dist += lower[lower.size() -1].distance(lower[0]);
        printf("%.2lf\n", dist);
        for(int i = 0 ; i < lower.size() ; i++)
            printf("%d ", lower[i].pos);
        printf("\n");
    }
    
    return 0;
}