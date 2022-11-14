const hanoi = (plateNumber, fromColumn, subColumn, toColumn)=>{
    if(plateNumber === 1){
        console.log(`${fromColumn} ${toColumn}`);
    }else{
        hanoi(plateNumber - 1, fromColumn, toColumn, subColumn);
        console.log(`${fromColumn} ${toColumn}`);
        hanoi(plateNumber - 1, subColumn, fromColumn, toColumn);
    }
}

