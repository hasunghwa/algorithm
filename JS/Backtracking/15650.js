const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let [N, M] = fs.readFileSync(filePath).toString().split(" ").map(Number);
let result = "";
let arr = new Array(M);
let isused = new Array(N).fill(false);
func(0);
console.log(result);
function func(K) {
  if (M == K) {
    let tmp = "";
    let min = arr[0];
    for (num of arr) {
      if (num < min) {
        return;
      }
      min = num;
      tmp += `${num + 1} `;
    }
    tmp += "\n";
    result += tmp;
    return;
  }

  for (let i = 0; i < N; i++) {
    if (!isused[i]) {
      arr[K] = i;
      isused[i] = true;
      func(K + 1);
      isused[i] = false;
    }
  }
}
