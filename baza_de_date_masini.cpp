#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
class Car{
protected:
    std::string mType;
    float mConsume;
public:
    virtual void print()=0;
    virtual void calculateConsume()=0;
    virtual float getConsume(){
        return mConsume;
    }
};
class Gas: public Car{
private:
    float mGas;
public:
    Gas(): Car(){
        mGas=0;
        mType="nedefinit";
    }
    Gas(float gas):Car(){
        mGas=gas;
        mType="benzina";
        mConsume=0;
    }
    void print(){
        printf("%s %0.2f\n",mType.c_str(),mGas);
    }
    void calculateConsume(){
        mConsume=mGas*5.8;
    }
    float getConsume(){
        return mConsume;
    }
};
bool comparator(Car* masina1,Car* masina2){
    return(masina1->getConsume()<masina2->getConsume());
}
class Hybrid: public Car{
private:
    float mGas;
    float mBattery;
public:
    Hybrid(): Car(){
        mGas=0;
        mBattery=0;
        mType="nedefinit";
    }
    Hybrid(float gas,float battery): Car(){
        mGas=gas;
        mBattery=battery;
        mType="hibrid";
    }
    void print(){
        printf("%s %0.2f %0.2f\n",mType.c_str(),mGas,mBattery);
    }
    void calculateConsume(){
        mConsume=mGas*5.8+mBattery;
    }
    float getConsume(){
        return mConsume;
    }
};
class Diesel: public Car{
private:
    float mDiesel;
public:
    Diesel(): Car(){
        mDiesel=0;
        mType="nedefinit";
    }
    Diesel(float diesel): Car(){
        mDiesel=diesel;
        mType="diesel";
    }
    void print(){
        printf("%s %0.2f\n",mType.c_str(),mDiesel);
    }
    void calculateConsume(){
        mConsume=mDiesel*6;
    }
    float getConsume(){
        return mConsume;
    }
};
int main(){
    int n;
    float consum,baterie;
    char tip[20];
    std::string tipmasina;
    scanf("%d",&n);
    std::vector<Car*>masini;
    for(int i=0;i<n;i++){
        scanf("%s %f %f",tip,&consum,&baterie);
        tipmasina=tip;
        if(tipmasina=="benzina"){
            masini.push_back(new Gas(consum));
        }
        if(tipmasina=="diesel"){
            masini.push_back(new Diesel(consum));
        }
        if(tipmasina=="hibrid"){
            masini.push_back(new Hybrid(consum,baterie));
        }
    }
    for(auto i:masini){
        i->calculateConsume();
    }
    sort(masini.begin(),masini.end(),comparator);
    for(auto i:masini){
        i->print();
    }
    return 0;
}
