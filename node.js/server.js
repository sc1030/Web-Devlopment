const fs = require("fs")

// console.log(fs)

console.log("starting")
// fs.writeFileSync("shyam.txt", "shyam is a good boy")
fs.writeFile("shyam2.txt", "shyam is a good boy", () => {
    console.log("done ")
    fs.readFile("shyam2.txt", (error, data) => {
        console.log(error, data.toString())
    } )
})
console.log("ending")