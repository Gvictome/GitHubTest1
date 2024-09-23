
/*
Course Code: COP3014 001
Assignment 5
Name: Giovanny Victome
Date: 6.23.2024
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Movie {
private:
    string name;
    string mpaaRating;
    int rating1Count;
    int rating2Count;
    int rating3Count;
    int rating4Count;
    int rating5Count;

public:
    // Constructor
    Movie(string movieName, string rating) {
        name = movieName;
        mpaaRating = rating;
        rating1Count = 0;
        rating2Count = 0;
        rating3Count = 0;
        rating4Count = 0;
        rating5Count = 0;
    }

    // Accessor and Mutator for movie name
    string getName() const {
        return name;
    }

    void setName(string movieName) {
        name = movieName;
    }

    // Accessor and Mutator for MPAA rating
    string getMpaaRating() const {
        return mpaaRating;
    }

    void setMpaaRating(string rating) {
        mpaaRating = rating;
    }

    // Accessor functions for rating counts
    int getRating1Count() const {
        return rating1Count;
    }

    int getRating2Count() const {
        return rating2Count;
    }

    int getRating3Count() const {
        return rating3Count;
    }

    int getRating4Count() const {
        return rating4Count;
    }

    int getRating5Count() const {
        return rating5Count;
    }

    // Function to add rating
    void addRating(int rating) {
        if (rating < 1 || rating > 5) {
            cout << "Invalid rating. Please enter a rating between 1 and 5." << endl;
            return;
        }
        switch (rating) {
            case 1:
                rating1Count++;
                break;
            case 2:
                rating2Count++;
                break;
            case 3:
                rating3Count++;
                break;
            case 4:
                rating4Count++;
                break;
            case 5:
                rating5Count++;
                break;
        }
    }

    // Function to calculate average rating
    double averageRating() const {
        int totalRatings = rating1Count + rating2Count + rating3Count + rating4Count + rating5Count;
        // Avoids division by zero
        if (totalRatings == 0) {
            return 0.0; 
        }
        int sumOfRatings = rating1Count * 1 + rating2Count * 2 + rating3Count * 3 + rating4Count * 4 + rating5Count * 5;
        return static_cast<double>(sumOfRatings) / totalRatings;
    }
};

// Main function to test the Movie class
int main() {
    // Seed for random number generation wanted to test this out
    srand(static_cast<unsigned int>(time(0))); 

    Movie movie1("The Shining", "R");
    Movie movie2("The Shawshank Redemption", "R");

    // Adding random ratings for movie1
    for (int i = 0; i < 5; ++i) {
        int rating = rand() % 5 + 1;
        movie1.addRating(rating);
    }

    // Adding random ratings for movie2
    for (int i = 0; i < 5; ++i) {
        int rating = rand() % 5 + 1;
        movie2.addRating(rating);
    }

    // Outputting movie details and average rating
    cout << "Movie: " << movie1.getName() << endl;
    cout << "MPAA Rating: " << movie1.getMpaaRating() << endl;
    cout << "Average Rating: " << movie1.averageRating() << endl;

    cout << "Movie: " << movie2.getName() << endl;
    cout << "MPAA Rating: " << movie2.getMpaaRating() << endl;
    cout << "Average Rating: " << movie2.averageRating() << endl;

    return 0;
}

