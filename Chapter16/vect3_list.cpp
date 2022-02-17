// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

struct Review {
    std::string title;
    int rating{};
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::cin;
    using std::list;
    using std::vector;

    list<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    if (!books.empty())
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
             << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

//        sort(books.begin(), books.end());
        books.sort();

        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

//        sort(books.begin(), books.end(), worseThan);
        books.sort(worseThan);

        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

//        random_shuffle(books.begin(), books.end());
        vector<Review> tmp;
        tmp.reserve(books.size());
        std::copy(books.begin(), books.end(), std::back_inserter(tmp));
        std::random_shuffle(tmp.begin(), tmp.end());
        books.assign(tmp.begin(), tmp.end());

        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
    if ((r1.title < r2.title) or (r1.title == r2.title && r1.rating < r2.rating))
        return true;
    else
        return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}
