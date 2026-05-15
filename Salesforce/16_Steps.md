# Student Record Management System using Salesforce

## Project Title

**Student Record Management System using Apex and Visualforce**

---

# Introduction

This project is developed on the Salesforce platform using:

* **Apex Programming Language**
* **Visualforce Pages**
* **Custom Objects**

The application is used to manage student records efficiently inside Salesforce.

The system stores:

* Student Name
* Roll Number
* Class
* Mobile Number

It allows users to:

* Add new student records
* View all records
* Store records in Salesforce database

---

# About Salesforce

Salesforce is a cloud-based Customer Relationship Management (CRM) platform.

It is widely used for:

* Data Management
* Application Development
* Automation
* Sales Management
* Customer Support
* Cloud Computing Solutions

Salesforce provides:

* No infrastructure setup
* Cloud database
* Security
* Scalability
* Rapid application development

---

# Technologies Used

| Technology    | Purpose                 |
| ------------- | ----------------------- |
| Salesforce    | Platform                |
| Apex          | Backend Programming     |
| Visualforce   | Frontend UI             |
| SOQL          | Database Query Language |
| Custom Object | Data Storage            |

---

# Objectives of the Project

* To learn Salesforce development
* To understand Apex programming
* To create and manage custom objects
* To perform CRUD operations
* To build UI using Visualforce
* To connect frontend with backend logic

---

# Software Requirements

* Salesforce Developer Account
* Internet Browser
* Developer Console

---

# Create Salesforce Developer Account

Signup from:

[Salesforce Developer Signup](https://developer.salesforce.com/signup?utm_source=chatgpt.com)

Login from:

[Salesforce Login](https://login.salesforce.com?utm_source=chatgpt.com)

---

# Project Workflow

```text
Visualforce Page
       ↓
Apex Controller
       ↓
Custom Object (Database)
```

---

# Step 1: Open Salesforce Setup

1. Login to Salesforce
2. Click Gear Icon (⚙️)
3. Click Setup

---

# Step 2: Create Custom Object

## Steps

1. Go to Object Manager
2. Click Create → Custom Object

Fill:

| Property     | Value        |
| ------------ | ------------ |
| Label        | Student      |
| Plural Label | Students     |
| Object Name  | Student      |
| Record Name  | Student Name |

Enable:

* Allow Reports
* Allow Activities

Click Save.

---

# Step 3: Create Custom Fields

---

## A) Roll Number Field

| Property   | Value   |
| ---------- | ------- |
| Field Type | Number  |
| Label      | Roll No |
| Length     | 5       |

API Name:

```text
Roll_No__c
```

---

## B) Class Field

| Property   | Value |
| ---------- | ----- |
| Field Type | Text  |
| Label      | Class |
| Length     | 20    |

API Name:

```text
Class__c
```

---

## C) Mobile Number Field

| Property   | Value     |
| ---------- | --------- |
| Field Type | Phone     |
| Label      | Mobile No |

API Name:

```text
Mobile_No__c
```

---

# Step 4: Create Custom Tab

1. Search Tabs in Setup
2. Open Tabs
3. Create New Custom Object Tab
4. Select Student Object
5. Save

This allows the object to appear in App Launcher.

---

# Step 5: Open Developer Console

1. Click Profile Icon
2. Select Developer Console

Developer Console is used for:

* Writing Apex Code
* Creating Visualforce Pages
* Debugging
* Testing

---

# Step 6: Create Apex Controller

## Apex Class Name

```text
StudentController
```

## Apex Code

```apex
public class StudentController {

    public Student__c stu {get; set;}
    public List<Student__c> studentList {get; set;}

    // Constructor
    public StudentController() {
        stu = new Student__c();
        loadStudents();
    }

    // Save student record
    public void saveStudent() {

        insert stu;

        stu = new Student__c();

        loadStudents();
    }

    // Load all records
    public void loadStudents() {

        studentList = [
            SELECT Id, Name, Roll_No__c,
                   Class__c, Mobile_No__c
            FROM Student__c
            ORDER BY CreatedDate DESC
        ];
    }
}
```

---

# Explanation of Apex Code

## `Student__c`

Represents custom object Student.

---

## `insert stu`

Used to store records into Salesforce database.

---

## `List<Student__c>`

Stores multiple student records.

---

## SOQL Query

```sql
SELECT Id, Name, Roll_No__c,
       Class__c, Mobile_No__c
FROM Student__c
```

Used to fetch student records from database.

---

# Step 7: Create Visualforce Page

## Visualforce Page Name

```text
StudentPage
```

## Visualforce Code

```html
<apex:page controller="StudentController">

    <apex:form>

        <apex:pageBlock title="Student Record Management System">

            <apex:pageBlockSection columns="1">

                <apex:inputText value="{!stu.Name}"
                                label="Student Name"/>

                <apex:inputText value="{!stu.Roll_No__c}"
                                label="Roll No"/>

                <apex:inputText value="{!stu.Class__c}"
                                label="Class"/>

                <apex:inputText value="{!stu.Mobile_No__c}"
                                label="Mobile No"/>

            </apex:pageBlockSection>

            <apex:commandButton value="Save Student"
                                action="{!saveStudent}"
                                rerender="studentTable"/>

        </apex:pageBlock>

        <apex:pageBlock title="Student Records"
                         id="studentTable">

            <apex:pageBlockTable value="{!studentList}"
                                 var="s">

                <apex:column value="{!s.Name}"
                             headerValue="Student Name"/>

                <apex:column value="{!s.Roll_No__c}"
                             headerValue="Roll No"/>

                <apex:column value="{!s.Class__c}"
                             headerValue="Class"/>

                <apex:column value="{!s.Mobile_No__c}"
                             headerValue="Mobile No"/>

            </apex:pageBlockTable>

        </apex:pageBlock>

    </apex:form>

</apex:page>
```

---

# Explanation of Visualforce Components

| Component               | Purpose                   |
| ----------------------- | ------------------------- |
| `<apex:page>`           | Creates Visualforce page  |
| `<apex:form>`           | Creates form              |
| `<apex:inputText>`      | Input field               |
| `<apex:commandButton>`  | Button                    |
| `<apex:pageBlockTable>` | Displays records in table |

---

# Step 8: Run the Application

1. Save all files
2. Click Preview
3. Application opens in browser

---

# Features of the Application

✅ Add Student Records
✅ Display Student Records
✅ Salesforce Database Storage
✅ Apex Backend Logic
✅ Visualforce Frontend UI
✅ Dynamic Data Fetching

---

# Sample Test Data

| Student Name | Roll No | Class | Mobile No  |
| ------------ | ------- | ----- | ---------- |
| Rahul Patil  | 101     | TE-A  | 9876543210 |
| Sneha Joshi  | 102     | TE-B  | 9123456780 |

---

# Advantages of Salesforce

* Cloud Based
* Highly Secure
* Scalable
* Fast Development
* Easy Integration
* Automatic Backup
* Accessible Anywhere

---

# Advantages of This Project

* Simple CRUD Application
* Beginner Friendly
* Real-Time Data Storage
* Good Understanding of Salesforce Architecture
* Demonstrates Frontend + Backend Integration

---

# Limitations

* No Edit/Delete functionality
* No Validation Rules
* Basic UI only

---

# Future Enhancements

* Add Update Feature
* Add Delete Feature
* Add Search Functionality
* Add Validation Rules
* Convert to Lightning Components
* Add Authentication

---

# Important Salesforce Terms

| Term            | Meaning                                                 |
| --------------- | ------------------------------------------------------- |
| CRM             | Customer Relationship Management                        |
| Apex            | Backend language of Salesforce                          |
| Visualforce     | UI framework                                            |
| SOQL            | Salesforce Query Language                               |
| Custom Object   | User-created database table                             |
| Governor Limits | Limits enforced by Salesforce for resource optimization |

---

# Viva Questions and Answers

## 1. What is Salesforce?

Salesforce is a cloud-based CRM platform used to develop business applications.

---

## 2. What is Apex?

Apex is an object-oriented programming language used for backend development in Salesforce.

---

## 3. What is Visualforce?

Visualforce is a framework used to design custom user interfaces in Salesforce.

---

## 4. What is SOQL?

SOQL stands for Salesforce Object Query Language used to fetch records from Salesforce database.

---

## 5. Difference between SOQL and SQL?

| SOQL                | SQL                           |
| ------------------- | ----------------------------- |
| Used in Salesforce  | Used in traditional databases |
| Retrieves data only | Retrieves and modifies data   |
| Object based        | Table based                   |

---

## 6. What is a Custom Object?

A custom object is a user-defined database table in Salesforce.

---

## 7. Why do custom objects use `__c`?

Salesforce automatically appends `__c` to custom objects and fields.

Example:

```text
Student__c
Roll_No__c
```

---

## 8. What is a Controller?

Controller contains backend business logic for the application.

---

## 9. What is a Visualforce Page?

A Visualforce page is the frontend UI page connected to Apex controller.

---

## 10. What is Governor Limit?

Governor Limits are runtime limits imposed by Salesforce to ensure efficient use of shared resources.

Example:

* SOQL Query Limits
* CPU Time Limits
* Heap Size Limits

---

## 11. What is Cloud Computing?

Cloud computing means storing and accessing data over the internet instead of local computers.

---

## 12. Why Salesforce is called SaaS?

Salesforce is Software as a Service because users access it through internet without installing software locally.

---

# Conclusion

The Student Record Management System successfully demonstrates:

* Salesforce custom object creation
* Apex programming
* Visualforce page development
* Database operations using SOQL
* Integration of frontend and backend

This project provides a strong foundation for learning Salesforce application development.
