let Arr = [1, 8, 9, 3, 10, 100, 5, 6, 7, 8, 2, 99];
let Even = [];
for(i=0; i<Arr.length; i++) {
    if(Arr[i] % 2 == 0) {
        Even.push(Arr[i]);
    }
}
console.log(Even);