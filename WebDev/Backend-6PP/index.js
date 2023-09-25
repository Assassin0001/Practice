import express from "express";
import path from "path";

const app = express();

//Get Request
app.get("/", (req, res) => {
  /*  
  res.sendStatus(404);
  res.json({
    success: true,
    products: [],
  });

  //Combined above Requests
  res.status(400).json({
    
    success: true,
    products: [],
  }); */

  res.sendFile("./index.html");
});

app.listen(5000, () => {
  console.log("app is working");
});
