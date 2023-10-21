#include<bits/stdc++.h>
using namespace std;

class point{
    public:
        double x;
        double y;
        point(double x,double y){
            this->x = x;
            this->y = y;
        }

};
point substract(point p1,point p2){
    return point({p1.x - p2.x,p1.y - p2.y});
}
bool onsegment(point i,point j,point k){
    return ((min(i.x,j.x)<=k.x && k.x <= max(i.x,j.x)) &&
            (min(i.y,j.y)<=k.y && k.y <= max(i.y,j.y))
    );
}
double direction(point p1,point p2,point p3){
    point np = substract(p3,p1);
    point np2 = substract(p2,p1);
    return ((np.x*np2.y)-(np.y*np2.x));
}
bool segmentIntersects(point p1,point p2,point p3,point p4){
    double
    d1 = direction(p3,p4,p1),
    d2 = direction(p3,p4,p2),
    d3 = direction(p1,p2,p3),
    d4 = direction(p1,p2,p4);
    if((d1*d2)<0 && (d3*d4)<0)return true;
    else if(d1 ==0 && onsegment(p3,p4,p1))return true;
    else if(d2 ==0 && onsegment(p3,p4,p2))return true;
    else if(d3 ==0 && onsegment(p1,p2,p3))return true;
    else if(d4 ==0 && onsegment(p1,p2,p4))return true;
    else return false;
}
double findPolarAngle(const point& ref, const point& p) {
    double deltaY = p.y - ref.y;
    double deltaX = p.x - ref.x;
   
    double res_radians = atan2(deltaY, deltaX);
    if (res_radians < 0) {
        res_radians += M_PI;
    }
    double res_degrees = res_radians * (180.0 / M_PI);
    return res_degrees;
}


vector<point> grahamScan(vector<point>points){
    if(points.size()<3)return {};
    point startPoint = points[0];
    for (int i = 1; i < points.size(); i++)
    {
        if(points[i].y < startPoint.y){
            startPoint = points[i];
        }else if( points[i].y==startPoint.y &&  points[i].x < startPoint.x){
            startPoint = points[i];
        }
    }
    vector<pair<double,point>>pointWithPolar;
    for (int i = 0; i < points.size(); i++)
    {
        pointWithPolar.push_back({findPolarAngle(startPoint,points[i]),points[i]});
    }
    sort(pointWithPolar.begin(),pointWithPolar.end(),[](pair<double,point>a,pair<double,point>b){
        return a.first < b.first;
    });
    stack<point>st;
    st.push(pointWithPolar[0].second);
    st.push(pointWithPolar[1].second);
    st.push(pointWithPolar[2].second);
    for (int i = 3; i < points.size(); i++)
    {
        point top = st.top();st.pop();
        point nextTop = st.top();st.push(top);
        while(!st.empty() && direction(nextTop,top,pointWithPolar[i].second) >= 0){
            st.pop();
            top = nextTop;st.pop();
            nextTop = st.top();st.push(top);
        }
        st.push(pointWithPolar[i].second);
    }
    vector<point>ans;
    while (!st.empty())
    {
        ans.push_back(st.top());st.pop();
    }
    return ans;
}
int main(){
    point p1(1,1),p2(4,8),p3(2,6),p4(6,3);
    cout<<segmentIntersects(p1,p2,p3,p4)<<endl;//true
    point np1(2,2),np2(8,3),np3(1,4),np4(6,5);
    cout<<segmentIntersects(np1,np2,np3,np4)<<endl;//false
    point mp1(1,1),mp2(3,3),mp3(5,5),mp4(8,8);
    cout<<segmentIntersects(mp1,mp2,mp3,mp4)<<endl;//false
    point lp1(1,1),lp2(5,5),lp3(3,3),lp4(8,8);
    cout<<segmentIntersects(lp1,lp2,lp3,lp4)<<endl;//true


    vector<point>points = {
        point({0,0}),point({3,1}),point({4,4}),point({1,2}),point({0,5}),point({2,2}),point({-1,3}),
    };
    vector<point>ans = grahamScan(points);
    cout<<"Convex Hull Points : "<<endl;
    for(auto p:ans){
        cout<<p.x<<" "<<p.y<<endl;
    }
    return 0;
}
