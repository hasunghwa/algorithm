const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs.readFileSync(filePath).toString().split("\n");
const N = input[0].split(" ")[0];
const M = +input[0].split(" ")[1];
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let arr = Array.from({ length: N }, () => []);
for (let i = 1; i < input.length; i++) {
  arr[i - 1] = input[i].split("\r")[0].split("").map(Number);
}

let vis = Array.from({ length: N }, () => new Array(M).fill(0));
let Q = [[0, 0]];

while (Q.length) {
  const xy = Q.shift();
  for (let i = 0; i < 4; i++) {
    const nx = xy[0] + dx[i];
    const ny = xy[1] + dy[i];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    if (vis[nx][ny] > 0 || arr[nx][ny] === 0) continue;
    vis[nx][ny] = vis[xy[0]][xy[1]] + 1;
    Q.push([nx, ny]);
  }
}

console.log(vis[N - 1][M - 1] + 1);
