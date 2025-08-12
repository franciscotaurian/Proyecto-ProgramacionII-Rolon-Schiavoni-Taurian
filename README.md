# 🏦 Bank Management System (C++ OOP)

A console-based banking management application developed in C++ using **Object-Oriented Programming (OOP)** principles.  
The system allows management of clients, employees, and transactions, providing separate menus and functionalities for employees and clients.

---

## 📌 Features

- **Client Management**  
  - Add new clients  
  - Remove clients (mark as inactive)  
  - View client details  
  - Assign client type and credit card based on account history  

- **Transaction Management**  
  - Deposit and withdraw money (in pesos or dollars)  
  - View transactions by month, year, or client  
  - Persistent transaction storage in text files  

- **Employee Management**  
  - Add employees  
  - Employee-specific operations for managing clients and transactions  

- **Persistence**  
  - Clients and transactions are saved in text files (`listadoClientes.txt`, `listaTrans.txt`) to maintain data between executions.

---

## 🛠️ Technologies Used

- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (Inheritance, Encapsulation, Composition)  
- **File Handling:** Text file read/write for persistence  
- **Standard Libraries:** `<iostream>`, `<fstream>`, `<string>`, `<cstring>`, `<sstream>`

---

## 📂 Project Structure
BankSystem/
│── main.cpp # Main program and menus
│── banco.cpp/.h # Bank class (manages clients, employees, transactions)
│── clientes.cpp/.h # Client class (inherits from Persona)
│── empleado.cpp/.h # Employee class (inherits from Persona)
│── persona.cpp/.h # Base class for people
│── transacciones.cpp/.h # Transaction class
│── tarjeta.cpp/.h # Credit card class
│── ejecutableBanco # Compiled executable
