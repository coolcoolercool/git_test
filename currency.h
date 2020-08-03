/** 
 * author: zzw5005
 * date: 2020/5/9 21:48
*/

#ifndef DATASTRUCTURESALGORITHMSANDAPPLICATIONINCPLUS_CURRENCY_H
#define DATASTRUCTURESALGORITHMSANDAPPLICATIONINCPLUS_CURRENCY_H

#include <iostream>
#include "../../tool/myExceptions.h"

using namespace std;

enum signType {Plus, Minus};

class currency{
public:
    currency(signType theSign = Plus, unsigned long theDollars = 0,
            unsigned int theCents = 0);

    ~currency(){}

    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);

    signType getSign() const{
        return sign;
    }
    unsigned long getDollars() const{
        return dollars;
    }
    unsigned int getCents() const{
        return cents;
    }

    currency add(const currency&) const;
    currency& increment(const currency&);

    void output() const;

private:
    signType sign;          //- 符号
    unsigned long dollars;  //- 美元
    unsigned int cents;     //- 美分
};


currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents){
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents){
    if(theCents > 99){
        throw illegalParameterValue("Cents should be < 100");
    }

    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount){
    if(theAmount < 0){
        sign = Minus;
        theAmount = -theAmount;
    }else{
        sign = Plus;
    }
    //- 提取整数部分
    dollars = (unsigned long)theAmount;
    //- 得到数字的后两位小数，转换成美分
    cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}

currency currency::add(const currency& x) const{
    long a1, a2, a3;
    currency result;

    //- 先将当前的currency转换成美分
    a1 = dollars * 100 + cents;
    if(sign == Minus){
        a1 = -a1;
    }

    //- 再将加数的currency转换成美分
    a2 = x.dollars * 100 + x.cents;
    if(x.sign == Minus){
        a2 = -a2;
    }

    //- 将两者相加，然后将美分转换成美元和美分的形式
    a3 = a1 + a2;
    if(a3 < 0){
        result.sign = Minus;
        a3 = -a3;
    }else{
        result.sign = Plus;
    }

    result.dollars = a3/100;
    result.cents = a3 - result.dollars * 100;

    return result;
}

currency& currency::increment(const currency& x){
    *this = add(x);
    return *this;
}

/**
 * 输出货币
 */
void currency::output() const{
    if(sign == Minus){
        cout << '-';
    }
    cout << '$' << dollars << '.';
    if(cents < 10){
        cout << '0';
    }
    cout << cents;
}

#endif //DATASTRUCTURESALGORITHMSANDAPPLICATIONINCPLUS_CURRENCY_H
