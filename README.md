# Grocery System

This is a simple grocery billing system implemented in C.

## Description

The Grocery System allows users to register, login, select items from a menu, specify quantities, and generate a bill. It has been implemented in multiple phases, each adding new features and improvements.

## Features

### Phase 1:
- **User Authentication:** Users can register and login to their accounts.
- **Item Selection:** Users can choose items from a menu.
- **Quantity Selection:** Users can specify the quantity of each item.
- **Total Bill Calculation:** The system calculates the total bill based on the selected items and quantities.

### Phase 2:
- **Structural Organization:** User data and shopping lists are organized using structures for better management.
- **Dynamic Memory Allocation:** Memory is allocated dynamically for storing user data and shopping lists.
- **String Matching:** String matching is implemented for user authentication and item selection.
- **File Handling:** User data and shopping lists are stored and retrieved from files.
- **Search Operation:** Users can search for items in the menu.

### Phase 3 (New Features):
- **Enhanced File Handling:** File handling capabilities are improved to support storing user data and shopping lists.
- **Merging Phases:** Code from previous phases is merged to create a comprehensive grocery system.
- **Detailed README:** The README file provides detailed explanations about the features used in the code, including structs, file handling, lists, strings, etc.

## Usage

1. **Registration and Login:**
    - Users can register with a username and password.
    - Registered users can log in to their accounts.

2. **Item Selection:**
    - Users can select items from the menu by entering the corresponding item number.

3. **Quantity Selection:**
    - After selecting an item, users can specify the quantity.

4. **Total Bill Generation:**
    - The system calculates the total bill based on the selected items and quantities.
    - Separate item quantities and prices are displayed before the total bill.

5. **File Handling:**
    - User data and shopping lists are stored in files for persistence.
    - Saved shopping lists can be loaded for future reference.

## Getting Started

To run the Grocery System on your local machine, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/grocery-system.git
    ```

2. Compile the source code:

    ```bash
    gcc -o grocery_system make.c user.c grocery.c
    ```

3. Run the executable:

    ```bash
    ./grocery_system
    ```

## Contributors

- Shay V Shah (@shayvshah)


