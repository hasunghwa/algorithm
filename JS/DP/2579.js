const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");
let N = +input[0];
let arr = [];
for (let i = 1; i < N + 1; i++) arr.push(+input[i]);
let DP = new Array(N + 1).fill(0);

DP[1] = arr[0];
DP[2] = arr[1];
DP[3] = arr[2];

for (let i = 4; i < N; i++) {
  DP[i] = Math.min(DP[i - 2], DP[i - 3]) + arr[i - 1];
}
console.log(arr.reduce((a, b) => a + b) - Math.min(DP[N - 1], DP[N - 2]));
