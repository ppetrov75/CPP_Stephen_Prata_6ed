#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>


struct Review {
    std::string title;
    int rating{};
    int price{};
};

bool operator<(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2);

bool sortByRating(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2);
bool sortByTitle(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2);
bool sortByPrice(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2);

bool FillReview(Review & rr);
void ShowReview(std::shared_ptr<Review> & rr);

int main()
{
    using namespace std;

    vector<std::shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(std::make_shared<Review>(temp));
    if (!books.empty())
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
             << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), sortByTitle);
        cout << "Sorted by title:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), sortByRating);
        cout << "Sorted by rating:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(),sortByPrice);
        cout << "Sort by Price:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        cout << "Sort by Price(expensive first):\nRating\tBook\tPrice\n";
        for_each(books.rbegin(), books.rend(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2)
{
    if ((r1->title < r2->title) or (r1->title == r2->title && r1->rating < r2->rating))
        return true;
    else
        return false;
}

bool sortByTitle(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2)
{
    return (r1->title < r2->title);
}

bool sortByRating(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2)
{
    return (r1->rating < r2->rating);
}

bool sortByPrice(std::shared_ptr<Review> & r1, std::shared_ptr<Review> & r2)
{
    return (r1->price < r2->price);
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

    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;

    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(std::shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}
