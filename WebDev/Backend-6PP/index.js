import express, { urlencoded } from "express";
import path from "path";

const app = express();
const users = [];

//Using middlewares
app.use(express.static(path.join(path.resolve(), "public")));
app.use(express.urlencoded({ extended: true }));

//Setting up view engine
app.set("view engine", "ejs");

//Get Request
app.get("/", (req, res) => {
  //Static HTML :
  // Shows error -> res.sendFile("./index.html");
  // const pathLocation = path.resolve();
  // res.sendFile(path.join(pathLocation,"./index.html"));

  //Dynamic
  res.render("index", { name: "Abhishek" });
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
  }); 
  */
});

app.post("/contact", (req, res) => {
  console.log(req.body);
  users.push({ userName: req.body.name, email: req.body.email });  
  res.redirect("/success");
});

app.get("/success",(req,res)=>{
  res.render("success");
});

app.get("/users",(req,res)=>{
  res.json(users);
});

app.listen(5000, () => {
  console.log("app is working");
});
