C++ Programming Assignment

Library Management System-:

It consist of 5 files mainly in two categories
i. Code source file
ii. Database file

1. Code Source File-: I have made a program file named as "main.cpp" which is the prime code file.

a. main()-: It consist of main() function for execution which also host Home page of libsystem. Cotains various options for user out of this main functionality i.e login render into Base class functions.
forget uses name and id of user to display password also Base class function
Registration is User class function as librarian can also access to register an user who is not familiar with this libsystem

b.page class functions-: It consist of various important pages of our system namely-> login_page, student_page, professor_page, librarian_page.

c.Book class-: it is the top most module/class in my implementation, and store all functions reated to book which is inherited by User class as public to see all functionalities.

Functions include->list_books(), add_book(), update_book(), delete_book(), issued_book(), search_book() to render various functionalities.

d.User class-: inherited from Book class, is top/parent class for student, professor.
implements all functionalities related to student and professor which are common to both.

Functions include->list_user(), registration(), update_user(), delete_user(), issued_books(), issue(), returning(), clear_fine(), due_date();

e.student class-: child class of User, implements some unique functionalities related to students only.

Functions include-> fine

f. professor class-: child class of User, implements some unique functionalities related to professors only.

Functions include-> fine

g. Base class-: implements some very basic functionalities like-> login, forgot.

h. checker class-: this is the class that I made for easy implementation of various functions it have functions like check and update, so as to check some elements and update some databse related to some operations.


2. Database-:

a.book_data.csv-: contains data of all books present in library.
stored as, title of book, author, ISBN, publication, quantity(can be 0,1 as said in question).

b.book_num.csv-: only made so as to store number of books a particular user have.
stored as, name of user, ID, title, author, count of books.

c.issue_data.csv-: contains info about different user having different books, along with time stamp of issue time in second with some reference.
stored as, name, ID, password, bookname(title), timestamp.

d.user_data.csv-: contains info about all the user which are logged in library management system.
stored as, ID, name, password, designation(1-: student, 2-: professor, 3-: librarian). 


3. To run -: please follow all the steps that comes as prompt while executing code main.cpp


4. To NOTE-: I did not make librarian as user as otherwise it has access to various important credentials of user.
5. i.e i had changed the structure as it is allowed as written in question.