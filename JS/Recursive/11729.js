const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let N = +fs.readFileSync(filePath).toString();
let result = "";

console.log(2 ** N - 1);
hanoi(1, 3, N);
console.log(result);

function hanoi(a, b, n) {
  if (n === 1) {
    result += `${a} ${b}\n`;
    return;
  }
  hanoi(a, 6 - a - b, n - 1);
  result += `${a} ${b}\n`;
  hanoi(6 - a - b, b, n - 1);
}
