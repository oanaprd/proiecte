#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<thread>
#include<chrono>
#include<cmath>
#include<algorithm>
#include<cstring>
class Person{
public:
    std::string mName;
    uint16_t mAge;
    double mSalary;
    Person(){
        mName="";mAge=0;mSalary=0;
    }
    Person(std::string nume,uint16_t varsta,double salariu){
        mName=nume;mAge=varsta;mSalary=salariu;
    }
    bool operator== (const Person&obj) const{
        if((obj.mName==mName)&&(obj.mAge==mAge)&&(obj.mSalary==mSalary)){
            return true;
        }else{
            return false;
        }
    }
    bool operator< (const Person&obj) const{
        if(std::string(mName)<std::string(obj.mName)){
            return true;
        }else{
            return false;
        }
    }
};
class Building{
protected:
    std::string mBuildingName;
    std::string mType;
    Person mCoordinator;
    std::vector<Person>mEmployees;
    std::vector<Person>mCitizens;
public:
    Building(std::string nume,std::string tip){
        mBuildingName=nume;
        mType=tip;
    }
    virtual void add(const Person&persoana)=0;
    virtual void remove(const Person&persoana)=0;
    virtual Building* operator+ (const Person& obj)=0;
    virtual Building* operator- (){
        return nullptr;
    }
    virtual Building* operator- (const Person&obj){
        return nullptr;
    }
    std::string getBuildingName() const{
        return mBuildingName;
    }
    std::string getType() const{
        return mType;
    }
    uint16_t getEmployeesSize() const{
        return mEmployees.size();
    }
    uint16_t getCitizensSize() const{
        return mCitizens.size();
    }
    Person getEmployee(uint16_t i) const{
        return mEmployees[i];
    }
    Person getCitizen(uint16_t i) const{
        return mCitizens[i];
    }
    Person getCoordinator() const{
        return mCoordinator;
    }
};
class CityHall:public Building{
public:
    CityHall(std::string nume):Building(nume,"CityHall"){
        mCitizens.clear();
        mCoordinator={};
    }
    Building* operator+ (const Person& obj) override{
        return this;
    }
    Building* operator- () override{
        return nullptr;
    }
    void add(const Person&persoana) override{
        mCitizens.push_back(persoana);
    }
    void remove(const Person&persoana) override{
        mCitizens.pop_back();
    }
};
class Hospital:public Building{
public:
    Hospital(std::string nume):Building(nume,"Hospital"){
        mCitizens.clear();
        mEmployees.clear();
    }
    Building* operator+ (const Person& obj) override{
        return this;
    }
    Building* operator- (const Person& obj) override{
        return nullptr;
    }
    void add(const Person&persoana) override{
        mCitizens.push_back(persoana);
    }
    void remove(const Person&persoana) override{
        mCitizens.pop_back();
    }
};
class PoliceStation:public Building{
public:
    PoliceStation(std::string nume):Building(nume,"PoliceStation"){
        mCitizens.clear();
        mEmployees.clear();
    }
    Building* operator+ (const Person& obj) override{
        return this;
    }
    Building* operator- (const Person& obj) override{
        return nullptr;
    }
    void add(const Person&persoana) override{
        mCitizens.push_back(persoana);
    }
    void remove(const Person&persoana) override{
        mCitizens.pop_back();
    }
};
class House:public Building{
private:
    uint16_t mMaxNumber;
public:
    House(std::string nume,uint16_t max):Building(nume,"House"){
        mMaxNumber=max;
        mCitizens.clear();
        mCoordinator= {};
    }
    Building* operator+ (const Person& obj) override{
        return this;
    }
    Building* operator- () override{
        return nullptr;
    }
    void add(const Person&persoana) override{
        if(mCitizens.size()<mMaxNumber) {
            mCitizens.push_back(persoana);
        }
    }
    void remove(const Person&persoana) override{
        if(persoana.mAge>=18) {
            mCitizens.pop_back();
        }
    }
};
class Block:public Building{
private:
    uint16_t mMaxNumberPerFloor;
    uint16_t numar_etaje;
public:
    Block(std::string nume,uint16_t etaje,uint16_t max):Building(nume,"House"){
        mMaxNumberPerFloor=max;
        mCitizens.clear();
        mCoordinator={};
        numar_etaje=etaje;
        mCitizens.reserve(numar_etaje*mMaxNumberPerFloor);
    }
    Building* operator+ (const Person& obj) override{
        return this;
    }
    Building* operator- () override{
        return nullptr;
    }
    void add(const Person&persoana) override{
        if(mCitizens.size()<numar_etaje*mMaxNumberPerFloor){
            mCitizens.push_back(persoana);
        }
    }
    void remove(const Person&persoana) override{
        if(mCitizens.size()<numar_etaje*mMaxNumberPerFloor) {
            if (persoana.mAge >= 18) {
                mCitizens.pop_back();
                Person locatar("",0,0);
                mCitizens.push_back(persoana);
            }
        }
    }
};
int main() {
    char actiune[20];
    char cladire_persoana[20];
    std::string cladire_persoana1;
    std::string actiune1;
    std::string nume_cladire1;
    char nume_cladire[20];
    char nume[20];
    char spatiu;
    char spatiu1;
    uint16_t varsta, val1, val2, nopih=0, nopib=0,max=0;
    std::vector <uint16_t>max_locatari;
    std::vector <uint16_t>max_locatari_etaj;
    std::vector <uint16_t>etaje;
    float salariu, asfd=0, asfc=0, asfm=0, asfche=0, aaobips=0;
    std::vector<Person *> cetateni;
    std::vector<Building *> primarie;
    std::vector<Building *> spital;
    std::vector<Building *> politie;
    std::vector<Building *> casa;
    std::vector<Building *> bloc;
    std::vector<uint16_t>nopiho;
    while (scanf("%s %s %s%c%", actiune, cladire_persoana, nume, &spatiu) != EOF) {
        actiune1 = actiune;
        cladire_persoana1 = cladire_persoana;
        if (cladire_persoana1 == "CityHall" || cladire_persoana1 == "Hospital" ||cladire_persoana1 == "PoliceStation" || cladire_persoana1 == "House" || cladire_persoana1 == "Block") {
            if (spatiu == ' ') {
                scanf("%hd%c", &val1, &spatiu1);
                if (spatiu1 == ' ') {
                    scanf("%hd", &val2);
                    bloc.push_back(new Block(nume, val1, val2));
                }else if (spatiu1 == '\n') {
                    casa.push_back(new House(nume, val1));
                }
            } else if (spatiu == '\n') {
                if (cladire_persoana1 == "CityHall") {
                    primarie.push_back(new CityHall(nume));
                } else if (cladire_persoana1 == "Hospital") {
                    spital.push_back(new Hospital(nume));
                } else if (cladire_persoana1 == "PoliceStation") {
                    politie.push_back(new PoliceStation(nume));
                }
            }
        } else if (cladire_persoana1 == "coordinator" || cladire_persoana1 == "employee" ||cladire_persoana1 == "citizen") {
            if(actiune1=="add") {
                scanf("%hd %f %s",&varsta,&salariu,nume_cladire);
                nume_cladire1=nume_cladire;
                cetateni.push_back(new Person(nume,varsta,salariu));
                if (nume_cladire1 == "CityHall") {
                    CityHall(nume_cladire1).add(Person(nume, varsta, salariu));
                }else if (nume_cladire1 == "Hospital") {
                    Hospital(nume_cladire1).add(Person(nume, varsta, salariu));
                    nopih=nopih+1;
                }else if (nume_cladire1 == "PoliceStation") {
                    PoliceStation(nume_cladire1).add(Person(nume, varsta, salariu));
                }
            }else if(actiune1=="remove"){
                scanf("%s",nume_cladire);
                if (nume_cladire1 == "CityHall") {
                    CityHall(nume_cladire1).remove(Person(nume, varsta, salariu));
                }else if (nume_cladire1 == "Hospital") {
                    Hospital(nume_cladire1).remove(Person(nume, varsta, salariu));
                }else if (nume_cladire1 == "PoliceStation") {
                    PoliceStation(nume_cladire1).remove(Person(nume, varsta, salariu));
                }else if (nume_cladire1 == "House") {
                    House(nume_cladire1,max_locatari[*nume_cladire]).remove(Person(nume, varsta, salariu));
                }else if (nume_cladire1 == "Block") {
                    Block(nume_cladire1,etaje[*nume_cladire],max_locatari_etaj[*nume_cladire]).remove(Person(nume, varsta, salariu));
                }
            }
        }
    }
    if((primarie.size()>=3)&&(spital.size()>=2)&&(politie.size()>=3)&&(casa.size()>=8)&&(bloc.size()>=4)) {
        printf("Type: Capital\n");
    }else if((primarie.size()>=2)&&(spital.size()>=1)&&(politie.size()>=2)&&(casa.size()>=4)&&(bloc.size()>=1)){
        printf("Type: Town\n");
    }else{
        printf("Type: Village\n");
    }
    printf("Number of patients in hospitals: %d\n",nopih);
    printf("Average salary for doctors: %.0f\n");
    printf("Average salary for cops: %.0f\n");
    printf("Average salary for mayors: %.0f\n");
    printf("Average salary for city hall employees: %.0f\n");
    printf("Average age of busted in police stations: %.0f\n");
    for(int i=0;i<casa.size();i++){
        std::cout<<"Number of people in House "<<casa[i]->getBuildingName()<<": 0\n";
    }
    for(int i=0;i<bloc.size();i++){
        std::cout<<"Number of people in Block "<<bloc[i]->getBuildingName()<<": 0\n";
    }
    printf("Administrators of house and block: Nobody\n");
}
