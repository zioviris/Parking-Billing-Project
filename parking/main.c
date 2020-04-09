/*
Name:Georgios Zioviris
Date:14/10/2017
Project: Create a program that calculates parking charges, depending on the vehicle type (vehicle_type)
and the time stayed in the parking space.
Motorcycles prices have a discount up to 25% while vans prices are up to 1.15 of the standard price rate(1.25/hour)
The first 2 hours cost 1 euro per hour stayed
Subdivisions of hour are charged as a whole hour.
*/


#include <stdio.h>
#include <stdlib.h>

int main(){

    char vehicle_type;
    int xreosi_dio_proton_oron;
    int xreosi_pano_apo_dio_ores;
    double diafora_timis;
    int ores_eisodou;
    int ores_exodou;
    int lepta_eisodou;
    int lepta_exodou;
    int actual_ores;
    int actual_lepta;
    double charge,lefta,amount_to_give;
    int billable_hours;

    double change;
    int change_in_pennies;
    int kermata_1_euro;
    int kermata_ektos_1_euro;
    int kermata_20_lepta;
    int kermata_ektos_20_lepta;
    int kermata_5_lepta;
    int kermata_1_lepta;
    double sum;
    double lefta2;





    printf("\n");
    printf("Vehicle type (M,m,S,s,V,v): ");
    scanf(" %c",&vehicle_type);
    printf("\n");

    switch(vehicle_type){
        case 'M':
        case 'm':
            printf("Moto");
            printf("\n");
            printf("\n");
            diafora_timis=0.75; //25% discount
            break;
        case 'S':
        case 's':
            printf("Sedan");
            printf("\n");
            printf("\n");
            diafora_timis=1;
            break;
        case 'V':
        case 'v':
            printf("Van");
            printf("\n");
            printf("\n");
            diafora_timis=1.15; //1,15% markup
            break;
        default:
            printf("Invalid vehicle type \"%c\"",vehicle_type);
            printf("\n");
            return 1;
    }


    printf("Entry (HH:MM): ");
    scanf("%02d:%02d",&ores_eisodou,&lepta_eisodou);
    printf("\n");

    if ((ores_eisodou<0 || ores_eisodou>23)||(lepta_eisodou<0 || lepta_eisodou>59)){
        printf("Error:Invalid entry time!");
        printf("\n");
        return 1;
    }

    else{

        printf("Exit (HH:MM): ");
        scanf("%02d:%02d",&ores_exodou,&lepta_exodou);
        printf("\n");


        if ((ores_exodou<0||ores_exodou>23)||(lepta_exodou<0||lepta_eisodou>59)){
            printf("Error:Invalid exit time!");
            printf("\n");
            return 1;
        }
        else if ((ores_eisodou==ores_exodou) && (lepta_eisodou>lepta_exodou)){
            printf("Error: Entry time cannot be after exit time!");
            printf("\n");
            return 1;
        }
        else if (ores_eisodou>ores_exodou){
            printf("Error: Entry time cannot be after exit time!");
            printf("\n");
            return 1;

        }
        else if ((ores_exodou>ores_eisodou)&&(lepta_exodou<lepta_eisodou)){
            actual_lepta=60-(lepta_eisodou-lepta_exodou); // tricky part 1
            actual_ores=(ores_exodou-ores_eisodou)-1; //tricky part 2
            printf("Actual duration: %02d:%02d",actual_ores,actual_lepta);
            printf("\n");
        }
        else{
            actual_lepta=lepta_exodou-lepta_eisodou;
            actual_ores=ores_exodou-ores_eisodou;
            printf("Actual duration: %02d:%02d",actual_ores,actual_lepta);
            printf("\n");
        }
    }


        if(actual_lepta>0){
            billable_hours=(actual_ores+1);
        }
        else{
            billable_hours=actual_ores;
        }

        if (billable_hours>2){
            charge=(2+(billable_hours-2)*1.25)*diafora_timis;
        printf("\n");
        printf("Billable hours: %02d", billable_hours);
        printf("\n");
        printf("\n");
        printf("Charge: %.2lf",charge);

        }
        else{
            charge=billable_hours*diafora_timis;


        printf("\n");
        printf("Billable hours: %2d", billable_hours);
        printf("\n");
        printf("\n");
        printf("Charge: %.2lf",charge);
        }

        printf("\n");
        printf(">\n");
        scanf("%lf",&lefta);


        while(lefta<charge){
            sum=charge-lefta;
            printf("\n");
            printf("You paid %.2lf euros. Please pay another %.2lf euros",lefta,sum);

            printf("\n");
            printf(">");
            scanf("%lf",&lefta2);
            lefta=lefta+lefta2;
            printf("\n");
        }

        change=lefta-charge;

        if(change>0) {



            change_in_pennies=change*100;


            kermata_1_euro=change_in_pennies/100;
            kermata_ektos_1_euro=change_in_pennies%100;
            kermata_20_lepta=kermata_ektos_1_euro/20;
            kermata_ektos_20_lepta=kermata_ektos_1_euro%20;
            kermata_5_lepta=kermata_ektos_20_lepta/5;
            kermata_1_lepta=kermata_ektos_20_lepta%5;
            printf("\n");
            printf("Thank you! Here is your change:\n");
            if(kermata_1_euro!=0){
                printf("%d euro ",kermata_1_euro);
            }
            if(kermata_20_lepta!=0){
                printf("%d twenties ",kermata_20_lepta);
            }
            if (kermata_5_lepta!=0){
                printf("%d fives ",kermata_5_lepta);
            }
            if (kermata_1_lepta!=0){
                printf("%d cents",kermata_1_lepta);

            }

        }

        else if(change==0){
            printf("\n");
            printf("Thank you!");

        }



        return 0;

}


