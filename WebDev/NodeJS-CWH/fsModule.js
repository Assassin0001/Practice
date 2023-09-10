const fs = require('fs');

//This doesnt wait for file to read completely
/*
fs.readFile('file.txt', 'utf-8',(err,data)=>{
    console.log(err,data)
})
*/

const a = fs.readFileSync('file1.txt')
console.log(a.toString())

fs.writeFile('file2.txt', "Race: Human",() =>{
    console.log("Succesfully Updated Details")
});

fs.writeFileSync('file2.txt', "Status: Unknown");

const a2 = fs.readFileSync("file2.txt");
console.log(a2.toString())