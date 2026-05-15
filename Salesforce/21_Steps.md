# README

# Email Notification System using Apex in Salesforce

---

# Project Title

**Console Based Apex Program for Sending Email Notifications using Salesforce**

---

# Project Description

This project demonstrates how to send email notifications using the Apex programming language in Salesforce.

The application uses Salesforce built-in email services and the `Messaging` class to send emails programmatically.

The project supports:

* Sending email without attachment
* Sending email with attachment
* Custom subject and message body
* Multiple recipient support

---

# Objectives

* Learn Apex programming
* Understand Salesforce email services
* Send automated emails using Apex
* Work with attachments in Salesforce
* Execute Apex code using Developer Console

---

# About Salesforce

Salesforce is a cloud-based CRM platform used for:

* Application Development
* Automation
* Customer Relationship Management
* Cloud Computing Services

Salesforce provides:

* Apex Programming Language
* Visualforce
* Lightning Components
* Database Management
* Email Services

---

# Technologies Used

| Technology        | Purpose             |
| ----------------- | ------------------- |
| Salesforce        | Platform            |
| Apex              | Backend Programming |
| Messaging Class   | Email Service       |
| Developer Console | Running Apex Code   |

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
✅ Send Email with Attachments
✅ Console-Based Execution
✅ Uses Built-in Messaging Class
✅ Supports Multiple Recipients
✅ Cloud-Based Email Service

---

# Project Workflow

```text
Apex Program
      ↓
Messaging Class
      ↓
Salesforce Email Service
      ↓
Recipient Email Inbox
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
* Running Apex Programs
* Debugging
* Testing

---

# Step 2: Open Execute Anonymous Window

In Developer Console:

```text
Debug → Open Execute Anonymous Window
```

Shortcut:

```text
Ctrl + E
```

The Execute Anonymous Window allows instant execution of Apex code without creating a class.

---

# Program 1: Send Email Without Attachment

## Apex Code

```apex
Messaging.SingleEmailMessage mail =
    new Messaging.SingleEmailMessage();

// Recipient Email
mail.setToAddresses(
    new String[] {'receiver@gmail.com'}
);

// Subject
mail.setSubject(
    'Student Notification'
);

// Email Body
mail.setPlainTextBody(
    'Hello,\n\nThis email is sent using Apex in Salesforce.'
);

// Send Email
Messaging.sendEmail(
    new Messaging.SingleEmailMessage[] { mail }
);

System.debug('Email Sent Successfully');
```

---

# Explanation of Code

| Statement            | Purpose              |
| -------------------- | -------------------- |
| `SingleEmailMessage` | Creates email object |
| `setToAddresses()`   | Sets recipient email |
| `setSubject()`       | Sets email subject   |
| `setPlainTextBody()` | Sets email content   |
| `sendEmail()`        | Sends email          |

---

# Program 2: Send Email With Attachment

## Apex Code

```apex
Messaging.SingleEmailMessage mail =
    new Messaging.SingleEmailMessage();

// Recipient
mail.setToAddresses(
    new String[] {'receiver@gmail.com'}
);

// Subject
mail.setSubject(
    'Salesforce Attachment Email'
);

// Body
mail.setPlainTextBody(
    'Hello,\n\nPlease find the attachment below.'
);

// Create Attachment
Messaging.EmailFileAttachment attachment =
    new Messaging.EmailFileAttachment();

attachment.setFileName('SampleFile.txt');

attachment.setBody(
    Blob.valueOf(
        'This is sample attachment content.'
    )
);

attachment.setContentType('text/plain');

// Add Attachment
mail.setFileAttachments(
    new Messaging.EmailFileAttachment[] { attachment }
);

// Send Email
Messaging.sendEmail(
    new Messaging.SingleEmailMessage[] { mail }
);

System.debug(
    'Email with Attachment Sent Successfully'
);
```

---

# Explanation of Attachment Code

| Statement             | Purpose                 |
| --------------------- | ----------------------- |
| `EmailFileAttachment` | Creates attachment      |
| `setFileName()`       | Sets attachment name    |
| `setBody()`           | Sets attachment data    |
| `Blob.valueOf()`      | Converts text to binary |
| `setContentType()`    | Defines file type       |

---

# How to Run the Program

1. Open Execute Anonymous Window
2. Paste Apex code
3. Click:

   ```text
   Execute
   ```

If successful:

```text
Email Sent Successfully
```

appears in logs.

---

# Output

The recipient receives:

* Email notification
* Subject line
* Message body
* Attachment (if added)

---

# Important Apex Email Methods

| Method               | Purpose         |
| -------------------- | --------------- |
| `setToAddresses()`   | Recipient email |
| `setCcAddresses()`   | CC recipients   |
| `setBccAddresses()`  | BCC recipients  |
| `setSubject()`       | Email subject   |
| `setPlainTextBody()` | Text email      |
| `setHtmlBody()`      | HTML email      |
| `sendEmail()`        | Sends email     |

---

# Advantages of the Project

* Simple and Beginner Friendly
* Demonstrates Apex Email Services
* Supports File Attachments
* Real-Time Notifications
* Easy to Execute

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

* Salesforce has daily email limits
* Attachment size restrictions
* Requires internet connectivity

---

# Future Enhancements

* Bulk Email Sending
* Dynamic Email Templates
* Database Integration
* Scheduled Email Service
* HTML Email Design

---

# Important Salesforce Terms

| Term              | Meaning                        |
| ----------------- | ------------------------------ |
| Apex              | Backend language of Salesforce |
| Messaging Class   | Used for email services        |
| Blob              | Binary large object            |
| Execute Anonymous | Runs Apex instantly            |
| SaaS              | Software as a Service          |

---

# Viva Questions and Answers

## 1. What is Salesforce?

Salesforce is a cloud-based CRM platform used for application development and automation.

---

## 2. What is Apex?

Apex is an object-oriented programming language used in Salesforce backend development.

---

## 3. What is Messaging Class?

Messaging class is a built-in Apex class used to send emails from Salesforce.

---

## 4. What is SingleEmailMessage?

`SingleEmailMessage` is used to send email to one or multiple recipients.

---

## 5. What is Blob?

Blob is a binary data type used to store files and attachments.

---

## 6. What is Execute Anonymous Window?

It is used to execute Apex code directly without creating a class.

---

## 7. Difference Between Plain Text and HTML Email?

| Plain Text  | HTML Email             |
| ----------- | ---------------------- |
| Simple text | Formatted email        |
| No styling  | Supports colors/images |
| Lightweight | Rich UI                |

---

## 8. Why Salesforce is called SaaS?

Salesforce is Software as a Service because applications are accessed through internet browsers.

---

## 9. What is Cloud Computing?

Cloud computing means accessing computing resources through internet instead of local systems.

---

# Conclusion

This project successfully demonstrates sending email notifications using Apex in Salesforce.

The project provides practical understanding of:

* Apex Programming
* Salesforce Email Services
* Messaging Class
* Email Attachments
* Cloud-Based Automation

It is a beginner-friendly project for learning Salesforce email functionality.
