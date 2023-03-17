#include <stdio.h>
#define DEMAND_CHG 35.00
#define PER_1000_CHG 1.10
#define LATE_CHG 2.00


void instruct_water(void);

double comp_use_charge (int previous, int current);

double comp_late_charge (double unpaid);

void display_bill (double late_charge, double bill, double unpaid);

int main (void)

{

	int previous;
	int current;
	double unpaid;
	double bill;
	int used;
	double use_charge;
	double late_charge;

	instruct_water ();

	printf(" Enter unpaid balance> $");
	scanf("%lf", &unpaid);
	printf("Enter previous meter reading> ");
	scanf("%d", &previous);
	printf(" Enter current meter reading> ");
	scanf("%d", &current);

	use_charge = comp_use_charge(previous, current);

	late_charge = comp_late_charge(unpaid);

	bill = DEMAND_CHG + use_charge + unpaid + late_charge;

	display_bill(late_charge, bill, unpaid);

	return (0);
	
}


void instruct_water(void)


{
	printf("  This program figures a water bill ");
	printf("  based on the  demand charge\n");
	printf("  ($%.2f) and a $%.2f per 1000 ", DEMAND_CHG, PER_1000_CHG);
	printf("  gallons use charge.\n\n");
	printf("  A $%.2f surcharge is added to ", LATE_CHG);
	printf("  accounts with an unpaid balance.\n");
	printf("\n  Enter unpaid balance, previous ");
	printf("and current meter readings\n");
	printf("  on seperate lines after the prompts.\n");
	printf("  Press <return> or <enter> after ");
	printf("typing each number.\n\n");

}

double comp_use_charge(int previous, int current)
{
	int used;
	double use_charge;

	used = current - previous;
	use_charge = used * PER_1000_CHG;

	return (use_charge);
}

double comp_late_charge(double unpaid)

{
	double late_charge;

	if(unpaid > 0)
		late_charge = LATE_CHG;
	else 
		late_charge = 0.0;

	return (late_charge);

}

void display_bill(double late_charge, double bill, double unpaid)
{
	if (late_charge >0.0)
	{
		printf("\nBill includes $%.2f late charge", late_charge);
		printf(" on unpaid balance of $%.2f\n", unpaid);
	}
	printf("\nTotal due = $%.2f\n", bill);
}