function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}


function urlAnimPic(){
    
    var aList = document.getElementsByTagName("a");
    var perview = document.getElementById("perview");


        aList[0].onmouseover = function(){
            moveElement("perview",-300,0,10);
        }
        aList[1].onmouseover = function(){
            moveElement("perview",-600,0,10);
        }
        aList[2].onmouseover = function(){
            moveElement("perview",-900,0,10);
        }
}


function moveElement(elementId, final_x, final_y, interval){
    var anim = document.getElementById(elementId);
    var curLeft = parseInt(anim.style.left);
    var curTop = parseInt(anim.style.top);
 
    if(anim.movement){
        clearTimeout(anim.movement);
    }

    if(!anim.style.left){
        anim.style.left = "0px";
    }
    if(!anim.style.top){
        anim.style.top = "0px";
    }

    if(curLeft == final_x && curTop == final_y){
        return true;
    }

    var dist = 0;
    if(curLeft < final_x){
        dist = Math.ceil((final_x - curLeft)/10);
        curLeft += dist;
    }

    if(curLeft > final_x){
        dist = Math.ceil((curLeft - final_x)/10);
        curLeft -= dist;
    }

    if(curTop < final_y){
        dist = Math.ceil((final_y - curTop)/10);
        curTop += dist;
    }

    if(curTop > final_y){
        dist = Math.ceil((curTop - final_y)/10);
        curTop -= dist;
    }

    anim.style.left = curLeft+"px";
    anim.style.top = curTop +"px";
    var functionName = "moveElement('"+elementId+"',"+final_x+","+final_y+","+interval+")";
    anim.movement = setTimeout(functionName,interval);
}

addLoadEvent(urlAnimPic);
