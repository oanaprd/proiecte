#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<thread>
#include<chrono>
#include<cmath>
class Policy{
protected:
    bool isChecked=false;
public:
    virtual void check(const std::string& parola)=0;
    bool getCheck() const{
        return isChecked;
    }
};
class LengthPolicy:public Policy{
private:
    uint16_t minLength;
    uint16_t maxLength;
public:
    LengthPolicy(uint16_t minim):Policy(){
        minLength=minim;
        maxLength=255;
    }
    LengthPolicy(uint16_t minim,uint16_t maxim){
        minLength=minim;
        maxLength=maxim;
    }
    void check(const std::string& parola) override{
        if((parola.length()>=minLength)&&(parola.length()<=maxLength)){
            isChecked=true;
        }else{
            isChecked=false;
        }
    }
};
class ClassPolicy:public Policy{
private:
    uint16_t minClassCount;
public:
    ClassPolicy(uint16_t numar):Policy(){
        minClassCount=numar;
    }
    void check(const std::string& parola) override{
        int count=0;
        for(int i=0;i<parola.size();i++) {
            if ((parola[i] >= 'A') && (parola[i] <= 'Z')) {
                count = count + 1;
                break;
            }
        }for(int i=0;i<parola.size();i++) {
            if ((parola[i] >= 'a') && (parola[i] <= 'z')) {
                count = count + 1;
                break;
            }
        }for(int i=0;i<parola.size();i++) {
            if (((parola[i] >= '!') && (parola[i] <= '/')) || ((parola[i] >= ':') && (parola[i] <= '@'))||((parola[i] >= '[') && (parola[i] <= '`')) || ((parola[i] >= '{') && (parola[i] <= '~'))) {
                count = count + 1;
                break;
            }
        }for(int i=0;i<parola.size();i++){
            if((parola[i]>='0')&&(parola[i]<='9')) {
                count = count + 1;
                break;
            }
        }
        if(count>=minClassCount){
                isChecked=true;
            }else{
                isChecked=false;
        }
    }
};
class IncludePolicy:public Policy{
private:
    char characterType;
public:
    IncludePolicy(char tip):Policy(){
        characterType=tip;
    }
    void check(const std::string& parola) override {
        int flag=0;
        if ((characterType >= 'A') && (characterType <= 'Z')) {
            for (int i = 0; i < parola.size(); i++) {
                if ((parola[i] >= 'A') && (parola[i] <= 'Z')) {
                    flag=1;
                    break;
                }
            }
        } else if ((characterType >= 'a') && (characterType <= 'z')) {
            for(int i=0;i<parola.size();i++) {
                if ((parola[i] >= 'a') && (parola[i] <= 'z')) {
                    flag=1;
                    break;
                }
            }
        } else if (((characterType >= '!') && (characterType <= '/')) ||
                   ((characterType >= ':') && (characterType <= '@')) ||
                   ((characterType >= '[') && (characterType <= '`')) ||
                   ((characterType >= '{') && (characterType <= '~'))) {
            for(int i=0;i<parola.size();i++) {
                if (((parola[i] >= '!') && (parola[i] <= '/')) || ((parola[i] >= ':') && (parola[i] <= '@')) ||
                    ((parola[i] >= '[') && (parola[i] <= '`')) || ((parola[i] >= '{') && (parola[i] <= '~'))) {
                    flag=1;
                    break;
                }
            }
        } else if ((characterType >= '0') && (characterType <= '9')) {
            for(int i=0;i<parola.size();i++){
                if((parola[i]>='0')&&(parola[i]<='9')) {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            isChecked=true;
        }else{
            isChecked=false;
        }
    }
};
class NotIncludePolicy:public Policy{
private:
    char characterType;
public:
    NotIncludePolicy(char tip):Policy(){
        characterType=tip;
    }
    void check(const std::string& parola) override{
        int flag=1;
        if ((characterType >= 'A') && (characterType <= 'Z')) {
            for (int i = 0; i < parola.size(); i++) {
                if ((parola[i] >= 'A') && (parola[i] <= 'Z')) {
                    flag=0;
                    break;
                }
            }
        } else if ((characterType >= 'a') && (characterType <= 'z')) {
            for(int i=0;i<parola.size();i++) {
                if ((parola[i] >= 'a') && (parola[i] <= 'z')) {
                    flag=0;
                    break;
                }
            }
        } else if (((characterType >= '!') && (characterType <= '/')) ||
                   ((characterType >= ':') && (characterType <= '@')) ||
                   ((characterType >= '[') && (characterType <= '`')) ||
                   ((characterType >= '{') && (characterType <= '~'))) {
            for(int i=0;i<parola.size();i++) {
                if (((parola[i] >= '!') && (parola[i] <= '/')) || ((parola[i] >= ':') && (parola[i] <= '@')) ||
                    ((parola[i] >= '[') && (parola[i] <= '`')) || ((parola[i] >= '{') && (parola[i] <= '~'))) {
                    flag=0;
                    break;
                }
            }
        } else if ((characterType >= '0') && (characterType <= '9')) {
            for(int i=0;i<parola.size();i++){
                if((parola[i]>='0')&&(parola[i]<='9')) {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            isChecked=true;
        }else{
            isChecked=false;
        }
    }
};
class RepetitionPolicy:public Policy{
private:
    uint16_t maxCount;
public:
    RepetitionPolicy(uint16_t maxnumar):Policy(){
        maxCount=maxnumar;
    }
    void check(const std::string& parola) override{
        int flag=1;
        for(int i=0;i<parola.size();i++){
            if(parola[i+maxCount]==parola[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            isChecked=true;
        }else{
            isChecked=false;
        }
    }
};
class ConsecutivePolicy:public Policy{
private:
    uint16_t maxCount;
public:
    ConsecutivePolicy(uint16_t maxnumar):Policy(){
        maxCount=maxnumar;
    }
    void check(const std::string& parola) override{
        int flag=1;
        char caracter;
        for(int i=0;i<parola.size();i++){
            caracter=parola[i];
            if(parola[i+maxCount]==caracter+maxCount){
                flag=0;
                break;
            }
        }
        if(flag==1){
            isChecked=true;
        }else{
            isChecked=false;
        }
    }
};
std::string checkPassword(std::string parola,std::vector<Policy*>politici){
    for(int i=0;i<politici.size();i++) {
        politici[i]->check(parola);
        if(politici[i]->getCheck()){
            i=i+1;
        }else{
            return "NOK";
        }
    }
    return "OK";
}
int main(){
    int n;
    uint16_t min_length,max_length,min_class_count,max_count,repetition,consecutive;
    char spatiu1,spatiu2,caracter1,caracter2;
    std::string policy;
    std::string parola;
    std::vector<std::string>parole;
    std::vector<Policy*>politici;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&policy);
        if(policy=="length"){
            scanf("%d%c",&min_length,spatiu1);
            if(spatiu1==' '){
                scanf("%d\n",&max_length);
            }else{

            }
        }else if(policy=="class"){
            scanf("%d%c",&min_class_count,spatiu2);
            if(spatiu2==' '){
                scanf("%d\n",&max_count);
            }
        }else if(policy=="include"){
            scanf("%d\n",caracter1);
        }else if(policy=="ninclude"){
            scanf("%d\n",caracter2);
        }else if(policy=="repetition"){
            scanf("%d\n",repetition);
        }else if(policy=="consecutive"){
            scanf("%d\n",consecutive);
        }
    }
    while(scanf("%s\n",&parola)!=EOF){
        parole.push_back(parola);
    }
}
