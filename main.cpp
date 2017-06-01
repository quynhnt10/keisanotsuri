//
//  main.cpp
//  TestCPlusPlus
//
//  Created by HanKun on 5/17/17.
//  Copyright © 2017 HanKun. All rights reserved.
//

#include <iostream>
#include <vector>


typedef struct money_count{
    int money_type;
    int count;
}money_count;
int TOTAL_MONEY_TYPE = 8;

money_count wallet[]={{1000,10},
    {2000,20},
    {5000,3},
    {10000,2},
    {20000,1},
    {50000,1},
    {100000,1},
     {200000,1}};
bool getReturnMoney(float totalMoney, money_count* returnMoney) {
    for(int i = TOTAL_MONEY_TYPE - 1; i >= 0; i--) {
        returnMoney[i].money_type = wallet[i].money_type;
        returnMoney[i].count = 0;
        
        returnMoney[i].count = (float)totalMoney/(float)wallet[i].money_type;
        totalMoney = (float)((int)totalMoney%wallet[i].money_type);
        
        if(returnMoney[i].count > wallet[i].count){
            totalMoney = totalMoney + (returnMoney[i].count-wallet[i].count)*(float)wallet[i].money_type;
            returnMoney[i].count = wallet[i].count;
        }
    }
    if(totalMoney!=0) {
        printf("お金足りません！\n");
        return false;
    }
    return true;
}
    


int main(int argc, const char * argv[]) {
    float input = atof(argv[1]);
    printf("input = %f\n", input);

    money_count returnMoney[TOTAL_MONEY_TYPE];

    if(getReturnMoney(input, returnMoney)==true) {
        for(int i = 0; i<TOTAL_MONEY_TYPE; i++) {
            printf("お金 %d: %d 枚\n", returnMoney[i].money_type, returnMoney[i].count);
        }
    }
    return 0;

}
