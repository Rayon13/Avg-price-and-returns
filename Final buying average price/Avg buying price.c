#include<stdio.h>
#include<math.h>
int main()
{
    float ip,off,tm,amo,amo1,i,j,ch;
    float n,avg,cmp,rem,quan1,quan2,pr;
    label:
    {
        printf("The price of crypto you wanna start buying at = ");
        scanf("%f",&ip);
        printf("\nThe amount of dip you wanna keep buying = ");
        scanf("%f",&off);
        printf("\nTotal amount you wanna invest = ");
        scanf("%f",&tm);
        printf("\nThe amount you wanna invest every time the desired price is reached = ");
        scanf("%f",&amo);

        i=1;
        quan2=0;
        amo1=round(amo*1.002);
        quan1=amo/ip;
        n=tm/amo1;
        rem=(int)tm%(int)amo1;
        j=tm;

        while(i<=n)
        {
            if(j>=amo1)
            {
                quan2+=quan1;
                ip=ip-off;
                quan1=amo/ip;
            }
            else
            {
                quan1=rem/ip;
                quan2+=quan1;
            }
            j=j-amo1;

            if(j==rem)
                i+=rem/amo1;
            else
                i++;
        }
        avg=(tm*0.998)/quan2;
        printf("\nFinal buying average price = %f",avg);
        printf("\n\nEnter CMP = ");
        scanf("%f",&cmp);
        pr=(cmp*quan2*0.998)-(avg*quan2);
        if(pr>=0)
            printf("\nProfit = %f",pr);
        else
            printf("\nLoss = %f",pr);
    }
    printf("\n\nDo you want to start again?(yes=1/No=0): ");
    scanf("%f",&ch);
    if(ch==1)
    {
        printf("\n");
        goto label;
    }
    else if(ch==0)
        printf("\nThank you for using the calculator.");
    else
        printf("\nInvalid input");

    return 0;
}
