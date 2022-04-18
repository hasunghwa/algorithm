const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";

let [A, B, C] = fs.readFileSync(filePath).toString().split(" ").map(BigInt);
console.log(Pow(A, B, C));
function Pow(a, b, c) {
  if (b === 1) return a % c;
  let val = Pow(a, BigInt(parseInt(b / BigInt(2))), c);
  val = (val * val) % c;
  if (b % BigInt(2) === 0) return val;
  return (val * a) % c;
}
