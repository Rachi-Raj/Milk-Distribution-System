#ifndef MILKDISTRIBUTIONSYSTEM_HEADER_H
#define MILKDISTRIBUTIONSYSTEM_HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

struct Customer {
    int customerHouseNumber;
    int milkQuantity;

    float milkRate;
    bool milkDelivered;
    char customerName[MAX_NAME_LENGTH];
    char customerGeoLocation[MAX_LOCATION_LENGTH];
    char customerHouseAddress[MAX_ADDRESS_LENGTH];
};

struct Customer* customers = NULL;
int numberOfCustomers = 0;

bool isHouseNumberExists(int customerHouseNumber);
int restrictIntegerValue();
float restrictFloatValue();
void addNewCustomer();
void displayCustomerDetails();
void updateCustomerDetails();
void updateDeliveryStatus();
void deleteCustomer();

#endif // MILKDISTRIBUTIONSYSTEM_HEADER_H
