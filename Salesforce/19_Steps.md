# README.md

# Product Inventory Management System using Salesforce Apex and Visualforce

## Project Overview

The Product Inventory Management System is a Salesforce application developed using:

* Apex Programming Language
* Visualforce Pages
* Salesforce Custom Objects

This application helps manage product inventory records stored in Salesforce database.

The system allows users to:

* Add Product Records
* View Product Inventory
* Delete Product Records
* Validate Product Details

The project stores the following product details:

* Product Name
* Serial Number
* Manufacture Date
* Expiry Date

---

# Features

* Add Product
* View Product Inventory
* Delete Product
* Visualforce Based UI
* Salesforce Database Integration
* Input Validations
* Success/Error Messages on UI

---

# Validations Implemented

The system validates:

* Product Name cannot be empty
* Serial Number cannot be empty
* Duplicate Serial Numbers are not allowed
* Manufacture Date cannot be future date
* Expiry Date must be greater than today
* Expiry Date cannot be before Manufacture Date

---

# Technologies Used

* Salesforce CRM
* Apex Programming
* Visualforce Pages
* SOQL
* DML Operations

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

```text id="v5m6i1"
Developer Console
```

5. Open Developer Console

---

# Step 2: Create Custom Object

Go to:

## Setup → Object Manager → Create → Custom Object

Fill the details:

| Property     | Value               |
| ------------ | ------------------- |
| Label        | Product Inventory   |
| Plural Label | Product Inventories |
| Object Name  | Product_Inventory   |
| Record Name  | Product Name        |
| Data Type    | Text                |

Click:

```text id="olp0a5"
Save
```

---

# Step 3: Create Custom Fields

Inside Product Inventory Object, create the following fields.

---

## Field 1: Product Name

| Property    | Value           |
| ----------- | --------------- |
| Field Label | Product Name    |
| API Name    | Product_Name__c |
| Data Type   | Text            |

---

## Field 2: Serial Number

| Property    | Value         |
| ----------- | ------------- |
| Field Label | Serial Number |
| API Name    | Serial_No__c  |
| Data Type   | Text          |

---

## Field 3: Manufacture Date

| Property    | Value               |
| ----------- | ------------------- |
| Field Label | Manufacture Date    |
| API Name    | Manufacture_Date__c |
| Data Type   | Date                |

---

## Field 4: Expiry Date

| Property    | Value          |
| ----------- | -------------- |
| Field Label | Expiry Date    |
| API Name    | Expiry_Date__c |
| Data Type   | Date           |

---

# Step 4: Create Apex Controller

Go to:

## Developer Console → File → New → Apex Class

Class Name:

```text id="dov4bw"
ProductInventoryController
```

Click:

```text id="w2p4h5"
OK
```

Replace generated code with the following code.

---

# Apex Controller Code

```apex id="txc4xk"
public class ProductInventoryController {

    public Product_Inventory__c productRec { get; set; }

    public List<Product_Inventory__c> productList { get; set; }

    public ProductInventoryController() {

        productRec = new Product_Inventory__c();

        loadProducts();
    }

    // Add Product with Validations
    public void addProduct() {

        // Product Name Validation
        if(String.isBlank(productRec.Product_Name__c)) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Product Name cannot be empty.'
                )
            );

            return;
        }

        // Serial Number Validation
        if(String.isBlank(productRec.Serial_No__c)) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Serial Number cannot be empty.'
                )
            );

            return;
        }

        // Manufacture Date Validation
        if(productRec.Manufacture_Date__c > Date.today()) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Manufacture Date cannot be a future date.'
                )
            );

            return;
        }

        // Expiry Date Validation
        if(productRec.Expiry_Date__c <= Date.today()) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Expiry Date must be greater than today.'
                )
            );

            return;
        }

        // Expiry Date before Manufacture Date
        if(productRec.Expiry_Date__c <
           productRec.Manufacture_Date__c) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Expiry Date cannot be before Manufacture Date.'
                )
            );

            return;
        }

        // Duplicate Serial Number Validation
        List<Product_Inventory__c> existingProducts = [

            SELECT Id
            FROM Product_Inventory__c
            WHERE Serial_No__c = :productRec.Serial_No__c
        ];

        if(existingProducts.size() > 0) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Serial Number already exists. Enter unique Serial Number.'
                )
            );

            return;
        }

        // Insert Product
        insert productRec;

        ApexPages.addMessage(
            new ApexPages.Message(
                ApexPages.Severity.CONFIRM,
                'Product Added Successfully.'
            )
        );

        // Reset Form
        productRec = new Product_Inventory__c();

        // Reload Products
        loadProducts();
    }

    // Load Products
    public void loadProducts() {

        productList = [

            SELECT Id,
                   Product_Name__c,
                   Serial_No__c,
                   Manufacture_Date__c,
                   Expiry_Date__c
            FROM Product_Inventory__c
            ORDER BY CreatedDate DESC
        ];
    }

    // Delete Product
    public void deleteProduct() {

        String productId =
            ApexPages.currentPage().getParameters().get('pid');

        Product_Inventory__c prod = [

            SELECT Id
            FROM Product_Inventory__c
            WHERE Id = :productId
            LIMIT 1
        ];

        delete prod;

        ApexPages.addMessage(
            new ApexPages.Message(
                ApexPages.Severity.CONFIRM,
                'Product Deleted Successfully.'
            )
        );

        loadProducts();
    }
}
```

---

# Step 5: Save Apex Controller

Click:

## File → Save

OR press:

```text id="tqjlwm"
Ctrl + S
```

---

# Step 6: Create Visualforce Page

Go to:

## Developer Console → File → New → Visualforce Page

Page Name:

```text id="e4rfxr"
ProductInventoryPage
```

Click:

```text id="d1q1wa"
OK
```

Replace generated code with the following code.

---

# Visualforce Page Code

```html id="y9mjlwm"
<apex:page controller="ProductInventoryController">

    <apex:form>

        <!-- Message Panel -->

        <apex:outputPanel id="msgPanel">

            <apex:pageMessages />

        </apex:outputPanel>

        <!-- Main Page -->

        <apex:pageBlock title="Product Inventory Management System">

            <!-- Add Product Section -->

            <apex:pageBlockSection
                title="Add Product"
                columns="2">

                <apex:inputField
                    value="{!productRec.Product_Name__c}" />

                <apex:inputField
                    value="{!productRec.Serial_No__c}" />

                <apex:inputField
                    value="{!productRec.Manufacture_Date__c}" />

                <apex:inputField
                    value="{!productRec.Expiry_Date__c}" />

            </apex:pageBlockSection>

            <!-- Add Button -->

            <apex:commandButton
                value="Add Product"
                action="{!addProduct}"
                rerender="msgPanel,productTable" />

        </apex:pageBlock>

        <br/>

        <!-- Product Table -->

        <apex:pageBlock title="Available Products">

            <apex:pageBlockTable
                value="{!productList}"
                var="p"
                id="productTable">

                <apex:column
                    value="{!p.Product_Name__c}"
                    headerValue="Product Name" />

                <apex:column
                    value="{!p.Serial_No__c}"
                    headerValue="Serial Number" />

                <apex:column
                    value="{!p.Manufacture_Date__c}"
                    headerValue="Manufacture Date" />

                <apex:column
                    value="{!p.Expiry_Date__c}"
                    headerValue="Expiry Date" />

                <!-- Delete Option -->

                <apex:column headerValue="Action">

                    <apex:commandLink
                        value="Delete"
                        action="{!deleteProduct}"
                        rerender="msgPanel,productTable">

                        <apex:param
                            name="pid"
                            value="{!p.Id}" />

                    </apex:commandLink>

                </apex:column>

            </apex:pageBlockTable>

        </apex:pageBlock>

    </apex:form>

</apex:page>
```

---

# Step 7: Save Visualforce Page

Click:

## File → Save

OR press:

```text id="09k1vk"
Ctrl + S
```

---

# Step 8: Run Application

Open the page using URL:

```text id="bcr7i9"
https://yourDomainName.apex/ProductInventoryPage
```

Example:

```text id="zjlwmz"
https://apex.salesforce.com/apex/ProductInventoryPage
```

---

# Validation Messages Displayed on UI

## Empty Product Name

```text id="kvsj2p"
Product Name cannot be empty.
```

---

## Empty Serial Number

```text id="8jrg9k"
Serial Number cannot be empty.
```

---

## Future Manufacture Date

```text id="ie8sxa"
Manufacture Date cannot be a future date.
```

---

## Invalid Expiry Date

```text id="h7n2py"
Expiry Date must be greater than today.
```

---

## Expiry Date Before Manufacture Date

```text id="vjlwm6"
Expiry Date cannot be before Manufacture Date.
```

---

## Duplicate Serial Number

```text id="pyk3hj"
Serial Number already exists. Enter unique Serial Number.
```

---

## Success Message

```text id="6l4jfh"
Product Added Successfully.
```

---

## Delete Success Message

```text id="9tqjlwm"
Product Deleted Successfully.
```

---

# SOQL Query Used

```sql id="jlwm6v"
SELECT Id,
       Product_Name__c,
       Serial_No__c,
       Manufacture_Date__c,
       Expiry_Date__c
FROM Product_Inventory__c
ORDER BY CreatedDate DESC
```

---

# DML Operations Used

| Operation | Purpose        |
| --------- | -------------- |
| insert    | Add Product    |
| delete    | Delete Product |

---

# Project Flow

```text id="4vslr8"
Start
   ↓
Create Custom Object
   ↓
Create Custom Fields
   ↓
Create Apex Controller
   ↓
Create Visualforce Page
   ↓
Add Product with Validations
   ↓
Display Products
   ↓
Delete Product
   ↓
End
```

---

# Advantages of Project

* User-Friendly Product Management
* Real-Time Salesforce Database Integration
* Prevents Invalid Product Entries
* Displays Proper Success/Error Messages
* Beginner Friendly Salesforce Project

---

# Learning Outcomes

After completing this project, you will understand:

* Salesforce Custom Objects
* Apex Controllers
* Visualforce Pages
* SOQL Queries
* DML Operations
* Page Messages
* Input Validations in Apex
* CRUD Operations in Salesforce

---

# Future Enhancements

* Add Update Product Feature
* Add Product Search
* Add Product Quantity
* Add Product Category
* Add Expiry Alert System
* Convert to Lightning Web Components (LWC)

---

# Author

## Mokshada Sheth

B.E. Computer Engineering
SCTR's PICT Pune
