# Directory-Manager

Directory-Manager is a program that imitates the traditional bash shell, which allows you to manage your files and folders with the basic commands.

&nbsp;

## I. Project Structure

<br>

* [Tree.h](https://github.com/SwethaVipparla/Directory-Manager/blob/master/Tree.h) <br>
`Tree.h` includes all the header files necessary, structures created,
 and the declarations for the functions used in `Tree.c`.

* [Tree.c](https://github.com/SwethaVipparla/Directory-Manager/blob/master/Tree.c) <br>
`Tree.c` includes all the function implementations required to 
 create the left child right sibling tree data structure and nodes.

* [hash.h](https://github.com/SwethaVipparla/Directory-Manager/blob/master/hash.h) <br>
`hash.h` includes all the header files necessary, structures created,
 and the declarations for the functions used in `hash.c`.

* [hash.c](https://github.com/SwethaVipparla/Directory-Manager/blob/master/hash.c) <br>
`Hash.c` includes all the function implementations required to 
 create and implement the hash table that is used in storing the 
 aliases of the directories.

* [Directory.h](https://github.com/SwethaVipparla/Directory-Manager/blob/master/Directory.h) <br>
`Directory.h` includes all the header files necessary, structures created,
 and the declarations for the functions used in `Directory.c`.

* [Directory.c](https://github.com/SwethaVipparla/Directory-Manager/blob/master/Directory.c) <br>
`Directory.c` includes all the function implementations required to 
 implement the `add`, `move`, `alias`, `teleport`, `find`, `ls`, and `quit` functionalities.

* [Main.c](https://github.com/SwethaVipparla/Directory-Manager/blob/master/Main.c) <br>
`Main.c` includes the function calls for the various features and menu
 interface. The entire codebase is included in this file.

&nbsp;
## II. Instructions To Run The Program

<br>

### 1. Clone the repo onto your local machine
```
git clone https://github.com/SwethaVipparla/Directory-Manager.git
```
### 2. Navigate to the Directory-Manager folder
```
cd Directory-Manager/
```
### 3. Compile the code
```
gcc Main.c -o Main
```
### 4. Run the compiled code
```
./Main
```

### 5. Input commands
Once the code is up and running, a menu appears, asking for the input corresponding to the function wished to execute. A command can be chosen from the list of features available.

&nbsp;
## III. Features
<br>

### 1.  Add
Adds a file or directory to the current directory
```
add di/fi <new_name>
```
>  Note: The name entered must be a single word.  

<br>

### 2.  Move
Changes the current directory to another directory
```
move <path_to_destination_directory>
```

>  Note:\
Since the initial directory we're in is "root", the path should be of the form **"root/Directory1/Directory2/..."**<br>
The function takes you inside the last directory you entered. You must enter the complete path. If an incorrect path is entered, no change in the current position is performed.<br>
For example: `move root/Dir1/Dir12/Dir123`
will move you inside the Dir123 directory.

<br>

### 3.  Alias
Saves a directory with an alias
```
alias <path_to_directory> <new_alias>
```
> Note:\
 Take care of format of address.\
Alias can only be stored for directory addresses, as specified in the document. Alias must be a single word. 

<br>

### 4.  Teleport
Changes the current directory to another directory by taking in an existing alias
```
teleport <existing_alias>
```
<br>

### 5.  Find
Finds directories and files with a given prefix inside the current directory

```
find <prefix>
```
> Note: The prefix must be a single word.

<br>

### 6.  Ls
Lists the contents of the current directory

```
ls
```
<br>

### 7.  Quit
Exits the program

```
quit
```
> Note: Make sure to add QUIT at the end of the test file if the input is taken via a text file.

&nbsp;

