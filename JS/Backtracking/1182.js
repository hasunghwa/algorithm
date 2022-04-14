const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");
let [N, S] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);
let cnt = 0;
func(0, 0);
if (S == 0) cnt--;
console.log(cnt);
function func(cur, sum) {
  if (cur == N) {
    if (sum == S) cnt++;
    return;
  }

  func(cur + 1, sum);
  func(cur + 1, sum + arr[cur]);
}
