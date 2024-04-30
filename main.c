#include "milkDistributionSystem_header.h"
#include "milkDistributionSystem_implementation.cpp"

int main() {

    int choice=0;

    printf("\n\t\t\t\t\t\t\t\t\t|--------------------------|\n");
    printf("\t\t\t\t\t\t\t\t\t| MILK DISTRIBUTION SYSTEM |\n");
    printf("\t\t\t\t\t\t\t\t\t|--------------------------|\n\n");

    while(choice!=7){
        printf("Menu:\n");
        printf("  1. Add New Customer\n");
        printf("  2. Display Customer Details\n");
        printf("  3. Update Customer Details\n");
        printf("  4. Update Delivery Status\n");
        printf("  5. Delete Customer\n");
        printf("  6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case add_New_Customer:
            addNewCustomer();
            // printf("%d",customers);
            break;
        case display_Customer_Details:
            displayCustomerDetails();
            break;
        case update_Customer_Details:
            updateCustomerDetails();
            break;
        case update_Delivery_Status:
            updateDeliveryStatus();
            break;
        case delete_Customer:
            deleteCustomer();
            break;

        case exit_:
            if (numberOfCustomers > 0) {
                free(customers); // Free allocated memory before exiting
            }
            printf("<< Exiting the Program >>\n");
            break;


        default:
            printf(" ~~ Invalid Choice! Please enter a number between 1 and 6.\n");
            printf("____________________________________________________________________\n");
        }
    }


    return 0;
}
