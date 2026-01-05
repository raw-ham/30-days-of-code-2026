xwin = 0;
owin = 0;
var chance_of = 0;
x_series = [2, 2, 2, 2, 2, 2, 2, 2, 2];
count = 0 ;
// 2d array
arr = [
    [2,3,4],
    [11,6,5],
    [10,8,9]
]

function playagain() {
    //page reload
    location.reload();
}

function toogleNote() {
    if (chance_of == 0) {
        document.getElementById("note").innerHTML = "O's Turn";
    }
    else{
        document.getElementById("note").innerHTML = "X's Turn";
    }
}

function play(elements) {
    document.getElementById("board").classList.add("grif");
    for (let i = 0; i < 9; i++) {
        elements[i].classList.add("change");
    }
    document.getElementById("bottom").classList.add("shrink");
}

function gameOver(i) { 
    document.getElementById("board").style.display = "none";
    document.getElementById("endboard").style.display = "grid";
    

    if (chance_of == 0) {
        document.getElementById("X").innerHTML = "X WON";
    }
    else{
        document.getElementById("X").innerHTML = "O WON";
    }

    document.getElementById("note").innerHTML = "";
}

function draw() {
    document.getElementById("board").style.display = "none";
    document.getElementById("endboard").style.display = "grid";
    

    document.getElementById("X").innerHTML = "DRAW";
}

function check(x,y) {
    xcheck = 0;
    ycheck = 0;
    crcheck = 0;
    for (let i = 0;i < 3; i++) {
        if (arr[i][1]==arr[i][0] && arr[i][2]==arr[i][1]) {
            ycheck = 1;
        }
    }

    for (let i = 0;i < 3; i++) {
        if (arr[1][i]==arr[0][i] && arr[2][i]==arr[1][i]) {
            xcheck = 1;
        }
    }

    if (arr[1][1]==arr[0][0] && arr[2][2]==arr[1][1]) {
        crcheck = 1;
    }
    if (arr[1][1]==arr[2][0] && arr[0][2]==arr[1][1]) {
        crcheck = 1;
    }


   console.log(xcheck,ycheck);
    if (xcheck == 1 || ycheck == 1 || crcheck == 1) {
        console.log("win" , chance_of);
        gameOver(chance_of);
        document.getElementById("note").style.display = "none";
        document.getElementById("bottom").style.scale = "1.5";
    }

    //ifdraw
    if (count == 9) {
        console.log("draw");
        
    document.getElementById("note").innerHTML = "";
        draw();
    }
        
}
function update(i,elements) {
    count++;
    y = i % 3 ;
    x = parseInt(i / 3) ;
    

    if (arr[x][y] < 2) {
        return;
    }
    else {
        arr[x][y] = chance_of;
        chance_of = 1 - chance_of;
        console.log(arr);
        if (chance_of == 0) {
            elements[i].classList.add("red");
            elements[i].innerHTML = "X";
        }
        else{
            elements[i].classList.add("green");
            elements[i].innerHTML = "O";
        }
        check(x,y);
        toogleNote();
    }
}



document.addEventListener("DOMContentLoaded", function () {
    console.log("DOM fully loaded and parsed");
    
    var elements = [];
    for (let index = 0; index < 9; index++) {
        var elem = document.getElementById((index + 1).toString());
        elements[index] = elem;
        elements[index].addEventListener("click", function () {
            update(index,elements);
            
        });
    }

    document.getElementById("endboard").style.display = "none";
    
    
    var main = document.getElementById("main");
    main.addEventListener("click", function () {
        //for (let index = 0; index < 9; index++) {
            //    elements[index].classList.add("a"+parseInt(index/3)+parseInt(index%3));
            //
        play(elements);
        
    });

});