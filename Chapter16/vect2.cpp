#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout << "Thank you. You enter the following:\n"
          << "Rating\tBook\n";
        for (int i = 0; i < num; i++)
        {
            ShowReview(books[i]);
        }
        cout << "Reprising:\n" << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end();pr++)
           ShowReview(*pr);
        vector<Review> oldList(books);
        if (num > 3)
        {
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erase:\n";
            for (pr = books.begin(); pr != books.end();pr++)
                ShowReview(*pr);
            books.insert(books.begin(), oldList.begin() + 1, oldList.begin() + 2);
            cout << "After insert:\n";
            for (pr = books.begin(); pr != books.end();pr++)
                ShowReview(*pr);
            books.swap(oldList);
            cout << "After swap:\n";
            for (pr = books.begin(); pr != books.end();pr++)
                ShowReview(*pr);
        }
        return 0;
    }
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title: ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
       return false;
    while (std::cin.get() != '\n')
       continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}