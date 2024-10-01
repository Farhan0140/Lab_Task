function All(num1, Char, num2) {
    if(Char == '+') {
        return num1 + num2;
    } else if(Char == '-') {
        return num1 - num2;
    } else if(Char == '*') {
        return num1 * num2;
    } else if(Char == '/') {
        return num1 / num2;
    } 
}
let num1 = parseInt(prompt("Enter 1st Number: "));
let num2 = parseInt(prompt("Enter 2nd Number: "));
let Chr = prompt("Enter +/ -/ */ /: ");

console.log(All(num1, Chr, num2));