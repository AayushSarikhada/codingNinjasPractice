import sqlite3 as sql
while True:
    print("Press 1 for Table Creation")
    print("Press 2 for Data Insertion in Database ")
    print("press 3 for rows Deletion in database")
    print("press 4 for data Read from table")
    print("press 5 for update the existing data")
    print("press 6 for come out from this loop")
    user_input = int(input("Enter Your Choice: "))

    if user_input == 1:
        # for table creation
        # authorName, BookName, Price, Rating or Review, Book
        # Bring
        # Date
        con = sql.connect('volvo.db')
        print("Connection Establish.... ")      print("#########################################################################")
        cursor = con.cursor()
        cursor.execute("CREATE TABLE Library(book_id INTEGER PRIMARY KEY AUTOINCREMENT, author_name TEXT Not Null, book_name TEXT Not Null, price INTEGER, review TEXT Not Null, book_bring_date TEXT Not Null)")
 print("Table Created Successfully..")
print("########################################################################")
  elif user_input == 2:

        con = sql.connect('volvo.db')
        print("Connection Establish....")
        cursor = con.cursor()
        auth_name = input("Enter Author Name: ")
        book_name = input("Enter Book Name: ")
        price = int(input("Enter Book Price: "))
        review = input("Enter review For Book: ")
        book_bring_date = input("Enter Book Bring date: ")

        statement = "INSERT INTO Library(author_name, book_name, price, review, book_bring_date) VALUES (?, ?, ?, ?, ?)"
        cursor.execute(statement, (auth_name, book_name,
                       price, review, book_bring_date))
        con.commit()
        print("###############################################################")
        print("data Inserted Successfully.........")
        print("###############################################################")

    elif user_input == 3:
        con = sql.connect('volvo.db')
        print("Connection Establish....")
        cursor = con.cursor()
        print("##################################################################")
        enter_book_id = int(
            input("Enter the book id which record you want to delete: "))
        statement1 = "DELETE FROM Library WHERE book_id = (?) "
        cursor.execute(statement1, (enter_book_id, ))
        cursor.close()
        con.commit()

        print("Row Deleted Successfully...")
        print("##################################################################")

    elif user_input == 4:
        con = sql.connect('volvo.db')
        print("Connection Establish....")
        cursor = con.cursor()
        cursor.execute("SELECT * FROM Library")
        print("data are: ")
        print("#################################################################################")

        output = cursor.fetchall()

        for row in output:
            print(row)

        print("#################################################################################")

        con.close()

    elif user_input == 5:
        con = sql.connect('volvo.db')
        print("Connection Establish....")
        cursor = con.cursor()

        exist_book_id = input(
            "Enter the book ID which record you want to UPDATE: ")
        auth_name = input("Enter Author Name: ")
        book_name = input("Enter Book Name: ")
        price = int(input("Enter Book Price: "))
        review = input("Enter review For Book: ")
        book_bring_date = input("Enter Book Bring date: ")

        statement2 = ''' UPDATE Library SET author_name = ?, book_name = ?, price = ?, review = ?, book_bring_date = ? 
                     WHERE book_id = ? ; '''
        cursor.execute(statement2, (auth_name, book_name, price,
                       review, book_bring_date, exist_book_id))
        cursor.close()
        con.commit()
        print("Data UPDATED Sucessfully....")

    elif user_input == 6:
        print("Thank you for using our Library management system....")
        break

    else:

        print("Enter a valid Choice")
