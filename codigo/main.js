fetch("http://0.0.0.0:18080/5", {
  method: "POST",
  headers: {
    'Content-Type': 'text/plain'
  },
  body: "Hello world",
})
  .then((response) => response.text())
  .then((result) => console.log(result))
  .catch((error) => {
    console.log("deu erro")
    console.error(error);
  });
