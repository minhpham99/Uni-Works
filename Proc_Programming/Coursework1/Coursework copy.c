#include <stdio.h>
#include <math.h>

int main()
{
    
    // declare variables suitable for domestic, commercial customer and statistic, in different line to be able to check 
    int number, choice, count_domestic, count_commercial;
    float fresh_domestic, waste_domestic, surface_domestic = 10.0, standing_domestic = 0.1*91, fresh_charge, total_domestic, domestic_highest, new_bill;
    float fresh_commercial, standing_commercial = 1.3*91, waste_commercial, surface_commercial = 50, VAT, total_commercial, commercial_highest; 
    float Total_water_used, Total_domestic_used, Total_commercial_used, average_domestic, average_commercial, revenue, cost, profit, tax, Total_commercial_bill, Total_domestic_bill;
   
    //initialize the variables to make sure they don't contain garbage value
    fresh_domestic = waste_domestic = fresh_charge = total_domestic = domestic_highest = new_bill = 0;
    fresh_commercial = waste_commercial = VAT = total_commercial = commercial_highest = 0;
     
    // initialize the sums
    Total_domestic_used = 0;
    Total_commercial_used = 0;
    Total_commercial_bill = 0;
    Total_domestic_bill = 0;

    //initialize the counter
    count_commercial = 0;
    count_domestic = 0;
    
    printf("1. Compute and print the bill for a customer\n");
    printf("2. Shows summary and statistic\n");
    printf("3. Quit the program\n");

    printf("Please enter your choice number:");
    scanf("%i", &number);
   
    while (number >=1 && number <=3)
    {
        if (number == 1)
        {
           printf("Enter 1 for commercial and 2 for domestic customer:");
           scanf("%i", &choice);

           // use and scan number for each choices

           if (choice == 2)
           {
               printf("Enter the amount of water use:");
               scanf("%f", &fresh_domestic);

               // the calculation methods for each band

               //band 1
               if (fresh_domestic>=1 && fresh_domestic<=5 )
               {
                   fresh_charge = fresh_domestic*0.2;
               }

               //band 2
               else if (fresh_domestic>=6 && fresh_domestic <=12)
               {
                   fresh_charge = 5*0.2 + (fresh_domestic - 5)*0.35;
               }
               
               //band 3
               else if (fresh_domestic>=13 && fresh_domestic <=25)
               {
                   fresh_charge = 5*0.2 + 7*0.35 + (fresh_domestic - 7 - 5)*0.5;
               }

               //band 4
               else if (fresh_domestic>=26 && fresh_domestic <=40)
               {
                   fresh_charge = 5*0.2 + 7*0.35 + 13*0.5 + (fresh_domestic - 5 - 7 - 13)*0.75;
               }

               //band 5
               else if (fresh_domestic>40)
               {
                   fresh_charge = 5*0.2 + 7*0.35 + 13*0.5 + 15*0.75 + (fresh_domestic - 5 - 7 - 13 - 15)*2.5;
               }
            
               // declare formulas for domestic
                waste_domestic = fresh_domestic*0.95*0.25;
                total_domestic = fresh_charge + waste_domestic + standing_domestic + surface_domestic;
            

                printf("Type of customer: domestic\n");
                printf("Amount of fresh water consumption: %.2f\n", fresh_domestic);
                printf("Fresh water charges: £%.2f\n", fresh_charge);
                printf("Waste water charges: £%.2f\n", waste_domestic);
                printf("Surface water charges: £%.2f\n", surface_domestic);
                printf("Standing charges: £%.2f\n", standing_domestic);
                printf("Amount of VAT: Not applicable\n");
                printf("Total amount to pay: £%.2f\n\n", total_domestic);

                //increment the count
                count_domestic++;

                // print the menu again after each operation
                printf("1. Compute and print the bill for a customer\n");
                printf("2. Shows summary and statistic\n");
                printf("3. Quit the program\n");

                printf("Please enter your choice number:");
                scanf("%i", &number);

                // return to the beginning of the while loop
                if (number == 1)
                {
                    continue;
                }
                
                if (number == 2)
                {

                    printf("Total amount of fresh water:%.2f\n", Total_water_used);
                    printf("Total amount of fresh water consumed by domestic consumers:%.2f\n", Total_domestic_used);
                    printf("Total amount of fresh water consumed by commercial consumers:%.2f\n", Total_commercial_used); //creative statistic 1
                    printf("Total cost of providing fresh water:£%.2f\n", cost);
                    printf("Total revenue:£%.2f\n", revenue);
                    printf("Total profit:£%.2f\n", profit);
                    printf("Total tax:£%.2f\n", tax); 
                    printf("The average bill for domestic customer is £%.2f\n", average_domestic);
                    printf("The avereage bill for commercial customer is £%.2f\n", average_commercial);

                    printf("1. Compute and print the bill for a customer\n");
                    printf("2. Shows summary and statistic\n");
                    printf("3. Quit the program\n");
    
                    printf("Please enter your choice number:");
                    scanf("%i", &number);

                    if (number == 1 && number == 2)
                    {
                        continue;
                    }

                    if (number == 3)
                    {
                        printf("You have quit the program");
                        return 0;
                    }
        
                }
            
            }
                else if (choice == 1)
                {
                    printf("Enter the amount of water use:");
                    scanf("%f", &fresh_commercial);

                    // declare formulas for commercial
                    fresh_charge = 2.5*fresh_commercial;
                    waste_commercial = fresh_commercial*0.95*2;
                    VAT = 0.2*(fresh_charge + waste_commercial + standing_commercial + surface_commercial);
                    total_commercial = fresh_charge + waste_commercial + surface_commercial + standing_commercial + VAT;


                    printf("Type of customer: commercial\n");
                    printf("Amount of fresh water consumption: %.2f\n", fresh_commercial);
                    printf("Fresh water charges: £%.2f\n", fresh_charge);
                    printf("Waste water charges: £%.2f\n", waste_commercial);
                    printf("Surface water charges: £%.2f\n", surface_commercial);
                    printf("Standing charges: £%.2f\n", standing_commercial);
                    printf("Amount of VAT: £%.2f\n", VAT);
                    printf("Total amount to pay: £%.2f\n\n", total_commercial);

                    //increment the count
                    count_commercial++;                    

                    printf("1. Compute and print the bill for a customer\n");
                    printf("2. Shows summary and statistic\n");
                    printf("3. Quit the program\n");
    
                    printf("Please enter your choice number:");
                    scanf("%i", &number);

                    if (number == 1)
                    {
                        continue;
                    }
                    
                    if (number == 2)
                    {

                        printf("Total amount of fresh water:%.2f\n", Total_water_used);
                        printf("Total amount of fresh water consumed by domestic consumers:%.2f\n", Total_domestic_used);
                        printf("Total amount of fresh water consumed by commercial consumers:%.2f\n", Total_commercial_used); //creative statistic 1
                        printf("Total cost of  providing fresh water:£%.2f\n", cost);
                        printf("Total revenue:£%.2f\n", revenue);
                        printf("Total profit:£%.2f\n", profit);
                        printf("Total tax:£%.2f\n", tax); 
                        printf("The average bill for domestic customer is £%.2f\n", average_domestic);
                        printf("The avereage bill for commercial customer is £%.2f\n", average_commercial);
                        

                        printf("1. Compute and print the bill for a customer\n");
                        printf("2. Shows summary and statistic\n");
                        printf("3. Quit the program\n");
        
                        printf("Please enter your choice number:");
                        scanf("%i", &number);
    
                        if (number == 1 && number == 2)
                        {
                            continue;
                        }

                        if (number == 3)
                        {
                            printf("You have quit the program");
                            return 0;
                        }
            
                    }


                }
        }
           
        else if (number == 2)
        {

            Total_domestic_used += fresh_domestic;
            Total_commercial_used += fresh_commercial;
            Total_water_used = Total_domestic_used + Total_commercial_used;
            cost = Total_water_used*1;
            Total_domestic_bill += total_domestic;
            Total_commercial_bill += total_commercial;
            revenue = Total_domestic_bill + Total_commercial_bill;
            profit = revenue - cost;
            tax = 0.25*profit;
            average_domestic = Total_domestic_bill/count_domestic;
            average_commercial = Total_commercial_bill/count_commercial;

            printf("Total amount of fresh water:%.2f\n", Total_water_used);
            printf("Total amount of fresh water consumed by domestic consumers:%.2f\n", Total_domestic_used);
            printf("Total amount of fresh water consumed by commercial consumers:%.2f\n", Total_commercial_used);
            printf("Total cost of  providing fresh water:£%.2f\n", cost);
            printf("Total revenue:£%.2f\n", revenue);
            printf("Total profit:£%.2f\n", profit);
            printf("Total tax:£%.2f\n", tax); 
            printf("The average bill for domestic customer is £%.2f\n", average_domestic);
            printf("The avereage bill for commercial customer is £%.2f\n", average_commercial);
            
            printf("1. Compute and print the bill for a customer\n");
            printf("2. Shows summary and statistic\n");
            printf("3. Quit the program\n");

            printf("Please enter your choice number:");
            scanf("%i", &number);

            if (number == 1 && number == 2)
            {
                continue;
            }


        else if (number == 3)
        {
            printf("You have quit the program\n");
            return 0;
        }         
    }
    
    else if (number == 3)
    {
        printf("You have quit the program\n");
        return 0;
    }         
    // when user enter anything else but 1 - 3
    if (number !=1 && number !=2 && number !=3)
    {
        printf("Invalid input");
    }
    } 
    return 0;
}