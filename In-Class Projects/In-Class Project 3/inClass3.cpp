/******************************************************************************
* Course       : CS 2250 E01 (Fall 2015)
* Assignment   : In-Class Project 3
* Summary      : Uses the two functions created in this program
* Author       : Ian Piskulic
* Last Modified: September 17, 2015
******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct Name
{
  string first;
  string last;
};

struct MovieInfo
{
  string title;
  Name director;
  int yearReleased;
};

/******************************************************************************
* Name    : initializeMovieList
* Purpose : Initializes an array of movies
* Inputs  : An array and the size of that array.
* Outputs : None.
******************************************************************************/
void initializeMovieList(MovieInfo* list, int size);
/******************************************************************************
* Name    : displayMovieList
* Purpose : Displays a list of movies
* Inputs  : An array and the size of that array.
* Outputs : None.
******************************************************************************/
void displayMovieList(MovieInfo* list, int size);

int main()
{
  int size;
  MovieInfo* movies = NULL;

  // Gets the number of movies you want
  cout << "How many movies?: ";
  cin >> size;
  cout << endl;
  movies = new MovieInfo[size];

  // Tests the two functions
  initializeMovieList(movies, size);
  displayMovieList(movies, size);

  // Deallocate memory
  delete[]movies;
  movies = NULL;

  return 0;
}

void initializeMovieList(MovieInfo* list, int size)
{
  // Gets the info about each movie from the user
  for (int i = 0; i < size; i++)
  {
    cout << "What is the title of movie #" << (i + 1) << "?: ";
    cin >> list[i].title;
    cout << "What is the director's first name?: ";
    cin >> list[i].director.first;
    cout << "What is the director's last name?: ";
    cin >> list[i].director.last;
    cout << "What year was this movie released?: ";
    cin >> list[i].yearReleased;
    cout << endl;
  }

  return;
}

void displayMovieList(MovieInfo* list, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "Title: " << list[i].title << endl;
    cout << "Director: " << list[i].director.first << " " << list[i].director.last << endl;
    cout << "Year Released: " << list[i].yearReleased << endl;
    cout << endl;
  }

  return;
}