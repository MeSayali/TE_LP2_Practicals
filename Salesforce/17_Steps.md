# README.md

# Employee Management System using Salesforce Apex

## Project Overview

The Employee Management System is a console-based Salesforce application developed using Apex programming language.
This project performs CRUD (Create, Read, Update, Delete) operations on employee records stored in Salesforce.

The system manages employee details such as:

* Employee ID
* Employee Name
* Email
* Birth Date
* Department

The project uses:

* Salesforce Custom Object
* Apex Class
* SOQL Queries
* DML Operations
* Developer Console

---

# Features

* Add Employee
* View All Employees
* Search Employee
* Update Employee Department
* Delete Employee
* Console-Based Execution
* Error Handling using Conditions

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
4. Search for:

* Developer Console

5. Open Developer Console

---

# Step 2: Create Custom Object

Go to:

## Setup → Object Manager → Create → Custom Object

Fill the details:

| Property     | Value         |
| ------------ | ------------- |
| Label        | Employee      |
| Plural Label | Employees     |
| Object Name  | Employee      |
| Record Name  | Employee Name |
| Data Type    | Text          |

Click:

* Save

---

# Step 3: Create Custom Fields

Inside Employee Object, create the following fields.

---

## Field 1: Employee ID

| Property    | Value       |
| ----------- | ----------- |
| Field Label | Employee ID |
| API Name    | Emp_ID__c   |
| Data Type   | Number      |

---

## Field 2: Employee Name

| Property    | Value         |
| ----------- | ------------- |
| Field Label | Employee Name |
| API Name    | Emp_Name__c   |
| Data Type   | Text          |

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

## Field 5: Department

| Property    | Value         |
| ----------- | ------------- |
| Field Label | Department    |
| API Name    | Department__c |
| Data Type   | Text          |

---

# Step 4: Create Apex Class

Go to:

## Developer Console → File → New → Apex Class

Class Name:

```text
EmployeeManagementSystem
```

Click:

* OK

Replace generated code with the following code.

---

# Apex Class Code

```apex
public class EmployeeManagementSystem {

    // Add Employee
    public static void addEmployee(Integer empId,
                                   String empName,
                                   String email,
                                   Date birthDate,
                                   String department) {

        Employee__c emp = new Employee__c();

        emp.Emp_ID__c = empId;
        emp.Emp_Name__c = empName;
        emp.Email__c = email;
        emp.Birth_Date__c = birthDate;
        emp.Department__c = department;

        insert emp;

        System.debug('Employee Added Successfully');
    }

    // View Employees
    public static void viewEmployees() {

        List<Employee__c> empList = [
            SELECT Emp_ID__c,
                   Emp_Name__c,
                   Email__c,
                   Birth_Date__c,
                   Department__c
            FROM Employee__c
        ];

        for(Employee__c emp : empList) {

            System.debug('----------------------------');
            System.debug('Employee ID : ' + emp.Emp_ID__c);
            System.debug('Employee Name : ' + emp.Emp_Name__c);
            System.debug('Email : ' + emp.Email__c);
            System.debug('Birth Date : ' + emp.Birth_Date__c);
            System.debug('Department : ' + emp.Department__c);
        }
    }

    // Search Employee
    public static void searchEmployee(Integer empId) {

        List<Employee__c> empList = [
            SELECT Emp_ID__c,
                   Emp_Name__c,
                   Email__c,
                   Birth_Date__c,
                   Department__c
            FROM Employee__c
            WHERE Emp_ID__c = :empId
        ];

        if(empList.size() > 0) {

            Employee__c emp = empList[0];

            System.debug('Employee Found');
            System.debug('Employee Name : ' + emp.Emp_Name__c);
            System.debug('Department : ' + emp.Department__c);

        } else {

            System.debug('Employee Not Found');
        }
    }

    // Update Employee Department
    public static void updateEmployee(Integer empId,
                                      String newDepartment) {

        List<Employee__c> empList = [
            SELECT Id,
                   Department__c
            FROM Employee__c
            WHERE Emp_ID__c = :empId
        ];

        if(empList.size() > 0) {

            Employee__c emp = empList[0];

            emp.Department__c = newDepartment;

            update emp;

            System.debug('Employee Updated Successfully');

        } else {

            System.debug('Employee Not Found');
        }
    }

    // Delete Employee
    public static void deleteEmployee(Integer empId) {

        List<Employee__c> empList = [
            SELECT Id
            FROM Employee__c
            WHERE Emp_ID__c = :empId
        ];

        if(empList.size() > 0) {

            delete empList[0];

            System.debug('Employee Deleted Successfully');

        } else {

            System.debug('Employee Not Found');
        }
    }
}
```

---

# Step 5: Save Apex Class

Click:

## File → Save

OR

Press:

```text
Ctrl + S
```

---

# Step 6: Execute Program

Go to:

## Debug → Open Execute Anonymous Window

Shortcut:

```text
Ctrl + E
```

---

# Add Employee

```apex
EmployeeManagementSystem.addEmployee(
    101,
    'Rahul Sharma',
    'rahul@gmail.com',
    Date.newInstance(2001, 5, 10),
    'HR'
);
```

Click:

* Execute

---

# View Employees

```apex
EmployeeManagementSystem.viewEmployees();
```

---

# Search Employee

```apex
EmployeeManagementSystem.searchEmployee(101);
```

---

# Update Employee

```apex
EmployeeManagementSystem.updateEmployee(
    101,
    'IT'
);
```

---

# Delete Employee

```apex
EmployeeManagementSystem.deleteEmployee(101);
```

---

# Step 7: Check Output

Go to:

## Logs → Debug Logs

You will see outputs like:

```text
Employee Added Successfully

Employee ID : 101
Employee Name : Rahul Sharma
Email : rahul@gmail.com
Birth Date : 2001-05-10
Department : HR
```

---

# SOQL Queries Used

## Select All Employees

```sql
SELECT Emp_ID__c,
       Emp_Name__c,
       Email__c,
       Birth_Date__c,
       Department__c
FROM Employee__c
```

---

## Search Employee by ID

```sql
SELECT Emp_ID__c,
       Emp_Name__c
FROM Employee__c
WHERE Emp_ID__c = :empId
```

---

# DML Operations Used

| Operation | Purpose         |
| --------- | --------------- |
| insert    | Add employee    |
| update    | Modify employee |
| delete    | Remove employee |

---

# Project Flow

```text
Start
   ↓
Create Employee Object
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

* Easy Employee Record Management
* Demonstrates Salesforce CRUD Operations
* Simple Console-Based Implementation
* Beginner Friendly Apex Project
* Uses Real Salesforce Database

---

# Learning Outcomes

After completing this project, you will understand:

* Apex Programming
* SOQL Queries
* Salesforce Objects
* DML Operations
* Salesforce Developer Console
* CRUD Operations in Salesforce

---

# Future Enhancements

* Add Visualforce Frontend
* Add Lightning Web Components (LWC)
* Add Validation Rules
* Add Email Notifications
* Add Department Filtering
* Add Pagination

---

# Author

## Mokshada Sheth

B.E. Computer Engineering
SCTR's PICT Pune
