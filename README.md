# NEA-Prototype

This is my A-Level Computer Science NEA courswork project prototype.

## Description

My project is mainly a machine learning project. I have decided to use machine learning to create an AI that will learn to imitate a human at a task. As I do not have access to much training data I have decided to go with a simple task so that I can collect my own training data over time. The task I chose was the game of Connect 4. The end project should allow a Neural Network to learn to play Connect 4 like their corresponding user. According to the [AQA NEA Specification](https://filestore.aqa.org.uk/resources/computing/specifications/AQA-7516-7517-SP-2015.PDF), my project hits 3 of the example projects to choose from (A Computer Game, Artificial Intelligence, Machine Learning).

In my eyes, this does not seem like a massive task which is why I have removed quite a few features from this prototype of the project. Mainly, I have removed all graphics from the program, all interactions will be done at the command line. I decided to do this as I have tried graphics programming a few times and have had a hard time making clean code that does what I want. Also, the main attraction of the program is the machine learning and connect 4 game not the graphics, which is another reason why this prototype only focuses on them as it is just a proof of concept that this project can be completed and even without a lot of Quality of Life features, be complicated enough to get a high mark.

## Changes from Final Project

As this project is just a prototype, many features will be added in the full build of the project. Here is a list of all the features that I ignored for this prototype:

- GUI (I am using the command line for the prototype)
- Saving to a file
- MD5 hash value for the files
- Passwords for accounts
- Encryption for those passwords
- A better leaderboard with searching ([Levenshtein Distance](https://en.wikipedia.org/wiki/Levenshtein_distance) or [Soundex](https://en.wikipedia.org/wiki/Soundex))
- Sorting algorithm for leaderboard
- Hash table for fast access of users
- Any libraries that I am able to easily make myself will be made personally
  - Eigen (Matrix Vector Math)
  - C++ Standard (Stack, Vector, Hash Table)

## Features

By Friday the 11th of September, this prototype should contain the following:

- A fully working Connect 4 game
  - Command line graphics
  - Two different people able to play
- A simple multilayer perceptron neural network with runtime layer sizes
  - Ability to pass in a vector of floating point values and have it forward propogate and give a result
- A working backpropagation algorithm
  - Be able to give a list of training examples and update the network to learn from these
- A State system which allows for easy creation of new menu screens and ease to move between them
- An account system which contains:
  - All information about the account
  - A corresponding neural network that learns based on the player
