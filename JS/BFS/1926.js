const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs.readFileSync(filePath).toString().split("\n");
const N = input[0].split(" ")[0];
const M = +input[0].split(" ")[1];
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let arr = Array.from({ length: N }, () => []);
for (let i = 1; i < input.length; i++) {
  arr[i - 1] = input[i].split("\r")[0].split(" ").map(Number);
}

let vis = Array.from({ length: N }, () => new Array(M).fill(0));
let count = 0;
let max = 0;
let Q = [];
for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (arr[i][j] === 0 || vis[i][j]) continue;
    count++;
    vis[i][j] = 1;
    let area = 0;
    Q.push([i, j]);
    while (Q.length) {
      area++;
      const xy = Q.shift();
      for (let k = 0; k < 4; k++) {
        const nx = xy[0] + dx[k];
        const ny = xy[1] + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (arr[nx][ny] === 0 || vis[nx][ny] === 1) continue;
        vis[nx][ny] = 1;
        Q.push([nx, ny]);
      }
    }
    max = max < area ? area : max;
  }
}

console.log(count);
console.log(max);
