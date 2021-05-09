# Directory-Manager

## Instructions 

### 1. Clone the repo onto your local machine using the following commands:
```
>> git clone https://github.com/SwethaVipparla/Directory-Manager.git
```
### 2. Navigate to the Directory-Manager folder
```
>> cd Directory-Manager/
```
### 3. Compile the code
```
>> gcc Main.c -o Main
```
### 4. Run the compiled code
```
>> ./Main
```

### 5. Once the code is up and running, run the following commands as per the task you wish to perform.

### 6. When the terminal asks you Enter your choice, Enter the operation you wish to perform.


<br><br>

### 7.  To ADD an Element
```
Enter your choice
>> ADD
```
* #### To Add a File
```
Directory(di)/File(fi)
>> fi
```
* #### To Add a Directory
```
Directory(di)/File(fi)
>> di
```
   * #### Name of the Element
  ``` 
  Enter the name
  >> Name_of_the_file/directory
  ```
  >  Note:The name entered must be a single word.

  > Note: The file/directory is added to the present working directory.

<br>
<br>

### 8. To move to an Address
```
Enter your choice
>> MOVE
```
```
Enter the Path
>> Enter the address where you wish to move
```
>  Note: Since the initial directory we're in is "root",<br>
The path should be of the form **"root/Directory1/Directory2/..."**<br>

>The function takes you inside the last directory you entered. If incorrect path is entered, no change in the current position is performed.<br>

> For example: root/Dir1/Dir12/Dir123
will move you inside the Dir123 directory

<br>
<br>

### 9.  To store an Address in the form an Alias
```
Enter your choice
>> ALIAS
```
```
Enter the path
>> Enter the address of the directory that you wish to store
```
> Note: Take care of format of address.


> Note: Alias can only be stored for directory addresses as specified in the document.
```
Enter the Alias
>> Alias_for_the_corresponding_address
```
> Note: Alias must be a single word. 

<br>
<br>

### 10.  To Teleport to a particular location
```
Enter your choice
>> TELEPORT
```
```
Enter the Alias
>> Alias_for_the_required_location
```
<br>
<br>

### 11.  To Find the Elements
```
Enter your choice
>> FIND
```
```
Enter the prefix
>> Prefix_to_be_found
```
> Note: The prefix must be a single word.

<br>
<br>

### 12. To list all Elements in the Current Directory
```
Enter your choice
>> ls
```
<br>
<br>

### 13. To terminate the function
```
Enter your choice
>> Quit
```
<br>
<br>

> Note: Make sure to put a QUIT at the end of test file if taking input via text file.

