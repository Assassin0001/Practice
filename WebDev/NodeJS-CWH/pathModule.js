//Path Module

const path = require('path');

const a1 = path.basename('C:\\ temp \\ myFile.html');
const a2 = path.dirname('C:\\ temp \\ myFile.html');
const a3 = path.extname(__filename)
console.log(a1,a2,__filename,a3);