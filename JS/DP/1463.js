const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let N = +fs.readFileSync(filePath).toString();
let DP = new Array(N + 1).fill(0);

for (let i = 2; i < N + 1; i++) {
  let nums = [];
  if (i % 3 === 0) nums.push(DP[i / 3] + 1);
  if (i % 2 === 0) nums.push(DP[i / 2] + 1);
  if (i - 1 !== 0) nums.push(DP[i - 1] + 1);
  DP[i] = Math.min(...nums);
}

console.log(DP[N]);
