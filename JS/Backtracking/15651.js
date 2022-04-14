const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
let [N, M] = fs.readFileSync(filePath).toString().split(" ").map(Number);
let result = "";
let arr = new Array(M);
func(0);
console.log(result);
function func(K) {
  if (K === M) {
    for (num of arr) result += `${num + 1} `;
    result += "\n";
    return;
  }

  for (let i = 0; i < N; i++) {
    arr[K] = i;
    func(K + 1);
  }
}
