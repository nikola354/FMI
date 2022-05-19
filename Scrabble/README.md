# Scrabble

Solution to course project #07 <2021-2022>

* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @compiler GCC
*
* < This is a readme file >

<h1>Documentation: </h1>

<ul>
    <li>
        <h3>Configuration:</h3>
            If the program cannot find the dictionary file, go to < dictionaryController.h > 
and change the path variable. Most likely, you should remove '../' from the path.
    </li>
    <li>
        <h3>Design notes:</h3>
        <ul>
            <li>
                All of the settings apply only while the program is running. They are not saved anywhere.
            </li>
            <li>
                A new word is added to the dictionary at its end and only if it is found earlier in the document.
            </li>
            <li>
                Every letter brings different points. You can check scrabble_points.jpg . <br>
                The points are stored in array of integers where the index in the array correspondents to the index of the letter in the alphabet.
            </li>
        </ul>
    </li>
    <li>
        <h3>Hint for testing:</h3>
        Every single letter is a word in the dictionary by itself.
        If you enter the letter, you have a correct word, and you go to the next round.
    </li>
</ul>

