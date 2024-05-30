# Themed Calculator
#### Video Demo: https://youtu.be/3BRb2dyqF0I
#### Description:
A themed calculator coded in javascript. Dynamic CSS styles allow for changing between light and dark modes, and event listeners for keyboard use is also active.
The html file includes mainly buttons coding for a displayed text input. Normal numerical buttons code for an appendValue function to this input. Whereas the calculate function, calculateIndices, deleteCharacter, calculateSin, calculateCos, calculateTan, calculateSqrt, calculateExponential, and toggleTheme functions are all coded in the script.js javascript file.
In the javascript file, the expression variable equals the display. The calculate function attempts to work out the expression, and if it fails flags up an error. Most of the scientific calculations work through the Math library of javascript and the deleteCharacter works through slicing negative values. Event Listeners are added to use the keyboard as an alternative to the clicked buttons. The toggleTheme function changes the body's class list so it follows a different css style!
In the css file, I've coded it to have a changeable width for mobile devices. Additionally I've set up a grid of columns for the calculator buttons to sit in, with the input spanning 4 columns.
