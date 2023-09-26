//Importing packages
const express = require("express");
const mongoose = require("mongoose");
const bodyParser = require("body-parser");

//Creating server
const app = express();

//Connecting to MongoDB using Mongoose (Object Data Modelling Library)
//useNewUrlParser: Parse MongoDB connection string
//useUnifiedTopology: Enables use of new MongoDB driver's unified topology engine
mongoose
  .connect("mongodb://127.0.0.1:27017/Sample", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  })
  .then(() => {
    console.log("Connected with mongoDB");
  })
  .catch((err) => {
    console.log(err);
  });

//Middleware Setup
//Parsing URL encoded form data
app.use(bodyParser.urlencoded({ extended: false }));
//Parsing JSON data from incoming requests
app.use(express.json());

//Creating Database schema
const productSchema = new mongoose.Schema({
  name: String,
  description: String,
  price: Number,
});

//Creating Collections
const Product = new mongoose.model("Product", productSchema);

//Create products
app.post("/api/v1/product/new", async (req, res) => {
  try {
    const product = await Product.create(req.body);

    res.status(201).json({
      success: true,
      product,
    });
  } catch (error) {
    console.error("Error creating product:", error);
    res.status(400).json({
      success: false,
      error: "Invalid data or server error",
    });
  }
});

//Read products
app.get("/api/v1/products", async (req, res) => {
  try {
    const products = await Product.find();

    res.status(200).json({
      success: true,
      products,
    });
  } catch (error) {
    console.error("Error fetching products:", error);
    res.status(500).json({
      success: false,
      error: "Server error",
    });
  }
});

//Update Product
app.put("/api/v1/product/:id", async (req, res) => {
  try {
    const product = await Product.findByIdAndUpdate(req.params.id, req.body, {
      new: true,
      useFindAndModify: false,
      runValidators: true,
    });

    if (!product) {
      return res.status(404).json({
        success: false,
        message: "Product not found",
      });
    }

    res.status(200).json({
      success: true,
      product,
    });
  } catch (error) {
    console.error("Error updating product:", error);
    res.status(500).json({
      success: false,
      error: "Server error",
    });
  }
});

//Delete Product
app.delete("/api/v1/product/:id", async (req, res) => {
  try {
    const product = await Product.findById(req.params.id);

    if (!product) {
      return res.status(404).json({
        success: false,
        message: "Product not found",
      });
    }

    //deleteOne function for removing entry
    await Product.deleteOne({ _id: req.params.id });

    // 204: No Content for successful deletion
    res.status(204).send();
  } catch (error) {
    console.error("Error deleting product:", error);
    res.status(500).json({
      success: false,
      error: "Server error",
    });
  }
});

app.listen(4500, () => {
  console.log("Server is working at http://localhost:4500");
});
