/*REG NO:PA106/G/28713/25
NAME:RONNY KIMUTAI 
DESCRIPTION:PROGRAM TO DISPLAY WORKERS SALARY
*/
#include <stdio.h>

int main() {
    float hours, rate, gross = 0.0, tax = 0.0, net;
    
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: $");
    scanf("%f", &rate);
    
    if (hours > 40) {
        gross = 40 * rate + (hours - 40) * rate * 1.5;
    } else {
        gross = hours * rate;
    }
    
    if (gross <= 600) {
        tax = gross * 0.15;
    } else {
        tax = 600 * 0.15 + (gross - 600) * 0.20;
    }
    
    net = gross - tax;
    
    printf("\nGross Pay: $%.2f\n", gross);
    printf("Taxes:     $%.2f\n", tax);
    printf("Net Pay:   $%.2f\n", net);
    
    return 0;
}
