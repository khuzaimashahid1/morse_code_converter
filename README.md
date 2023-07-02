Morse Code Converter
This is a C++ program that allows you to encode English text into Morse code and decode Morse code back to English. It also provides functionality for searching, replacing, inserting, deleting, and displaying elements in a Morse code tree.

Instructions
Run the program in a C++ compiler or IDE that supports C++.
Choose one of the following options:
Enter 1 to decode Morse code to English.
Enter 2 to encode English to Morse code.
Enter 3 to search and replace elements in the Morse code tree.
Enter 4 to insert a new element into the Morse code tree.
Enter 5 to search and delete an element from the Morse code tree.
Enter 6 to display the Morse code tree.
Enter 7 to exit the program.
Follow the prompts and provide the required input for the selected option.
View the output generated by the program.
Morse Code Tree
The Morse code tree used in this program is represented using an array. The array arr contains the Morse code representation for each English alphabet and some special characters. The tree structure is based on the relationship between dots (.) and dashes (-).

Example Usage
cpp
Copy code
Enter what you wish to convert to Morse: Hello World
Encoded Text is: .... . .-.. .-.. --- / .-- --- .-. .-.. -..

Enter the Morse code you wish to decode:
Kindly put one space between Morse code of each character.
Use slash (/) to separate words.
Your Input: .... . .-.. .-.. --- / .-- --- .-. .-.. -..
The decoded Text is: hello world

Enter the element you wish to replace: h
Item Found in tree
Enter the element you wish to replace it with: x
Item Replaced Successfully
The Morse code of the replaced item is: -..-

Enter the element you wish to insert in the tree: z
Enter the index at which you wish to insert: 28
Item Inserted Successfully
The Morse code of the inserted item is: --..

Enter the element you wish to delete from the tree: x
Item deleted Successfully

Enter Appropriate input

Feel free to modify and improve the program according to your needs.

Note
This program assumes a specific Morse code mapping and may not be compatible with alternative Morse code systems.
