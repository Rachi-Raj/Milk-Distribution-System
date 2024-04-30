#include "milkDistributionSystem_header.h"


bool isHouseNumberExists(int customerHouseNumber) {
    for (int customerIndex = 0; customerIndex < numberOfCustomers; customerIndex++) {
        if (customers[customerIndex].customerHouseNumber == customerHouseNumber) {
            return true;
        }
    }
    return false;
}

int restrictIntegerValue() {
    int checkHouseNumber;
    while (true) {
        if (scanf("%d", &checkHouseNumber) == 1)  {
            if(checkHouseNumber<1){
                printf(" ~~ Please enter a valid positive integer.\n");
            }else{
                return checkHouseNumber;
            }
        } else {
            printf(" ~~ Please enter a valid positive integer.\n");
            scanf("%*s");
        }
    }
}


float restrictFloatValue() {
    float floatValue;
    while (true) {
        if (scanf("%f", &floatValue) == 1) {
            if(floatValue<1){
                printf(" ~~ Please enter a valid positive float value.\n");
            }else{
                return floatValue;
            }
        } else {
            printf(" ~~ Please enter a valid positive float value .\n");
            scanf("%*s");
        }
    }
}


void addNewCustomer() {
    printf("Enter Details of New Customer %d:\n", numberOfCustomers + 1);
    printf("---------------------------------\n");
        int customerHouseNumber;
    do {
        printf("House Number: ");
        customerHouseNumber = restrictIntegerValue();
        if (isHouseNumberExists(customerHouseNumber)) {
            printf(" ~~ House number %d already exists. Please enter a different house number.\n", customerHouseNumber);
            printf("--------------------------------------------------------------------------\n");
        }
    } while (isHouseNumberExists(customerHouseNumber));

    if (numberOfCustomers == 0) {
        customers = (struct Customer*)malloc(sizeof(struct Customer));
    } else {
        customers = (struct Customer*)realloc(customers, (numberOfCustomers + 1) * sizeof(struct Customer));
    }

    if (customers == NULL) {
        printf(" ~~ Memory allocation failed!.\n");
        exit(1);
    }

    customers[numberOfCustomers].customerHouseNumber = customerHouseNumber;

    printf("Enter Customer Name: ");
    scanf("%s", customers[numberOfCustomers].customerName);

    printf("House Geo-Location: ");
    scanf("%s", customers[numberOfCustomers].customerGeoLocation);

    printf("House Address: ");
    scanf("%s", customers[numberOfCustomers].customerHouseAddress);
    printf("Milk Quantity: ");
    customers[numberOfCustomers].milkQuantity = restrictIntegerValue();
    printf("Milk Rate Per Litre: ");
    customers[numberOfCustomers].milkRate = restrictFloatValue();

    customers[numberOfCustomers].milkDelivered = false;

    numberOfCustomers++; // Increase the number of customers
    printf("<< Customer Registered Successfully. >>\n");
    printf("____________________________________________________________________\n");
}





void displayCustomerDetails() {
    if (numberOfCustomers > 0) {
        // Sort customers by delivery status
        for (int customerIndex = 0; customerIndex < numberOfCustomers - 1; customerIndex++)
        {
            for (int swapCustomerIndex = customerIndex + 1; swapCustomerIndex < numberOfCustomers; swapCustomerIndex++) {
                if (customers[customerIndex].milkDelivered && !customers[swapCustomerIndex].milkDelivered) {
                    struct Customer tempCustomer = customers[customerIndex];
                    customers[customerIndex] = customers[swapCustomerIndex];
                    customers[swapCustomerIndex] = tempCustomer;
                }

            }
        }

        printf("\nCustomer Details:\n");
        printf("  ______________________________________________________________________________________________"
               "________________________________________________________________\n");
        printf(" |  House-Number  |\tName\t |\tGeo Location\t|\tAddress\t\t|  Milk-Delivered  |  Quantity(ltr)  |"
               "  Rate(Rs./ltr)  |\tBill(Rs.)\t|\n");
        printf(" |________________|______________|______________________|_______________________|________________"
               "__|_________________|_________________|________________________|\n");

        int remainingHouses = 0;
        int housesDelivered = 0;
        float totalBill = 0;

        for (int customerIndex = 0; customerIndex < numberOfCustomers; customerIndex++) {
            float bill = customers[customerIndex].milkQuantity * customers[customerIndex].milkRate;
            totalBill += bill;

            printf(" |%-16d|%-14s|%-22s|%-23s|%-18s|%-17d|%-17.2f|%-24.2f|\n",
                   customers[customerIndex].customerHouseNumber, customers[customerIndex].customerName,
                   customers[customerIndex].customerGeoLocation, customers[customerIndex].customerHouseAddress,
                   customers[customerIndex].milkDelivered ? "Delivered" : "Not Delivered",
                   customers[customerIndex].milkQuantity, customers[customerIndex].milkRate, bill);
            printf(" |-----------------------------------------------------------------------------------------------"
                   "---------------------------------------------------------------|\n");

            if (!customers[customerIndex].milkDelivered) {
                remainingHouses++;
            } else {
                housesDelivered++;
            }
        }

        printf(" |Total Houses: %-144d|\n", numberOfCustomers);
        printf(" |Remaining Houses to Deliver: %-129d|\n", remainingHouses);
        printf(" |Delivered Houses: %-140d|\n", housesDelivered);
        printf(" |Total Bill: Rs.%-143.2f|\n", totalBill);
        printf(" ------------------------------------------------------------------------------------------------"
               "----------------------------------------------------------------\n");
    } else {
        printf(" ~~ No customers added yet!\n");
        printf("____________________________________________________________________\n");
    }
}

void updateCustomerDetails() {
    if (numberOfCustomers > 0) {
        int searchHouseNumber;
        printf("Enter customer house number to update details: ");
        searchHouseNumber = restrictIntegerValue();

        printf("\n-------------------------------------------------------\n");

        for (int customerIndex = 0; customerIndex < numberOfCustomers; customerIndex++) {
            if (customers[customerIndex].customerHouseNumber == searchHouseNumber) {
                printf("Enter update details for customer with house number %d:", searchHouseNumber);
                printf("\n-------------------------------------------------------\n");

                printf("Name: ");
                scanf(" %[^\n]", customers[customerIndex].customerName);

                printf("House Geo-Location: ");
                scanf(" %[^\n]", customers[customerIndex].customerGeoLocation);

                printf("House Address: ");
                scanf(" %[^\n]", customers[customerIndex].customerHouseAddress);

                printf("Milk Quantity: ");
                customers[customerIndex].milkQuantity = restrictIntegerValue();

                printf("Milk Rate Per Litre: ");
                customers[customerIndex].milkRate = restrictFloatValue();

                printf("<< Customer Details Updated Successfully. >>\n");
                printf("____________________________________________________________________\n");

                return;
            }
        }

        printf(" ~~ Customer with house number %d not found!\n", searchHouseNumber);
        printf("____________________________________________________________________\n");
    } else {
        printf(" ~~ No customers added yet!\n");
        printf("____________________________________________________________________\n");
    }
}

void updateDeliveryStatus() {
    if (numberOfCustomers > 0) {
        int searchHouseNumber;
        printf("Enter customer house number to update delivery status: ");
        searchHouseNumber = restrictIntegerValue();

        printf("\n-------------------------------------------------------\n");

        for (int customerIndex = 0; customerIndex < numberOfCustomers; customerIndex++) {
            if (customers[customerIndex].customerHouseNumber == searchHouseNumber) {
                printf("Current delivery status: %s\n", customers[customerIndex].milkDelivered ? "Delivered" : "Not Delivered");
                printf("Press 1 to delivered or press 2 to not delivered: ");
                int choice = restrictIntegerValue();

                if (choice == 1) {
                    if(customers[customerIndex].milkDelivered == 1){
                        printf("Milk Already Delivered. \n");
                    }else{
                        customers[customerIndex].milkDelivered = 1;
                        printf("<< Delivery Status Updated to delivered. >>\n");
                    }

                } else if (choice == 2) {
                    if( customers[customerIndex].milkDelivered == 0){
                        printf("Delivery Status is already in not delivered. \n");
                    }else{
                        customers[customerIndex].milkDelivered = 0;
                        printf("<< Delivery Status updated to not delivered. >>\n");
                    }

                } else {
                    printf("Invalid choice!\n");
                }

                printf("____________________________________________________________________\n");
                return;
            }
        }

        printf(" ~~ Customer with house number %d not found!\n", searchHouseNumber);
        printf("____________________________________________________________________\n");
    } else {
        printf(" ~~ No customers added yet!\n");
        printf("____________________________________________________________________\n");
    }
}


void deleteCustomer() {
    int deleteHouseNumber;
    printf("Enter customer house number to delete: ");
    deleteHouseNumber=restrictIntegerValue();

    int deleteIndex = -1;
    for (int searchIndex = 0; searchIndex < numberOfCustomers; searchIndex++) {
        if (customers[searchIndex].customerHouseNumber == deleteHouseNumber) {
            deleteIndex = searchIndex;
            break;
        }
    }

    if (deleteIndex == -1) {
        printf(" ~~ Customer with house number %d not found!\n", deleteHouseNumber);
        printf("____________________________________________________________________\n");
        return;
    }

    // Shift the data after the deleted customer to fill the gap
    for (int shiftIndex = deleteIndex; shiftIndex < numberOfCustomers - 1; shiftIndex++) {
        customers[shiftIndex] = customers[shiftIndex + 1];
    }

    // Decrease the size of the customers array
    (numberOfCustomers)--;
    customers = (struct Customer*)realloc(customers, (numberOfCustomers) * sizeof(struct Customer));
    if (customers == NULL && numberOfCustomers > 0) {
        printf(" ~~ Memory reallocation failed!.\n");
        exit(1);
    }

    printf("<< Customer with house number %d deleted successfully. >>\n", deleteHouseNumber);
    printf("____________________________________________________________________\n");
}
