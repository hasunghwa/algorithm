const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");

for (line of input) {
  if (line === ".") break;
  if (line) console.log(check(line) ? "yes" : "no");
}

function check(line) {
  let stack = new Array(101).fill();
  let p = -1;
  for (char of line) {
    if (char === "(" || char === "[") {
      stack[++p] = char;
    } else if (char === ")") {
      if (p === -1 || stack[p] !== "(") {
        return false;
      } else if (stack[p] === "(") {
        stack[p--] = 0;
      }
    } else if (char === "]") {
      if (p === -1 || stack[p] !== "[") {
        return false;
      } else if (stack[p] === "[") {
        stack[p--] = 0;
      }
    }
  }
  if (p === -1) return true;
  else return false;
}
