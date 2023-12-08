#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <thread>

class LibraryItem {
public:
    virtual ~LibraryItem() {}
    virtual void display() const = 0;
    virtual std::string getTitle() const = 0;
    virtual std::string getAuthor() const = 0;
    virtual int getYear() const = 0;
    virtual bool searchItemTitle(const std::string& title) const = 0;
    virtual bool searchItemAuthor(const std::string& author) const = 0;
    virtual bool searchItemYear(int year) const = 0;
};

class Book : public LibraryItem {
public:
    Book(const std::string& title, const std::string& author, int year, int pages, double price) : title(title), author(author), year(year), pages(pages), price(price) {}
    void display() const override { std::cout << "Book: " << title << " by " << author << ", Year: " << year << ", Pages: " << pages << ", Price: " << price << '.' << std::endl; }
    bool searchItemTitle(const std::string& title) const override {
        return (this->title == title);
    }
    bool searchItemAuthor(const std::string& author) const override {
        return (this->author == author);
    }
    bool searchItemYear(int year) const override {
        return (this->year == year);
    }
    void setTitle(const std::string& title) { this->title = title; }
    void setAuthor(const std::string& author) { this->author = author; }
    void setPages(int pages) { this->pages = pages; }
    void setYear(int year) { this->year = year; }
    void setPrice(double price) { this->price = price; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPages() const { return pages; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
private:
    std::string title;
    std::string author;
    int year;
    int pages;
    double price;
};


class CD : public LibraryItem {
public:
    CD(const std::string& title, const std::string& artist, int year, double duration) : title(title), artist(artist), year(year), duration(duration) {}
    void display() const override { std::cout << "CD: " << title << " by " << artist << ", Year: " << year << ", Duration: " << duration << " minutes." << std::endl; }
    bool searchItemTitle(const std::string& title) const override {
        return (this->title == title);
    }
    bool searchItemAuthor(const std::string& artist) const override {
        return (this->artist == artist);
    }
    bool searchItemYear(int year) const override {
        return (this->year == year);
    }
    void setTitle(const std::string& title) { this->title = title; }
    void setArtist(const std::string& artist) { this->artist = artist; }
    void setYear(int year) { this->year = year; }
    void setDuration(double duration) { this->duration = duration; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return artist; }
    int getYear() const { return year; }
    double getDuration() const { return duration; }
private:
    std::string title;
    std::string artist;
    int year;
    double duration;
};

class Library {
public:
    Library(const std::string& name) : name(name) {}
    void add_item(std::shared_ptr<LibraryItem> item) {
        items.push_back(item);
    }
    void remove_item(std::shared_ptr<LibraryItem> item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }
    void remove_item(const std::string& title) {
        items.erase(std::remove_if(items.begin(), items.end(), [&](const auto& item) {
            const Book* book = dynamic_cast<const Book*>(item.get());
            const CD* cd = dynamic_cast<const CD*>(item.get());
            if (book && book->getTitle() == title) {
                return true;
            }
            if (cd && cd->getTitle() == title) {
                return true;
            }
            return false;
            }), items.end());
    }
    void remove_item(int year) {
        items.erase(std::remove_if(items.begin(), items.end(), [&](const auto& item) {
            const Book* book = dynamic_cast<const Book*>(item.get());
            const CD* cd = dynamic_cast<const CD*>(item.get());
            if (book && book->getYear() == year) {
                return true;
            }
            if (cd && cd->getYear() == year) {
                return true;
            }
            return false;
            }), items.end());
    }
    std::shared_ptr<LibraryItem> searchItemTitle(const std::string& title) {
        bool flag = false;
        for (const auto& item : items) {
            if (item->getTitle() == title) {
                if (item != nullptr) {
                    item->display();
                    flag = true;
                }
            }
        }
        if (!flag) {
            std::cout << "Элемент с названием \"" << title << "\" не найден." << std::endl;
        }
        return nullptr; // Если элемент не найден, возвращаем nullptr
    }
    std::shared_ptr<LibraryItem> searchItemYear(int year) {
        bool flag = false;
        for (const auto& item : items) {
            if (item->getYear() == year) {
                if (item != nullptr) {
                    item->display();
                    flag = true;
                }
            }
        }
        if (!flag) {
            std::cout << "Элемент \"" << year << "\" года не найден." << std::endl;
        }
        return nullptr; // Если элемент не найден, возвращаем nullptr
    }
    std::shared_ptr<LibraryItem> searchItemAuthor(const std::string& author) {
        bool flag = false;
        for (const auto& item : items) {
            if (item->getAuthor() == author) {
                if (item != nullptr) {
                    item->display();
                    flag = true;
                }
            }
        }
        if (!flag) {
            std::cout << "Авторство \"" << author << "\" не найдено." << std::endl;
        }
        return nullptr; // Если элемент не найден, возвращаем nullptr
    }
    std::vector<std::shared_ptr<LibraryItem>> getItems() const {
        return items;
    }
    void display_items() const {
        std::cout << "Items in the library:" << std::endl;
        for (const auto& item : items) {
            if (item != nullptr) {
                item->display();
            }
        }
    }
    std::vector<std::shared_ptr<Book>> getBooks() const {
        std::vector<std::shared_ptr<Book>> books;
        for (const auto& item : items) {
            const std::shared_ptr<Book> book = std::dynamic_pointer_cast<Book>(item);
            if (book) {
                books.push_back(book);
            }
        }
        return books;
    }
    std::vector<std::shared_ptr<CD>> getCDs() const {
        std::vector<std::shared_ptr<CD>> cds;
        for (const auto& item : items) {
            const std::shared_ptr<CD> cd = std::dynamic_pointer_cast<CD>(item);
            if (cd) {
                cds.push_back(cd);
            }
        }
        return cds;
    }
private:
    std::string name;
    std::vector<std::shared_ptr<LibraryItem>> items;
};

void printAllBooks(const Library& library) {
    const std::vector<std::shared_ptr<Book>>& books = library.getBooks();
    std::cout << "All Books:" << std::endl;
    for (const auto& book : books) {
        book->display();
    }
}

void printAllCDs(const Library& library) {
    const std::vector<std::shared_ptr<CD>>& cds = library.getCDs();
    std::cout << "All CDs:" << std::endl;
    for (const auto& cd : cds) {
        cd->display();
    }
}

void addLibraryItem(Library& library) {
    std::string itemType;
    std::cout << "Выберите тип элемента (book/cd): ";
    std::cin >> itemType;

    if (itemType == "book") {
        std::string title, author;
        int year, pages;
        double price;

        std::cout << "Введите название книги: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        std::cout << "Введите автора книги: ";
        std::getline(std::cin, author);

        std::cout << "Введите год выпуска книги: ";
        std::cin >> year;

        std::cout << "Введите количество страниц книги: ";
        std::cin >> pages;

        std::cout << "Введите цену книги: ";
        std::cin >> price;

        std::shared_ptr<Book> book = std::make_shared<Book>(title, author, year, pages, price);
        library.add_item(book);

        std::cout << "Книга успешно добавлена в библиотеку.\n";
    }
    else if (itemType == "cd") {
        std::string name, artist;
        int year;
        double duration;

        std::cout << "Введите название диска: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Введите исполнителя диска: ";
        std::getline(std::cin, artist);

        std::cout << "Введите год выпуска диска: ";
        std::cin >> year;

        std::cout << "Введите продолжительность диска (в минутах): ";
        std::cin >> duration;

        std::shared_ptr<CD> cd = std::make_shared<CD>(name, artist, year, duration);
        library.add_item(cd);

        std::cout << "Диск успешно добавлен в библиотеку.\n";
    }
    else {
        std::cout << "Некорректный тип элемента. Попробуйте ещё раз.\n";
    }
}

void readData(Library& library, std::string path) {
    std::ifstream inputFile(path);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string name;
            std::string author;
            int data;
            int year;
            double price;
            if (line.find(';') != std::string::npos) {
                std::getline(ss, name, ';');
                std::getline(ss, author, ';');
                ss >> data;
                ss.ignore();
                ss >> year;
                ss.ignore();
                ss >> price;
                std::shared_ptr<Book> book = std::make_shared<Book>(name, author, year, data, price);
                library.add_item(book);
            }
            else {
                std::getline(ss, name, ':');
                std::getline(ss, author, ':');
                ss >> year;
                ss.ignore();

                std::string durationStr;
                std::getline(ss, durationStr, '.');
                int minutes = std::stoi(durationStr);
                std::getline(ss, durationStr);
                int seconds = std::stoi(durationStr);

                double duration = minutes + (seconds / 100.0);
                std::shared_ptr<CD> cd = std::make_shared<CD>(name, author, year, duration);
                library.add_item(cd);
            }
        }
        inputFile.close();
    }
    else {
        std::cout << "Невозможно открыть файл." << std::endl;
    }
}

void writeData(const Library& library, const std::string& path) {
    std::ofstream outputFile(path,std::ofstream::trunc);
    if (outputFile.is_open()) {
        const std::vector<std::shared_ptr<LibraryItem>>& items = library.getItems();
        for (const auto& item : items) {
            const Book* book = dynamic_cast<const Book*>(item.get());
            const CD* cd = dynamic_cast<const CD*>(item.get());
            if (book) {
                outputFile << book->getTitle() << ";" << book->getAuthor() << ";"
                    << book->getPages() << ";" << book->getYear() << ";" << book->getPrice()
                    << std::endl;
            }
            else if (cd) {
                int minutes = static_cast<int>(cd->getDuration());
                double seconds = (cd->getDuration() - minutes) * 100;
                outputFile << cd->getTitle() << ":" << cd->getAuthor() << ":"
                    << cd->getYear() << ":" << cd->getDuration()
                    << std::endl;
            }
        }
        outputFile.close();
        std::cout << "Database was updated." << std::endl;
    }
    else {
        std::cout << "Unable to open the file data.txt" << std::endl;
    }
}

void showLoadingAnimation(int percent) {
    std::string animation = "[";
    int numEquals = percent / 5;
    int feeling = std::rand() % 256;
    for (int i = 0; i < 20; ++i) {
        if (i < numEquals) {
            animation += "\033[0;31m=\033[0m";
        }
        else {
            animation += " ";
        }
    }
    std::stringstream ss;
    ss << percent;
    std::string percentStr = ss.str();
    ss.str("");
    ss << feeling;
    std::string feelingStr = ss.str();
    animation += "] " + percentStr + "% Загрузка FEFU Library...";
    std::cout << "\r" << animation << std::flush;
}

void deleteLibraryItem(Library& library) {
    std::cout << "Как будем удалять?(title/year): ";
    std::string ans;
    std::cin >> ans;
    if (ans == "title") {
        {
            std::string title;
            std::cout << "Введите название элемента для удаления: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            library.remove_item(title);
            std::cout << "Элемент успешно удален.\n";
        }
    }
    else if (ans == "year") {
        {
            int year;
            std::cout << "Введите год элемента для удаления: ";
            std::cin >> year;
            library.remove_item(year);
            std::cout << "Элемент успешно удален.\n";
        }
    }
    else {
        std::cout << "Некорректный ввод. Попробуйте снова.";
    }
}

void searchLibrary(Library& library) {
    std::string ans;
    std::cout << "Как будем искать? (title/author/year): ";
    std::cin >> ans;
    if (ans == "title") {
        std::string title;
        std::cout << "Введите название: ";
        std::cin >> title;
        try {
            std::shared_ptr<LibraryItem> item = library.searchItemTitle(title);
        }
        catch (const std::exception& e) {
            std::cout << e.what();
        }
    }
    else if (ans == "author") {
        std::string author;
        std::cout << "Введите автора: ";
        std::cin >> author;
        try {
            std::shared_ptr<LibraryItem> item = library.searchItemAuthor(author);
        }
        catch (const std::exception& e) {
            std::cout << e.what();
        }
    }
    else if (ans == "year") {
        int year;
        std::cout << "Введите год: ";
        std::cin >> year;
        try {
            std::shared_ptr<LibraryItem> item = library.searchItemYear(year);
        }
        catch (const std::exception& e) {
            std::cout << e.what();
        }
    }
    else {
        std::cout << "Некорректный ввод." << std::endl;
    }
}

int menu(Library& library) {
    setlocale(LC_ALL, "Russian");
    int choice;
    readData(library, "data.txt");
    while (true) {
        std::cout << "Меню:\n";
        std::cout << "1. Распечатать все элементы из библиотеки\n";
        std::cout << "2. Вывести книги\n";
        std::cout << "3. Вывести диски\n";
        std::cout << "4. Добавить книгу/диск\n";
        std::cout << "5. Удалить книгу/диск\n";
        std::cout << "6. Найти книгу/диск\n";
        std::cout << "0. Выход из программы\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            library.display_items();
            break;
        case 2:
            printAllBooks(library);
            break;
        case 3:
            printAllCDs(library);
            break;
        case 4:
            addLibraryItem(library);
            writeData(library, "data.txt");
            break;
        case 5:
            deleteLibraryItem(library);
            writeData(library, "data.txt");
            break;
        case 6:
            searchLibrary(library);
            break;
        case 0:
            writeData(library, "data.txt");
            std::cout << "Выходим...\n";
            return 0;
        default:
            std::cout << "Некорректный ввод. Попробуйте ещё раз.\n";
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}

void start(Library& library) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialize random seed
    for (int percent = 0; percent <= 100; percent += 5) {
        showLoadingAnimation(percent);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << std::endl;
    std::cout << "Загрузка завершена, книги успешно добавлены!\n";
    menu(library);
}


int main() {
    setlocale(LC_ALL, "Russian");
    Library library("FEFU");
    start(library);
    return 0;
}