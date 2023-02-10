#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>


int main(){
char row[3][3] = {'x','x','x',
'x','x','x',
'x','x','x'};

char slotChar[4];
slotChar[0] = '7';
slotChar[1] = '%';
slotChar[2] = '$';
slotChar[3] = '+';
//slot char's'
int money = 100;

//clr's'
char red[10] = "\033[0;31m";
char normal[10] = "\033[0m";

int moneyBuffer = 0;
int maxTurns;
int turns;
int timesTurn = 5;
//
int chose;
//
int minSlotUse = 10;
//start ammount of money
int z;
//option select
//
//randSlotCharBuffer
srand(time(0));
int randX;
//speed of spinning in ms
int speed = 40;

int speedRev = 1200;
//maxWin on min slot
int moneyJP = minSlotUse * 25;
int moneyW = minSlotUse * 5;
int moneyDol = minSlotUse * 10;
int moneySmW = minSlotUse * 2;

start:
if (money<=minSlotUse){
printf("You have lost all your money =(\n");
return 0;
}
printf("\e[1;1H\e[2J");
printf("You have %d$\nIf you wanna play type 1\nIf you wanna quit type 0\nType option:",money);
scan:
scanf("%d",&z);
switch(z){
    //end program + proggres
    case 0:
        printf("\e[1;1H\e[2J");
        printf("You have ended with %d$\n",money);
        return 0;
        break;
    //start spinning
    case 1:
        slotStart:
        moneyBuffer = 0;
        printf("\e[1;1H\e[2J");
        printf("--- %c %c %c ---\n",row[0][0],row[0][1],row[0][2]);
        printf(">>> %c %c %c <<<\n",row[1][0],row[1][1],row[1][2]);
        printf("--- %c %c %c ---\n\n",row[2][0],row[2][1],row[2][2]);
        printf("Chose option\nTo play slot machine press 1(%d$), to stop - 0\nYou have %d$\nInput:",minSlotUse,money);
        scanf("%d",&chose);
        switch(chose){
            case 1:
                if(money<minSlotUse){
                printf("\e[1;1H\e[2J");
                printf("You don't have enough money\nYou lose=(\n");
                return 0;
                }
                maxTurns = money / minSlotUse;
                printf("How many turns? (for now max:%d)",maxTurns);
                scanTurns:
                scanf("%d",&turns);
                if (turns > maxTurns || turns < 1){printf("Maximum is %d and minimum is 1\nTurns:",maxTurns); goto scanTurns;}
                money = money - minSlotUse*turns;
                //
                //
                //ITS SOMEHOW WORKING AND I DON'T WANT TO KNOW HOW
                for(int turnsLeft = turns-1; turnsLeft>-1; turnsLeft--){
                for(int limil = 0; limil<timesTurn; limil++){

                for(int j = 0; j<3; j++){
                randX = rand() % 4;
                // row[i+1][j] = row[i][j];
                row[0][j] = slotChar[randX];
                printf("\e[1;1H\e[2J");
                printf("--- %c %c %c ---\n",row[0][0],row[0][1],row[0][2]);
                printf(">>> %c %c %c <<<\n",row[1][0],row[1][1],row[1][2]);
                printf("--- %c %c %c ---\n\n",row[2][0],row[2][1],row[2][2]);
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speed*1000);
                }
                for(int i = 2; i>0; i--){
                for(int j = 0; j<3; j++){
                row[i][j] = row[i-1][j];
                printf("\e[1;1H\e[2J");
                printf("--- %c %c %c ---\n",row[0][0],row[0][1],row[0][2]);
                printf(">>> %c %c %c <<<\n",row[1][0],row[1][1],row[1][2]);
                printf("--- %c %c %c ---\n\n",row[2][0],row[2][1],row[2][2]);
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speed*1000);
                }
                }
                }
                for(int j = 0; j<3; j++){
                randX = rand() % 4;
                // row[i+1][j] = row[i][j];
                row[0][j] = slotChar[randX];
                printf("\e[1;1H\e[2J");
                printf("--- %c %c %c ---\n",row[0][0],row[0][1],row[0][2]);
                printf(">>> %c %c %c <<<\n",row[1][0],row[1][1],row[1][2]);
                printf("--- %c %c %c ---\n\n",row[2][0],row[2][1],row[2][2]);
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speed*1000);
                }
                //ITS SOMEHOW WORKING AND I DON'T WANT TO KNOW HOW
                //
                //case's of winning'
                if (row[0][0] == row[1][1] && row[0][0] == row[2][2]){
                printf("\e[1;1H\e[2J");
                printf("--- %s%c%s %c %c ---\n",red,row[0][0],normal,row[0][1],row[0][2]);
                printf(">>> %c %s%c%s %c <<<\n",row[1][0],red,row[1][1],normal,row[1][2]);
                printf("--- %c %c %s%c%s ---\n\n",row[2][0],row[2][1],red,row[2][2],normal);
                if(row[0][0] == slotChar[0]){moneyBuffer = moneyBuffer + moneyJP;}
                if(row[0][0] == slotChar[1]){moneyBuffer = moneyBuffer + moneyW;}
                if(row[0][0] == slotChar[2]){moneyBuffer = moneyBuffer + moneyDol;}
                if(row[0][0] == slotChar[3]){moneyBuffer = moneyBuffer + moneySmW;}
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speedRev*1000);
                }
                if (row[2][0] == row[1][1] && row[2][0] == row[0][2]){
                printf("\e[1;1H\e[2J");
                printf("--- %c %c %s%c%s ---\n",row[0][0],row[0][1],red,row[0][2],normal);
                printf(">>> %c %s%c%s %c <<<\n",row[1][0],red,row[1][1],normal,row[1][2]);
                printf("--- %s%c%s %c %c ---\n\n",red,row[2][0],normal,row[2][1],row[2][2]);
                if(row[2][0] == slotChar[0]){moneyBuffer = moneyBuffer + moneyJP;}
                if(row[2][0] == slotChar[1]){moneyBuffer = moneyBuffer + moneyW;}
                if(row[2][0] == slotChar[2]){moneyBuffer = moneyBuffer + moneyDol;}
                if(row[2][0] == slotChar[3]){moneyBuffer = moneyBuffer + moneySmW;}
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speedRev*1000);
                }
                if (row[0][0] == row[0][1] && row[0][0] == row[0][2]){
                printf("\e[1;1H\e[2J");
                printf("--- %s%c %c %c%s ---\n",red,row[0][0],row[0][1],row[0][2],normal);
                printf(">>> %c %c %c <<<\n",row[1][0],row[1][1],row[1][2]);
                printf("--- %c %c %c ---\n\n",row[2][0],row[2][1],row[2][2]);
                if(row[0][0] == slotChar[0]){moneyBuffer = moneyBuffer + moneyJP;}
                if(row[0][0] == slotChar[1]){moneyBuffer = moneyBuffer + moneyW;}
                if(row[0][0] == slotChar[2]){moneyBuffer = moneyBuffer + moneyDol;}
                if(row[0][0] == slotChar[3]){moneyBuffer = moneyBuffer + moneySmW;}
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speedRev*1000);
                }
                if (row[1][0] == row[1][1] && row[1][0] == row[1][2]){
                printf("\e[1;1H\e[2J");
                printf("--- %c %c %c ---\n",row[0][0],row[0][1],row[0][2]);
                printf(">>> %s%c %c %c%s <<<\n",red,row[1][0],row[1][1],row[1][2],normal);
                printf("--- %c %c %c ---\n\n",row[2][0],row[2][1],row[2][2]);
                if(row[1][0] == slotChar[0]){moneyBuffer = moneyBuffer + moneyJP;}
                if(row[1][0] == slotChar[1]){moneyBuffer = moneyBuffer + moneyW;}
                if(row[1][0] == slotChar[2]){moneyBuffer = moneyBuffer + moneyDol;}
                if(row[1][0] == slotChar[3]){moneyBuffer = moneyBuffer + moneySmW;}
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speedRev*1000);
                }
                if (row[2][0] == row[2][1] && row[2][0] == row[2][2]){
                printf("\e[1;1H\e[2J");
                printf("--- %c %c %c ---\n",row[0][0],row[0][1],row[0][2]);
                printf(">>> %c %c %c <<<\n",row[1][0],row[1][1],row[1][2]);
                printf("--- %s%c %c %c%s ---\n\n",red,row[2][0],row[2][1],row[2][2],normal);
                if(row[2][0] == slotChar[0]){moneyBuffer = moneyBuffer + moneyJP;}
                if(row[2][0] == slotChar[1]){moneyBuffer = moneyBuffer + moneyW;}
                if(row[2][0] == slotChar[2]){moneyBuffer = moneyBuffer + moneyDol;}
                if(row[2][0] == slotChar[3]){moneyBuffer = moneyBuffer + moneySmW;}
                printf("\nturns left:%d\n",turnsLeft);
                printf("Winning:%d$\n",moneyBuffer);
                usleep(speedRev*1000);
                }
                usleep(speedRev*1000);
                }
                // sleep(2);
                money = money + moneyBuffer;
                goto slotStart;
            case 0:
                goto start;
            default:
                goto slotStart;
        }

    //err input
    default:
        printf("\e[1;1H\e[2J");
        printf("If you wanna play type 1\nIf you wanna quit type 0\nPlease, type correct option:");
        goto scan;
}
}
