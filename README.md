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

## What I Learned

I have finished my prototype now and this is what I learned:

- Start by making a dynamic system
  - Adding new objects (states for example) is simple
  - This definitely helped the entire project with the state system
  - It will probably also help with other systems within the project
- Program to interface
  - I now understand this statement fully as you should write interfaces before implementation
  - Then work from the inside out
    - Code the thing that relys on everything first
    - Then you know what that needs
    - So you can add new methods if needed or just program the implementation once the code is complete
- Find a way to relate decomposition to the project
  - The state system really helped me program this as I had a way to break the project down that actually meant something
  - Each screen was its own state meaning I only had to focus on that state and program what it does and not focus on anything else

## Things to add to final project

Now that I have finished I have some new ideas on what to add / improve

- GUI
  - Using SFML
- MD5 hash value or better would be Hamming Codes
  - When saving to files to make sure the file wasn't corrupted
  - Hamming Codes would be amazing if I could implement it
    - 3b1b Videos:
    - https://youtu.be/X8jsijhllIA
    - https://youtu.be/b3NxrZOu_CE
- Encryption for password
  - Encrypt the passwords so the usr file cannot be opened and the password read
- A leaderboard
  - I didn't implement the leaderboard for the prototype at all
  - It would sort all accounts by whatever heuristic chosen
  - Searching for a name would be added
    - [Levenshtein Distance](https://en.wikipedia.org/wiki/Levenshtein_distance)
    - [Soundex](https://en.wikipedia.org/wiki/Soundex)
- My own data structures
  - Hash table
  - Stack
  - Matrix Vector Math
    - Matricies
    - Vectors

# New Features

- Better training data
  - Better layout of how the neural network is given input and how it outputs input
  - Improved inital state of all weights and biases
  - Saving the past 100 or so games to a file and training on them instead of just the one game after it is done
    - The training in the prototype was way too slow and boring
    - A heuristic probably needs to be introduced to measure how well the neural network is performing
      - Scale the training rate depending on this too
  - Learn more about Multilayer Perceptron and Backpropagation
- If I have time, maybe add a new game
  - The game would have to be made
  - Accounts would have to have two neural networks
    - One being active depending on what game is being played
  - Both neural networks would have to be saved to a file
- A 'perfect' AI could be made
  - Create an NN which learns from a perfected AI that wins at Connect 4 each time
  - Then see how well this NN performs as it is trying to learn from an already perfect AI
- Create a logging system
  - Prints information when in debug mode
    - Information
    - Warnings
    - Errors
    - Fatal Errors
- Improvement to state system
  - See: ac20f0993f0ce75a10fd6b501868baf434baab37
- Use a consistent layout to code
  - Using printf vs std::cout
  - Added newlines to the end on lines or the start