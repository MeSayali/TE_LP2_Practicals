# Employee Management System using Lightning App in Salesforce

# Aim

To develop an Employee Management System that allows users to add employee records with validations.

---

# Requirements

The system validates:

* Employee Name cannot be empty and must contain at least 3 characters.
* Employee ID must be greater than 0 and unique.
* Salary must be greater than 10,000 and less than 500,000.
* Email must follow valid email format.
* Department must be selected from available list.
* Joining Date cannot be future date.

---

# STEP 1: Create Employee Object

## Open Setup

1. Login to Salesforce
2. Click Gear Icon (⚙️)
3. Click Setup

---

## Create Custom Object

1. Search:

```text id="g4m8qp"
Object Manager
```

2. Click:

```text id="w2k7zr"
Create → Custom Object
```

3. Fill details:

| Property     | Value         |
| ------------ | ------------- |
| Label        | Employee      |
| Plural Label | Employees     |
| Object Name  | Employee      |
| Record Name  | Employee Name |

4. Click:

```text id="t6n3xc"
Save
```

---

# STEP 2: Create Fields

Go to:

```text id="f1q7wp"
Employee → Fields & Relationships → New
```

Create the following fields.

---

## 1. Employee ID

| Property       | Value          |
| -------------- | -------------- |
| Field Type     | Number         |
| Field Label    | Employee ID    |
| API Name       | Employee_ID__c |
| Length         | 10             |
| Decimal Places | 0              |

Check:

```text id="p9m2yl"
Unique
```

Save.

---

## 2. Employee Name

| Property   | Value            |
| ---------- | ---------------- |
| Field Type | Text             |
| Label      | Employee Name    |
| API Name   | Employee_Name__c |
| Length     | 100              |

Save.

---

## 3. Salary

| Property   | Value     |
| ---------- | --------- |
| Field Type | Currency  |
| Label      | Salary    |
| API Name   | Salary__c |

Save.

---

## 4. Email

| Property   | Value    |
| ---------- | -------- |
| Field Type | Email    |
| Label      | Email    |
| API Name   | Email__c |

Save.

---

## 5. Department

| Property   | Value         |
| ---------- | ------------- |
| Field Type | Picklist      |
| Label      | Department    |
| API Name   | Department__c |

Values:

```text id="n5r7km"
IT
HR
Finance
Marketing
Sales
```

Save.

---

## 6. Joining Date

| Property   | Value           |
| ---------- | --------------- |
| Field Type | Date            |
| Label      | Joining Date    |
| API Name   | Joining_Date__c |

Save.

---

# STEP 3: Create Validation Rules

Go to:

```text id="y7m4wp"
Employee → Validation Rules → New
```

---

# Validation Rule 1: Employee Name

## Rule Name

```text id="r5k9zr"
EmployeeNameValidation
```

## Formula

```text id="v3q8mx"
OR(
    ISBLANK(Employee_Name__c),
    LEN(TRIM(Employee_Name__c)) < 3
)
```

## Error Message

```text id="u6t2yl"
Employee Name must contain at least 3 characters.
```

Save.

---

# Validation Rule 2: Salary Validation

## Rule Name

```text id="k4w7kp"
SalaryValidation
```

## Formula

```text id="j8m2vc"
OR(
    Salary__c <= 10000,
    Salary__c >= 500000
)
```

## Error Message

```text id="f2q1wp"
Salary must be between 10,001 and 499,999.
```

Save.

---

# Validation Rule 3: Joining Date

## Rule Name

```text id="n5s9xr"
JoiningDateValidation
```

## Formula

```text id="p7w3yl"
Joining_Date__c > TODAY()
```

## Error Message

```text id="x4m8qp"
Joining Date cannot be a future date.
```

Save.

---

# Validation Rule 4: Email Validation

## Rule Name

```text id="b8r2wp"
EmailValidation
```

## Formula

```text id="g3k7mx"
NOT(
    REGEX(
        Email__c,
        "^[A-Za-z0-9+._-]+@[A-Za-z0-9-]+\\.[A-Za-z]{2,}$"
    )
)
```

## Error Message

```text id="v9n4yl"
Please enter a valid email address.
```

Save.

---

# STEP 4: Create Employee Tab

1. Go to:

```text id="t1r6wc"
Setup → Tabs
```

2. Under Custom Object Tabs click:

```text id="q7k4xp"
New
```

3. Select Object:

```text id="d3n8vl"
Employee
```

4. Choose Tab Style
5. Click:

```text id="m7w2yr"
Next → Next → Save
```

---

# STEP 5: Create Lightning App

Go to:

```text id="z5q1xt"
Setup → App Manager
```

Click:

```text id="x8w4kp"
New Lightning App
```

---

## Fill Details

| Property | Value                   |
| -------- | ----------------------- |
| App Name | Employee Management App |

Click:

```text id="h4m7zc"
Next
```

---

## Utility Items

Skip and click:

```text id="k9r3vl"
Next
```

---

## Navigation Items

Add:

```text id="c6t3wp"
Employee
```

Move it to selected items.

Click:

```text id="j2n8ky"
Next → Save & Finish
```

---

# STEP 6: Open the Application

1. Click the:

```text id="u5k1zr"
App Launcher (9 Dots)
```

2. Search:

```text id="r8m4wp"
Employee Management App
```

3. Open the app.

---

# STEP 7: Add Employee Records

1. Open:

```text id="q3t7yl"
Employee Tab
```

2. Click:

```text id="n6k2xp"
New
```

3. Enter employee details.

4. Click:

```text id="w1m9vc"
Save
```

---

# Output

The system:

* stores employee records,
* validates user input,
* prevents invalid data,
* displays validation error messages automatically.

---

# Conclusion

Successfully developed an Employee Management System in Salesforce using:

* Custom Object
* Fields & Relationships
* Validation Rules
* Custom Tab
* Lightning App Manager.
