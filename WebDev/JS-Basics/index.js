const interestRate = 0.5;//Constant
//Primitive Type 
let name = "DeKU";//String literal
console.log(name);
let age = 30;//Number literal
letisApproved = true; //Bool
let firstName = undefined; //Undefined
let selectedColor = null; //Null

//Reference type
let person ={
    name :'Aman',
    age: 22
};
//Dot Notation
console.log(person);
person.name = "Ryser";
 
//Bracket Notation
let selection= 'name';
person[selection] ='Mary';
console.log(person.name);

//Array
let selectedColors =['red','blue'];
selectedColors[2] = 1;
console.log(selectedColors.length) ;

//Function
function greet(name,lastName){
    console.log('Hello'+name+' '+lastName);
}

greet('John','Smith');

//Calculating a value
function square(number){
    return number*number;
}

console.log(square(2));