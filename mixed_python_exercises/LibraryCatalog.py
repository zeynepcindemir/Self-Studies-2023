class LibraryCatalog:
    def __init__(self, name):
        self.name = name
        self.books = []

    def __str__(self):
        if len(self.books) == 0:
            return f"The catalog '{self.name}' is empty."
        return f"Catalog '{self.name}':\n" + "\n".join(
            f"Title: {book['title']}, Author: {book['author']}, Year: {book['year']}" for book in self.books
        )

    def add_book(self, title, author, year):
        book = {"title": title, "author": author, "year": year}
        self.books.append(book)
        print(f"Added book '{title}' to the catalog '{self.name}'.")

    def remove_book(self, title):
        for book in self.books:
            if book["title"] == title:
                self.books.remove(book)
                print(f"Removed book '{title}' from the catalog '{self.name}'.")
                break
        else:
            print(f"Book '{title}' not found in the catalog.")

    def search_book(self, title):
        for book in self.books:
            if book["title"] == title:
                return f"Book found: Title: {book['title']}, Author: {book['author']}, Year: {book['year']}"
        return f"Book '{title}' not found in the catalog."

    def compare_catalogs(self, other_catalog):
        common_books = []
        for book in self.books:
            if book in other_catalog.books:
                common_books.append(book)
        return common_books

    def group_by_year(self):
        books_by_year = {}
        for book in self.books:
            year = book["year"]
            if year not in books_by_year:
                books_by_year[year] = []
            books_by_year[year].append(book)
        return books_by_year

    def search_by_author(self, author):
        books = []
        for book in self.books:
            if book["author"] == author:
                books.append(book["title"])
        if not books:
            return f"No books found by {author}."
        return books


# -------------------------Instructions for testing---------------------------
# Testing the LibraryCatalog class
catalog = LibraryCatalog("Computer Science")
print(catalog)

# Add some books
catalog.add_book("Python Programming", "John Smith", 2019)
catalog.add_book("Introduction to Algorithms", "Thomas Cormen", 2009)
catalog.add_book("Data Science for Beginners", "Emily Davis", 2021)
catalog.add_book("Web Development Basics", "John Smith", 2021)
catalog.add_book("Data Structures and Algorithms", "Jane Doe", 2009)

print(catalog)

# Test searching for a book
print(catalog.search_book("Python Programming"))
print(catalog.search_book("Introduction to Coding"))

# Test removing a book
catalog.remove_book("Introduction to Algorithms")
catalog.remove_book("Introduction to Coding")

print(catalog)

# Create a second instance of the LibraryCatalog class
catalog2 = LibraryCatalog("Programming")

catalog2.add_book("Python Programming", "John Smith", 2019)
catalog2.add_book("Introduction to Programming", "Jane Doe", 2020)
catalog2.add_book("Data Science for Beginners", "Emily Davis", 2021)

# Compare two catalogs
common_books = catalog.compare_catalogs(catalog2)
print(common_books)

# Group books by year
books_by_year = catalog.group_by_year()
print(books_by_year)

# Search for books by author
author = "John Smith"
books_by_author = catalog.search_by_author(author)
print(books_by_author)

author2 = "Fyodor Dostoevsky"
books_by_author = catalog.search_by_author(author2)
print(books_by_author)
