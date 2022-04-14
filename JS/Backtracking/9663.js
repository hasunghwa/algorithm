const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let N = +fs.readFileSync(filePath).toString();
let isused1 = new Array(N).fill(false);
let isused2 = new Array(N * 2 - 1).fill(false);
let isused3 = new Array(N * 2 - 1).fill(false);
let cnt = 0;
func(0);
console.log(cnt);
function func(cur) {
  if (cur == N) {
    cnt++;
    return;
  }

  for (let i = 0; i < N; i++) {
    if (!isused1[i] && !isused2[cur + i] && !isused3[cur - i + N - 1]) {
      isused1[i] = true;
      isused2[cur + i] = true;
      isused3[cur - i + N - 1] = true;
      func(cur + 1);
      isused1[i] = false;
      isused2[cur + i] = false;
      isused3[cur - i + N - 1] = false;
    }
  }
}
