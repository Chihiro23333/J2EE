function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}

function setPos(){
    var anim = document.getElementById("anim");
    anim.style.position = "absolute";
    anim.style.left = "100px";
    anim.style.top = "50px";
}

function setPos1(){
    var anim = document.getElementById("anim1");
    anim.style.position = "absolute";
    anim.style.left = "100px";
    anim.style.top = "50px";
}

function move(){
    setTimeout("setPos1()",3000);
}


var moveAnimTimeOut;
function moveAnim(){
    var anim = document.getElementById("anim");
    var curLeft = parseInt(anim.style.left);
    var curTop = parseInt(anim.style.top);

    var targrtLeft = 200;
    var targrtTop = 100;
 
    if(curLeft == targrtLeft && curTop == targrtTop){
        if(moveAnimTimeOut){
            clearTimeout(moveAnimTimeOut);
        }
        return true;
    }

    var gap = 1;
    if(curLeft < targrtLeft){
        anim.style.left = curLeft + gap +"px";
    }

    if(curTop < targrtTop){
        anim.style.top = curTop + gap + "px";
    }

    moveAnimTimeOut = setTimeout("moveAnim()",10);
}

var moveEleAnimTimeOut;
function moveElement(elementId, final_x, final_y, interval){
    var anim = document.getElementById(elementId);
    var curLeft = parseInt(anim.style.left);
    var curTop = parseInt(anim.style.top);
 
    if(curLeft == final_x && curTop == final_y){
        if(moveEleAnimTimeOut){
            clearTimeout(moveEleAnimTimeOut);
        }
        return true;
    }

    var gap = 1;
    if(curLeft < final_x){
        anim.style.left = curLeft + gap +"px";
    }

    if(curTop < final_y){
        anim.style.top = curTop + gap + "px";
    }

    var functionName = "moveElement('"+elementId+"',"+final_x+","+final_y+","+interval+")";
    moveEleAnimTimeOut = setTimeout(functionName,interval);
}

function moveText(){
    moveElement("anim", 800, 500, 10);
    moveElement("anim1", 600, 200, 30);
}


addLoadEvent(setPos);
addLoadEvent(setPos1);
addLoadEvent(moveText); 