#include<iostream>
#include<climits>
#include<cmath>
#include<cfloat>
using namespace std;

class point{
    public:
    int x,y;
};

float max(float a,float b,float c){
    return max(max(a,b),c);
}

int compX(const void* a,const void* b){
    point *ap=(point*)a;
    point *bp=(point*)b;
    return ap->x-bp->x;
}

int compY(const void* a,const void* b){
    point *ap=(point*)a;
    point *bp=(point*)b;
    return ap->y-bp->y;
}

float dist(point p1, point p2)  
{  
    return sqrt(   (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)    );  
}  

float yclose(point p[],int n,float diff){
    qsort(p,n,sizeof(p[0]),compY);
    float min=diff;
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n && (p[j].y - p[i].y) < min; ++j)  
            if (dist(p[i],p[j]) < min)  
                min = dist(p[i], p[j]);  
    return min;
}
float close(point P[],int n){
    if(n<=3){
        float mini=FLT_MAX;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                mini=min(mini,dist(P[i],P[j]));
            }
        }
        return mini;
    }
    
    int m=n/2;

    float l=close(P,m);
    float r=close(P+m,n-m);

    float diff=min(l,r);

    point xdiff[n];
    int j=0;

    for(int i=0;i<n;i++){
        if(abs(P[i].x-P[m].x)<diff)
            xdiff[j++]=P[i];
    }

    return min(diff,yclose(xdiff,j,diff));

}

float closest(point P[],int n){
    qsort(P,n,sizeof(P[0]),compX);
    return close(P,n);
}


int main(){
    point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout<<closest(P,6);
    return 0;
}