# Game Store
This program should ask the user for the name of a game store and receive input for 5 of the games.

Most of the implementation has already been completed for you in `main` so all you need to do is provide some logic, create objects and make function calls.

## GameStore Class
Create a class called `GameStore` that will have the following:

### Private Member Variables
1. `name_` which is a `string` that will be the name of the store
1. `games_` which is an array containing 5 `Game` objects. **NOTE**: The `Game` class is already provided to you.
1. `num_games_` which is a `int` that will store the size of the array.

### Default Constructor
Create a default constructor for `GameStore` that sets the name to `"GamePause"` and the number of games to `5`.

### Non-Default Constructor
Create a non-default constructor that takes in 1 parameter, a `string` for the name of the store. It should also set the value of `num_games_` to `5`.

### Accessors and Mutators
Create accessors called `getName`, `getGame`, `getNumGames`. **NOTE**: `getGame` should have 1 parameter that takes in an `int` `index` and should return the object in the array at that `index`.

Create mutators called `setName` and `setGame`. **NOTE**: `setGame` should have 2 parameters, the first is an `int` `index` and the second one is a `Game` object.
This mutator should use the accessors from the `Game` object parameter to retrieve the corresponding values for setting the title, price, and rating of the `games_` array at that `index`.

### Print Member Function
Create a `void` member function called `print` that will take one parameter, a `char` for the rating.

This function should display all the games in the `games_` array with the specified rating. The sample output below shows the format for this function. This function should print the line `Here are all the games with a rating of <rating>` followed by the list of games with the rating. **NOTE**: The line that asks for input from the user (`What rating of game do you want to buy?`) should be in `main()`.

## Main Function
Most of the main function is already filled out for you. Please follow the instructions located inside of `main.cpp` to complete the main function.

# Sample Output
```
Welcome to Game Store inventory system. ESRB rating edition
What is the name of the store? Fullerton Games
What is the name of the game you are going to put into inventory? Tuffy's Adventure
What is the rating for Tuffy's Adventure? E
What is the price for Tuffy's Adventure? 30.00
What is the name of the game you are going to put into inventory? Tuffy's Adventure 2
What is the rating for Tuffy's Adventure 2? E
What is the price for Tuffy's Adventure 2? 40.00
What is the name of the game you are going to put into inventory? Tuffy's EXTREME Racer
What is the rating for Tuffy's EXTREME Racer? T
What is the price for Tuffy's EXTREME Racer? 40.00
What is the name of the game you are going to put into inventory? Super Tuffy Adventure
What is the rating for Super Tuffy Adventure? E
What is the price for Super Tuffy Adventure? 60.00
What is the name of the game you are going to put into inventory? San's A God
What is the rating for San's A God? M
What is the price for San's A God? 1.00
What rating of game do you want to buy? E
Here are all the games with a rating of E
Tuffy's Adventure : $30
Tuffy's Adventure 2 : $40
Super Tuffy Adventure : $60
```

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Call function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex08-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `game_store.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 *.cpp -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit -m "short description of code changes"
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
