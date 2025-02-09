
#  🏦 Bank Management System (OOP)
📌 Project Description

This Bank Management System is designed to streamline banking operations by managing users and clients, tracking activities, and offering currency exchange services. Built with Object-Oriented Programming (OOP) principles, the system is structured for scalability and maintainability. It utilizes external file storage for data persistence and implements OOP concepts like inheritance and polymorphism to enhance modularity and code reusability.


## ✨ Features
**1- User & Client Management:**

 Supports multiple users and clients, ensuring secure data handling 
The system reads and writes user data from/to the text file. It supports operations like adding, updating, and finding users/client in the file.

**2- Authentication System :**

  Controls access and maintains account security.

**3-Permissions Management:**

  Assigns different access levels to users based on their roles

**4-Activity Logging:**

  Automatically records user and client actions in an external log file for tracking and auditing.

**5- Currency Exchange System :**

   Provides real-time currency conversion between different currencies.

**6- Transaction Management:**

  Facilitates deposits, withdrawals, and transfers between accounts.




##  💡 How it Works

The` Login` function authenticates users by checking their credentials against the data stored in `Users.txt.`


Once logged in, Users can perform any of the operations available in the main menu.


**Files:**
`Users.txt`:
Stores the User information , such as name, email,phone number, username, password and persmissions

`Clients.txt`: Stores the client information, such as account number, PIN code, name, phone number, and account balance.

`TransferLogs.txt`:
After each transaction, the updated data is written back to the file and Svaed in an external file 

`Currencies.txt`:
 file contains exchange rate data for various countries, including the currency code, name, and its conversion rate to another currency 

`LogIns.txt`:
tracks user login activity, saving each user's information along with the time of login to monitor and audit system access.

`TransferLogs.txt`:
records all transfer operations, saving the details of both clients involved, the transfer amount, and the time of the transaction for tracking and auditing purposes.

🛑 **How to Access:**

you can  run the code and access the system using:

User Name: User3
password : 125




