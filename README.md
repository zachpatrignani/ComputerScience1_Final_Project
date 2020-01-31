# ComputerScience1_Final_Project
This project is a catalog of books, journals, and magazines. The user can checkout, return, and add items of each.
I started this project by designing a base class called library, and deriving book, magazine, and journal from it through public inheritance.
Since the user can add books, I knew I needed to use vectors since the size would be able to increase throughout the program.
When the user wants to search for a book, journal, or magazine, I list out the items in the library so that the user can browse the items.
The user can also search for the item by the title, author, issue, and volume. The user can see if that item is available for checkout
or not.
Once the user checks out or returns an item, they can check whether it was successful by looking at the menu of those items and
looking at the status to see if it corresponds with their action. The user can also make sure an item was added correctly by
displaying the menu of the category which will display the items already stored and the newly added item. 
