// http and fs Modules
 
const fs = require('fs');
const http = require('http');

const port = process.env.port || 3000;

const server = http.createServer((req, res) => {
    console.log(req.url)
    res.setHeader('Content-Type','text/html');
    if(req.url == '/'){
        res.statusCode = 200;
        res.end('<h1> This is NoTDeKU</h1> <p> Thou shall rule the world </p>');
    }
    else if(req.url == '/about'){
        res.statusCode = 200;
        res.end('<h1> This is Sung JinWoo, The Shadow Monarch</h1><p> Arise!</p>');
    }
    else if(req.url == '/hello'){
        res.statusCode = 200;
        const data = fs.readFileSync('index.html');
        res.end(data.toString());
    }
    else{
        res.statusCode = 404;
        res.end('<p>This Page was not found on the server.</p.');
    }
}) 

server.listen(port, () =>{
    console.log(`Server is listening on port ${port}`);
})