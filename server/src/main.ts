import express from "express";

const app = express();

app.get("/", (req, res) => {
  res.send({
    text: "Hello World",
  });
});

app.listen(3000, () => {
  console.log("App is listening in port 3k.");
});
