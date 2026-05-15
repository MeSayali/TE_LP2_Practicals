# README

# Email Notification System with File Upload using Apex and Visualforce in Salesforce

---

# Project Title

**Email Notification System using Apex, Visualforce, and Salesforce Email Services**

---

# Project Description

This project is developed using Salesforce technologies to send email notifications through a Visualforce frontend.

The application allows users to:

* Enter recipient email address
* Enter subject
* Enter message body
* Upload attachment from Visualforce page
* Send email using Apex Messaging class
* Validate email address
* Display appropriate error messages

The system uses:

* Apex Programming
* Visualforce Pages
* Salesforce Messaging Services
* File Upload Functionality

---

# Objectives

* Learn Salesforce email services
* Understand Apex programming
* Create frontend using Visualforce
* Upload files using Visualforce
* Send emails with attachments
* Validate email addresses
* Handle exceptions and errors

---

# About Salesforce

Salesforce is a cloud-based CRM platform used for:

* Application Development
* Business Automation
* Data Management
* Cloud Computing
* Customer Relationship Management

Salesforce provides:

* Apex Language
* Visualforce Framework
* Lightning Components
* SOQL
* Email Services

---

# Technologies Used

| Technology        | Purpose                 |
| ----------------- | ----------------------- |
| Salesforce        | Platform                |
| Apex              | Backend Programming     |
| Visualforce       | Frontend UI             |
| Messaging Class   | Email Sending           |
| Blob              | File Storage            |
| Developer Console | Development Environment |

---

# Software Requirements

* Salesforce Developer Account
* Internet Browser
* Developer Console

---

# Salesforce Login

Login using:

[Salesforce Login](https://login.salesforce.com?utm_source=chatgpt.com)

Create Developer Account:

[Salesforce Developer Signup](https://developer.salesforce.com/signup?utm_source=chatgpt.com)

---

# Features of the Project

✅ Send Email Notifications
✅ Upload Attachments from UI
✅ Email Validation
✅ Error Handling
✅ Frontend using Visualforce
✅ Uses Salesforce Messaging Class
✅ User Friendly Interface

---

# Project Workflow

```text id="mh5n7h"
Visualforce Page
       ↓
File Upload using inputFile
       ↓
Apex Controller
       ↓
Messaging.EmailFileAttachment
       ↓
Salesforce Email Service
       ↓
Recipient Inbox
```

---

# Step 1: Open Developer Console

1. Login to Salesforce
2. Click Profile Icon
3. Select:

   ```text
   Developer Console
   ```

Developer Console is used for:

* Writing Apex Code
* Creating Visualforce Pages
* Running Programs
* Debugging

---

# Step 2: Create Apex Controller

## Apex Class Name

```text id="7m7j9v"
EmailController
```

---

# Apex Controller Code

```apex id="a67ycv"
public class EmailController {

    // Form Fields
    public String toAddress {get; set;}
    public String subject {get; set;}
    public String body {get; set;}

    // File Upload Variables
    public Blob uploadedFileBody {get; set;}
    public String uploadedFileName {get; set;}

    // Send Email Method
    public PageReference sendEmail() {

        // Email Validation Regex
        String emailRegex =
            '^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$';

        // Validate Email
        if(toAddress == null ||
           !Pattern.matches(emailRegex, toAddress)) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Invalid Email Address'
                )
            );

            return null;
        }

        try {

            // Create Email Object
            Messaging.SingleEmailMessage mail =
                new Messaging.SingleEmailMessage();

            // Recipient Email
            mail.setToAddresses(
                new String[] {toAddress}
            );

            // Subject
            mail.setSubject(subject);

            // Email Body
            mail.setPlainTextBody(body);

            // Add Attachment if Uploaded
            if(uploadedFileBody != null) {

                Messaging.EmailFileAttachment attachment =
                    new Messaging.EmailFileAttachment();

                attachment.setFileName(uploadedFileName);

                attachment.setBody(uploadedFileBody);

                mail.setFileAttachments(
                    new Messaging.EmailFileAttachment[] {
                        attachment
                    }
                );
            }

            // Send Email
            Messaging.sendEmail(
                new Messaging.SingleEmailMessage[] {
                    mail
                }
            );

            // Success Message
            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.CONFIRM,
                    'Email Sent Successfully'
                )
            );

        }
        catch(Exception e) {

            // Error Message
            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    e.getMessage()
                )
            );
        }

        return null;
    }
}
```

---

# Explanation of Apex Code

| Statement             | Purpose              |
| --------------------- | -------------------- |
| `SingleEmailMessage`  | Creates email object |
| `setToAddresses()`    | Sets recipient email |
| `setSubject()`        | Sets email subject   |
| `setPlainTextBody()`  | Sets message body    |
| `EmailFileAttachment` | Creates attachment   |
| `Blob`                | Stores file data     |
| `Pattern.matches()`   | Validates email      |
| `sendEmail()`         | Sends email          |

---

# Step 3: Create Visualforce Page

## Visualforce Page Name

```text id="u0x7qz"
EmailPage
```

---

# Visualforce Page Code

```html id="5qnzpk"
<apex:page controller="EmailController">

    <!-- Important for File Upload -->
    <apex:form enctype="multipart/form-data">

        <apex:pageBlock
            title="Email Notification System">

            <!-- Display Messages -->
            <apex:pageMessages />

            <apex:pageBlockSection columns="1">

                <!-- Recipient Email -->
                <apex:inputText
                    value="{!toAddress}"
                    label="Recipient Email"/>

                <!-- Subject -->
                <apex:inputText
                    value="{!subject}"
                    label="Subject"/>

                <!-- Message Body -->
                <apex:inputTextarea
                    value="{!body}"
                    label="Message Body"
                    rows="5"/>

                <!-- File Upload -->
                <apex:inputFile
                    value="{!uploadedFileBody}"
                    filename="{!uploadedFileName}"/>

            </apex:pageBlockSection>

            <!-- Send Button -->
            <apex:commandButton
                value="Send Email"
                action="{!sendEmail}"/>

        </apex:pageBlock>

    </apex:form>

</apex:page>
```

---

# Important Point

This line is mandatory for file upload:

```html id="4lby4q"
<apex:form enctype="multipart/form-data">
```

Without this:
❌ File upload will not work.

---

# Explanation of Visualforce Components

| Component              | Purpose                  |
| ---------------------- | ------------------------ |
| `<apex:page>`          | Creates Visualforce page |
| `<apex:form>`          | Creates form             |
| `<apex:inputText>`     | Text input               |
| `<apex:inputTextarea>` | Multi-line textbox       |
| `<apex:inputFile>`     | File upload              |
| `<apex:commandButton>` | Button                   |
| `<apex:pageMessages>`  | Displays messages        |

---

# Step 4: Save and Run

1. Save Apex Class
2. Save Visualforce Page
3. Click:

   ```text
   Preview
   ```

---

# Testing the Application

---

## Valid Input Example

| Field      | Value                                   |
| ---------- | --------------------------------------- |
| Email      | [test@gmail.com](mailto:test@gmail.com) |
| Subject    | Apex Mail                               |
| Message    | Hello from Salesforce                   |
| Attachment | sample.pdf                              |

Output:

```text id="wlh4ec"
Email Sent Successfully
```

---

## Invalid Email Example

| Field | Value  |
| ----- | ------ |
| Email | abc123 |

Output:

```text id="vpc4y9"
Invalid Email Address
```

---

# Output

The application:

* Sends email successfully
* Uploads attachment dynamically
* Displays confirmation message
* Shows error for invalid email ID

---

# Advantages of the Project

* Real File Upload Support
* User Friendly Interface
* Email Validation
* Exception Handling
* Dynamic Attachments
* Cloud-Based Email Service

---

# Applications

* Student Notifications
* Attendance Alerts
* OTP Systems
* Password Reset Emails
* CRM Notifications
* Automated Alerts

---

# Limitations

* Daily email limits in Salesforce
* Limited attachment size
* Internet connection required

---

# Future Enhancements

* Multiple Attachments
* HTML Email Templates
* CC and BCC Support
* Database Integration
* Scheduled Emails
* Lightning Components

---

# Important Salesforce Terms

| Term            | Meaning                        |
| --------------- | ------------------------------ |
| Apex            | Backend language of Salesforce |
| Visualforce     | UI framework                   |
| Blob            | Binary file data               |
| Messaging Class | Email service class            |
| SaaS            | Software as a Service          |

---

# Viva Questions and Answers

## 1. What is Salesforce?

Salesforce is a cloud-based CRM platform used for application development and automation.

---

## 2. What is Apex?

Apex is an object-oriented programming language used for backend development in Salesforce.

---

## 3. What is Visualforce?

Visualforce is a framework used to create custom user interfaces in Salesforce.

---

## 4. What is Messaging Class?

Messaging class is a built-in Apex class used for sending emails.

---

## 5. What is `<apex:inputFile>`?

`<apex:inputFile>` is used to upload files from Visualforce pages.

---

## 6. Why use `multipart/form-data`?

It is required to transfer file data from frontend to backend.

---

## 7. What is Blob in Salesforce?

Blob is a binary data type used to store files and attachments.

---

## 8. What is EmailFileAttachment?

It is a Salesforce class used to attach files in emails.

---

## 9. What is Email Validation?

Email validation checks whether entered email follows proper format.

---

## 10. What is Cloud Computing?

Cloud computing means accessing services through internet instead of local systems.

---

## 11. Why Salesforce is called SaaS?

Salesforce is Software as a Service because users access applications through browsers without local installation.

---

# Conclusion

This project successfully demonstrates:

* Apex Programming
* Visualforce Frontend Development
* Salesforce Email Services
* File Upload Functionality
* Email Validation
* Exception Handling

The Email Notification System provides practical understanding of cloud-based email automation using Salesforce technologies.
