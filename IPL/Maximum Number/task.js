let Arr = [1, 8, 9, 3, 10, 100, 5, 6, 7, 8, 2, 99];
let mx = 0;
for(i=0; i<Arr.length; i++) {
    if(mx < Arr[i]) {
        mx = Arr[i];
    }
}
console.log(mx);