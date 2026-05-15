# README.md

# Bank Account System using Salesforce Apex

## Project Overview

The Bank Account System is a console-based Salesforce application developed using Apex programming language.
This project manages customer bank account records and performs CRUD operations using Salesforce database.

The system stores customer details such as:

* Customer ID
* Customer Name
* Email
* Birth Date
* Account Type
* Account Balance

The project demonstrates:

* Salesforce Custom Objects
* Apex Classes
* SOQL Queries
* DML Operations
* Console-Based Execution

---

# Features

* Add Customer Record
* View All Customers
* Search Customer
* Update Customer Details
* Delete Customer Record
* Console-Based Bank Management

---

# Technologies Used

* Salesforce CRM
* Apex Programming
* SOQL
* Salesforce Developer Console

---

# Prerequisites

Before starting the project, ensure you have:

* Salesforce Developer Account
* Salesforce Developer Console Access
* Basic Knowledge of Apex and Salesforce

Create free account here:

[Salesforce Developer Signup](https://developer.salesforce.com/signup?utm_source=chatgpt.com)

---

# Step 1: Login to Salesforce

1. Open Salesforce Developer Account
2. Login using credentials
3. Open App Launcher
4. Search:

```text id="c8twh6"
Developer Console
```

5. Open Developer Console

---

# Step 2: Create Custom Object

Go to:

## Setup → Object Manager → Create → Custom Object

Fill the following details:

| Property     | Value         |
| ------------ | ------------- |
| Label        | Customer      |
| Plural Label | Customers     |
| Object Name  | Customer      |
| Record Name  | Customer Name |
| Data Type    | Text          |

Click:

```text id="j30xuh"
Save
```

---

# Step 3: Create Custom Fields

Inside Customer Object, create the following fields.

---

## Field 1: Customer ID

| Property    | Value          |
| ----------- | -------------- |
| Field Label | Customer ID    |
| API Name    | Customer_ID__c |
| Data Type   | Number         |

---

## Field 2: Customer Name

| Property    | Value            |
| ----------- | ---------------- |
| Field Label | Customer Name    |
| API Name    | Customer_Name__c |
| Data Type   | Text             |

---

## Field 3: Email

| Property    | Value    |
| ----------- | -------- |
| Field Label | Email    |
| API Name    | Email__c |
| Data Type   | Email    |

---

## Field 4: Birth Date

| Property    | Value         |
| ----------- | ------------- |
| Field Label | Birth Date    |
| API Name    | Birth_Date__c |
| Data Type   | Date          |

---

## Field 5: Account Type

| Property    | Value           |
| ----------- | --------------- |
| Field Label | Account Type    |
| API Name    | Account_Type__c |
| Data Type   | Text            |

---

## Field 6: Account Balance

| Property    | Value              |
| ----------- | ------------------ |
| Field Label | Account Balance    |
| API Name    | Account_Balance__c |
| Data Type   | Currency           |

---

# Step 4: Create Apex Class

Go to:

## Developer Console → File → New → Apex Class

Class Name:

```text id="jlwm9g"
BankAccountSystem
```

Click:

```text id="qn5h08"
OK
```

Replace generated code with the following code.

---

# Apex Class Code

```apex id="6z7rfx"
public class BankAccountSystem {

    // Add Customer
    public static void addCustomer(Integer customerId,
                                   String customerName,
                                   String email,
                                   Date birthDate,
                                   String accountType,
                                   Decimal accountBalance) {

        Customer__c cust = new Customer__c();

        cust.Customer_ID__c = customerId;
        cust.Customer_Name__c = customerName;
        cust.Email__c = email;
        cust.Birth_Date__c = birthDate;
        cust.Account_Type__c = accountType;
        cust.Account_Balance__c = accountBalance;

        insert cust;

        System.debug('Customer Added Successfully');
    }

    // View Customers
    public static void viewCustomers() {

        List<Customer__c> custList = [

            SELECT Customer_ID__c,
                   Customer_Name__c,
                   Email__c,
                   Birth_Date__c,
                   Account_Type__c,
                   Account_Balance__c
            FROM Customer__c
        ];

        for(Customer__c cust : custList) {

            System.debug('----------------------------');
            System.debug('Customer ID : ' + cust.Customer_ID__c);
            System.debug('Customer Name : ' + cust.Customer_Name__c);
            System.debug('Email : ' + cust.Email__c);
            System.debug('Birth Date : ' + cust.Birth_Date__c);
            System.debug('Account Type : ' + cust.Account_Type__c);
            System.debug('Account Balance : ' + cust.Account_Balance__c);
        }
    }

    // Search Customer
    public static void searchCustomer(Integer customerId) {

        List<Customer__c> custList = [

            SELECT Customer_ID__c,
                   Customer_Name__c,
                   Email__c,
                   Account_Type__c,
                   Account_Balance__c
            FROM Customer__c
            WHERE Customer_ID__c = :customerId
        ];

        if(custList.size() > 0) {

            Customer__c cust = custList[0];

            System.debug('Customer Found');
            System.debug('Customer Name : ' + cust.Customer_Name__c);
            System.debug('Account Type : ' + cust.Account_Type__c);
            System.debug('Balance : ' + cust.Account_Balance__c);

        } else {

            System.debug('Customer Not Found');
        }
    }

    // Update Account Balance
    public static void updateBalance(Integer customerId,
                                     Decimal newBalance) {

        List<Customer__c> custList = [

            SELECT Id,
                   Account_Balance__c
            FROM Customer__c
            WHERE Customer_ID__c = :customerId
        ];

        if(custList.size() > 0) {

            Customer__c cust = custList[0];

            cust.Account_Balance__c = newBalance;

            update cust;

            System.debug('Balance Updated Successfully');

        } else {

            System.debug('Customer Not Found');
        }
    }

    // Delete Customer
    public static void deleteCustomer(Integer customerId) {

        List<Customer__c> custList = [

            SELECT Id
            FROM Customer__c
            WHERE Customer_ID__c = :customerId
        ];

        if(custList.size() > 0) {

            delete custList[0];

            System.debug('Customer Deleted Successfully');

        } else {

            System.debug('Customer Not Found');
        }
    }
}
```

---

# Step 5: Save Apex Class

Click:

## File → Save

OR press:

```text id="gmkx4n"
Ctrl + S
```

---

# Step 6: Execute Program

Go to:

## Debug → Open Execute Anonymous Window

Shortcut:

```text id="h6f0a9"
Ctrl + E
```

---

# Add Customer

```apex id="z9qv25"
BankAccountSystem.addCustomer(
    101,
    'Rahul Sharma',
    'rahul@gmail.com',
    Date.newInstance(2000, 5, 10),
    'Savings',
    50000
);
```

---

# View Customers

```apex id="8v4fmv"
BankAccountSystem.viewCustomers();
```

---

# Search Customer

```apex id="2d74je"
BankAccountSystem.searchCustomer(101);
```

---

# Update Balance

```apex id="wxvh6k"
BankAccountSystem.updateBalance(
    101,
    75000
);
```

---

# Delete Customer

```apex id="wb0bzg"
BankAccountSystem.deleteCustomer(101);
```

---

# Step 7: Check Output

Go to:

## Logs → Debug Logs

Example output:

```text id="wh27om"
Customer Added Successfully

Customer ID : 101
Customer Name : Rahul Sharma
Email : rahul@gmail.com
Birth Date : 2000-05-10
Account Type : Savings
Account Balance : 50000
```

---

# SOQL Queries Used

## View All Customers

```sql id="j4v46k"
SELECT Customer_ID__c,
       Customer_Name__c,
       Email__c,
       Birth_Date__c,
       Account_Type__c,
       Account_Balance__c
FROM Customer__c
```

---

## Search Customer

```sql id="7nhkjf"
SELECT Customer_ID__c,
       Customer_Name__c
FROM Customer__c
WHERE Customer_ID__c = :customerId
```

---

# DML Operations Used

| Operation | Purpose         |
| --------- | --------------- |
| insert    | Add customer    |
| update    | Modify balance  |
| delete    | Remove customer |

---

# Project Flow

```text id="olcqmy"
Start
   ↓
Create Customer Object
   ↓
Create Fields
   ↓
Write Apex Class
   ↓
Execute Methods
   ↓
Perform CRUD Operations
   ↓
View Output in Logs
   ↓
End
```

---

# Advantages of Project

* Easy Customer Record Management
* Demonstrates Salesforce CRUD Operations
* Beginner Friendly Project
* Uses Real Salesforce Database
* Simple Console-Based System

---

# Learning Outcomes

After completing this project, you will understand:

* Apex Programming
* Salesforce Objects
* SOQL Queries
* DML Operations
* CRUD Operations in Salesforce
* Salesforce Developer Console

---

# Future Enhancements

* Add Visualforce Frontend
* Add Lightning Web Components (LWC)
* Add Validation Rules
* Add Transaction History
* Add Deposit and Withdraw Features
* Add Email Notifications

---

# Author

## Mokshada Sheth

B.E. Computer Engineering
SCTR's PICT Pune
