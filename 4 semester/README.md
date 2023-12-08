## Class Structure
- **LibraryItem (Abstract Class):** 
  - Serves as a base class for Book and CD classes, defining common methods to be overridden by its subclasses.
- **Book Class:** 
  - Represents a book in the library, storing attributes such as title, author, year, pages, and price.
- **CD Class:** 
  - Represents a CD in the library, storing attributes like title, artist, year, and duration.
- **Library Class:** 
  - Manages the collection of LibraryItems, providing methods to add, remove, and search items. It segregates Books and CDs and provides specific methods to retrieve them.

## Key Functionality
- **Adding Items:** 
  - The `add_item` method in the Library class allows adding both books and CDs to the library collection.
- **Removing Items:** 
  - The `remove_item` method in the Library class supports removal by title, author, or year for both books and CDs.
- **Searching Items:** 
  - The `searchItemTitle`, `searchItemAuthor`, and `searchItemYear` methods in the Library class enable searching items by title, author, or year.
- **Reading/Writing Data:** 
  - The `readData` and `writeData` functions handle reading from and writing to a file to maintain library data persistently.
- **Menu and User Interaction:** 
  - The `menu` function provides a command-line menu for users to interact with library functionalities.

## Overall
This code demonstrates basic library management functionalities using C++ and object-oriented principles. It's a foundational example but might need additional enhancements for production-level applications, especially in error handling and input validation.
