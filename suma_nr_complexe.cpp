//programul compara distanta dintre fiecare numar cu distanta dintre fiecare numar si suma totala dintre ele. daca distanta dintre numere este mai mare decat distanta dintre numar si suma totala programul afiseaza patratul numarului respectiv
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
class Point{
protected:
    std::vector<double>mCoordinates;
    double mDistance{};
    friend class Point2D;
    friend class Point3D;
    friend class Point4D;
public:
    virtual void print()=0;
    virtual void calculateDistance()=0;
    virtual Point* add(Point* p)=0;
    virtual Point* multiply(Point* p)=0;
    double getDistance(){
        return mDistance;
    }
    uint64_t getSize(){
        return mCoordinates.size();
    }
};
class Point2D: public Point{
public:
    Point2D(){
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point2D(double a,double b){
        mCoordinates.push_back(a);
        mCoordinates.push_back(b);
    }
    virtual void print(){
        printf("%0.3lf%+0.3lfi -> ",mCoordinates[0],mCoordinates[1]);
    }
    virtual void calculateDistance(){
        mDistance=fabs((mCoordinates[0]+mCoordinates[1])/2)+pow(fabs(mCoordinates[0]*mCoordinates[1]) ,1.0/2);
    }
    virtual Point* add(Point* point){
        double x,y;
        x=mCoordinates[0]+point->mCoordinates[0];
        y=mCoordinates[1]+point->mCoordinates[1];
        return new Point2D(x,y);
    };
    virtual Point* multiply(Point* point){
        double x,y;
        x=mCoordinates[0]*point->mCoordinates[0]-mCoordinates[1]*point->mCoordinates[1];
        y=mCoordinates[0]*point->mCoordinates[1]+mCoordinates[1]*point->mCoordinates[0];
        return new Point2D(x,y);
    }
};
class Point3D:public Point{
public:
    Point3D(){
        mDistance=0;
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
    }
    Point3D(double a, double b, double c){
        mCoordinates.push_back(a);
        mCoordinates.push_back(b);
        mCoordinates.push_back(c);
    }
    virtual void print(){
        printf("%0.3lf%+0.3lfi%+0.3lfj -> ",mCoordinates[0],mCoordinates[1],mCoordinates[2]);
    }
    virtual void calculateDistance(){
         mDistance=fabs((mCoordinates[0]+mCoordinates[1]+mCoordinates[2])/3)+pow(fabs(mCoordinates[0]*mCoordinates[1]*mCoordinates[2]),1.0/3);
    }
    virtual Point* add(Point* point){
        double x,y,z;
        x=mCoordinates[0]+point->mCoordinates[0];
        y=mCoordinates[1]+point->mCoordinates[1];
        z=mCoordinates[2]+point->mCoordinates[2];
        return new Point3D(x,y,z);
    };
    virtual Point* multiply(Point* point){
        double x,y,z;
        x=mCoordinates[0]*point->mCoordinates[0]-mCoordinates[1]*point->mCoordinates[1]-mCoordinates[2]*point->mCoordinates[2];
        y=mCoordinates[0]*point->mCoordinates[1]+mCoordinates[1]*point->mCoordinates[0];
        z=mCoordinates[0]*point->mCoordinates[2]+mCoordinates[2]*point->mCoordinates[0];
        return new Point3D(x,y,z);
    }
};
class Point4D:public Point{
public:
    Point4D(){
        mDistance=0;
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
    }
    Point4D(double a, double b, double c,double d){
        mCoordinates.push_back(a);
        mCoordinates.push_back(b);
        mCoordinates.push_back(c);
        mCoordinates.push_back(d);
    }
    virtual void print(){
        printf("%0.3lf%+0.3lfi%+0.3lfj%+0.3lfk -> ",mCoordinates[0],mCoordinates[1],mCoordinates[2],mCoordinates[3]);
    }
    virtual void calculateDistance(){
        mDistance=fabs((mCoordinates[0]+mCoordinates[1]+mCoordinates[2]+mCoordinates[3])/4)+pow(fabs(mCoordinates[0]*mCoordinates[1]*mCoordinates[2]*mCoordinates[3]),1.0/4);
    }
    virtual Point* add(Point* point){
        double x,y,z,w;
        x=mCoordinates[0]+point->mCoordinates[0];
        y=mCoordinates[1]+point->mCoordinates[1];
        z=mCoordinates[2]+point->mCoordinates[2];
        w=mCoordinates[3]+point->mCoordinates[3];
        return new Point4D(x,y,z,w);
    };
    virtual Point* multiply(Point* point){
        double x,y,z,w;
        x=mCoordinates[0]*point->mCoordinates[0]-mCoordinates[1]*point->mCoordinates[1]-mCoordinates[2]*point->mCoordinates[2]-mCoordinates[3]*point->mCoordinates[3];
        y=mCoordinates[0]*point->mCoordinates[1]+mCoordinates[1]*point->mCoordinates[0];
        z=mCoordinates[0]*point->mCoordinates[2]+mCoordinates[2]*point->mCoordinates[0];
        w=mCoordinates[0]*point->mCoordinates[3]+mCoordinates[3]*point->mCoordinates[0];
        return new Point4D(x,y,z,w);
    }
};
bool comparator(Point* x, Point* y){
    x->calculateDistance();
    y->calculateDistance();
    return x->getDistance()>=y->getDistance();
}
int main(){
    double x,y,z=1000,w=1000;
    Point *s2;
    Point *s3;
    Point *s4;
    std::vector<Point *>punct2d;
    std::vector<Point *>punct3d;
    std::vector<Point *>punct4d;
    while(scanf("%lf;%lf;%lf;%lf",&x,&y,&z,&w)!=EOF){
        if(w!=1000){
            punct4d.push_back(new Point4D(x,y,z,w));
        }else if(z!=1000){
            punct3d.push_back(new Point3D(x,y,z));
        }else{
            punct2d.push_back(new Point2D(x,y));
        }
        z=1000;
        w=1000;
    }
    if(punct2d.size()>=1){
        s2=punct2d[0];
        for(int i=1;i<punct2d.size();i++){
            s2=s2->add(punct2d[i]);
        }
        s2->calculateDistance();
    }
    if(punct2d.size()>=1){
        s3=punct3d[0];
        for(int i=1;i<punct3d.size();i++){
            s3=s3->add(punct3d[i]);
        }
        s3->calculateDistance();
    }
    if(punct4d.size()>=1){
        s4=punct4d[0];
        for(int i=1;i<punct4d.size();i++){
            s4=s4->add(punct4d[i]);
        }
        s4->calculateDistance();
    }
    sort(punct2d.begin(),punct2d.end(),comparator);
    sort(punct3d.begin(),punct3d.end(),comparator);
    sort(punct4d.begin(),punct4d.end(),comparator);
    for(int i=0;i<punct4d.size();i++){
        punct4d[i]->calculateDistance();
        if(punct4d[i]->getDistance()>=s4->getDistance()){
            (punct4d[i]->multiply(punct4d[i]))->print();
            printf("%0.3lf\n",punct4d[i]->getDistance());
        }
    }
    for(int i=0;i<punct3d.size();i++){
        punct3d[i]->calculateDistance();
        if(punct3d[i]->getDistance()>=s3->getDistance()){
            (punct3d[i]->multiply(punct3d[i]))->print();
            printf("%0.3lf\n",punct3d[i]->getDistance());
        }
    }
    for(int i=0;i<punct2d.size();i++){
        punct2d[i]->calculateDistance();
        if(punct2d[i]->getDistance()>=s2->getDistance()){
            (punct2d[i]->multiply(punct2d[i]))->print();
            printf("%0.3lf\n",punct2d[i]->getDistance());
        }
    }
    return 0;
}
