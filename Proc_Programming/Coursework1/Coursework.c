/********************************************************************

I declare that the following program was written by me and that I have NOT copied any part of this code from any other source.

Name: Minh Hien Pham

Email: sc17mp@leeds.ac.uk

Date: 23 Oct 2017

*********************************************************************/

#include <stdio.h>
#include <math.h>

int main() 
{
    // declare variables suitable for domestic, commercial customer and statistic in different lines for easier checking 
    int menu_choice, customer_choice, count_domestic, count_commercial; 
    float fresh_domestic, waste_domestic, surface_domestic = 10.0, standing_domestic = 0.1*91, total_domestic, domestic_highest, domestic_new_bill; // for domestic customers
    float fresh_commercial, standing_commercial = 1.3*91, waste_commercial, surface_commercial = 50, total_commercial, commercial_highest, commercial_new_bill; // for commercial customers
    float fresh_charge, VAT, revenue, cost, profit, tax, total_water_used, total_domestic_used, total_commercial_used, average_domestic, average_commercial, total_commercial_bill, total_domestic_bill; // for company stats

    //initialize the float so they don't contain garbage memory
    fresh_charge = VAT = revenue = cost = profit = tax = 0;
    fresh_domestic = waste_domestic = total_domestic = domestic_highest = domestic_new_bill = 0;
    fresh_commercial = waste_commercial = total_commercial = commercial_highest = commercial_new_bill = 0;

    // initialize the sums
    total_domestic_used = 0;
    total_commercial_used = 0;
    total_commercial_bill = 0;
    total_domestic_bill = 0;

    // initialize the counters
    count_commercial = 0;
    count_domestic = 0;

    // initialize menu_choice so menu gets printed starts on first run( either 1,2 or 3 since those are the menu_choice numbers)
    menu_choice = 1;

    // start the while loop
    while (menu_choice >=1 && menu_choice <=3) 
    {
        // printing the menu
        printf("1. Compute and print the bill for a customer\n");
        printf("2. Show summary and statistics\n");
        printf("3. Quit the program\n");

        printf("Please enter your choice: ");
        scanf("%i", &menu_choice);

        // if menu_choice 1 compute and print bill for customer
        if (menu_choice == 1) 
        {
           printf("\nEnter 1 for commercial and 2 for domestic customer: ");
           scanf("%i", &customer_choice);

           // if choice is domestic customer
           if (customer_choice == 2) 
           {
               printf("Enter the amount of water use: ");
               scanf("%f", &fresh_domestic);

               // the calculation methods for each band
               // band 1
               if (fresh_domestic >=1 && fresh_domestic <=5 ) 
               {
                   fresh_charge = fresh_domestic * 0.2;
               }

               // band 2
               else if (fresh_domestic >= 6 && fresh_domestic <= 12) 
               {
                   fresh_charge = 5 * 0.2 + (fresh_domestic - 5) * 0.35;
               }

               // band 3
               else if (fresh_domestic >= 13 && fresh_domestic <= 25) 
               {
                   fresh_charge = 5 * 0.2 + 7 * 0.35 + (fresh_domestic - 7 - 5) * 0.5;
               }

               // band 4
               else if (fresh_domestic >= 26 && fresh_domestic <= 40) 
               {
                   fresh_charge = 5 * 0.2 + 7 * 0.35 + 13 * 0.5 + (fresh_domestic - 5 - 7 - 13) * 0.75;
               }

               // band 5
               else if (fresh_domestic > 40) 
               {
                   fresh_charge = 5 * 0.2 + 7 * 0.35 + 13 * 0.5 + 15 * 0.75 + (fresh_domestic - 5 - 7 - 13 - 15) * 2.5;
               }

               // declare formulas for domestic use
                waste_domestic = fresh_domestic * 0.95 * 0.25;
                total_domestic = fresh_charge + waste_domestic + standing_domestic + surface_domestic;

                // print statistics for domestic customers
                printf("\nType of customer: domestic\n");
                printf("Amount of fresh water consumption: %.2f\ncm3", fresh_domestic);
                printf("Fresh water charges: £%.2f\n", fresh_charge);
                printf("Waste water charges: £%.2f\n", waste_domestic);
                printf("Surface water charges: £%.2f\n", surface_domestic);
                printf("Standing charges: £%.2f\n", standing_domestic);
                printf("Amount of VAT: Not applicable\n");
                printf("Total amount to pay: £%.2f\n\n", total_domestic);

                // increment the domestic counter
                count_domestic++;

                // set an if to compare the domestic new bill value to the highest domestic bill value
                if (domestic_new_bill > domestic_highest)
                {
                    domestic_new_bill = domestic_highest;
                }
            }
            else if (customer_choice == 1) 
            {
                printf("Enter the amount of water use: ");
                scanf("%f", &fresh_commercial);

                // declare formulas for commercial
                fresh_charge = 2.5 * fresh_commercial;
                waste_commercial = fresh_commercial * 0.95 * 2;
                VAT = 0.2 * (fresh_charge + waste_commercial + standing_commercial + surface_commercial);
                total_commercial = fresh_charge + waste_commercial + surface_commercial + standing_commercial + VAT;

                // print statistics for commercial customers
                printf("Type of customer: commercial\n");
                printf("Amount of fresh water consumption: %.2f\n cm3", fresh_commercial);
                printf("Fresh water charges: £%.2f\n", fresh_charge);
                printf("Waste water charges: £%.2f\n", waste_commercial);
                printf("Surface water charges: £%.2f\n", surface_commercial);
                printf("Standing charges: £%.2f\n", standing_commercial);
                printf("Amount of VAT: £%.2f\n", VAT);
                printf("Total amount to pay: £%.2f\n\n", total_commercial);

                //increment the commercial counter
                count_commercial++;
                
                // set an if to compare the commercial new bill value to the highest commercial bill value
                if (commercial_new_bill > commercial_highest)
                {
                    commercial_new_bill = commercial_highest;
                }
            }
        }

        // if menu_choice 2, print company summary and statistics
        else if (menu_choice == 2) 
        {
            // declare sums and formulas for statistics
            total_domestic_used += fresh_domestic;
            total_commercial_used += fresh_commercial;
            total_water_used = total_domestic_used + total_commercial_used;
            cost = total_water_used*1;
            total_domestic_bill += total_domestic;
            total_commercial_bill += total_commercial;
            revenue = total_domestic_bill + total_commercial_bill;
            profit = revenue - cost;
            tax = 0.25*profit;
            average_domestic = total_domestic_bill/count_domestic;
            average_commercial = total_commercial_bill/count_commercial;

            // print company statistics
            printf("Total amount of fresh water:%.2f\n", total_water_used);
            printf("Total amount of fresh water consumed by domestic consumers:%.2f\n", total_domestic_used);
            printf("Total amount of fresh water consumed by commercial consumers:%.2f\n", total_commercial_used);
            printf("Total cost of  providing fresh water:£%.2f\n", cost);
            printf("Total revenue:£%.2f\n", revenue);
            printf("Total profit:£%.2f\n", profit);
            printf("Total tax:£%.2f\n", tax);
            printf("The average bill for domestic customer is £%.2f\n", average_domestic);
            printf("The average bill for commercial customer is £%.2f\n\n", average_commercial);
            printf("The maximum domestic bill is £%.2f\n," domestic_highest);
            printf("The maximum commercial bill is £%.2f\n," commercial_highest);
            
        }

        else if (menu_choice == 3) 
        {
            printf("You have quit the program\n");
            return 0;
        }

        // when user enter anything else but 1 - 3
        if (menu_choice != 1 && menu_choice != 2 && menu_choice != 3) 
        {
            printf("Invalid input");
            return 0;
        }
    }
    return 0;
}