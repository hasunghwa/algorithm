const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");
let N = +input[0];
const arr = Array.from(Array(N), () => []);
for (let i = 1; i < N + 1; i++) arr[i - 1] = input[i].split(" ").map(Number);
let DP = Array.from(Array(N + 1), () => new Array(3));

DP[1][0] = arr[0][0];
DP[1][1] = arr[0][1];
DP[1][2] = arr[0][2];
for (let i = 2; i < N + 1; i++) {
  DP[i][0] = Math.min(DP[i - 1][1], DP[i - 1][2]) + arr[i - 1][0];
  DP[i][1] = Math.min(DP[i - 1][0], DP[i - 1][2]) + arr[i - 1][1];
  DP[i][2] = Math.min(DP[i - 1][0], DP[i - 1][1]) + arr[i - 1][2];
}
console.log(Math.min(DP[N][0], DP[N][1], DP[N][2]));
