const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs.readFileSync(filePath).toString().split(" ");
const N = +input[0];
const K = +input[1];
let arr = new Array(100002).fill(-1);

let Q = [N];
arr[N] = 0;
while (arr[K] == -1) {
  const x = +Q.shift();

  for (let i = 0; i < 3; i++) {
    let dx = 0;
    if (i === 0) dx = x - 1;
    else if (i === 1) dx = x + 1;
    else dx = x * 2;

    if (dx < 0 || dx > 100000) continue;
    if (arr[dx] != -1) continue;

    arr[dx] = arr[x] + 1;
    Q.push(dx);
  }
}
console.log(arr[K]);
